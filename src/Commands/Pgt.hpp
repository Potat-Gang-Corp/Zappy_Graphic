/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pgt.hpp
*/


#pragma once

#ifndef PGT_HPP_
    #define PGT_HPP_

#include "ICommand.hpp"
#include <iostream>

class PgtCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //player take an object
            std::cout << "Handling pgt: " << data << std::endl;
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

#endif /* !PGT_HPP_ */