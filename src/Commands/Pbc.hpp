/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Pbc.hpp
*/


#ifndef PBC_HPP_
    #define PBC_HPP_


#include "ICommand.hpp"
#include <iostream>

class PbcCommand : public ICommand {
    public:
        void execute(const std::string& data) override {
            //broadcast player id message
            std::cout << "Handling pbc: " << data << std::endl;
            std::istringstream iss(data);
            std::string command;
            std::string player_id;
            std::string message;
            iss >> command;
            iss >> player_id;
            iss >> message;
            std::cout << "Player id: " << player_id << std::endl;
            std::cout << "Message: " << message << std::endl;
        }
};

#endif /* !PBC_HPP_ */