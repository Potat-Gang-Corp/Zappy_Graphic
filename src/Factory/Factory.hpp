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
                {"msz", msz_command},
                {"bct", bct_command},
                {"tna", tna_command},
                {"pnw", pnw_command},
                {"ppo", ppo_command},
                {"plv", plv_command},
                {"pin", pin_command},
                {"pex", pex_command},
                {"pbc", pbc_command},
                {"pic", pic_command},
                {"pie", pie_command},
                {"pfk", pfk_command},
                {"pdr", pdr_command},
                {"pgt", pgt_command},
                {"pdi", pdi_command},
                {"enw", enw_command},
                {"ebo", ebo_command},
                {"edi", edi_command},
                {"sgt", sgt_command},
                {"sst", sst_command},
                {"seg", seg_command},
                {"smg", smg_command},
                {"suc", suc_command},
                {"sbp", sbp_command},
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
        void execCommand(const std::string& commandType)
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
