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

class GUI {
    public:
        GUI(int height, int width, const std::string &WindowName);
        ~GUI();

    private:
        int _screenH, _screenW;
        
};

#endif /* !GUI_HPP_ */
