#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Socket
{
    std::string ip;
    uint32_t port;
    uint32_t socketDescriptor;

  public:
    Socket(const std::string& ip, uint32_t port);

    ssize_t acceptClient();
    ssize_t receive(int32_t clientConn, std::vector<char>& buffer);
    uint32_t getPort() const;
};
