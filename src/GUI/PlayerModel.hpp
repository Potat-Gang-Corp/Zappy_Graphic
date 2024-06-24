/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** PlayerModel
*/

#pragma once

#ifndef PLAYERMODEL_HPP_
    #define PLAYERMODEL_HPP_

    #include "AModels.hpp"
    #include <memory>
    #include <chrono>

class PlayerModel : public AModels {
    public:
        PlayerModel(const std::string &modelFilename, const std::string &animationFilename);
        ~PlayerModel();
        void updateAnimation(float deltaTime);
        void setAnimation(const std::shared_ptr<ModelAnimation> &anim);
        void setRotation(float rotationAngle);
        void onHover() override final;
        void onHoverEnd() override final;

    private:
        std::shared_ptr<ModelAnimation> animation;
        int frameCounter;
        float frameTime;
        std::chrono::steady_clock::time_point lastUpdateTime;
        bool _isAnimating = false;
        bool _isHovered = false;
        float _animationTime = 0.0f;
        std::shared_ptr<ModelAnimation> _defaultAnimation;
        std::shared_ptr<ModelAnimation> _hoverAnimation;
};


#endif /* !PLAYERMODEL_HPP_ */
