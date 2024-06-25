/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Player
*/

#include "Player.hpp"
#include <iostream>
#include "raymath.h"

Player::Player(int id, Vector3 position, int orientation, const std::string& teamName, int level) : _id(id), _position(position), _scale(0.09f),
_orientation(orientation), _teamName(teamName), _hover(false), _clicked(false), _level(level), _frameCounter(0), _currentAnimation(0) {
    _model = LoadModel("assets/player.glb");

    _animations = LoadModelAnimations("assets/player.glb", &_animationCount);
    loadDefaultAnimation();
    _inventory.resize(7, 0);
    _boundingBox = GetModelBoundingBox(_model);
    _boundingBox.min = Vector3Scale(_boundingBox.min, _scale);
    _boundingBox.max = Vector3Scale(_boundingBox.max, _scale);
    _boundingBox.min = Vector3Add(_boundingBox.min, position);
    _boundingBox.max = Vector3Add(_boundingBox.max, position);
}

Player::~Player() {}

void Player::Render()
{
    float angle = 0.0f;
    switch (_orientation) {
        case 1: angle = 0.0f; break;
        case 2: angle = 90.0f; break;
        case 3: angle = 180.0f; break;
        case 4: angle = 270.0f; break;
    }

    _frameCounter++;
    UpdateModelAnimation(_model, _animations[_currentAnimation], _frameCounter);
    if (_frameCounter >= _animations[_currentAnimation].frameCount) {
        _frameCounter = 0;
        if (_currentAnimation != 0) {
            _currentAnimation = 0;
            loadDefaultAnimation();
        }
    }

    DrawModelEx(_model, _position, (Vector3){0, 1, 0}, angle, (Vector3){_scale, _scale, _scale}, WHITE);
    DrawBoundingBox(_boundingBox, GREEN);
}

void Player::OnClick()
{
    std::cout << "Player " << _id << " clicked\n";
    _clicked = !_clicked;
}

void Player::setHover(bool hover)
{
    _hover = hover;
}

bool Player::isHovered() const
{
    return _hover;
}

void Player::setPosition(Vector3 position)
{
    this->_position = position;
}

void Player::setOrientation(int orientation)
{
    this->_orientation = orientation;
}

void Player::playAnimation(const std::string& animationPath)
{
    ModelAnimation* newAnimations = LoadModelAnimations(animationPath.c_str(), &_animationCount);
    if (newAnimations) {
        for (int i = 0; i < _animationCount; i++) {
            UnloadModelAnimation(_animations[i]);
        }
        RL_FREE(_animations);

        _animations = newAnimations;
        _currentAnimation = 0;
        _frameCounter = 0;
    }
}

void Player::loadDefaultAnimation()
{
    _currentAnimation = 0;
}

int Player::getId() const {
    return _id;
}

Vector3 Player::getPosition() const {
    return _position;
}

int Player::getOrientation() const {
    return _orientation;
}

std::string Player::getTeamName() const {
    return _teamName;
}

void Player::addInventory(int resourceIndex, int amount)
{
    if (resourceIndex >= 0 && resourceIndex < _inventory.size()) {
        _inventory[resourceIndex] += amount;
    }
}

void Player::removeInventory(int resourceIndex, int amount)
{
    if (resourceIndex >= 0 && resourceIndex < _inventory.size() && _inventory[resourceIndex] >= amount) {
        _inventory[resourceIndex] -= amount;
    }
}

void Player::setPlayerLevel(int level)
{
    _level = level;
}