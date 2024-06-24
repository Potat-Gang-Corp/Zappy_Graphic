/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Island
*/

#include "Island.hpp"
#include "ModelsLoader.hpp"
#include "Light.hpp"
#include "Map.hpp"

Island::Island(int random, int x, int y) : _rotationAxis({0, 1, 0}), _rotationAngle(0.0f),
 _hoverRotationSpeed(30.0f), _returnRotationSpeed(60.0f) // 30 degrees per second for hover, 60 degrees per second for return
{
    _islandX = x;
    _islandY = y;
    ModelsLoaderPtr modelsLoader = ModelsLoader::getInstance();
    if (random == 1) {
        _model = modelsLoader->getModel("Island_farm");
        _boundbox = GetModelBoundingBox(_model);
        _boundbox.max.y -= 10.0f;
        _originalBoundBox = _boundbox;
    } else if (random == 2) {
        _model = modelsLoader->getModel("Island_tree");
        _boundbox = GetModelBoundingBox(_model);
        _boundbox.max.y -= 15.0f;
        _originalBoundBox = _boundbox;
    } else {
        _model = modelsLoader->getModel("Island");
        _boundbox = GetModelBoundingBox(_model);
        _boundbox.max.y -= 1.0f;
        _originalBoundBox = _boundbox;
    }
}

void Island::onHover()
{
    if (!_isHovered) {
        _isHovered = true;
    }
}

void Island::onHoverEnd()
{
    if (_isHovered) {
        _isHovered = false;
        _rotationAngle = 0.0f;
    }
}

void Island::updateRotation(float deltaTime)
{
    if (_isHovered) {
        _rotationAngle += _hoverRotationSpeed * deltaTime;
        if (_rotationAngle >= 360.0f) {
            _rotationAngle -= 360.0f;
        }
    }
    Matrix rotation = MatrixRotate(_rotationAxis, _rotationAngle * DEG2RAD);
    _model.transform = rotation;
}
