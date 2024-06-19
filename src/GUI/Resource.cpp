/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Resource
*/

#include "Resource.hpp"
#include "Map.hpp"

Resource::Resource(Resource::RessourceType type)
{
    ModelsLoaderPtr loader = ModelsLoader::getInstance();
    _model = loader->getModel(Map::getInstance()->resourceToString(type));
    _boundbox = GetModelBoundingBox(_model);
    _originalBoundBox = _boundbox;
}
