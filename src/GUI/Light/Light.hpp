/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Light
*/

#pragma once

#ifndef LIGHT_HPP_
    #define LIGHT_HPP_

    #include <iostream>
    #include <vector>
    #include <memory>
    #include "IModels.hpp"
    #include "raylib.h"
    #include "raymath.h"
    #include "rlights.h"

class LightWrapper {
    public:
        LightWrapper();
        ~LightWrapper();
        void SetShaderToModel(std::vector<std::shared_ptr<IModels>> _models);
        void createlight(Vector3 position, Vector3 target, Color color);
        void updateShaderValues(float CamX, float CamY, float CamZ);
        void drawSphereOnLights();
        void updateLightColor(Color color);
        void UpdateLightDayColor(float cycleTime, float dayPhaseDuration);
        Color getCurrentBackgroundColor() { return _currentBackgroundColor; }

    private:
        Light _lights[MAX_LIGHTS] = { 0 };
        int _indLight = 0;
        Shader _shader;
        Color _currentBackgroundColor;
        Color _currentLightColor;
};

#endif /* !LIGHT_HPP_ */