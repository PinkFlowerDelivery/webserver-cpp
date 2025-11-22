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
#include <vector>

Socket::Socket(const std::string& ip, uint32_t port) : ip(ip), port(port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }
    this->socketDescriptor = sock;

    sockaddr_in SockInfo;
    SockInfo.sin_family = AF_INET;
    SockInfo.sin_addr.s_addr = inet_addr(ip.c_str());
    SockInfo.sin_port = htons(port);

    ssize_t BindAddr = bind(sock, reinterpret_cast<sockaddr*>(&SockInfo), sizeof(SockInfo));
    if (BindAddr == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }

    ssize_t listener = listen(sock, 10);
    if (listener == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }
};

ssize_t Socket::acceptClient()
{

    ssize_t ClientConnection = accept(this->socketDescriptor, nullptr, nullptr);
    if (ClientConnection == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }

    return ClientConnection;
}

ssize_t Socket::receive(int32_t clientConn, std::vector<char>& buffer)
{
    ssize_t receivedBytes = recv(clientConn, buffer.data(), buffer.size(), 0);
    if (receivedBytes == -1)
    {
        fmt::println("Error: {}", strerror(errno));
    }

    return receivedBytes;
};

uint32_t Socket::getPort() const
{
    return port;
}
