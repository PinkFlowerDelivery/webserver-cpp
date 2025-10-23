#include "network/socket.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <sys/socket.h>

int main()
{
    std::cout << "Hello, world!" << "\n";

    Socket socket{"192.168.0.105", 8080};
    socket.init();

    return 0;
}
