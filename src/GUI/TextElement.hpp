/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** TextElement
*/

#pragma once

#ifndef TEXTELEMENT_HPP_
    #define TEXTELEMENT_HPP_

    #include "IUIElement.hpp"
    #include <raylib.h>
    #include <string>

class TextElement : public UIElement {
    public:
        TextElement(const std::string& text, const Vector2& position, int fontSize, const Color& color)
            : _text(text), _position(position), _fontSize(fontSize), _color(color) {}

        void draw() const override {
            DrawText(_text.c_str(), (int)_position.x, (int)_position.y, _fontSize, _color);
        }

        int getTextWidth() const {
            return MeasureText(_text.c_str(), _fontSize);
        }

        void setPosition(const Vector2& position) {
            _position = position;
        }

    private:
        std::string _text;
        Vector2 _position;
        int _fontSize;
        Color _color;
};

#endif /* !TEXTELEMENT_HPP_ */
