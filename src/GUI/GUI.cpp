/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "Island.hpp"
#include "Resource.hpp"

GUI::GUI()
{
    _playerManager = PlayerManager::getInstance();
    _window = Window::getInstance();
    _window->setLogInfo("LOG_INFO");

    Map::getInstance()->setMapSize(10, 10);

    _camera = std::make_unique<CameraWrapper>();
}

GUI::~GUI() {}

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
        resourceModel->setScale(0.1f);
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

bool GUI::CheckCollisionRayBox(Ray ray, BoundingBox box)
{
    float tmin = (box.min.x - ray.position.x) / ray.direction.x;
    float tmax = (box.max.x - ray.position.x) / ray.direction.x;
    
    if (tmin > tmax) {
        float temp = tmin;
        tmin = tmax;
        tmax = temp;
    }

    float tymin = (box.min.y - ray.position.y) / ray.direction.y;
    float tymax = (box.max.y - ray.position.y) / ray.direction.y;

    if (tymin > tymax) {
        float temp = tymin;
        tymin = tymax;
        tymax = temp;
    }

    if ((tmin > tymax) || (tymin > tmax)) return false;

    if (tymin > tmin) tmin = tymin;
    if (tymax < tmax) tmax = tymax;

    float tzmin = (box.min.z - ray.position.z) / ray.direction.z;
    float tzmax = (box.max.z - ray.position.z) / ray.direction.z;

    if (tzmin > tzmax) {
        float temp = tzmin;
        tzmin = tzmax;
        tzmax = temp;
    }

    if ((tmin > tzmax) || (tzmin > tmax)) return false;

    if (tzmin > tmin) tmin = tzmin;
    if (tzmax < tmax) tmax = tzmax;

    return true;
}

void GUI::loadPlayers()
{
    auto players = PlayerManager::getInstance()->getPlayersSave();
    for (auto& player : players) {
        _playerManager->AddPlayer(player);
    }
    _playerManager->AddPlayer(Player(1, 0, 0, "team", NORTH, {}, 1));
}

void GUI::handleMouseInteraction()
{
    Ray ray = GetMouseRay(GetMousePosition(), _camera->getCamera());
    float closestDistance = std::numeric_limits<float>::max();
    std::shared_ptr<IModels> closestModel = nullptr;

    for (auto& model : _models) {
        if (CheckCollisionRayBox(ray, model->getBoundingBox())) {
            float distance = Vector3Distance(ray.position, model->getPosition());
            if (distance < closestDistance) {
                closestDistance = distance;
                closestModel = model;
            }
        }
    }

    // for (auto& resource : _resource) {
    //     if (CheckCollisionRayBox(ray, resource->getBoundingBox())) {
    //         float distance = Vector3Distance(ray.position, resource->getPosition());
    //         if (distance < closestDistance) {
    //             closestDistance = distance;
    //             closestModel = resource;
    //         }
    //     }
    // }

    auto players = _playerManager->getPlayers();
    for (auto& player : players) {
        int playerId = player.first;
        for (auto& playerInstance : player.second) {
            auto model = _playerManager->getPlayerModels()[playerId];
            if (CheckCollisionRayBox(ray, model->getBoundingBox())) {
                float distance = Vector3Distance(ray.position, model->getPosition());
                if (distance < closestDistance) {
                    closestDistance = distance;
                    closestModel = model;
                }
            }
        }
    }

    if (closestModel != nullptr) {
        closestModel->onHover();
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            closestModel->onClick();
        }
    }
}

void GUI::load()
{
    _window->initWindow(1920, 1080, "Potat Zappy", 144);
    this->loadPlayers();
    this->LoadIsland();
    this->loadResources();

    const float lightX = (float)(Map::getInstance()->getMapSizeX() / 2 * 10);
    const float lightZ = (float)(Map::getInstance()->getMapSizeY() / 2 * 10);
    const Vector3 lightPosition = { lightX, 30, lightZ };

    _lightWrapper = std::make_unique<LightWrapper>();
    _lightWrapper->SetShaderToModel(_models);
    _lightWrapper->SetShaderToModel(_resource);
    _lightWrapper->createlight(lightPosition, Vector3Zero(), RED);
}

void GUI::run()
{
    this->load();

    const float cycleDuration = 90.0f;
    const float dayPhaseDuration = cycleDuration / 4.0f;

    while (!WindowShouldClose()) {
        float currentTime = GetTime();
        float cycleTime = fmod(currentTime, cycleDuration);
        _lightWrapper->UpdateLightDayColor(cycleTime, dayPhaseDuration);

        _camera->update();

        float deltaTime = GetFrameTime();
        _playerManager->UpdateAnimations(deltaTime);

        _lightWrapper->updateShaderValues(_camera->getX(), _camera->getY(), _camera->getZ());
        BeginDrawing();
        ClearBackground(_lightWrapper->getCurrentBackgroundColor());
        _camera->BeginMode();
        handleMouseInteraction();
        for (auto& model : _models) {
            model->drawModel();
        }
        _playerManager->DrawPlayers();
        this->UpdateMapContent();
        _lightWrapper->drawSphereOnLights();
        _camera->EndMode();
        _window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow();
    exit(0);
}
