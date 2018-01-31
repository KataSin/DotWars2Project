#pragma once
#include <memory>
class TCPServerSocket;
class TCPClientSocket;
using TCPServerSocketPtr = std::shared_ptr<TCPServerSocket>;
using TCPClientSocketPtr= std::shared_ptr<TCPClientSocket>;
