/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#pragma once

#ifndef GUI_HPP_
    #define GUI_HPP_

    #include <iostream>
    #include <raylib.h>
    #include <string>
    #include <vector>
    #include "Player.hpp"
    #include <map>
    #include "Map.hpp"
    #include "Camera.hpp"
    #include "Window.hpp"
    #include "IModels.hpp"
    #include <chrono>
    #include "Light.hpp"
    #include "PlayerManager.hpp"

class GUI {
    public:
        GUI();
        ~GUI();
        static std::shared_ptr<GUI> getInstance() {
            static std::shared_ptr<GUI> instance(new GUI());
            return instance;
        }
        void load();
        void run();
        void LoadIsland();
        void loadResources();
        void loadPlayers();
        void UpdateMapContent();
        void setFreq(int freq) { _freq = freq; }
        std::shared_ptr<PlayerManager> getPlayerManager() { return _playerManager; }
        void handleMouseInteraction();

    private:
        WindowPtr _window;
        std::string _TextDisplay;
        std::shared_ptr<IModels> _selectedModel = nullptr;
        bool _displayInfo = false;
        std::vector<std::string> _cachedInfo;
        std::unique_ptr<CameraWrapper> _camera;
        std::shared_ptr<LightWrapper> _lightWrapper;
        std::shared_ptr<PlayerManager> _playerManager;
        std::vector<std::shared_ptr<IModels>> _models;
        std::vector<std::shared_ptr<IModels>> _resource;
        int _freq = 10;
};

typedef std::shared_ptr<GUI> GuiPtr;

#endif /* !GUI_HPP_ */
