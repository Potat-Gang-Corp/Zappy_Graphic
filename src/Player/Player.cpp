/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(int number, int posX, int posY, std::string teamName, Orientation orientation, std::map<Resource::RessourceType, int> inventory, int lvl)
{
    _playerData._number = number;
    _playerData._posX = posX;
    _playerData._posY = posY;
    _playerData._level = lvl;
    _playerData._teamName = teamName;
    _playerData._orientation = orientation;
    _playerData._inventory = inventory;
}

Player::~Player() {}

const Vector3 Player::getPosition()
{
    return (Vector3){(float)_playerData._posX, 0.0f, (float)_playerData._posY};
}

const int &Player::getNumber() const
{
    return _playerData._number;
}

const int &Player::getPosX() const
{
    return _playerData._posX;
}

const int &Player::getPosY() const
{
    return _playerData._posY;
}

const int &Player::getLevel() const
{
    return _playerData._level;
}

const std::string &Player::getTeamName()
{
    return _playerData._teamName;
}

const Orientation &Player::getOrientation()
{
    return _playerData._orientation;
}

const PlayerData &Player::getPlayerData()
{
    return _playerData;
}

const std::map<Resource::RessourceType, int> &Player::getInventory()
{
    return _playerData._inventory;
}

void Player::setPosition(int x, int y, Orientation orientation)
{
    _playerData._posX = x;
    _playerData._posY = y;
    _playerData._orientation = orientation;
}

void Player::setLevel(int level)
{
    _playerData._level = level;
}

void Player::addInventory(Resource::RessourceType resource, int quantity)
{
    _playerData._inventory[resource] += quantity;
}

void Player::removeInventory(Resource::RessourceType resource, int quantity)
{
    _playerData._inventory[resource] -= quantity;
}
