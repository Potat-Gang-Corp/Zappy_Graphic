/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Window
*/

#pragma once

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include <iostream>
    #include <raylib.h>
    #include <unordered_map>
    #include <memory>

class Window {
    public:
        Window();
        ~Window();
        static std::shared_ptr<Window> getInstance() {
            static std::shared_ptr<Window> instance(new Window());
            return instance;
        }
        void setLogInfo(const std::string &log);
        void initWindow(int height, int width, const std::string &WindowName, int fps);
        void DrawMap(int mapSizeX, int mapSizeY);
        void DrawFps(int x, int y);

    private:
        int _screenH, _screenW, _fps;
};

typedef std::shared_ptr<Window> WindowPtr;

#endif /* !WINDOW_HPP_ */
