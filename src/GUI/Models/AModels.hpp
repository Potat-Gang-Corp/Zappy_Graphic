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
        Model getModel() override final { return _model; }
        void drawModel() override;

    protected:
        float _scale;
        Vector3 _position;
        Model _model;
        BoundingBox _boundbox;
};

#endif /* !AMODELS_HPP_ */
