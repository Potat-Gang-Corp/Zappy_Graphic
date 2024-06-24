/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Island
*/

#ifndef ISLAND_HPP_
#define ISLAND_HPP_

    #include "AModels.hpp"

class Island : public AModels {
    public:
        Island(int random, int x, int y);
        void onHover() override final;
        void onHoverEnd() override final;
        void updateRotation(float deltaTime);
        bool getIsHovered() const { return _isHovered; }

    private:
        Vector3 _rotationAxis;
        float _rotationAngle;
        bool _isHovered = false;
        bool _isReturning = false;
        float _hoverRotationSpeed;
        float _returnRotationSpeed;
};

#endif /* !ISLAND_HPP_ */
