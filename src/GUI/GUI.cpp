/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"

GUI::GUI() {}

GUI::~GUI() {}

void GUI::initWindow(int height, int width, const std::string &WindowName)
{
    _screenH = height;
    _screenW = width;
    InitWindow(_screenW, _screenH, WindowName.c_str()); 
    SetTargetFPS(144);
}

void GUI::AddPlayer(Player player)
{
    int playerId = player.getNumber();
    _players[playerId].push_back(player);
}

void GUI::run()
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    exit(0);
}

