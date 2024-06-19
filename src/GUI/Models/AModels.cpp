/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** AModels
*/

#include "AModels.hpp"

void AModels::drawModel()
{
    DrawModel(_model, _position, _scale, WHITE);
    DrawBoundingBox(_boundbox, WHITE);
}

void AModels::setPosition(Vector3 position)
{
    _position = position;

    _boundbox.min.x += position.x;
    _boundbox.min.y += position.y;
    _boundbox.min.z += position.z;
    _boundbox.max.x += position.x;
    _boundbox.max.y += position.y;
    _boundbox.max.z += position.z;
}

void AModels::setScale(float scale)
{
    _scale = scale;
    _boundbox.min.x *= scale;
    _boundbox.min.y *= scale;
    _boundbox.min.z *= scale;
    _boundbox.max.x *= scale;
    _boundbox.max.y *= scale;
    _boundbox.max.z *= scale;
}   
