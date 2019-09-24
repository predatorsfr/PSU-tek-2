//
// EPITECH PROJECT, 2019
// parser
// File description:
// 
//

#include "client.hpp"

void parser(int ac, char **av)
{
    int c;
    std::unique_ptr<Client> client;
    std::string team;
    std::string interf = "127.0.0.1";
    int port = 0;

    while ((c = getopt(ac, av, "p:n:h:")) != -1) {
        switch (c) {
        case 'p':
            port = atoi(optarg);
            break;
        case 'n':
            team = optarg;
            break;
        case 'h':
            interf = optarg;
            break;
        default:
            exit(84);
            break;
        }
    }
    if (team == "" || port <= 0)
        exit(84);
    client = std::make_unique<Client>(port, team, interf);
}