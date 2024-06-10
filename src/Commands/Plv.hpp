/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Plv.hpp
*/

#pragma once

#ifndef PLV_HPP_
    #define PLV_HPP_

#include "ICommand.hpp"
#include <iostream>

class PlvCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            std::cout << "Handling plv: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            std::string level;
            iss >> command;
            iss >> player_id;
            iss >> level;
            std::cout << "Player id: " << player_id << std::endl;
            std::cout << "Level: " << level << std::endl;
        }
};

#endif /* !PLV_HPP_ */