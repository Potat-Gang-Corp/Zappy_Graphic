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
    
    Model model = ModelsLoader::getInstance()->getModel("PlayerModel");
    std::shared_ptr<ModelAnimation> anim = ModelsLoader::getInstance()->getAnim("Player");

    _playerModels[playerId] = std::make_pair(model, anim);

    _playerAnimFrameCounters[playerId] = 0;
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

void GUI::UpdateAnimations()
{
    for (auto& playerModel : _playerModels) {
        int playerId = playerModel.first;
        Model model = playerModel.second.first;
        std::shared_ptr<ModelAnimation> anim = playerModel.second.second;
        int& animFrameCounter = _playerAnimFrameCounters[playerId];
        UpdateModelAnimation(model, anim.get()[0], animFrameCounter);
        if (animFrameCounter >= anim.get()[0].frameCount) {
            animFrameCounter = 0;
            if (anim != _defaultPlayerAnimations[playerId]) {
                resetPlayerAnimation(playerId);
            }
        }
        animFrameCounter++;
    }
}

void GUI::drawPlayers()
{
    for (auto& player : _players) {
        int playerId = player.first;
        for (auto& playerInstance : player.second) {
            Vector3 playerPosition = playerInstance.getPosition();
            Model model = _playerModels[playerId].first;
            DrawModel(model, playerPosition, 0.09f, WHITE);
        }
    }
}

void GUI::resetPlayerAnimation(int playerId) {
    // Vérifiez si le joueur existe
    if (_playerModels.find(playerId) == _playerModels.end()) {
        std::cerr << "Player ID " << playerId << " not found." << std::endl;
        return;
    }

    _playerModels[playerId].second = _defaultPlayerAnimations[playerId];

    _playerAnimFrameCounters[playerId] = 0;
}

void GUI::changePlayerAnimation(int playerId, const std::string& animFilename)
{
    if (_playerModels.find(playerId) == _playerModels.end()) {
        std::cerr << "Player ID " << playerId << " not found." << std::endl;
        return;
    }

    std::shared_ptr<ModelAnimation> newAnim = ModelsLoader::getInstance()->getAnim(animFilename);
    if (!newAnim) {
        std::cerr << "Animation " << animFilename << " not found." << std::endl;
        return;
    }

    if (_defaultPlayerAnimations.find(playerId) == _defaultPlayerAnimations.end()) {
        _defaultPlayerAnimations[playerId] = _playerModels[playerId].second;
    }

    _playerModels[playerId].second = newAnim;

    _playerAnimFrameCounters[playerId] = 0;
}

void GUI::run()
{
    Map::getInstance()->setMapSize(10, 10);
    WindowPtr window = Window::getInstance();
    window->setLogInfo("LOG_INFO");
    window->initWindow(1920, 1080, "Potat Zappy", 144);
    CameraWrapper camera;

    AddPlayer(Player(1, 0, 0, "Team1", Orientation::NORTH, { {Resource::RessourceType::FOOD, 10}, {Resource::RessourceType::LINEMATE, 0}, {Resource::RessourceType::DERAUMERE, 0}, {Resource::RessourceType::SIBUR, 0}, {Resource::RessourceType::MENDIANE, 0}, {Resource::RessourceType::PHIRAS, 0}, {Resource::RessourceType::THYSTAME, 0} }));
    changePlayerAnimation(1, "Dying");

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

        this->UpdateAnimations();

        lightWrapper.updateShaderValues(camera.getX(), camera.getY(), camera.getZ());
        BeginDrawing();
        ClearBackground(lightWrapper.getCurrentBackgroundColor());
        camera.BeginMode();
        for (auto& model : _models) {
            model->drawModel();
        }
        this->drawPlayers();
        this->UpdateMapContent();
        lightWrapper.drawSphereOnLights();
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}
