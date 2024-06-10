/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Commands.cpp
*/

#include <iostream>
#include <sstream>
#include <ostream>

void msz_command(const std::string& data) {
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