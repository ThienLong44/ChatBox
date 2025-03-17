#include "socket.hpp"

void showHelp(void)
{
    std::cout << "******************************** Chat Application ********************************"   << std::endl;
    std::cout << "Use the commands below: "                                                             << std::endl;
    std::cout << "1. help                             : display user interface options"                 << std::endl;
    std::cout << "2. myip                             : display IP address of this app"                 << std::endl;
    std::cout << "3. myport                           : display listening port of this app"             << std::endl;
    std::cout << "4. connect <destination> <port no>  : connect to the app of another computer"         << std::endl;
    std::cout << "5. list                             : list all the connections of this app"           << std::endl;
    std::cout << "6. terminate <connection id>        : terminate a connection"                         << std::endl;
    std::cout << "7. send <connection id> <message>   : send a message to a connection"                 << std::endl;
    std::cout << "8. exit                             : close all connections & terminate this app"     << std::endl;  
    std::cout << "**********************************************************************************"   << std::endl;
}

void Socket::SetPort(int port)
{
    this->port = port;
}

void Socket::CreateSocket(void)
{
    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(this->port);
}

void Socket::BindSocket(void)
{
    if (bind(this->socket_fd, (struct sockaddr *)&this->address, sizeof(this->address)) < 0)
    {
        std::cerr << "Failed to bind the socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Socket::ListenSocket(void)
{
    if (listen(this->socket_fd, 3) < 0)
    {
        std::cerr << "Failed to listen on the socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Socket::AcceptSocket(void)
{
    this->address_length = sizeof(this->address);
    this->socket_fd = accept(this->socket_fd, (struct sockaddr *)&this->address, &this->address_length);
    if (this->socket_fd < 0)
    {
        std::cerr << "Failed to accept the socket" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Socket::CloseSocket(void)
{
    close(this->socket_fd);
}

void Socket::InitializeSocket(void)
{
    // Set the port to 8080
    this->SetPort(8080);
    // Create the socket
    this->CreateSocket();
    // Bind the socket
    this->BindSocket();
    // Listen on the socket
    this->ListenSocket();
    // Accept the socket
    this->AcceptSocket();
}
