/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"

GUI::GUI() {}

GUI::~GUI() {}

void GUI::AddPlayer(Player player)
{
    int playerId = player.getNumber();
    _players[playerId].push_back(player);
}

void GUI::run()
{
    WindowPtr window = Window::getInstance();
    window->setLogInfo("LOG_INFO");
    window->initWindow(1920, 1080, "raylib [core] example - 3d camera free", 144);
    CameraWrapper camera;
    MapPtr map = Map::getInstance();
    map->setMapSize(10, 10);
    // Model model = LoadModel("assets/island.glb");
    while (!WindowShouldClose())
    {
        // camera.update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        camera.BeginMode();
        window->DrawMap(map->getMapSizeX(), map->getMapSizeY());
        // DrawModel(model, (Vector3){0.0f, 0.0f, 0.0f}, 1.0f, WHITE);
        // DrawGrid(10, 1.0f);
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
