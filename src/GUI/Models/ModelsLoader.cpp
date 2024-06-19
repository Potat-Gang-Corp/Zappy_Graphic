/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** ModelsLoader.cpp
*/


#include "ModelsLoader.hpp"

ModelsLoader::ModelsLoader()
{
    _models = {
        {"Island", LoadModel("assets/Island.obj")},
        {"Player", LoadModel("assets/Player.obj")},
        {"Egg", LoadModel("assets/Egg.obj")},
        {"Stone", LoadModel("assets/Stone.obj")},
        {"Food", LoadModel("assets/Food.obj")},
        {"Linemate", LoadModel("assets/Linemate.obj")},
        {"Deraumere", LoadModel("assets/Deraumere.obj")},
        {"Sibur", LoadModel("assets/Sibur.obj")},
        {"Mendiane", LoadModel("assets/Mendiane.obj")},
        {"Phiras", LoadModel("assets/Phiras.obj")},
        {"Thystame", LoadModel("assets/Thystame.obj")},
    };
}

Model ModelsLoader::getModel(std::string filename)
{
    for (auto it: _models) {
        if (it.first == filename)
            return it.second;
    }
}