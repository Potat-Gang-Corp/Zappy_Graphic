/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** main
*/

// #include "Raylib.hpp"
#include "Team.hpp"
#include "GUI.hpp"
#include "PlayerData.hpp"
#include "Server.hpp"
#include <raylib.h>
#include <unistd.h>
#include "Map.hpp"

int main(int argc, char **argv) 
{
    if (argc != 5) {
        std::cerr << "USAGE: " << argv[0] << " -p port -h machine" << std::endl;
        return 1;
    }
    std::string port = argv[2];
    std::string host = argv[4];


    GUI gui;
    Server server;
    if (server.connect_server(port, host) != 0) {
        std::cerr << "Failed to connect to server" << std::endl;
        return 1;
    }
    gui.initWindow(800, 800, "Zappy");

    std::thread listeningThread(&Server::listening, &server);
    std::thread gameThread(&GUI::run, &gui);

    gameThread.join();
    server.stop();
    listeningThread.join(); 
    return 0;
}

