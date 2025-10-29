#include "network/Socket.h"
#include "protocol/ParseHttp.h"
#include <fmt/base.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

int main()
{
    Socket   socket{"192.168.0.105", 8080};
    uint32_t socketPort = socket.init();
    fmt::println("Server started at {}", socketPort);

    while (true)
    {

        int32_t ClientConnection = accept(socket.getSocketDescriptor(), nullptr, nullptr);
        if (ClientConnection == -1)
        {
            fmt::println("Error: {}", strerror(errno));
        }

        // WARN: Magic numbers
        std::vector<char> buffer;
        buffer.reserve(128);

        recv(ClientConnection, buffer.data(), 1024, 0);
        close(ClientConnection);
    }

    return 0;
}
