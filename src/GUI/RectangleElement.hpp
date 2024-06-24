/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Rectangle
*/

#pragma once

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_

    #include "IUIElement.hpp"
    #include <raylib.h>

class RectangleElement : public UIElement {
    public:
        RectangleElement(const Rectangle& rect, const Color& color)
            : _rect(rect), _color(color) {}

        void draw() const override {
            DrawRectangleRec(_rect, _color);
        }

        void drawOutline(const Color& outlineColor) const {
            DrawRectangleLines((int)_rect.x, (int)_rect.y, (int)_rect.width, (int)_rect.height, outlineColor);
        }

        Rectangle getRect() const {
            return _rect;
        }

    private:
        Rectangle _rect;
        Color _color;
};

#endif /* !RECTANGLE_HPP_ */
