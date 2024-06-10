/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Bct.hpp
*/

#ifndef BCT_HPP_
    #define BCT_HPP_

#include "ICommand.hpp"
#include <iostream>

class BctCommand : public ICommand {
    public:
        void execute (const std::string& data) override {
            std::cout << "Handling bct: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
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
            iss >> x;
            iss >> y;
            iss >> food;
            iss >> linemate;
            iss >> deraumere;
            iss >> sibur;
            iss >> mendiane;
            iss >> phiras;
            iss >> thystame;
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

#endif /* !BCT_HPP_ */