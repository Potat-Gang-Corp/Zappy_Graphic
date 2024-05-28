/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** main
*/

#include "Team.hpp"
#include "PlayerData.hpp"
#include "Server.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "Usage: " << av[0] << " <host> <port>\n";
        return 1;
    }

    // Debug messages
    std::cout << "Arguments received - Host: " << av[1] << ", Port: " << av[2] << std::endl;

    Server server;
    std::string host = av[1];
    std::string port = av[2];

    return server.connect_server(host, port);
}