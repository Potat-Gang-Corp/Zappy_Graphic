/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Camera
*/

#pragma once

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "raylib.h"

class CameraWrapper {
    public:
        CameraWrapper();
        CameraWrapper(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection);
        void SetPosition(Vector3 position);
        void SetTarget(Vector3 target);
        void SetUp(Vector3 up);
        void SetFovy(float fovy);
        void SetProjection(int projection);
        void BeginMode();
        void EndMode();
        void update() {
            UpdateCamera(&_camera, CAMERA_ORTHOGRAPHIC);
        }

    private:
        Camera3D _camera;
};

#endif /* !CAMERA_HPP_ */
