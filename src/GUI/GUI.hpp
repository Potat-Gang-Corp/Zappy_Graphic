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

class GUI {
    public:
        GUI();
        ~GUI();
        static GUI *getInstance()
        {
            static GUI instance;
            return &instance;
        }
        void initWindow(int height, int width, const std::string &WindowName);
        void AddPlayer(Player player);

    private:
        std::map<int, std::vector<Player>> _players;
        int _screenH, _screenW;
        
};

#endif /* !GUI_HPP_ */
