/*
** EPITECH PROJECT, 2023
** src
** File description:
** Ppo.hpp
*/

#pragma once

#ifndef PPO_HPP
    #define PPO_HPP

#include "ICommand.hpp"
#include <iostream>

class PpoCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            std::cout << "Handling ppo: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            std::string x;
            std::string y;
            std::string orientation;
            iss >> command;
            iss >> player_id;
            iss >> x;
            iss >> y;
            iss >> orientation;
            std::cout << "Player id: " << player_id << std::endl;
            std::cout << "X: " << x << std::endl;
            std::cout << "Y: " << y << std::endl;
            std::cout << "Orientation: " << orientation << std::endl;
        }
};


#endif /* !PPO_HPP */