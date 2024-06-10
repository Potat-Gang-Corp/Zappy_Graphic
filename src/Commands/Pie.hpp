/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pie.hpp
*/


#pragma once

#ifndef PIE_HPP_
    #define PIE_HPP_

#include "ICommand.hpp"
#include <iostream>

class PieCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //end of an incantation
            std::cout << "Handling pie: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string x;
            std::string y;
            std::string result;
            iss >> command;
            iss >> x;
            iss >> y;
            iss >> result;
            std::cout << "X: " << x << "Y: " << y << std::endl;
            std::cout << "Result: " << result << std::endl;
        }
};