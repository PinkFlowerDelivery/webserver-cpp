#pragma once

#include <cstdint>
#include <string>

class Socket
{
    std::string ip;
    uint32_t    port;
    uint32_t    socketDescriptor;

  public:
    Socket(std::string ip, uint32_t port);

    uint32_t       init();
    const uint32_t getSocketDescriptor() const;
};
