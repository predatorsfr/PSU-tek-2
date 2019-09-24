#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include <memory>
#include "mappe.hpp"

class Graphe
{
public:
        Graphe();
        ~Graphe(){};
        void load_data(int x, int y);
        void set_data(int x, int y);

        std::unique_ptr<Map> map;
};