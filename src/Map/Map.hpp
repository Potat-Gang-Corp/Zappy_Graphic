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
    #include "Ressources.hpp"

using Coordinates = std::pair<int, int>;
using ResourceMap = std::map<Ressources::RessourceType, int>;

class Map {
    public:
        Map();
        ~Map();
        static Map *getInstance()
        {
            static Map instance;
            return &instance;
        }
        void addResource(int x, int y, Ressources::RessourceType resource, int quantity);
        void removeResource(int x, int y, Ressources::RessourceType resource, int quantity);
        ResourceMap &getResources(int x, int y) {
            return _map[{x, y}];
        }
        void printResources(int x, int y);
        void printMap();
        std::string resourceToString(Ressources::RessourceType ressource) {
            switch (ressource) {
                case Ressources::RessourceType::FOOD: return "Food";
                case Ressources::RessourceType::LINEMATE: return "Linemate";
                case Ressources::RessourceType::DERAUMERE: return "Deraumere";
                case Ressources::RessourceType::SIBUR: return "Sibur";
                case Ressources::RessourceType::MENDIANE: return "Mendiane";
                case Ressources::RessourceType::PHIRAS: return "Phiras";
                case Ressources::RessourceType::THYSTAME: return "Thystame";
                // Ajoutez d'autres cas pour chaque ressource
                default: return "Unknown";
            }
        }
        void setMapSize(int sizeX, int sizeY);
        int getMapSizeX() const { return _sizeX; }
        int getMapSizeY() const { return _sizeY; }

    private:
        int _sizeX, _sizeY;
        std::map<Coordinates, ResourceMap> _map;
};

#endif /* !MAP_HPP_ */
