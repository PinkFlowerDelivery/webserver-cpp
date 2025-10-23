#include "socket.h"
#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

Socket::Socket(std::string ip, uint16_t port)
{
    this->ip   = ip;
    this->port = port;
}

void Socket::init()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        std::cout << "Error: " << strerror(errno) << std::endl;
    }

    sockaddr_in SockInfo;
    SockInfo.sin_family      = AF_INET;
    SockInfo.sin_addr.s_addr = inet_addr(ip.c_str());
    SockInfo.sin_port        = htons(port);

    int32_t BindAddr = bind(sock, (sockaddr*)&SockInfo, sizeof(SockInfo));
    if (BindAddr == -1)
    {
        std::cout << "Error: " << strerror(errno) << std::endl;
    }

    int32_t listener = listen(sock, 10);
    if (listener == -1)
    {
        std::cout << "Error: " << strerror(errno) << std::endl;
    }

    // while (true)
    // {
    //     int ClientConnect = accept(sock, nullptr, nullptr);
    //     if (ClientConnect > 0)
    //     {
    //         std::cout << "Connection" << std::endl;
    //     }
    //
    //     std::unique_ptr<char[]> buffer = std::make_unique<char[]>(255);
    //
    //     char msg[] = "hello";
    //
    //     recv(ClientConnect, buffer.get(), 255, 0);
    //     send(ClientConnect, msg, sizeof(msg), 0);
    //     close(ClientConnect);
    // }
};
