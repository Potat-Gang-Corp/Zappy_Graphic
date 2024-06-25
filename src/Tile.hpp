/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Tile
*/

#pragma once

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include "raylib.h"
    #include "IRenderable.hpp"
    #include "IClickable.hpp"
    #include <vector>

class Tile : public IRenderable, public IClickable {
    public:
        Tile(Vector3 position, const Model& islandModel, const std::vector<Model>& resourceModels);
        ~Tile();

        void Render() override final;
        BoundingBox getBoundingBox() const override final;
        void OnClick() override final;
        void setHover(bool status) override final { _isHovered = status; }
        void setResources(const std::vector<int>& resources);
        std::vector<int> getResources() const;
        void addResource(int resourceIndex, int amount);
        void removeResource(int resourceIndex, int amount);

    private:
        Vector3 _position;
        Model _model;
        float _scale;
        BoundingBox _boundingBox;
        bool _isHovered, _isClicked;
        float _rotationAngle;
        std::vector<int> _resources;
        std::vector<Model> _resourceModels;
};

#endif /* !TILE_HPP_ */
