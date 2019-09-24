
#include "graphe.hpp"
#include <vector>
#include <string.h>
#include <string>
#include <cstring>
// int ten(char **av)
// {
//     sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window");
//     sf::Texture texture;
//     if (!texture.loadFromFile("download.jpeg"))
//         return EXIT_FAILURE;
//     sf::Sprite sprite(texture);
//     std::vector <sf::Sprite> enemies;
//     std::unique_ptr<Graphe> graphe(new Graphe);
//     graphe->set_data(std::atoi(av[1]), std::atoi(av[2]));
//     graphe->map->display();
//     // sprite.scale(4,4);
//     // sprite.setPosition(40, 50);
//     while (window.isOpen())
//     {

//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == true))
//                 window.close();
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//         window.clear();
//         for (int i = 0; i < graphe->map->getY(); i++) {
//             for (int j = 0; j < graphe->map->getX(); j++) {
//                 if (graphe->map->getChar(i, j) == 'X') {
//                     enemies.push_back(sprite);
//                     if (!enemies.empty()) {
//                     enemies.back().setPosition(i, j);
//                     window.draw(enemies,sprite);
//                     }
//                 }
//             }
//         }
//         // window.draw(sprite);
//         window.display();
//     }
//     return EXIT_SUCCESS;
// }
// int main(int ac, char **av)
// {
//     if (ac == 3)
//         ten(av);
// }
Map::~Map()
{
}

Map::Map(std::vector<std::string> ptr) : _x(ptr.back().size()), _y(ptr.size() - 1)
{
    map = new char*[_y + 1];
    map[_y] = NULL;
    for (int y = 0 ; y < _y ; y++) {
        map[y] = new char[_x + 1];
        std::strcpy(map[y], ptr.at(y+1).c_str());
    }
}

void Map::create_map()
{
    this->map = new char*[_y + 1];

    map[_y] = NULL;
    for (int i = 0; i < _y; i++) {
        map[i] = new char[_x + 1];
        map[i][_x] = '\0';
    }
    for (int i = 0; i < _x; i++)
        map[0][i] = 'X';
    for (int i = 1; i < _y; i++) {
        map[i][0] = 'X';
        for (int c = 1; c < _x; c++)
            map[i][c] = 'X';
        map[i][_x - 1] = 'X';
        }
    for (int i = 0; i < _x; i++)
        map[_y - 1][i] = 'X';
}

void Map::gen_map()
{

    create_map();
}

void Map::display()
{
    for (int i = 0; map[i] != NULL; i++)
        std::cout << map[i] << std::endl;
}