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
        {"Island_farm", LoadModel("assets/island_farm.glb")},
        {"Island_tree", LoadModel("assets/island_tree.glb")},
        {"Island", LoadModel("assets/island.glb")},
        {"FOOD", LoadModel("assets/potato.glb")},
        {"LINEMATE", LoadModel("assets/mine1.glb")},
        {"DERAUMERE", LoadModel("assets/mine2.glb")},
        {"SIBUR", LoadModel("assets/mine3.glb")},
        {"MENDIANE", LoadModel("assets/mine4.glb")},
        {"PHIRAS", LoadModel("assets/mine5.glb")},
        {"THYSTAME", LoadModel("assets/mine6.glb")},
        {"EGG", LoadModel("assets/Egg.glb")},

        // {"Player", LoadModel("assets/Player.obj")},
        // {"Egg", LoadModel("assets/Egg.obj")},
        // {"Stone", LoadModel("assets/Stone.obj")},
        // {"Food", LoadModel("assets/Food.obj")},
        // {"Linemate", LoadModel("assets/Linemate.obj")},
        // {"Deraumere", LoadModel("assets/Deraumere.obj")},
        // {"Sibur", LoadModel("assets/Sibur.obj")},
        // {"Mendiane", LoadModel("assets/Mendiane.obj")},
        // {"Phiras", LoadModel("assets/Phiras.obj")},
        // {"Thystame", LoadModel("assets/Thystame.obj")},
    };
}

Model ModelsLoader::getModel(std::string filename)
{
    for (auto it: _models) {
        if (it.first == filename)
            return it.second;
    }
    printf("Model not found\n");
    return _models["Island"];
}