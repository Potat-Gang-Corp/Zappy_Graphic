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
    MapPtr gameMap = Map::getInstance();

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
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command >> player_id >> ressource_number;
    player_id = player_id.substr(1);

    GuiPtr gui = GUI::getInstance();
    auto& player = gui->getPlayers()[std::stoi(player_id)][0];
    player.removeInventory(static_cast<Ressources::RessourceType>(std::stoi(ressource_number)), 1);
    Map::getInstance()->addResource(player.getPosX(), player.getPosY(), static_cast<Ressources::RessourceType>(std::stoi(ressource_number)), 1);
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
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command >> player_id >> ressource_number;
    player_id = player_id.substr(1);

    GuiPtr gui = GUI::getInstance();
    auto& player = gui->getPlayers()[std::stoi(player_id)][0];
    player.addInventory(static_cast<Ressources::RessourceType>(std::stoi(ressource_number)), 1);
    Map::getInstance()->removeResource(player.getPosX(), player.getPosY(), static_cast<Ressources::RessourceType>(std::stoi(ressource_number)), 1);
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
    iss >> command >> player_id >> x >> y >> food >> linemate >> deraumere >> sibur >> mendiane >> phiras >> thystame;
    player_id = player_id.substr(1);

    GuiPtr gui = GUI::getInstance();
    auto& player = gui->getPlayers()[std::stoi(player_id)][0];
    player.setPosition(std::stoi(x), std::stoi(y), player.getOrientation());
    player.addInventory(Ressources::RessourceType::FOOD, std::stoi(food));
    player.addInventory(Ressources::RessourceType::LINEMATE, std::stoi(linemate));
    player.addInventory(Ressources::RessourceType::DERAUMERE, std::stoi(deraumere));
    player.addInventory(Ressources::RessourceType::SIBUR, std::stoi(sibur));
    player.addInventory(Ressources::RessourceType::MENDIANE, std::stoi(mendiane));
    player.addInventory(Ressources::RessourceType::PHIRAS, std::stoi(phiras));
    player.addInventory(Ressources::RessourceType::THYSTAME, std::stoi(thystame));
}

void plv_command(const std::string& data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string level;
    iss >> command >> player_id >> level;
    player_id = player_id.substr(1);

    GUI::getInstance()->getPlayers()[std::stoi(player_id)][0].setLevel(std::stoi(level));
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
    iss >> command >> player_id >> x >> y >> orientation >> level >> team_name;
    player_id = player_id.substr(1);
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
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    std::string player_id;
    std::string x;
    std::string y;
    iss >> command >> egg_id >> player_id >> x >> y;
    player_id = player_id.substr(1);
    egg_id = egg_id.substr(1);
    GuiPtr gui = GUI::getInstance();
    auto& player = gui->getPlayers()[std::stoi(player_id)][0];
    MapPtr map = Map::getInstance();
    map->addResource(std::stoi(x), std::stoi(y), Ressources::RessourceType::EGG, 1);
    map->addEgg(std::stoi(x), std::stoi(y), std::stoi(egg_id));
}

void ebo_command(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command >> egg_id;
    egg_id = egg_id.substr(1);
    MapPtr map = Map::getInstance();
    map->removeResource(map->getEggX(std::stoi(egg_id)), map->getEggY(std::stoi(egg_id)),  Ressources::RessourceType::EGG, 1);
    map->removeEgg(std::stoi(egg_id));
}

void edi_command(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command >> egg_id;
    egg_id = egg_id.substr(1);
    MapPtr map = Map::getInstance();
    map->removeResource(map->getEggX(std::stoi(egg_id)), map->getEggY(std::stoi(egg_id)),  Ressources::RessourceType::EGG, 1);
    map->removeEgg(std::stoi(egg_id));
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