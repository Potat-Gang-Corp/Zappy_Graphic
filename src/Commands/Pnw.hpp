/*
** EPITECH PROJECT, 2023
** src
** File description:
** Pnw.hpp
*/

#pragma once

#ifndef PNW_HPP_
    #define PNW_HPP_

#include "ICommand.hpp"
#include <iostream>

class PnwCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            std::cout << "Handling pnw: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            std::string x;
            std::string y;
            std::string orientation;
            std::string level;
            std::string team_name;
            iss >> command;
            iss >> player_id;
            iss >> x;
            iss >> y;
            iss >> orientation;
            iss >> level;
            iss >> team_name;
            std::cout << "Player id: " << player_id << std::endl;
            std::cout << "X: " << x << std::endl;
            std::cout << "Y: " << y << std::endl;
            std::cout << "Orientation: " << orientation << std::endl;
            std::cout << "Level: " << level << std::endl;
            std::cout << "Team name: " << team_name << std::endl;
        }
};

#endif /* !PNW_HPP_ */