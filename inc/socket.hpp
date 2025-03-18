#ifndef __SOCKET_HPP__
#define __SOCKET_HPP__

#include "main.hpp"

// Class definition
typedef class Socket
{
private:
    int id;
    int socket_fd;
    int port;
    struct sockaddr_in address;
    socklen_t address_length;

    // Instance variables
    static Socket *instance;

public:
    void InitializeSocket(void);
    void CreateSocket(void);
    void SetPort(int port);
    int GetPort(void);
    void BindSocket(void);
    void ListenSocket(void);
    void AcceptSocket(void);
    void CloseSocket(void);
    
    // Singleton pattern
    static Socket getInstance(void); 

}device_t;


#endif // __SOCKET_HPP__