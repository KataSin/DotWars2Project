#pragma once
#include <memory>
class MySocketServer;
class MySocketClient;
using MySocketServerPtr = std::shared_ptr<MySocketServer>;
using MySocketClientPtr = std::shared_ptr<MySocketClient>;