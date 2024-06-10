/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pex.hpp
*/

#pragma once

#ifndef PEX_HPP_
    #define PEX_HPP_

#include "ICommand.hpp"
#include <iostream>

class PexCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //explusion player id
            std::cout << "Handling pex: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            iss >> command;
            iss >> player_id;
            std::cout << "Player id: " << player_id << std::endl;
        }
};

#endif /* !PEX_HPP_ */