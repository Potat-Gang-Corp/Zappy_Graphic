/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pfk.hpp
*/

#pragma once

#ifndef PFK_HPP_
    #define PFK_HPP_

#include "ICommand.hpp"
#include <iostream>

class PfkCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //egg layed by player id
            std::cout << "Handling pfk: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            iss >> command;
            iss >> player_id;
            std::cout << "Player id: " << player_id << std::endl;
        }
};