/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** main
*/

#include "GUI.hpp"
#include "Server.hpp"

int main(int argc, char **argv) 
{
    GuiPtr gui = GUI::getInstance();
    ServerPtr server = Server::getInstance();
    std::string port, host;
    if (argc == 5) {
        port = argv[2];
        host = argv[4];
        gui->setHostPort(host, port);
    }

    std::thread listeningThread(&Server::listening, server);
    std::thread gameThread(&GUI::run, gui);

    gameThread.join();
    server->stop();
    listeningThread.join(); 
    return 0;
}

