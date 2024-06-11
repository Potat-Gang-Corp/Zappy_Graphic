/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** GUI
*/

#include "GUI.hpp"

GUI::GUI(int height, int width, const std::string &WindowName) : _screenH(height), _screenW(width)
{
    InitWindow(_screenH, _screenW, WindowName.c_str());
    SetTargetFPS(144);
}

GUI::~GUI() {}
