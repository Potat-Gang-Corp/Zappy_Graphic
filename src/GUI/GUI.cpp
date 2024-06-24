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
    _port = "4243";
    _host = "127.0.0.1";
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
    const Rectangle form = { (float)_width / 2 - 250, (float)_height / 2 - 250, 500, 300 };
    const Rectangle port = { form.x + 10, form.y + 100, form.width - 20, 40 };
    const Rectangle host = { form.x + 10, form.y + 180, form.width - 20, 40 };
    const std::string footerText = "Press Enter to connect !";
    const std::string mainTitle = "Connect to the Server !";
    _camera->SetTarget((Vector3){ (float)Map::getInstance()->getMapSizeX() / 2 * 10, 0.0f, (float)Map::getInstance()->getMapSizeY() / 2 * 10});
    bool portActive = false;
    bool hostActive = false;

    while (!WindowShouldClose()) {
        if (Server::getInstance()->getConnectionStatus() == false) {
            BeginDrawing();
            ClearBackground(SKYBLUE);
            _camera->BeginMode();
            for (auto& model : _models) {
                model->drawModel();
            }
            _camera->EndMode();
            DrawRectangleRec(form, WHITE);
            DrawRectangleLines((int)form.x, (int)form.y, (int)form.width, (int)form.height, DARKGRAY);
            int titleWidth = MeasureText(mainTitle.c_str(), 30);
            DrawText(mainTitle.c_str(), form.x + form.width / 2 - titleWidth / 2, form.y + 20, 30, DARKGRAY);
            DrawText("Port :", (int)port.x, (int)port.y - 25, 20, DARKGRAY);
            DrawRectangleRec(port, Fade(LIGHTGRAY, 0.5f));
            if (CheckCollisionPointRec(GetMousePosition(), port)) {
                DrawRectangleLines((int)port.x, (int)port.y, (int)port.width, (int)port.height, RED);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    portActive = true;
                    hostActive = false;
                }
            } else {
                DrawRectangleLines((int)port.x, (int)port.y, (int)port.width, (int)port.height, DARKGRAY);
            }
            DrawText(_port.c_str(), (int)port.x + 5, (int)port.y + port.height / 2 - 10, 20, BLACK);
            if (portActive) {
                DrawText("_", (int)port.x + 10 + MeasureText(_port.c_str(), 20), (int)port.y + port.height / 2 - 10, 20, BLACK);
            }
            
            DrawText("Host :", (int)host.x, (int)host.y - 25, 20, DARKGRAY);
            DrawRectangleRec(host, Fade(LIGHTGRAY, 0.5f));
            if (CheckCollisionPointRec(GetMousePosition(), host)) {
                DrawRectangleLines((int)host.x, (int)host.y, (int)host.width, (int)host.height, RED);
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    hostActive = true;
                    portActive = false;
                }
            } else {
                DrawRectangleLines((int)host.x, (int)host.y, (int)host.width, (int)host.height, DARKGRAY);
            }
            DrawText(_host.c_str(), (int)host.x + 5, (int)host.y + host.height / 2 - 10, 20, BLACK);
            if (hostActive) {
                DrawText("_", (int)host.x + 10 + MeasureText(_host.c_str(), 20), (int)host.y + host.height / 2 - 10, 20, BLACK);
            }
            
            int footerWidth = MeasureText(footerText.c_str(), 20);
            DrawText(footerText.c_str(), form.x + form.width / 2 - footerWidth / 2, form.y + form.height - 60, 20, DARKGRAY);
            
            Color statusColor = _status ? GREEN : RED;
            const std::string statusText = _status ? "Connected" : "Disconnected";
            DrawCircle(form.x + 20, form.y + form.height - 20, 10, statusColor);
            DrawText(statusText.c_str(), form.x + 40, form.y + form.height - 28, 20, statusColor);
            
            int key = GetCharPressed();
            while (key > 0) {
                if (portActive && (key >= 32) && (key <= 125) && (_port.length() < 5)) {
                    _port += (char)key;
                }
                if (hostActive && (key >= 32) && (key <= 125) && (_host.length() < 15)) {
                    _host += (char)key;
                }
                key = GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE)) {
                if (portActive && !_port.empty()) _port.pop_back();
                if (hostActive && !_host.empty()) _host.pop_back();
            }
            EndDrawing();
            if (IsKeyPressed(KEY_ENTER))
                _status = true;
            else
                _status = false;
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
            DrawRectangle(35, 35, 200, 30, Fade(WHITE, 0.5f));
            DrawRectangleLines(35, 35, 200, 30, WHITE);
            DrawText("Press T to close.", 40, 40, 20, BLACK);
            DrawRectangle(1920 - 410, 10, 400, _cachedInfo.size() * 40, Fade(WHITE, 0.5f));
            DrawRectangleLines(1920 - 410, 10, 400, _cachedInfo.size() * 40, WHITE);
            
            for (const auto& text : _cachedInfo) {
                DrawText(text.c_str(), 1920 - 400, yPosition, 20, BLACK);
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
