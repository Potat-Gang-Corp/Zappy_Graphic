/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "Light.hpp"
#include "Island.hpp"

GUI::GUI() {}

GUI::~GUI() {}

void GUI::AddPlayer(Player player)
{
    int playerId = player.getNumber();
    _players[playerId].push_back(player);
}

void GUI::LoadIsland()
{
    for (auto i = 0; i < Map::getInstance()->getMapSizeX(); i++) {
        for (auto j = 0; j < Map::getInstance()->getMapSizeY(); j++) {
            auto rdmNumber = std::rand() % 3 + 1;
            std::shared_ptr<IModels> monModel = std::make_shared<Island>(rdmNumber);
            monModel->setScale(0.2f);
            monModel->setPosition((Vector3){ (float)(i) * 10, 0.0f, (float)(j) * 10 });
            _models.push_back(monModel);
        }
    }
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

    this->LoadIsland();
    LightWrapper lightWrapper;
    lightWrapper.SetShaderToModel(_models);
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
        for (auto& model : _models) {
            model->drawModel();
        }

        // window->updateMap(map);
        // window->DrawMap(map->getMapSizeX(), map->getMapSizeY());

        lightWrapper.drawSphereOnLights();
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
