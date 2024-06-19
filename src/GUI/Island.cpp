/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Island
*/

#include "Island.hpp"
#include "ModelsLoader.hpp"

Island::Island(int random)
{
    ModelsLoaderPtr modelsLoader = ModelsLoader::getInstance();
    if (random == 1) {
        _model = modelsLoader->getModel("Island_farm");
        _boundbox = GetModelBoundingBox(_model);
        _boundbox.max.y -= 10.0f;
    } else if (random == 2) {
        _model = modelsLoader->getModel("Island_tree");
        _boundbox = GetModelBoundingBox(_model);
        _boundbox.max.y -= 15.0f;
    } else {
        _model = modelsLoader->getModel("Island");
        _boundbox = GetModelBoundingBox(_model);
        _boundbox.max.y -= 1.0f;
    }
}

