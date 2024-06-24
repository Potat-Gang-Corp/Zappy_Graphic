/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** AModels
*/

#pragma once

#ifndef AMODELS_HPP_
    #define AMODELS_HPP_

    #include "IModels.hpp"
    #include <raymath.h>
    #include "ModelsLoader.hpp"

class AModels : public IModels {
    public:
        ~AModels() = default;
        void setPosition(Vector3 position) override final;
        void setScale(float scale) override final;
        void setRotation(Vector3 rotation) override final;
        Model getModel() override final { return _model; }
        void drawModel() override;
        void updateBoundingBox();
        BoundingBox getBoundingBox() override { return _boundbox; }
        void onHover() override;
        void onClick() override;
        Vector3 getPosition() const override { return _position; }
        void setHover(bool hover) override final { _Hover = hover; }
        int GetIslandX() override final { return _islandX; }
        int GetIslandY() override final { return _islandY; }
        void onHoverEnd() override;

    protected:
        int _islandX, _islandY;
        bool _Hover = false;
        float _scale;
        Vector3 _position, _rotation;
        Model _model;
        BoundingBox _boundbox;
        BoundingBox _originalBoundBox;
};

#endif /* !AMODELS_HPP_ */
