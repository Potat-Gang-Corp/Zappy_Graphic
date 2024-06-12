/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Player
*/

#pragma once

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

#include <iostream>
#include "PlayerData.hpp"
#include <map>
#include "Ressources.hpp"

class Player {
    public:
        Player(int number, int posX, int posY, std::string teamName, Orientation orientation, std::map<Ressources::RessourceType, int> inventory, int level = 1);
        ~Player();
        const int &getNumber() const;
        const int &getPosX() const;
        const int &getPosY() const;
        const int &getLevel() const;
        void setPosition(int x, int y, Orientation orientation);
        void setLevel(int level);
        const std::string &getTeamName();
        const Orientation &getOrientation();
        const PlayerData &getPlayerData();
        const std::map<Ressources::RessourceType, int> &getInventory();
        void addInventory(Ressources::RessourceType resource, int quantity);
        void removeInventory(Ressources::RessourceType resource, int quantity);

    private:
        PlayerData _playerData;
};

#endif /* !PLAYER_HPP_ */
