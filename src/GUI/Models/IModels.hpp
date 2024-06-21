/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** IModels
*/

#pragma once

#ifndef IMODELS_HPP_
    #define IMODELS_HPP_

    #include <raylib.h>

class IModels {
    public:
        virtual ~IModels() = default;
        virtual void setPosition(Vector3 position) = 0;
        virtual void setRotation(Vector3 rotation) = 0;
        virtual void setScale(float scale) = 0;
        virtual Model getModel() = 0;
        virtual void drawModel() = 0;
};

#endif /* !IMODELS_HPP_ */
