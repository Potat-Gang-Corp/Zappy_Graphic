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
        int getNumber() const;
        int getPosX() const;
        int getPosY() const;
        int getLevel() const;
        void setPosition(int x, int y, Orientation orientation);
        std::string getTeamName();
        Orientation getOrientation();
        PlayerData getPlayerData();
        std::map<Ressources::RessourceType, int> getInventory();

    private:
        PlayerData _playerData;
};

#endif /* !PLAYER_HPP_ */
