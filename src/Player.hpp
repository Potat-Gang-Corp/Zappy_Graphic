/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Player
*/

#pragma once

#ifndef PLAYER_HPP
    #define PLAYER_HPP

    #include "raylib.h"
    #include "IRenderable.hpp"
    #include "IClickable.hpp"
    #include <string>
    #include <memory>
    #include <vector>

class Player : public IRenderable, public IClickable {
    public:
        Player(int id, Vector3 position, int orientation, const std::string& teamName);
        ~Player();

        void Render() override;
        void OnClick() override;

        void setHover(bool hover);
        bool isHovered() const;

        void setPosition(Vector3 position);
        void setOrientation(int orientation);
        void playAnimation(const std::string& animationPath);

        int getId() const;
        Vector3 getPosition() const;
        int getOrientation() const;
        std::string getTeamName() const;
        BoundingBox getBoundingBox() const override {
            return _boundingBox;
        }
        Model getModel() override final {
            return _model;
        }

    private:
        float _scale;
        int _id;
        Vector3 _position;
        int _orientation;
        std::string _teamName;
        int _level;
        std::vector<int> _inventory;
        Model _model;
        BoundingBox _boundingBox;
        ModelAnimation *_animations;
        int _animationCount;
        int _currentAnimation;
        int _frameCounter;
        bool _hover;
        bool _clicked;
        void loadDefaultAnimation();
};

#endif // PLAYER_HPP

