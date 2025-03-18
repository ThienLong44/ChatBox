#include <iostream>
#include <string>
#include <sys/socket.h>


#include "main.hpp"
#include "socket.hpp"
#include "user_interface.hpp"


//Global variables
device_t this_device;
user_interface_t user_interface;

int main()
{
    // Initialize the socket
    this_device.InitializeSocket();

    //Show the help menu
    user_interface.showHelp();

    // Show the port
    this_device.GetPort();

    return 0;
}