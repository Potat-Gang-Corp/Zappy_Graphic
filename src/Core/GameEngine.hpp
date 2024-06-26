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
    #include "ModelsLoader.hpp"
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
        static std::shared_ptr<GameEngine> &getInstance() {
            static std::shared_ptr<GameEngine> instance = std::make_shared<GameEngine>();
            return instance;
        }
        GameEngine();
        ~GameEngine();
        void Initialize();
        void Run();
        void Shutdown();
        void loadTiles();
        void loadModels();
        void UpdateTileResources(int x, int y, const std::vector<int>& resources);
        void AddPlayer(int id, int x, int y, int orientation, const std::string& teamName, int level);
        void addFullPlayer(Player player);
        void UpdatePlayerPosition(int id, int x, int y, int orientation);
        float getSizeX () { return _sizeX; }
        float getSizeY () { return _sizeY; }
        void setMapSize(float sizeX, float sizeY);
        std::vector<std::shared_ptr<Player>> getPlayers() { return _players; }
        std::vector<std::shared_ptr<Tile>> getTiles() { return _tiles; }
        void removeResourceTail(int x, int y, int resourceIndex, int amount);
        void addResourceTail(int x, int y, int resourceIndex, int amount);
        void addEgg(int id, int x, int y, int resourceIndex);

    private:
        void Update(float deltaTime);
        void Render();

        std::vector<std::shared_ptr<IUpdatable>> _updatables;
        std::vector<std::shared_ptr<IRenderable>> _renderables;
        std::vector<std::shared_ptr<IClickable>> _clickables;
        std::shared_ptr<CameraWrapper> _camera;
        std::vector<std::shared_ptr<Tile>> _tiles;
        std::vector<std::shared_ptr<Player>> _players;
        std::shared_ptr<ModelsLoader> _modelsGetter;
        std::vector<Model> _resourceModels;
        std::shared_ptr<LightWrapper> _lightWrapper;
        std::shared_ptr<HUD> _hud;
        Model _tileModel;
        bool _isRunning;
        float _sizeX = 0;
        float _sizeY = 0;
};

typedef std::shared_ptr<GameEngine> GameEnginePtr;

#endif // GAME_ENGINE_HPP
