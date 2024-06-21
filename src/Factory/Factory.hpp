/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Factory
*/

#pragma once

/**
 * @file Factory.hpp
 * @brief Contains the declaration of the CommandFactory class
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    #include "Commands.hpp"
    #include <unordered_map>
    #include <memory>

/**
 * @class CommandFactory
 * @brief Class that represents the factory's method to execute commands
*/

class CommandFactory {
    public:
        /**
         * @brief Get the instance of the CommandFactory
         * @return CommandFactory* The instance of the CommandFactory
        */
        static CommandFactory *getInstance()
        {
            static CommandFactory instance;
            return &instance;
        }
        
        /**
         * @brief Construct a new CommandFactory object.
         * 
         * Initializes a map that associates command strings with their corresponding command functions.
        */
        CommandFactory()
        {
            std::map<std::string, std::function<void(const std::string&)>> mymap = {
                {"msz", Commands::msz},
                {"bct", Commands::bct},
                {"tna", Commands::tna},
                {"pnw", Commands::pnw},
                {"ppo", Commands::ppo},
                {"plv", Commands::plv},
                {"pin", Commands::pin},
                {"pex", Commands::pex},
                {"pbc", Commands::pbc},
                {"pic", Commands::pic},
                {"pie", Commands::pie},
                {"pfk", Commands::pfk},
                {"pdr", Commands::pdr},
                {"pgt", Commands::pgt},
                {"pdi", Commands::pdi},
                {"enw", Commands::enw},
                {"ebo", Commands::ebo},
                {"edi", Commands::edi},
                {"sgt", Commands::sgt},
                {"sst", Commands::sst},
                {"seg", Commands::seg},
                {"smg", Commands::smg},
                {"suc", Commands::suc},
                {"sbp", Commands::sbp},
            };
            commands = mymap;
        }

        /**
         * @brief Get the commands map
         * @return std::map<std::string, std::function<void(const std::string&)>> The commands map
        */
        std::map<std::string, std::function<void(const std::string&)>> getCommands()
        {
            return commands;
        }

        /**
         * @brief Executes a command based on the command type.
         * 
         * This function extracts the command prefix from the first three characters of the command type.
         * It then looks up the command in the `commands` map and executes the corresponding function if found.
         * If the command type is empty or the command is not found, an error message is printed.
         * 
         * @param commandType The full command string that includes the command type and its arguments.
        */
        void execCommand(const std::string &commandType)
        {
            std::string prefix = commandType.substr(0, 3);
            if (prefix.empty()) {
                std::cerr << "Error: Command type is empty." << std::endl;
                return;
            }
            auto it = commands.find(prefix);
            if (it != commands.end()) {
                return it->second(commandType);
            } else {
                std::cerr << "Command not found: " << prefix << std::endl;
                return;
            }
        }

    private:
        std::map<std::string, std::function<void(const std::string&)>> commands;
};

#endif /* !FACTORY_HPP_ */
