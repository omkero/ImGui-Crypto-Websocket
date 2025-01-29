#include "binance_web_socket.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <nlohman/json.hpp>
#include <string>
#include <cstring>

// SSL/TLS encryption for secure wss/ connection
Ctx on_tls_init() {
    Ctx ctx = websocketpp::lib::make_shared<websocketpp::lib::asio::ssl::context>(websocketpp::lib::asio::ssl::context::tlsv12);

    try {
        ctx->set_options(websocketpp::lib::asio::ssl::context::default_workarounds |
            websocketpp::lib::asio::ssl::context::no_sslv2 |
            websocketpp::lib::asio::ssl::context::no_sslv3 |
            websocketpp::lib::asio::ssl::context::single_dh_use);
    }
    catch (std::exception& e) {
        std::cout << "Error setting TLS context options: " << e.what() << std::endl;
    }
    return ctx;
}

// the default constructor
BinanceWebSocket::BinanceWebSocket(std::string type) : type(type) {
    ws_client.init_asio();

    // set properties and bind it
    ws_client.set_tls_init_handler([](websocketpp::connection_hdl) {
        return on_tls_init();
        });

    ws_client.set_close_handler([this](websocketpp::connection_hdl hdl) {
        on_close(hdl);
        });

    ws_client.set_message_handler([this](websocketpp::connection_hdl hdl, client::message_ptr message) {
        on_message(hdl, message);
        });

    ws_client.set_fail_handler([this](websocketpp::connection_hdl hdl) {
        on_fail(hdl);
        });
};

BinanceWebSocket::~BinanceWebSocket() {
    stop();
}

// connect 
void BinanceWebSocket::connect(const std::string& url) {
    websocketpp::lib::error_code ec;

    auto conn = ws_client.get_connection(url, ec);
    if (ec) {
        std::cerr << "Connection error" << ec.message() << std::endl;
    }

    conn_handle = conn->get_handle();
    ws_client.connect(conn);

    isRunning = true;
    ws_thread = std::thread([this]() {

        ws_client.run();
        });
}

void BinanceWebSocket::on_connect(websocketpp::connection_hdl hdl) {
    std::cout << "Connected to binance server" << std::endl;
}

void BinanceWebSocket::on_message(websocketpp::connection_hdl hdl, client::message_ptr mesage) {
    // std::cout << "Received message: " << mesage->get_payload() << std::endl;
    nlohmann::json toJson = nlohmann::json::parse(mesage->get_payload());

    if (std::strcmp(type.c_str(), "price") == 0) {
        crypto_price = toJson["c"];
    }
    else if (std::strcmp(type.c_str(), "trades") == 0) {
        try {
            if (trades.size() >= 40) {
                trades.pop_back();
            }
            // Ensure numeric fields are converted to strings
            trades.insert(trades.begin(), {
                std::to_string(toJson["T"].get<long long>()), // Convert timestamp to string
                toJson["s"].get<std::string>(),             
                toJson["p"].get<std::string>(),              
                toJson["q"].get<std::string>()               
                });
        }
        catch (std::exception& e) {
            std::cerr << "Error on pushing" << e.what() << std::endl;
        }
    }
    else {
        crypto_price = "type not allowed";
        return;
    }
};

void BinanceWebSocket::on_fail(websocketpp::connection_hdl hdl) {
    std::cout << "Connection failed" << std::endl;
}

void BinanceWebSocket::on_close(websocketpp::connection_hdl hdl) {
    std::cout << "Connection closed" << std::endl;
}

void BinanceWebSocket::stop() {
    if (isRunning) {
        websocketpp::lib::error_code ec;
        ws_client.stop_perpetual();
        ws_client.close(conn_handle, websocketpp::close::status::normal, "Shutting down", ec);
        if (ec) {
            std::cerr << "Error closing connection: " << ec.message() << std::endl;
        }

        isRunning = false;
        if (ws_thread.joinable()) {
            ws_thread.join();
        }
    }
}

std::string BinanceWebSocket::get_crypto_price() {
    return crypto_price;
}

std::vector<TradesStruct> BinanceWebSocket::get_order_book() {
    return this->trades;
}