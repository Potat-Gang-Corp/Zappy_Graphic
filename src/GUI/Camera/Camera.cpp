/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Camera
*/

#include "Camera.hpp"

CameraWrapper::CameraWrapper()
{
    _camera = { 0 };
    _camera.position = { 0.0f, 10.0f, 10.0f };
    _camera.target = { 0.0f, 0.0f, 0.0f };
    _camera.up = { 0.0f, 1.0f, 0.0f };
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

CameraWrapper::CameraWrapper(Vector3 position, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = position;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
}

void CameraWrapper::SetPosition(Vector3 position)
{
    _camera.position = position;
}

void CameraWrapper::SetTarget(Vector3 target)
{
    _camera.target = target;
}

void CameraWrapper::SetUp(Vector3 up)
{
    _camera.up = up;
}

void CameraWrapper::SetFovy(float fovy)
{
    _camera.fovy = fovy;
}

void CameraWrapper::SetProjection(int projection)
{
    _camera.projection = projection;
}

void CameraWrapper::BeginMode()
{
    BeginMode3D(_camera);
}

void CameraWrapper::EndMode()
{
    EndMode3D();
}