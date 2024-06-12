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
    #include <memory>

class GUI {
    public:
        GUI();
        ~GUI();
        static std::shared_ptr<GUI> getInstance() {
            static std::shared_ptr<GUI> instance(new GUI());
            return instance;
        }
        void initWindow(int height, int width, const std::string &WindowName);
        void AddPlayer(Player player);
        std::map<int, std::vector<Player>> &getPlayers()
        {
            return _players;
        }
        void run();

    private:
        std::map<int, std::vector<Player>> _players;
        int _screenH, _screenW;
        
};

typedef std::shared_ptr<GUI> GuiPtr;

#endif /* !GUI_HPP_ */
