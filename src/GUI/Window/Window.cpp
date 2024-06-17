/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Window
*/

#include "Window.hpp"

Window::Window() {}

Window::~Window() {}

void Window::setLogInfo(const std::string &log)
{
    static const std::unordered_map<std::string, int> logLevels = {
        {"LOG_ALL", LOG_ALL},
        {"LOG_TRACE", LOG_TRACE},
        {"LOG_DEBUG", LOG_DEBUG},
        {"LOG_INFO", LOG_INFO},
        {"LOG_WARNING", LOG_WARNING},
        {"LOG_ERROR", LOG_ERROR},
        {"LOG_FATAL", LOG_FATAL}
    };

    auto it = logLevels.find(log);
    if (it != logLevels.end()) {
        SetTraceLogLevel(it->second);
    } else {
        SetTraceLogLevel(LOG_NONE);
    }
    // LOG_ALL, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_FATAL
}

void Window::initWindow(int height, int width, const std::string &WindowName, int fps)
{
    _screenH = height;
    _screenW = width;
    _fps = fps;
    InitWindow(_screenH, _screenW, WindowName.c_str()); 
    SetTargetFPS(_fps);
}

void Window::DrawMap(int mapSizeX, int mapSizeY)
{
    for (float i = 0; i < mapSizeX; i++) {
        for (float j = 0; j < mapSizeY; j++) {
            Color randomColor = {
                static_cast<unsigned char>(GetRandomValue(0, 255)), // Red component
                static_cast<unsigned char>(GetRandomValue(0, 255)), // Green component
                static_cast<unsigned char>(GetRandomValue(0, 255)), // Blue component
                255 // Alpha component (fully opaque)
            };
            DrawCube((Vector3){(float)(i - mapSizeX / 2 + 0.5), 0, (float)(j - mapSizeY / 2 + 0.5)}, 0.5f, 0.5f, 0.5f, randomColor);
        }
    }
}

void Window::DrawFps(int x, int y)
{
    DrawFPS(x, y);
}
