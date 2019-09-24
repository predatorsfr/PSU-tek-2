//
// EPITECH PROJECT, 2019
// client
// File description:
//
//

#include "client.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

static struct sockaddr TcpFormatAdress(const char * host, u_short port )
{
    struct sockaddr_in addr;
    struct sockaddr addrRet;
    struct hostent *lphost ;
    u_long IP;

    memset((char*)&addr, 0, sizeof(addr));
    if ((IP = inet_addr(host)) == (u_long)INADDR_NONE) {
    if ((lphost  = gethostbyname(host))==NULL)
        {
            memset( (char * )&addrRet, 0, sizeof(addrRet) );
            return  addrRet;
        }
    addr.sin_family = lphost->h_addrtype;
#ifdef _WIN16 /* A définir dans le projet WIN16	*/
        _fmemcpy (&addr.sin_addr, lphost->h_addr, lphost->h_length);
#else /*	WIN32, UNIX*/
        memcpy (&addr.sin_addr, lphost->h_addr, lphost->h_length);
#endif
    }
    else {
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = IP;
    }
    addr.sin_port = htons((u_short)port );
    memcpy( (char *)&addrRet, (char *)&addr, sizeof(addrRet) );
    return addrRet;
}

Client::Client(int port, std::string team, std::string interf = "localhost") : _port(port), _interf(interf)
{
        struct sockaddr_in address;
        int sock = 0, valread;
        struct sockaddr_in serv_addr;
        char *hello = NULL;
        char buffer[1024] = {0};
        size_t length;

        _team = team;
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
                printf("Socket creation error\n");
                exit (-1);
        }

        memset(&serv_addr, '0', sizeof(serv_addr));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(_port);

        // Convert IPv4 and IPv6 addresses from text to binary form
        if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
        {
                printf("Invalid address/ Address not supported\n");
                exit (-1);
        }

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
                printf("Connection Failed\n");
                exit (-1);
        }
        _team += "\n";
        if (send(sock, _team.c_str(), strlen(_team.c_str()), 0) < 0)
            exit(84);
       // if (recv())
        //    if(send(sock, ai(true), sizeof(ai(true)), 0) < 0)
          //      exit(84);
        exit(0);

}
