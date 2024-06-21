/*
** EPITECH PROJECT, 2024
** 
** File description:
** Map
*/

#include "Map.hpp"

Map::Map() {}

Map::~Map() {}

void Map::setMapSize(int sizeX, int sizeY)
{
    _sizeX = sizeX;
    _sizeY = sizeY;
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            _map[{x, y}] = {};
        }
    }
}

void Map::addResource(int x, int y, Resource::RessourceType ressource, int quantity)
{
    if ((int)ressource == 7) {
        if (_map[{x, y}][ressource] > 0) {
            _map[{x, y}][ressource] += quantity;
            return;
        }
    }
    _map[{x, y}][ressource] = quantity;
}

void Map::removeResource(int x, int y, Resource::RessourceType ressource, int quantity)
{
    _map[{x, y}][ressource] -= quantity;
    if (_map[{x, y}][ressource] <= 0) {
        _map[{x, y}].erase(ressource);
    }
}

void Map::addEgg(int x, int y, int number)
{
    _eggs[number] = {x, y};
}

void Map::removeEgg(int number)
{
    _eggs.erase(number);
}

void Map::printResources(int x, int y)
{
    ResourceMap resources = getResources(x, y);
    std::cout << "Resources at (" << x << ", " << y << "):" << std::endl;
    for (const auto &[resource, quantity] : resources) {
        std::cout << "  Resource " << resourceToString(resource) << ": " << quantity << std::endl;
    }
}

void Map::printMap()
{
    for (int y = 0; y < _sizeY; y++) {
        for (int x = 0; x < _sizeX; x++) {
            printResources(x, y);
        }
    }
}

std::string Map::resourceToString(Resource::RessourceType ressource)
{
    switch (ressource) {
        case Resource::RessourceType::FOOD: return "FOOD";
        case Resource::RessourceType::LINEMATE: return "LINEMATE";
        case Resource::RessourceType::DERAUMERE: return "DERAUMERE";
        case Resource::RessourceType::SIBUR: return "SIBUR";
        case Resource::RessourceType::MENDIANE: return "MENDIANE";
        case Resource::RessourceType::PHIRAS: return "PHIRAS";
        case Resource::RessourceType::THYSTAME: return "THYSTAME";
        case Resource::RessourceType::EGG: return "EGG";
        // Ajoutez d'autres cas pour chaque ressource
        default: return "Unknown";
    }
}
