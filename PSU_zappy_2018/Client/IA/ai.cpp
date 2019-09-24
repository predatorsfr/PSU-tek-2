/*
** EPITECH PROJECT, 2019
** ai
** File description:
** ai
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../client.hpp"

char *ai(bool ai_state)
{
    int action;
    std::srand(std::time(NULL));
    action = std::rand() % 13;

    if (ai_state == true) {
        switch (action) {
        case 0:
            return("Forward\n");
            break;
        case 1:
            return("Right\n");
            break;
        case 2:
            return("Left\n");
            break;
        case 3:
            return("Look\n");
            break;
        case 4:
            return("Inventory\n");
            break;
        case 5:
            return("Broadcast text\n");
            break;
        case 6:
            return("Connect_nbr\n");
            break;
        case 7:
            return("Fork\n");
            break;
        case 8:
            return("Eject\n");
            break;
        case 9:
            return("Dead\n");
            break;
        case 10:
            return("Take object\n");
            break;
        case 11:
            return("Set object\n");
            break;
        case 12:
            return("Incantation\n");
            break;
        default:
            break;
        }
    }
    return (0);
}
