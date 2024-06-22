/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** PlayerManager
*/

#pragma once

#ifndef PLAYERMANAGER_HPP_
    #define PLAYERMANAGER_HPP_

    #include "Player.hpp"
    #include "PlayerModel.hpp"
    #include <unordered_map>
    #include <vector>
    #include <memory>

class PlayerManager {
    public:
        PlayerManager();
        ~PlayerManager();
        static std::shared_ptr<PlayerManager> getInstance() {
            static std::shared_ptr<PlayerManager> instance(new PlayerManager());
            return instance;
        }
        void AddPlayer(Player player);
        void addSavePlayer(Player &player);
        std::vector<Player> &getPlayersSave() { return _savePlayers; }
        void UpdateAnimations(float deltaTime);
        void DrawPlayers();
        void ChangePlayerAnimation(int playerId, const std::string &animFilename);
        std::unordered_map<int, std::vector<Player>> &getPlayers() { return _players; }
        std::unordered_map<int, std::shared_ptr<PlayerModel>> &getPlayerModels() { return _playerModels; }

    private:
        std::vector<Player> _savePlayers;
        std::unordered_map<int, std::vector<Player>> _players;
        std::unordered_map<int, std::shared_ptr<PlayerModel>> _playerModels;
};

typedef std::shared_ptr<PlayerManager> PlayerManagerPtr;

#endif /* !PLAYERMANAGER_HPP_ */
