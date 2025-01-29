#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <iostream>
#include "inter_font.h" // Include your font data header
#include <string>
#include "custom_ui.h"
#include "binance_web_socket.h"
#include "imgui_style.h"
#include <chrono>
#include <cstring>
#include <iomanip>
#include <sstream>

#ifndef _WINSOCKAPI_   
#define _WINSOCKAPI_    // stops windows.h including winsock.h
#endif // !_WINSOCKAPI_   

#define ASIO_STANDALONE
#define _WEBSOCKETPP_CPP11_TYPE_TRAITS_
#define _WEBSOCKETPP_CPP11_RANDOM_DEVICE_
#include <websocketpp/config/asio_client.hpp>
#include <websocketpp/client.hpp>
#include <websocketpp/common/asio.hpp>


// int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, 1);
    glfwWindowHint(GLFW_DECORATED, true);
    glfwWindowHint(GLFW_RESIZABLE, true);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_REFRESH_RATE, 50);

    // Create a windowed mode window and its OpenGL context
    int win_height = 500;
    int win_width = 700;

    // Get the primary monitor
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    // Create the window
    GLFWwindow* window = glfwCreateWindow(win_width, win_height, "Realtime Crypto Websocket", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    int resize_win_width;
    int resize_win_height;


    glfwGetWindowSize(window, &resize_win_width, &resize_win_height);

    // Calculate the position to center the window
    int windowPosX = (mode->width - resize_win_width) / 2;
    int windowPosY = (mode->height - resize_win_height) / 2;
    // Set the window position to the center of the screen
    glfwSetWindowPos(window, windowPosX, windowPosY);

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        return -1;
    }

    const char* glsl_version = "#version 130";

    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Adjust the font size by DPI scale

    io.Fonts->AddFontFromMemoryTTF(rawData, sizeof(rawData), 21.0f);

    LoadUbuntuStyle();

    // Initialize ImGui GLFW and OpenGL bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    CustomUI ui;

    BinanceWebSocket client("price");
    client.connect("wss://stream.binance.com:9443/ws/xrpusdt@miniTicker");

    BinanceWebSocket client2("price");
    client2.connect("wss://stream.binance.com:9443/ws/btcusdt@miniTicker");


    BinanceWebSocket client3("trades");
    client3.connect("wss://stream.binance.com:9443/ws/btcusdt@trade");

    BinanceWebSocket client4("price");
    client4.connect("wss://stream.binance.com:9443/ws/ethusdt@miniTicker");

    BinanceWebSocket client5("trades");
    client5.connect("wss://stream.binance.com:9443/ws/ethusdt@trade");

   
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        if (glfwWindowShouldClose(window)) {

            glfwTerminate();
            glfwDestroyWindow(window);
            break; // Exit the loop immediately
        }

        glfwPollEvents();
        glfwSwapInterval(1);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        int responsive_win_width;
        int responsive_win_height;


        glfwGetWindowSize(window, &responsive_win_width, &responsive_win_height);


        static float f = 0.0f;
        static int counter = 0;
        static char text_inp_buf1[999999] = ""; // 256 is the buffer size, adjust as needed
        static char text_inp_buf2[999999] = ""; // 256 is the buffer size, adjust as needed

        char message_imp[256] = "";

        bool isDemo = false;
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(responsive_win_width, responsive_win_height));


        if (ImGui::Begin("Realtime Crypto Websocket", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar))
        {
            ui.MenuBar(window);
        }

        //ui.LoginPanel(window, 265, 400, true);

        
        ImGui::Text("Bitcoin: ");
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
        ImGui::Text(client2.get_crypto_price().c_str());
        ImGui::PopStyleColor();

        ImGui::Text("Ethereum: ");
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
        ImGui::Text(client4.get_crypto_price().c_str());
        ImGui::PopStyleColor();
       
        ImGui::Text("XRP: ");
        ImGui::SameLine();
        ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
        ImGui::Text(client.get_crypto_price().c_str());
     
        ImGui::PopStyleColor();
       

        float btc_window_h = 400;
        float btc_window_w = 400;

        ImGui::SetNextWindowSize(ImVec2(btc_window_w, btc_window_h));
        ImGui::Begin("BTC/USDT Trades");
        // iterate into 
        for (auto& item : client3.trades) {

            ImGui::Text(item.TradeCoin.c_str());
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
            ImGui::Text(item.Quantity.c_str());
            ImGui::PopStyleColor();
            ImGui::SameLine();
            ImGui::Text("%s", item.TradeTime.c_str());
        }

        ImGui::End();

        float eth_window_h = 400;
        float eth_window_w = 400;

        ImGui::SetNextWindowSize(ImVec2(eth_window_w, eth_window_h));
        ImGui::Begin("ETH/USDT Trades");
        // iterate into 
        for (auto& item : client5.trades) {

            ImGui::Text(item.TradeCoin.c_str());
            ImGui::SameLine();
            ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
            ImGui::Text(item.Quantity.c_str());
            ImGui::PopStyleColor();
            ImGui::SameLine();
            ImGui::Text("%s", item.TradeTime.c_str());
        }

        ImGui::End();


        ImGui::End();
        ImGui::Render();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    client.stop();
    client2.stop();
    client3.stop();
    client4.stop();
    client5.stop();
    return 0;
}
