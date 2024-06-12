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
}

void Map::addResource(int x, int y, Ressources::RessourceType ressource, int quantity)
{
    _map[{x, y}][ressource] += quantity;
}

void Map::removeResource(int x, int y, Ressources::RessourceType ressource, int quantity)
{
    _map[{x, y}][ressource] -= quantity;
    if (_map[{x, y}][ressource] <= 0) {
        _map[{x, y}].erase(ressource);
    }
}

void Map::printResources(int x, int y)
{
    ResourceMap resources = getResources(x, y);
    std::cout << "Resources at (" << x << ", " << y << "):" << std::endl;
    for (const auto& [resource, quantity] : resources) {
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
