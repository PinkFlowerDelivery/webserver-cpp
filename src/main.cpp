#include "network/Socket.h"
#include "protocol/HttpParser.h"
#include <cstdint>
#include <fmt/base.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

int main()
{
    Socket socket{"192.168.0.105", 8080};
    fmt::println("Server started at {}", socket.getPort());

    while (true)
    {

        int32_t clientConn = socket.acceptClient();

        std::vector<char> buffer(1024);
        int32_t receivedBytes = socket.receive(clientConn, buffer);

        std::string data(buffer.data(), receivedBytes);

        ParseHttp ph;
        ph.parse(data);

        close(clientConn);
    }
}
