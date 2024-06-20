/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** PlayerManager
*/

#include "PlayerManager.hpp"
#include "ModelsLoader.hpp"
#include <iostream>
#include <chrono>

PlayerManager::PlayerManager() {}

PlayerManager::~PlayerManager() {}

void PlayerManager::AddPlayer(const Player& player)
{
    int playerId = player.getNumber();
    _players[playerId].push_back(player);

    std::shared_ptr<PlayerModel> playerModel = std::make_shared<PlayerModel>("PlayerModel", "Player");

    _playerModels[playerId] = playerModel;
}

void PlayerManager::UpdateAnimations(float deltaTime)
{
    for (auto& playerModelPair : _playerModels) {
        playerModelPair.second->updateAnimation(deltaTime);
    }
}

void PlayerManager::DrawPlayers()
{
    for (auto& player : _players) {
        int playerId = player.first;
        for (auto& playerInstance : player.second) {
            Vector3 playerPosition = playerInstance.getPosition();
            _playerModels[playerId]->setPosition(playerPosition);
            _playerModels[playerId]->drawModel();
        }
    }
}

void PlayerManager::ChangePlayerAnimation(int playerId, const std::string& animFilename)
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

    _playerModels[playerId]->setAnimation(newAnim);
}

