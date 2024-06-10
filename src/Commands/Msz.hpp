/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Msz
*/

#pragma once

#ifndef MSZ_HPP_
    #define MSZ_HPP_

    #include "ICommand.hpp"
    #include <iostream>

class MszCommand : public ICommand {
public:
    void execute(const std::string& data) override {
        std::cout << "Handling msz: " << data << std::endl;
        std::istringstream iss(data);
        std::string command;
        std::string x;
        std::string y;
        iss >> command;
        iss >> x;
        iss >> y;
        std::cout << "X: " << x << "Y: " << y << std::endl;
    }
};

#endif /* !MSZ_HPP_ */