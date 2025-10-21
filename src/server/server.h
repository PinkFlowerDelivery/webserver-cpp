#pragma once

#include <cstdint>
#include <string>

class Server
{
    std::string ip;
    uint16_t    port;

  public:
    Server(std::string ip, uint16_t port);

    void init();
};
