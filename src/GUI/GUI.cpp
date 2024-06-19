/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "Light.hpp"
#include "Island.hpp"
#include "Resource.hpp"

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

void GUI::loadResources()
{
    auto ressourceTypes = Resource::getInstance()->allRessourceTypes();
    for (const auto& resource : ressourceTypes) {
        std::shared_ptr<IModels> resourceModel = std::make_shared<Resource>(resource);
        resourceModel->setScale(0.08f);
        _resource.push_back(resourceModel);
    }
}

void GUI::UpdateMapContent()
{
    MapPtr map = Map::getInstance();
    for (int x = 0; x < map->getMapSizeX(); x++) {
        for (int y = 0; y < map->getMapSizeY(); y++) {
            Vector3 basePosition = {(float)(x * 10 - 2), 0.07f, (float)(y * 10 - 2.2)};
            auto resources = map->getResources(x, y);

            int modelIndex = 0;
            for (const auto& resource : resources) {
                if (resource.second > 0) {
                    Vector3 resourcePosition = basePosition;
                    resourcePosition.x += (modelIndex % 3) * 1.0f;
                    resourcePosition.z += (modelIndex / 3) * 1.0f;
                    int index = static_cast<int>(resource.first);
                    _resource[index]->setPosition(resourcePosition);
                    _resource[index]->drawModel();
                    modelIndex++;
                }
            }
        }
    }
}

void GUI::run()
{
    WindowPtr window = Window::getInstance();
    window->setLogInfo("LOG_INFO");
    window->initWindow(1920, 1080, "raylib [core] example - 3d camera free", 144);
    CameraWrapper camera;

    this->LoadIsland();
    this->loadResources();
    LightWrapper lightWrapper;
    lightWrapper.SetShaderToModel(_models);
    lightWrapper.createlight((Vector3){ (float)(Map::getInstance()->getMapSizeX() / 2 * 10), 30, (float)(Map::getInstance()->getMapSizeY() / 2 * 10) }, Vector3Zero(), RED);

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
        this->UpdateMapContent();
        lightWrapper.drawSphereOnLights();
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
