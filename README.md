[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/) 

![rgr](https://github.com/user-attachments/assets/c08f0e92-c828-4980-8336-c28b55ae0a9d)

![cmdr](https://github.com/user-attachments/assets/7f0aac49-af6f-4a11-af7e-b1ca2184d79a)

# Real-Time Crypto Price Tracker!

A lightweight tool to fetch and display real-time cryptocurrency prices from the Binance API using WebSocket. Built with a simple and intuitive GUI powered by Dear ImGui.

## Features

- Real-Time Updates: Fetches live cryptocurrency prices directly from Binance via WebSocket.
- Simple GUI: Clean and user-friendly interface using ImGui.
- Customizable: Easily add or remove cryptocurrencies to track by creating new instance of BinanceWebSocket thread.
- Lightweight: Minimalistic design with efficient performance.

## How It Works
The tool connects to Binance's WebSocket API to stream real-time price data for selected cryptocurrencies. The data is displayed in a straightforward GUI, making it easy to monitor price changes.

## Requirements

- C++ compiler (Visual Studio supporting C++11 or later)
- Binance websocket API
- [Dear ImGui](https://github.com/ocornut/imgui) for the GUI
- [Asio](https://think-async.com/Asio/) (Asio-standalone)
- [Websocketpp](https://github.com/zaphoyd/websocketpp) for realtime-fetching
- [openssl](https://github.com/openssl/openssl) for secure connection to wss server
- [glfw](https://github.com/glfw/glfw) create and manage window and OpenGL and handle joystick, keyboard and mouse input
- [glad](https://github.com/Dav1dde/glad) to manages function pointers for OpenGL
  
## Usage
Clone the repository.

`git clone https://github.com/omarker09/ImGui-Crypto-Websocket.git`

`cd ImGui-Crypto-Websocket`

`open realtime_crypto_websocket.sln`

`make sure to change Solution configuration to Release not Debug`

Build the project using Visual Studio build system.

click Run and Enjoy.

## End

Contributions are welcome! Feel free to open issues or submit pull requests to improve the tool.

- [@omkero](https://github.com/omkero) 
