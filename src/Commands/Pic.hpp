/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pic.hpp
*/

#pragma once

#ifndef PIC_HPP_
    #define PIC_HPP_

#include "ICommand.hpp"
#include <iostream>

class PicCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //player id, x, y, level
            std::cout << "Handling pic: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string x;
            std::string y;
            std::string level;
            std::string player_id;
            iss >> command;
            iss >> x;
            iss >> y;
            iss >> level;
            iss >> player_id;
            std::cout << "X: " << x << "Y: " << y << std::endl;
            std::cout << "Level: " << level << std::endl;
            std::cout << "Player id: " << player_id << std::endl;
        }
};

#endif /* !PIC_HPP_ */