/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "Light.hpp"

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
    LightWrapper lightWrapper;
    lightWrapper.SetShaderToModel(window->getLoadedModels());
    lightWrapper.SetShaderToModel(window->getResourceModels());
    lightWrapper.createlight((Vector3){ (float)(map->getMapSizeX() / 2 * 10), 30, (float)(map->getMapSizeY() / 2 * 10) }, Vector3Zero(), RED);

    // std::vector<Model> models = window->getLoadedModels();
    // std::vector<BoundingBox> BB;
    // for (auto &model : models) {
    //     BB.push_back(GetModelBoundingBox(model));
    // }

    float cycleDuration = 90.0f;
    float dayPhaseDuration = cycleDuration / 4.0f;

    while (!WindowShouldClose())
    {
        float currentTime = GetTime();
        float cycleTime = fmod(currentTime, cycleDuration);
        lightWrapper.UpdateLightDayColor(cycleTime, dayPhaseDuration);

        camera.update();
        lightWrapper.updateShaderValues(camera.getX(), camera.getY(), camera.getZ());
        BeginDrawing();
        ClearBackground(lightWrapper.getCurrentBackgroundColor());
        camera.BeginMode();

        window->updateMap(map);
        window->DrawMap(map->getMapSizeX(), map->getMapSizeY());

        lightWrapper.drawSphereOnLights();
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
