/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** GameEngine
*/

#include "GameEngine.hpp"
#include <limits>
#include <algorithm>

GameEngine::GameEngine() : _isRunning(false) {
    _camera = CameraWrapper::getInstance();
}

void GameEngine::setMapSize(float sizeX, float sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
}

void GameEngine::loadTiles()
{
    float x;
    float y;
    _sizeX = x;
    _sizeY = y;
    for (x = 0; x < _sizeX; ++x) {
        for (y = 0; y < _sizeY; ++y) {
            Vector3 position = {x * 10, 0.0f, y * 10};
            _tiles.push_back(std::make_shared<Tile>(position, _tileModel, _resourceModels));
            _renderables.push_back(_tiles.back());
            _clickables.push_back(_tiles.back());
        }
    }
}

void GameEngine::loadModels()
{
    _tileModel = LoadModel("assets/island_farm.glb");
    if (!_tileModel.meshCount) {
        std::cerr << "Failed to load model: assets/island_farm.glb" << std::endl;
        throw std::runtime_error("Failed to load model");
    }

    _resourceModels.push_back(LoadModel("assets/potato.glb"));
    _resourceModels.push_back(LoadModel("assets/mine1.glb"));
    _resourceModels.push_back(LoadModel("assets/mine2.glb"));
    _resourceModels.push_back(LoadModel("assets/mine3.glb"));
    _resourceModels.push_back(LoadModel("assets/mine4.glb"));
    _resourceModels.push_back(LoadModel("assets/mine5.glb"));
    _resourceModels.push_back(LoadModel("assets/mine6.glb"));
    _resourceModels.push_back(LoadModel("assets/Egg.glb"));
}

GameEngine::~GameEngine() {
}

void GameEngine::Initialize() {
    InitWindow(1920, 1080, "3D Game with Raylib");
    SetTargetFPS(60);
    _isRunning = true;

    this->loadModels();
    this->loadTiles();

    const float lightX = (float)(10 / 2 * 10);
    const float lightZ = (float)(10 / 2 * 10);
    const Vector3 lightPosition = { lightX, 60, lightZ };

    _lightWrapper = LightWrapper::getInstance();
    _lightWrapper->SetShaderToModel(_renderables);
    // _lightWrapper->SetShaderToModel(_resource);
    _lightWrapper->createlight(lightPosition, Vector3Zero(), YELLOW);
    
    AddPlayer(1, 0, 0, 1, "Team 1");
}

void GameEngine::Run()
{
    while (_isRunning && !WindowShouldClose()) {

        float deltaTime = GetFrameTime();

        Update(deltaTime);
        Render();
        DrawFPS(10, 10);
    }

    CloseWindow();
}

void GameEngine::Shutdown() {
}

void GameEngine::Update(float deltaTime)
{
    _camera->handleInput(deltaTime);
    _camera->update();

    for (auto& updatable : _updatables) {
        updatable->Update(deltaTime);
    }

    Vector3 rayOrigin = GetMouseRay(GetMousePosition(), _camera->getCamera()).position;
    Vector3 rayDirection = GetMouseRay(GetMousePosition(), _camera->getCamera()).direction;
    float closestDistance = std::numeric_limits<float>::max();
    std::shared_ptr<IClickable> closestElement = nullptr;

    Ray ray = {rayOrigin, rayDirection};
    for (auto& clickable : _clickables) {
        RayCollision collision = GetRayCollisionBox(ray, clickable->getBoundingBox());
        if (collision.hit && collision.distance < closestDistance) {
            closestDistance = collision.distance;
            closestElement = clickable;
        } else {
            clickable->setHover(false);
        }
    }

    if (closestElement) {
        closestElement->setHover(true);
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            closestElement->OnClick();
        }
    }
}

void GameEngine::Render()
{
    BeginDrawing();
    ClearBackground(SKYBLUE);
    BeginMode3D(_camera->getCamera());

    for (auto &renderable : _renderables)
        renderable->Render();

    EndMode3D();
    EndDrawing();
}

void GameEngine::UpdateTileResources(int x, int y, const std::vector<int>& resources)
{
    int index = x * 10 + y;
    if (index >= 0 && index < _tiles.size()) {
        _tiles[index]->setResources(resources);
    }
}

void GameEngine::AddPlayer(int id, int x, int y, int orientation, const std::string& teamName, int level)
{
    Vector3 position = {(float)x * 10.0f, 0.0f, (float)y * 10.0f};
    auto player = std::make_shared<Player>(id, position, orientation, teamName, level);
    _players.push_back(player);
    _renderables.push_back(player);
    _clickables.push_back(player);
}

void GameEngine::UpdatePlayerPosition(int id, int x, int y, int orientation)
{
    for (auto& player : _players) {
        if (player->getId() == id) {
            Vector3 position = {(float)x * 10.0f, 0.0f, (float)y * 10.0f};
            player->setPosition(position);
            player->setOrientation(orientation);
            break;
        }
    }
}

void GameEngine::removeResourceTail(int x, int y, int resourceIndex, int amount)
{
    int index = x * 10 + y;
    if (index >= 0 && index < _tiles.size()) {
        _tiles[index]->removeResource(resourceIndex, amount);
    }
}

void GameEngine::addResourceTail(int x, int y, int resourceIndex, int amount)
{
    int index = x * 10 + y;
    if (index >= 0 && index < _tiles.size()) {
        _tiles[index]->addResource(resourceIndex, amount);
    }
}