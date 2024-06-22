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

void PlayerManager::AddPlayer(Player player)
{
    player.setPosition(player.getPosX(), player.getPosY(), player.getOrientation());
    int playerId = player.getNumber();
    _players[playerId].push_back(player);

    std::shared_ptr<PlayerModel> playerModel = std::make_shared<PlayerModel>("PlayerModel", "Player");
    if (playerModel) {
        switch (player.getOrientation()) {
            case Orientation::NORTH:
                playerModel->setRotation(180.0f);
                break;
            case Orientation::EAST:
                playerModel->setRotation(90.0f);
                break;
            case Orientation::SOUTH:
                playerModel->setRotation(0.0f);
                break;
            case Orientation::WEST:
                playerModel->setRotation(-90.0f);
                break;
        }
    } else {
        std::cout << "Failed to create player model\n";
    }

    _playerModels[playerId] = playerModel;
}

void PlayerManager::addSavePlayer(Player &player)
{ 
    player.setPosition(player.getPosX(), player.getPosY(), player.getOrientation());
    _savePlayers.push_back(player);
}

void PlayerManager::UpdateAnimations(float deltaTime)
{
    for (auto &playerModelPair : _playerModels) {
        playerModelPair.second->updateAnimation(deltaTime);
    }
}

void PlayerManager::DrawPlayers() {
    for (auto &player : _players) {
        int playerId = player.first;
        for (auto &playerInstance : player.second) {
            Vector3 playerPosition = playerInstance.getPosition();
            Vector3 savePos = playerPosition;
            playerPosition.x *= 10;
            playerPosition.z *= 10;
            _playerModels[playerId]->setPosition(playerPosition);

            Orientation orientation = playerInstance.getOrientation();
            switch (orientation) {
                case Orientation::NORTH:
                    _playerModels[playerId]->setRotation(180.0f);
                    break;
                case Orientation::EAST:
                    _playerModels[playerId]->setRotation(90.0f);
                    break;
                case Orientation::SOUTH:
                    _playerModels[playerId]->setRotation(0.0f);
                    break;
                case Orientation::WEST:
                    _playerModels[playerId]->setRotation(-90.0f);
                    break;
            }

            _playerModels[playerId]->drawModel();
            playerPosition = savePos;
        }
    }
}

void PlayerManager::ChangePlayerAnimation(int playerId, const std::string &animFilename)
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

