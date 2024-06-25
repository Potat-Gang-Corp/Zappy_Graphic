/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Main
*/

#include "GameEngine.hpp"

int main(int argc, char **argv)
{
    GameEngine gameEngine;
     if (argc != 5) {
        std::cerr << "USAGE: " << argv[0] << " -p port -h machine" << std::endl;
        return 1;
    }
    std::string port = argv[2];
    std::string host = argv[4];
    
    gameEngine.Initialize();
    gameEngine.Run();
    gameEngine.Shutdown();

    return 0;
}

