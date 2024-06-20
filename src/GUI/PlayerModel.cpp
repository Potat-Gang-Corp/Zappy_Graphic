/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** PlayerModel
*/

#include "PlayerModel.hpp"
#include "ModelsLoader.hpp"

PlayerModel::PlayerModel(const std::string& modelFilename, const std::string& animationFilename)
    : frameCounter(0), frameTime(0.016f), lastUpdateTime(std::chrono::steady_clock::now())
{
    _model = ModelsLoader::getInstance()->getModel(modelFilename);
    animation = ModelsLoader::getInstance()->getAnim(animationFilename);
    _scale = 0.09f;
    _position = {0, 0, 0};
    _originalBoundBox = GetModelBoundingBox(_model);
    _originalBoundBox.max.x -= 4.0f;
    _originalBoundBox.min.x += 4.0f;
    updateBoundingBox();
}

PlayerModel::~PlayerModel() {}

void PlayerModel::updateAnimation(float deltaTime)
{
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedTime = now - lastUpdateTime;

    if (elapsedTime.count() >= frameTime) {
        int framesToAdvance = static_cast<int>(elapsedTime.count() / frameTime);
        frameCounter += framesToAdvance;
        lastUpdateTime = now;

        UpdateModelAnimation(_model, animation.get()[0], frameCounter);
        if (frameCounter >= animation.get()[0].frameCount) {
            frameCounter = 0;
        }
    }
}

void PlayerModel::setAnimation(const std::shared_ptr<ModelAnimation>& anim)
{
    animation = anim;
    frameCounter = 0;
    lastUpdateTime = std::chrono::steady_clock::now();
}

