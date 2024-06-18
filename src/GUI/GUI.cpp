/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "rlgl.h"
#include "raymath.h"  
#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

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
    window->loadModels();
    float updateInterval = 1.0f / _freq;
    float lastUpdateTime = GetTime();
    map->addResource(0, 0, Ressources::RessourceType::FOOD, 1);
    map->addResource(0, 0, Ressources::RessourceType::LINEMATE, 1);
    map->addResource(0, 0, Ressources::RessourceType::DERAUMERE, 1);
    map->addResource(0, 0, Ressources::RessourceType::SIBUR, 1);
    map->addResource(0, 0, Ressources::RessourceType::MENDIANE, 1);
    map->addResource(0, 0, Ressources::RessourceType::PHIRAS, 1);
    map->addResource(0, 0, Ressources::RessourceType::THYSTAME, 1);

    Shader shader = LoadShader("assets/lighting.vs", "assets/lighting.fs");
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    int ambientLoc = GetShaderLocation(shader, "ambient");
    float ambient[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    SetShaderValue(shader, ambientLoc, ambient, SHADER_UNIFORM_VEC4);
    std::vector<Model> _loadedModels = window->getLoadedModels();
    std::vector<Model> resourceModels = window->getResourceModels();
    for (int i = 0; i < _loadedModels.size(); i++) {
        for (int j = 0; j < _loadedModels[i].materialCount; j++) {
            _loadedModels[i].materials[j].shader = shader;
        }
    }
    for (int i = 0; i < resourceModels.size(); i++) {
        for (int j = 0; j < resourceModels[i].materialCount; j++) {
            resourceModels[i].materials[j].shader = shader;
        }
    }
    Light lights[MAX_LIGHTS] = { 0 };
    lights[0] = CreateLight(LIGHT_POINT, (Vector3){ 0, 1, 0 }, Vector3Zero(), WHITE, shader);

    
    while (!WindowShouldClose())
    {
        camera.update();
        float cameraPos[3] = { camera.getX(), camera.getY(), camera.getZ() };
        SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
        for (int i = 0; i < MAX_LIGHTS; i++) UpdateLightValues(shader, lights[i]);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        camera.BeginMode();
        // float currentTime = GetTime();
        // if (currentTime - lastUpdateTime >= updateInterval) {
        //     lastUpdateTime = currentTime;
        // }
        window->updateMap(map);
        window->DrawMap(map->getMapSizeX(), map->getMapSizeY());
        for (int i = 0; i < MAX_LIGHTS; i++)
        {
            if (lights[i].enabled) DrawSphereEx(lights[i].position, 0.2f, 8, 8, lights[i].color);
        }
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
