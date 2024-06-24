/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** AModels
*/

#include "AModels.hpp"

void AModels::drawModel()
{
    printf("Drawing model\n");
    printf("Position: %f %f %f\n", _position.x, _position.y, _position.z);
    printf("Scale: %f\n", _scale);
    DrawModel(_model, _position, _scale, WHITE);
}

void AModels::setPosition(Vector3 position)
{
    _position = position;
    updateBoundingBox();
}

void AModels::setScale(float scale)
{
    _scale = scale;
    updateBoundingBox();
}

void AModels::updateBoundingBox()
{
    BoundingBox originalBoundBox = _originalBoundBox;

    _boundbox.min.x = originalBoundBox.min.x * _scale + _position.x;
    _boundbox.min.y = originalBoundBox.min.y * _scale + _position.y;
    _boundbox.min.z = originalBoundBox.min.z * _scale + _position.z;
    _boundbox.max.x = originalBoundBox.max.x * _scale + _position.x;
    _boundbox.max.y = originalBoundBox.max.y * _scale + _position.y;
    _boundbox.max.z = originalBoundBox.max.z * _scale + _position.z;
}

void AModels::setRotation(Vector3 rotation)
{
    _rotation = rotation;
    _model.transform = MatrixRotateXYZ(_rotation);
}

void AModels::onHover()
{
    DrawBoundingBox(_boundbox, RED);
}

void AModels::onClick()
{
    // DrawBoundingBox(_boundbox, GREEN);
}

void AModels::onHoverEnd()
{
    // DrawBoundingBox(_boundbox, BLACK);
}

