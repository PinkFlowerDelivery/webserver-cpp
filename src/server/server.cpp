#include "server.h"
#include <arpa/inet.h>
#include <cerrno>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

Server::Server(std::string ip, uint16_t port)
{
    this->ip   = ip;
    this->port = port;
}

// TODO: Error handling
void Server::init()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        throw std::runtime_error("Socket not given");
    }

    sockaddr_in SockInfo;
    SockInfo.sin_family      = AF_INET;
    SockInfo.sin_addr.s_addr = inet_addr(ip.c_str());
    SockInfo.sin_port        = htons(port);

    int bin = bind(sock, (sockaddr*)&SockInfo, sizeof(SockInfo));

    int listener = listen(sock, 5);

    while (true)
    {
        int ClientConnect = accept(sock, nullptr, nullptr);
        if (ClientConnect > 0)
        {
            std::cout << "Connection" << std::endl;
        }

        std::unique_ptr<char[]> buffer = std::make_unique<char[]>(255);

        char msg[] = "hello";

        recv(ClientConnect, buffer.get(), 255, 0);
        send(ClientConnect, msg, sizeof(msg), 0);
        close(ClientConnect);
    }
};
