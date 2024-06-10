/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pin.hpp
*/


#pragma once

#ifndef PIN_HPP_
    #define PIN_HPP_

#include "ICommand.hpp"
#include <iostream>

class PinCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            std::cout << "Handling pin: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            std::string x;
            std::string y;
            std::string linemate;
            std::string deraumere;
            std::string sibur;
            std::string mendiane;
            std::string phiras;
            std::string thystame;
            std::string food;
            iss >> command;
            iss >> player_id;
            iss >> x;
            iss >> y;
            iss >> food;
            iss >> linemate;
            iss >> deraumere;
            iss >> sibur;
            iss >> mendiane;
            iss >> phiras;
            iss >> thystame;
            std::cout << "Player id: " << player_id << std::endl;
            std::cout << "X: " << x << std::endl;
            std::cout << "Y: " << y << std::endl;
            std::cout << "Food: " << food << std::endl;
            std::cout << "Linemate: " << linemate << std::endl;
            std::cout << "Deraumere: " << deraumere << std::endl;
            std::cout << "Sibur: " << sibur << std::endl;
            std::cout << "Mendiane: " << mendiane << std::endl;
            std::cout << "Phiras: " << phiras << std::endl;
            std::cout << "Thystame: " << thystame << std::endl;
        }
};