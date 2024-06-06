/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Factory
*/

#pragma once

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    #include "Msz.hpp"
    #include <unordered_map>
    #include <memory>

class CommandFactory {
    public:
        static CommandFactory *getInstance()
        {
            static CommandFactory instance;
            return &instance;
        }

        CommandFactory()
        {
            std::map<std::string, std::shared_ptr<ICommand>> mymap = {
                {"msz", std::make_shared<MszCommand>()},
            };
            commands = mymap;
        }

        std::map<std::string, std::shared_ptr<ICommand>> getCommands()
        {
            return commands;
        }

        ICommand* getCommand(const std::string& commandType)
        {
            if (commandType.empty()) {
                std::cerr << "Error: Command type is empty." << std::endl;
                return nullptr;
            }
            auto it = commands.find(commandType);
            if (it != commands.end()) {
                return it->second.get();
            } else {
                std::cerr << "Command not found: " << commandType << std::endl;
                return nullptr;
            }
        }

    private:
        std::map<std::string, std::shared_ptr<ICommand>> commands;
};
#endif /* !FACTORY_HPP_ */
