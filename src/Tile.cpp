/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Tile
*/

#include "Tile.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "raymath.h"

Tile::Tile(Vector3 position, const Model& islandModel, const std::vector<Model>& resourceModels)
    : _position(position), _scale(0.2f), _model(islandModel), _resourceModels(resourceModels)
{
    if (!_model.meshCount) {
        std::cerr << "Failed to load model: assets/island_farm.glb" << std::endl;
        throw std::runtime_error("Failed to load model");
    }

    _boundingBox = GetMeshBoundingBox(_model.meshes[0]);
    _boundingBox.min = Vector3Scale(_boundingBox.min, _scale);
    _boundingBox.max = Vector3Scale(_boundingBox.max, _scale);
    _boundingBox.min = Vector3Add(_boundingBox.min, position);
    _boundingBox.max = Vector3Add(_boundingBox.max, position);
}

Tile::~Tile() {}

void Tile::Render()
{
    if (_isHovered) {
        _rotationAngle += 1.0f;
        if (_rotationAngle > 360.0f) _rotationAngle -= 360.0f;
    }

    for (int i = 0; i < 10; i++) {
        Color glowColor = Fade(RED, 1.0f - (i * 0.1f));
        if (_isHovered)
            DrawModelEx(_model, _position, (Vector3){0, 1, 0}, _rotationAngle, (Vector3){_scale, _scale, _scale}, glowColor);
        else {
            _rotationAngle = 0.0f;
            DrawModel(_model, _position, _scale, WHITE);
        }
    }

    float radius = 0.5f;
    int resourceCount = 0;
    size_t resourceSize = _resources.size();
    for (size_t i = 0; i < resourceSize; ++i) {
        if (_resources[i] > 0) {
            float angle = resourceCount * (360.0f / resourceSize) * DEG2RAD + _rotationAngle * DEG2RAD;
            angle *= -1;
            Vector3 resourcePosition = {
                _position.x + radius * cos(angle),
                _position.y,
                _position.z + radius * sin(angle)
            };
            DrawModel(_resourceModels[i], resourcePosition, 0.09f, WHITE);
            resourceCount++;
        }
    }
}

BoundingBox Tile::getBoundingBox() const
{
    return _boundingBox;
}

void Tile::OnClick()
{
    std::cout << "Tile clicked" << std::endl;
}

void Tile::setResources(const std::vector<int>& resources)
{
    if (resources.size() == 8) {
        _resources = resources;
    }
}

std::vector<int> Tile::getResources() const
{
    return _resources;
}

void Tile::addResource(int resourceIndex, int amount)
{
    if (resourceIndex >= 0 && resourceIndex < _resources.size()) {
        _resources[resourceIndex] += amount;
    }
}

void Tile::removeResource(int resourceIndex, int amount)
{
    if (resourceIndex >= 0 && resourceIndex < _resources.size() && _resources[resourceIndex] >= amount) {
        _resources[resourceIndex] -= amount;
    }
}
