/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** ICommand
*/

#pragma once

#ifndef ICOMMAND_HPP_
    #define ICOMMAND_HPP_

#include <string>

class ICommand {
    public:
        virtual ~ICommand() = default;
        virtual void execute(const std::string& data) = 0;
};


#endif /* !ICOMMAND_HPP_ */
