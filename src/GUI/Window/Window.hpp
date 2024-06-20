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
    #include "Map.hpp"
    #include <vector>

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
        void DrawFps(int x, int y);
        void loadModels();
        void updateMap(std::shared_ptr<Map> map);
        bool getInit() { return _init; }
        std::vector<Model> getResourceModels() { return _resourceModels; }

    private:
        int _screenH, _screenW, _fps;
        std::vector<Model> _resourceModels;
        bool _init = false;
};

typedef std::shared_ptr<Window> WindowPtr;

#endif /* !WINDOW_HPP_ */
