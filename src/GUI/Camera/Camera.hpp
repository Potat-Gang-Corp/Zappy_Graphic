/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Camera
*/

#pragma once

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include <raylib.h>
    #include <cstdio>
    #include <memory>

class CameraWrapper {
    public:
        static std::shared_ptr<CameraWrapper> getInstance() {
            static std::shared_ptr<CameraWrapper> instance(new CameraWrapper());
            return instance;
        }
        CameraWrapper();
        void SetPosition(Vector3 position);
        void SetTarget(Vector3 target);
        void SetUp(Vector3 up);
        void SetFovy(float fovy);
        void SetProjection(int projection);
        void BeginMode();
        void EndMode();
        Camera3D getCamera() { return _camera; }
        void update() {
            UpdateCamera(&_camera, CAMERA_ORTHOGRAPHIC);
        }
        float getX() { return _camera.position.x; }
        float getY() { return _camera.position.y; }
        float getZ() { return _camera.position.z; }

    private:
        Camera3D _camera;
        float _zoom = 0;
};

typedef std::shared_ptr<CameraWrapper> CameraWrapperPtr;

#endif /* !CAMERA_HPP_ */
