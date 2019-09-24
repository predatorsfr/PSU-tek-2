//
// EPITECH PROJECT, 2019
// main
// File description:
// 
//

#include "client.hpp"

void print_help()
{
	std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
	std::cout << "\tport\tis the port number" << std::endl;
	std::cout << "\tname\tis the name of the team" << std::endl;
	std::cout << "\tmachine\tis the name of the machine; localhost by default" <<std::endl;
}

int main(int ac, char **av)
{
	std::unique_ptr<Client> client;

	if (ac == 2 && strcmp(av[1],"-help"))
		print_help();
	else
		if (ac >= 5)
			parser(ac, av);
		else
			return (84);
	return (0);
}
