/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"
#include "Island.hpp"
#include "Server.hpp"
#include "Resource.hpp"
#include "ConnectionUI.hpp"
#include "RectangleElement.hpp"

GUI::GUI()
{
    _playerManager = PlayerManager::getInstance();
    _window = Window::getInstance();
    _window->setLogInfo("LOG_INFO");

    Map::getInstance()->setMapSize(10, 10);

    _camera = CameraWrapper::getInstance();
}

GUI::~GUI() {}

void GUI::LoadIsland()
{
    std::srand(std::time(nullptr));
    for (auto i = 0; i < Map::getInstance()->getMapSizeX(); i++) {
        for (auto j = 0; j < Map::getInstance()->getMapSizeY(); j++) {
            auto rdmNumber = std::rand() % 3 + 1;
            std::shared_ptr<IModels> monModel = std::make_shared<Island>(rdmNumber, i ,j);
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

void GUI::loadPlayers()
{
    auto players = PlayerManager::getInstance()->getPlayersSave();
    for (auto& player : players) {
        _playerManager->AddPlayer(player);
    }
    _playerManager->AddPlayer(Player(1, 0, 0, "team", NORTH, {}, 1));
    // _playerManager->AddPlayer(Player(2, 0, 0, "team", NORTH, {}, 1));
    Map::getInstance()->addResource(0, 0, Resource::RessourceType::EGG, 10);
}

void GUI::handleMouseInteraction()
{
    Ray ray = GetMouseRay(GetMousePosition(), _camera->getCamera());
    float closestDistance = std::numeric_limits<float>::max();
    std::shared_ptr<IModels> closestModel = nullptr;
    auto players = _playerManager->getPlayers();

    for (auto& model : _models) {
        if (GetRayCollisionBox(ray, model->getBoundingBox()).hit) {
            float distance = Vector3Distance(ray.position, model->getPosition());
            if (distance < closestDistance) {
                closestDistance = distance;
                closestModel = model;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    model->onClick();
                    _TextDisplay = "";
                    _selectedModel = model;
                    _displayInfo = true;
                    _cachedInfo.clear();
                    _TextDisplay = "Island: X: " + std::to_string(_selectedModel->GetIslandX()) + " Y: " + std::to_string(_selectedModel->GetIslandY());
                    _cachedInfo.push_back(_TextDisplay);
                    for (auto ressource : Map::getInstance()->getResources(_selectedModel->GetIslandX(), _selectedModel->GetIslandY())) {
                        std::string test = Map::getInstance()->resourceToString(ressource.first);
                        _TextDisplay = test + ": " + std::to_string(ressource.second) + "";
                        _cachedInfo.push_back(_TextDisplay);
                    }
                    std::vector<int> ids;
                    auto model_player = _playerManager->getPlayerModels();
                    for (auto& playerModel : model_player) {
                        if (playerModel.second->getPosition().x == _selectedModel->GetIslandX() && playerModel.second->getPosition().z == _selectedModel->GetIslandY()) {
                            ids.push_back(playerModel.first);
                        }
                    }
                    if (!ids.empty()) {
                        _TextDisplay = "Player: ";
                        for (auto &id : ids) {
                            _TextDisplay += "#" + std::to_string(id) + " ";
                        }
                        _cachedInfo.push_back(_TextDisplay);
                    }
                    closestDistance = distance;
                }
            }
        }
    }

    for (auto& player : players) {
        int playerId = player.first;
        for (auto& playerInstance : player.second) {
            auto model = _playerManager->getPlayerModels()[playerId];
            if (GetRayCollisionBox(ray, model->getBoundingBox()).hit) {
                float distance = Vector3Distance(ray.position, model->getPosition());
                if (distance < closestDistance) {
                    closestDistance = distance;
                    closestModel = model;
                    model->setHover(true);
                }
            } else {
                model->setHover(false);
            }
        }
    }

    for (auto& model : _models) {
        if (model == closestModel) {
            model->onHover();
        } else {
            model->onHoverEnd();
        }
    }

    for (auto& player : players) {
        for (auto& playerInstance : player.second) {
            auto model = _playerManager->getPlayerModels()[player.first];
            if (model == closestModel) {
                model->onHover();
            } else {
                model->onHoverEnd();
            }
        }
    }
}

void GUI::load()
{
    _height = 1080;
    _width = 1920;
    Window::getInstance()->initWindow(_width, _height, "Potat Zappy", 144);
    this->loadPlayers();
    this->LoadIsland();
    this->loadResources();

    const float lightX = (float)(Map::getInstance()->getMapSizeX() / 2 * 10);
    const float lightZ = (float)(Map::getInstance()->getMapSizeY() / 2 * 10);
    const Vector3 lightPosition = { lightX, 30, lightZ };

    _lightWrapper = LightWrapper::getInstance();
    _lightWrapper->SetShaderToModel(_models);
    _lightWrapper->SetShaderToModel(_resource);
    _lightWrapper->createlight(lightPosition, Vector3Zero(), RED);
}

void GUI::run()
{
    this->load();

    const float cycleDuration = 180.0f;
    const float dayPhaseDuration = cycleDuration / 4.0f;
    _camera->SetTarget((Vector3){ (float)Map::getInstance()->getMapSizeX() / 2 * 10, 0.0f, (float)Map::getInstance()->getMapSizeY() / 2 * 10});

    ConnectionUI connectionUI(_width, _height);

    while (!WindowShouldClose()) {
        if (Server::getInstance()->getConnectionStatus() == false) {
            connectionUI.draw();
            _host = connectionUI.getHost();
            _port = connectionUI.getPort();
            _status = connectionUI.getStatus();
            continue;
        }

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
            auto island = dynamic_cast<Island*>(model.get());
            if (island->getIsHovered()) {
                island->updateRotation(deltaTime);
            }
        }
        _playerManager->DrawPlayers();
        this->UpdateMapContent();
        _lightWrapper->drawSphereOnLights();
        _camera->EndMode();
        int yPosition = 20;
        if (_displayInfo && _selectedModel != nullptr) {
            RectangleElement rectClose({ 35, 35, 200, 30 }, Fade(WHITE, 0.5f));
            rectClose.draw();
            rectClose.drawOutline(WHITE);

            TextElement textClose("Press T to close.", { 40, 40 }, 20, BLACK);
            textClose.draw();

            RectangleElement rectInfo({ 1920 - 410, 10, 400, (float)(_cachedInfo.size() * 40) }, Fade(WHITE, 0.5f));
            rectInfo.draw();
            rectInfo.drawOutline(WHITE);

            int yPosition = 20;
            for (const auto& text : _cachedInfo) {
                TextElement cachedText(text, { 1920 - 400, (float)yPosition }, 20, BLACK);
                cachedText.draw();
                yPosition += 40;
            }
        }
        if (IsKeyPressed(KEY_T)) {
            _displayInfo = false;
            _selectedModel = nullptr;
        }
        _window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow();
    exit(0);
}
