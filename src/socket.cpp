#include "socket.hpp"

Socket *Socket::instance = NULL;

Socket Socket::getInstance(void)
{
    if(instance == NULL)
    {
        instance = new Socket();
    }
    return *instance;
}

void Socket::SetPort(int port)
{
    this->port = port;
}

int Socket::GetPort(void)
{
    std::cout << "Application is listening on port: " << this->port << std::endl;
    return this->port;
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
    // Get the instance of the socket
    getInstance();
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
