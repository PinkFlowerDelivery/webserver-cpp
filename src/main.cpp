#include "server/server.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>

int main()
{
    std::cout << "Hello, world!" << "\n";

    Server server{"192.168.0.105", 8080};
    server.init();

    return 0;
}
