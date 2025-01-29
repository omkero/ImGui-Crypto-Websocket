#ifndef BINANCE_WEB_SOCKET_H
#define BINANCE_WEB_SOCKET_H

#define _WINSOCKAPI_    // stops windows.h including winsock.h
#define ASIO_STANDALONE
#define _WEBSOCKETPP_CPP11_TYPE_TRAITS_
#define _WEBSOCKETPP_CPP11_RANDOM_DEVICE_
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/asio.hpp>
#include <vector>

typedef websocketpp::client<websocketpp::config::asio_tls_client> client;
typedef websocketpp::lib::shared_ptr<websocketpp::lib::asio::ssl::context> Ctx;

struct TradesStruct
{
	std::string TradeTime;
	std::string TradeCoin;
	std::string Price;
	std::string Quantity;
};

class BinanceWebSocket {
public:
	BinanceWebSocket(std::string type);
	~BinanceWebSocket();

	std::atomic<bool> isRunning;
	void connect(const std::string &url);
	std::vector<TradesStruct> trades;
	std::string get_crypto_price();
	std::vector<TradesStruct> get_order_book();

	void stop();
private:
	std::string type;
	// events
	void on_connect(websocketpp::connection_hdl hd);
	void on_message(websocketpp::connection_hdl hdl, client::message_ptr message);
	void on_close(websocketpp::connection_hdl hdl);
	void on_fail(websocketpp::connection_hdl hdl);
	
	// contexts
	client ws_client;
	std::thread ws_thread;
	websocketpp::connection_hdl conn_handle;

	// data
	std::string crypto_price = "waiting for connection ..";

};

#endif