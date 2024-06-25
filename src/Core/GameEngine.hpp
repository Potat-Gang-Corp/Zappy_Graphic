/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** GameEngine
*/

#pragma once

#ifndef GAME_ENGINE_HPP
    #define GAME_ENGINE_HPP

    #include <vector>
    #include <memory>
    #include "IRenderable.hpp"
    #include "IUpdatable.hpp"
    #include "IClickable.hpp"
    #include "CameraWrapper.hpp"
    #include "raylib.h"
    #include "Tile.hpp"
    #include "HUD.hpp"
    #include "Player.hpp"
    #include <iostream>
    #include "Light.hpp"
    #include <ostream>

class GameEngine {
    public:
        GameEngine();
        ~GameEngine();
        void Initialize();
        void Run();
        void Shutdown();
        void loadTiles();
        void loadModels();
        void UpdateTileResources(int x, int y, const std::vector<int>& resources);
        void AddPlayer(int id, int x, int y, int orientation, const std::string& teamName);
        void UpdatePlayerPosition(int id, int x, int y, int orientation);

    private:
        void Update(float deltaTime);
        void Render();

        std::vector<std::shared_ptr<IUpdatable>> _updatables;
        std::vector<std::shared_ptr<IRenderable>> _renderables;
        std::vector<std::shared_ptr<IClickable>> _clickables;
        std::shared_ptr<CameraWrapper> _camera;
        std::vector<std::shared_ptr<Tile>> _tiles;
        std::vector<std::shared_ptr<Player>> _players;
        std::vector<Model> _resourceModels;
        std::shared_ptr<LightWrapper> _lightWrapper;
        std::shared_ptr<HUD> _hud;
        Model _tileModel;
        bool _isRunning;
};

#endif // GAME_ENGINE_HPP
