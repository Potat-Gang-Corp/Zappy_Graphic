/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Main
*/

#include "GameEngine.hpp"

int main()
{
    GameEngine gameEngine;

    gameEngine.Initialize();
    gameEngine.Run();
    gameEngine.Shutdown();

    return 0;
}

