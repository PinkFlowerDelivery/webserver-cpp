#pragma once

#include <cstdint>
#include <string>

class Socket
{
    std::string ip;
    uint16_t    port;

  public:
    Socket(std::string ip, uint16_t port);

    void init();
};
