/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** ModelsLoader.cpp
*/

#include "ModelsLoader.hpp"
#include "Window.hpp"

Model LoadModelSafely(const char* fileName) {
    std::cout << "Attempting to load model: " << fileName << "\n";
    Model model = LoadModel(fileName);
    if (model.meshCount == 0) {
        std::cerr << "Failed to load model: " << fileName << "\n";
        throw std::runtime_error("Failed to load model: " + std::string(fileName));
    } else {
        std::cout << "Model " << fileName << " loaded successfully with " << model.meshCount << " meshes\n";
    }
    return model;
}

std::shared_ptr<ModelAnimation> LoadModelAnimationsSafely(const char* fileName) {
    std::cout << "Attempting to load animations: " << fileName << "\n";
    int animsCount = 0;
    ModelAnimation* anims = LoadModelAnimations(fileName, &animsCount);
    if (animsCount == 0) {
        std::cerr << "Failed to load animations: " << fileName << "\n";
        throw std::runtime_error("Failed to load animations: " + std::string(fileName));
    } else {
        std::cout << "Animations " << fileName << " loaded successfully with " << animsCount << " animations\n";
    }
    return std::shared_ptr<ModelAnimation>(anims);
}

ModelsLoader::ModelsLoader()
{
    try {
        _models = {
            {"Island_farm", LoadModelSafely("assets/island_farm.glb")},
            {"Island_tree", LoadModelSafely("assets/island_tree.glb")},
            {"Island", LoadModelSafely("assets/island.glb")},
            {"FOOD", LoadModelSafely("assets/potato.glb")},
            {"LINEMATE", LoadModelSafely("assets/mine1.glb")},
            {"DERAUMERE", LoadModelSafely("assets/mine2.glb")},
            {"SIBUR", LoadModelSafely("assets/mine3.glb")},
            {"MENDIANE", LoadModelSafely("assets/mine4.glb")},
            {"PHIRAS", LoadModelSafely("assets/mine5.glb")},
            {"THYSTAME", LoadModelSafely("assets/mine6.glb")},
            {"EGG", LoadModelSafely("assets/Egg.glb")},
            {"PlayerModel", LoadModelSafely("assets/player.glb")}
        };

        _anims = {
            {"Player", LoadModelAnimationsSafely("assets/player.glb")},
            {"Dying", LoadModelAnimationsSafely("assets/animation/dying.glb")},
            {"Dropping", LoadModelAnimationsSafely("assets/animation/dropping.glb")},
            {"LevelUp", LoadModelAnimationsSafely("assets/animation/level_up.glb")},
            {"Hands", LoadModelAnimationsSafely("assets/animation/hands.glb")}
        };
    } catch (const std::exception &e) {
        std::cerr << "Error in ModelsLoader: " << e.what() << std::endl;
        throw;
    }
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
    printf("Getting animation %s\n", filename.c_str());
    for (auto it: _anims) {
        if (it.first == filename)
            return it.second;
    }
    printf("Animation not found\n");
    return _anims["Player"];
}
