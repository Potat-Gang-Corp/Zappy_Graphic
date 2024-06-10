/*
** EPITECH PROJECT, 2023
** src
** File description:
** Tna.hpp
*/

#pragma once

#ifndef TNA_HPP_
    #define TNA_HPP_

#include "ICommand.hpp"
#include <iostream>

class TnaCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            std::cout << "Handling tna: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string team_name;
            iss >> command;
            iss >> team_name;
            std::cout << "Team name: " << team_name << std::endl;
        }
};

#endif /* !TNA_HPP_ */