/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Commands.cpp
*/

#include <iostream>
#include <sstream>
#include <ostream>
#include "Map.hpp"
#include "Player.hpp"
#include "GUI.hpp"

void msz_command(const std::string& data)
{
    std::istringstream iss(data);
    std::string command;
    std::string x;
    std::string y;
    iss >> command >> x >> y;
    Map::getInstance()->setMapSize(std::stoi(x), std::stoi(y));
}

void bct_command(const std::string& data)
{
    std::istringstream iss(data);
    std::string command;
    int x, y;
    int food, linemate, deraumere, sibur, mendiane, phiras, thystame;
    Map *gameMap = Map::getInstance();

    iss >> command >> x >> y >> food >> linemate >> deraumere >> sibur >> mendiane >> phiras >> thystame;

    gameMap->addResource(x, y, Ressources::RessourceType::FOOD, food);
    gameMap->addResource(x, y, Ressources::RessourceType::LINEMATE, linemate);
    gameMap->addResource(x, y, Ressources::RessourceType::DERAUMERE, deraumere);
    gameMap->addResource(x, y, Ressources::RessourceType::SIBUR, sibur);
    gameMap->addResource(x, y, Ressources::RessourceType::MENDIANE, mendiane);
    gameMap->addResource(x, y, Ressources::RessourceType::PHIRAS, phiras);
    gameMap->addResource(x, y, Ressources::RessourceType::THYSTAME, thystame);
}

void pbc_command(const std::string& data)
{
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

void pdr_command(const std::string& data)
{
    //player drop an object
    std::cout << "Handling pdr: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command;
    iss >> player_id;
    iss >> ressource_number;
    std::cout << "Player id: " << player_id << std::endl;
    std::cout << "Ressource number: " << ressource_number << std::endl;
}

void pex_command(const std::string& data)
{
    //explusion player id
    std::cout << "Handling pex: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    iss >> command;
    iss >> player_id;
    std::cout << "Player id: " << player_id << std::endl;
}

void pfk_command(const std::string& data)
{
    //egg layed by player id
    std::cout << "Handling pfk: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    iss >> command;
    iss >> player_id;
    std::cout << "Player id: " << player_id << std::endl;
}

void pgt_command(const std::string& data)
{
    //player take an object
    std::cout << "Handling pgt: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command;
    iss >> player_id;
    iss >> ressource_number;
    std::cout << "Player id: " << player_id << std::endl;
    std::cout << "Ressource number: " << ressource_number << std::endl;
}

void pic_command(const std::string& data)
{
    //player id, x, y, level
    std::cout << "Handling pic: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string x;
    std::string y;
    std::string level;
    std::string player_id;
    iss >> command;
    iss >> x;
    iss >> y;
    iss >> level;
    iss >> player_id;
    std::cout << "X: " << x << "Y: " << y << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Player id: " << player_id << std::endl;
}

void pie_command(const std::string& data)
{
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

void pin_command(const std::string& data)
{
    std::cout << "Handling pin: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
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
    iss >> player_id;
    iss >> x;
    iss >> y;
    iss >> food;
    iss >> linemate;
    iss >> deraumere;
    iss >> sibur;
    iss >> mendiane;
    iss >> phiras;
    iss >> thystame;
    std::cout << "Player id: " << player_id << std::endl;
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

void plv_command(const std::string& data)
{
    std::cout << "Handling plv: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string level;
    iss >> command;
    iss >> player_id;
    iss >> level;
    std::cout << "Player id: " << player_id << std::endl;
    std::cout << "Level: " << level << std::endl;
}

void pnw_command(const std::string& data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string x;
    std::string y;
    std::string orientation;
    std::string level;
    std::string team_name;
    iss >> command;
    iss >> player_id;
    iss >> x;
    iss >> y;
    iss >> orientation;
    iss >> level;
    iss >> team_name;
    Player player(std::stoi(player_id), std::stoi(x), std::stoi(y), team_name, static_cast<Orientation>(std::stoi(orientation)), {}, std::stoi(level));
    GUI::getInstance()->AddPlayer(player);
}

void ppo_command(const std::string& data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string x;
    std::string y;
    std::string orientation;
    iss >> command >> player_id >> x >> y >> orientation;
    player_id = player_id.substr(1);

    GUI::getInstance()->getPlayers()[std::stoi(player_id)][0].setPosition(std::stoi(x), std::stoi(y), static_cast<Orientation>(std::stoi(orientation)));
}

void tna_command(const std::string& data)
{
    std::cout << "Handling tna: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string team_name;
    iss >> command;
    iss >> team_name;
    std::cout << "Team name: " << team_name << std::endl;
}

void pdi_command(const std::string& data)
{
    std::cout << "Handling pdi: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    iss >> command;
    iss >> player_id;
    std::cout << "Player id: " << player_id << std::endl;
}

void enw_command(const std::string &data)
{
    std::cout << "Handling enw: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    std::string player_id;
    std::string x;
    std::string y;
    iss >> command;
    iss >> egg_id;
    iss >> player_id;
    iss >> x;
    iss >> y;
    std::cout << "Egg id: " << egg_id << std::endl;
    std::cout << "Player id: " << player_id << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
}

void ebo_command(const std::string &data)
{
    std::cout << "Handling ebo: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command;
    iss >> egg_id;
    std::cout << "Egg id: " << egg_id << std::endl;
}

void edi_command(const std::string &data)
{
    std::cout << "Handling edi: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command;
    iss >> egg_id;
    std::cout << "Egg id: " << egg_id << std::endl;
}

void sgt_command (const std::string &data)
{
    std::cout << "Handling sgt: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string time_unit;
    iss >> command;
    iss >> time_unit;
    std::cout << "Time unit: " << time_unit << std::endl;
}

void sst_command (const std::string &data)
{
    std::cout << "Handling sst: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string time_unit;
    iss >> command;
    iss >> time_unit;
    std::cout << "Time unit: " << time_unit << std::endl;
}

void seg_command (const std::string &data)
{
    std::cout << "Handling seg: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string team_name;
    iss >> command;
    iss >> team_name;
    std::cout << "Team name: " << team_name << std::endl;
}

void smg_command (const std::string &data)
{
    std::cout << "Handling smg: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string message;
    iss >> command;
    iss >> message;
    std::cout << "Message: " << message << std::endl;
}

void suc_command (const std::string &data)
{
    std::cout << "Handling suc: " << data << std::endl;
}

void sbp_command (const std::string &data)
{
    std::cout << "Handling sbp: " << data << std::endl;
}