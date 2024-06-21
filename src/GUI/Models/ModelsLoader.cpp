/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** ModelsLoader.cpp
*/


#include "ModelsLoader.hpp"
#include "Window.hpp"

ModelsLoader::ModelsLoader()
{
    try {
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
            {"PlayerModel", LoadModel("assets/player.glb")}
        };

        _anims = {
            {"Player", std::shared_ptr<ModelAnimation>(LoadModelAnimations("assets/player.glb", &_animsCount))},
            {"Dying", std::shared_ptr<ModelAnimation>(LoadModelAnimations("assets/animation/dying.glb", &_animsCount))},
            {"Dropping", std::shared_ptr<ModelAnimation>(LoadModelAnimations("assets/animation/dropping.glb", &_animsCount))},
            {"LevelUp", std::shared_ptr<ModelAnimation>(LoadModelAnimations("assets/animation/level_up.glb", &_animsCount))}
        };
    } catch (const std::exception &e) {
        std::cerr << "Error in ModelsLoader: " << e.what() << std::endl;
        throw;
    }
}

Model LoadModelSafely(const char* fileName) {
    std::cout << "Attempting to load model: " << fileName << "\n";
    Model model = LoadModel(fileName);
    if (model.meshCount == 0) {
        std::cout << "Failed to load model: " << fileName << "\n";
    } else {
        std::cout << "Model " << fileName << " loaded successfully with " << model.meshCount << " meshes\n";
    }
    return model;
}

Model ModelsLoader::getModel(std::string filename)
{
    printf("Getting model %s\n", filename.c_str());
    for (auto it: _models) {
        if (it.first == filename)
            return it.second;
    }
    printf("Model not found\n");
    return _models["Island"];
}

std::shared_ptr<ModelAnimation> ModelsLoader::getAnim(std::string filename)
{
    for (auto it: _anims) {
        if (it.first == filename)
            return it.second;
    }
    printf("Model not found\n");
    return _anims["Player"];
}