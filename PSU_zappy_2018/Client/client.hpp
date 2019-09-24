//
// EPITECH PROJECT, 2019
// client
// File description:
//
//

#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string.h>
#include <getopt.h>
#include <memory>
#include <string>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>


class Client
{
public:
    Client(int port, std::string team, std::string interf);
    ~Client(){};
    std::string ai(bool ai_state);

private:
    struct protoent *p;
    struct sockaddr_in src_in;
    int sock;
    const int _port;
    std::string _team;
    const std::string _interf;
};
void parser(int ac, char **av);

#endif
