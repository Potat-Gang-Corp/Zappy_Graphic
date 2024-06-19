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
    #include "Resource.hpp"
    #include <memory>

using Coordinates = std::pair<int, int>;
using ResourceMap = std::map<Resource::RessourceType, int>;

class Map {
    public:
        Map();
        ~Map();
        static std::shared_ptr<Map> getInstance() {
            static std::shared_ptr<Map> instance(new Map());
            return instance;
        }
        void addResource(int x, int y, Resource::RessourceType resource, int quantity);
        void removeResource(int x, int y, Resource::RessourceType resource, int quantity);
        ResourceMap &getResources(int x, int y) {
            return _map.at({x, y});
        }
        void printResources(int x, int y);
        void printMap();
        std::string resourceToString(Resource::RessourceType ressource);
        void setMapSize(int sizeX, int sizeY);
        int getMapSizeX() const { return _sizeX; }
        int getMapSizeY() const { return _sizeY; }
        void addEgg(int x, int y, int number);
        void removeEgg(int number);
        int &getEggX(int number) { return _eggs[number].first; }
        int &getEggY(int number) { return _eggs[number].second; }

    private:
        int _sizeX, _sizeY;
        std::map<Coordinates, ResourceMap> _map;
        std::map<int, Coordinates> _eggs;
};

typedef std::shared_ptr<Map> MapPtr;

#endif /* !MAP_HPP_ */
