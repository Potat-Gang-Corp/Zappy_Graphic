/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Map
*/

#pragma once

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include <iostream>
    #include <map>

enum class Resource {
    Food,
    Linemate,
    Deraumere,
    Sibur,
    Mendiane,
    Phiras,
    Thystame,
    // Ajoutez d'autres ressources si nécessaire
};

using Coordinates = std::pair<int, int>;
using ResourceMap = std::map<Resource, int>;

class Map {
    public:
        Map();
        ~Map();
        static Map *getInstance()
        {
            static Map instance;
            return &instance;
        }
        void addResource(int x, int y, Resource resource, int quantity);
        void removeResource(int x, int y, Resource resource, int quantity);
        ResourceMap getResources(int x, int y) {
            return _map[{x, y}];
        }
        void printResources(int x, int y);
        void printMap();
        std::string resourceToString(Resource resource) {
            switch (resource) {
                case Resource::Food: return "Food";
                case Resource::Linemate: return "Linemate";
                case Resource::Deraumere: return "Deraumere";
                case Resource::Sibur: return "Sibur";
                case Resource::Mendiane: return "Mendiane";
                case Resource::Phiras: return "Phiras";
                case Resource::Thystame: return "Thystame";
                // Ajoutez d'autres cas pour chaque ressource
                default: return "Unknown";
            }
        }
        void setMapSize(int sizeX, int sizeY);

    private:
        int _sizeX, _sizeY;
        std::map<Coordinates, ResourceMap> _map;
};

#endif /* !MAP_HPP_ */
