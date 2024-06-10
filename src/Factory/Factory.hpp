/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Factory
*/

#pragma once

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    #include <unordered_map>
    #include <memory>
    #include "Msz.hpp"
    #include "Bct.hpp"
    #include "Tna.hpp"
    #include "Pnw.hpp"
    #include "Ppo.hpp"
    #include "Plv.hpp"
    #include "Pin.hpp"
    #include "Pex.hpp"
    #include "Pbc.hpp"
    #include "Pic.hpp"
    #include "Pie.hpp"
    #include "Pfk.hpp"
    #include "Pdr.hpp"

class CommandFactory {
    public:
        static CommandFactory *getInstance()
        {
            static CommandFactory instance;
            return &instance;
        }

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



                // {"bct", std::make_shared<BctCommand>()},
                // {"tna", std::make_shared<TnaCommand>()},
                // {"pnw", std::make_shared<PnwCommand>()},
                // {"ppo", std::make_shared<PpoCommand>()},
                // {"plv", std::make_shared<PlvCommand>()}, 
                // {"pin", std::make_shared<PinCommand>()},
                // {"pex", std::make_shared<PexCommand>()},
                // {"pbc", std::make_shared<PbcCommand>()},
                // {"pic", std::make_shared<PicCommand>()},
                // {"pie", std::make_shared<PieCommand>()},
                // {"pfk", std::make_shared<PfkCommand>()},
                // {"pdr", std::make_shared<PdrCommand>()},


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
void msz_command(const std::string& data);
#endif /* !FACTORY_HPP_ */
