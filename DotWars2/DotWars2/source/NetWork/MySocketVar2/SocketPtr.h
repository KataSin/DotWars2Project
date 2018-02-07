#pragma once
#include <memory>
class TCPServerSocket;
class TCPClientSocket;

class UDPServerSocket;
class UDPClientSocket;

using TCPServerSocketPtr = std::shared_ptr<TCPServerSocket>;
using TCPClientSocketPtr= std::shared_ptr<TCPClientSocket>;

using UDPServerSocketPtr = std::shared_ptr<UDPServerSocket>;
using UDPClientSocketPtr = std::shared_ptr<UDPClientSocket>;
