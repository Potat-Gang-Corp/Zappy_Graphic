/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "Map.hpp"

GUI::GUI() {}

GUI::~GUI() {}

void GUI::initWindow(int height, int width, const std::string &WindowName)
{
    _screenH = height;
    _screenW = width;
    InitWindow(_screenH, _screenW, WindowName.c_str()); 
    SetTargetFPS(144);
}

void GUI::AddPlayer(Player player)
{
    int playerId = player.getNumber();
    _players[playerId].push_back(player);
}

void GUI::run()
{
    initWindow(1920, 1080, "raylib [core] example - 3d camera free");

    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    SetTargetFPS(144);
    MapPtr map = Map::getInstance();
    map->setMapSize(10, 10);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        for (float i = 0; i < map->getMapSizeX(); i++) {
            for (float j = 0; j < map->getMapSizeY(); j++) {
                DrawCube((Vector3){(float)(i - map->getMapSizeX() / 2 + 0.5), 0, (float)(j - map->getMapSizeY() / 2 + 0.5)}, 0.5f, 0.5f, 0.5f, RED);
            }
        }
        DrawGrid(10, 1.0f);
        EndMode3D();
        DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
