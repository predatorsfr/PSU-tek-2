#pragma once


#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

class Map
{
public:
    Map(std::vector<std::string> ptr);
    Map(int x, int y) : _x(x), _y(y) {
            gen_map();
    };
    ~Map();

    void create_map();
    // void put_destructibles();
    void gen_map();
    // void gen_obstacle();
    // void rand_empty();
    // int gen_rand();
    void display();
//    void setBomb(int x, int y);

//  Getter
    char *getLine(int y)
        {return (map[y]);};
    char **getMap()
    {return(map);};
    int getX()
    {return(_x);};
    int getY()
    {return(_y);};
    char getChar(int y, int x) {
        return (map[y][x]);
    };

private:
    char **map;
    //std::vector <std::unique_ptr<Bomb>> bombers;
    const int _x;
    const int _y;
};