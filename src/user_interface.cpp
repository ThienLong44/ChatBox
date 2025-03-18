#include "user_interface.hpp"

void UserInterface::showHelp(void)
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

void UserInterface::showMyIp(void)
{
    char ip_address[IP_ADDRESS_LENGTH];

    FILE *file = popen("hostname -I", "r");

    if(file == NULL)
    {
        std::cerr << "Failed to get the IP address" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(fgets(ip_address, sizeof(ip_address), file) == NULL)
    {
        std::cerr << "Failed to read the IP address" << std::endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "IP address: " << ip_address << std::endl;
    }

    pclose(file);
}

void UserInterface::showMyPort(void)
{
    std::cout << "Listening port: " << PORT << std::endl;
}