#include "Socket.h"
#include <arpa/inet.h>
#include <cerrno>
#include <cstdint>
#include <cstring>
#include <fmt/base.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

Socket::Socket(std::string ip, uint32_t port)
{
    this->ip   = ip;
    this->port = port;
}

uint32_t Socket::init()
{
    uint32_t sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }
    this->socketDescriptor = sock;

    sockaddr_in SockInfo;
    SockInfo.sin_family      = AF_INET;
    SockInfo.sin_addr.s_addr = inet_addr(ip.c_str());
    SockInfo.sin_port        = htons(port);

    // auto c = static_cast<sockaddr*>(&SockInfo);

    int32_t BindAddr = bind(sock, (sockaddr*)&SockInfo, sizeof(SockInfo));
    if (BindAddr == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }

    int32_t listener = listen(sock, 10);
    if (listener == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }

    return this->port;
};

const uint32_t Socket::getSocketDescriptor() const
{
    return this->socketDescriptor;
};
