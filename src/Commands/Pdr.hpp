/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pdr.hpp
*/


#pragma once

#ifndef PDR_HPP_
    #define PDR_HPP_

#include "ICommand.hpp"
#include <iostream>

class PdrCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //player drop an object
            std::cout << "Handling pdr: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            std::string ressource_number;
            iss >> command;
            iss >> player_id;
            iss >> ressource_number;
            std::cout << "Player id: " << player_id << std::endl;
            std::cout << "Ressource number: " << ressource_number << std::endl;
        }
};