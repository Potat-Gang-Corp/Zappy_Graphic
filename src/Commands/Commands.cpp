/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Commands.cpp
*/

/**
 * @file Commands.cpp
 * @brief Contains the implementation of the commands functions
 */

#include <iostream>
#include <sstream>
#include <ostream>
#include "Map.hpp"
#include "Player.hpp"
#include "GUI.hpp"

/**
 * @brief Handle the msz command (map size)
 * @param data The data to handle
 * @param x The x size of the map
 * @param y The y size of the map
 */
void msz_command(const std::string& data)
{
    std::istringstream iss(data);
    std::string command;
    std::string x;
    std::string y;
    iss >> command >> x >> y;
    Map::getInstance()->setMapSize(std::stoi(x), std::stoi(y));
}

/**
 * @brief Handle the bct command (tile content) add the resources to the map
 * @param data The data to handle
 * @param x The x position of the tile
 * @param y The y position of the tile
 * @param food The food quantity on the tile
 * @param linemate The linemate quantity on the tile
 * @param deraumere The deraumere quantity on the tile
 * @param sibur The sibur quantity on the tile
 * @param mendiane The mendiane quantity on the tile
 * @param phiras The phiras quantity on the tile
 * @param thystame The thystame quantity on the tile
 */
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

/**
 * @brief Handle the pbc command (broadcast)
 * @param data The data to handle
 * @param player_id The id of the player who broadcasted
 * @param message The message broadcasted
 */

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

/**
 * @brief Handle the pdr command (player drop ressource)
 * @param data The data to handle
 * @param player_id The id of the player who dropped
 * @param ressource_number The ressource number dropped
 */

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

/**
 * @brief Handle the pex command (player expulsion)
 * @param data The data to handle
 * @param player_id The id of the player who got expelled
 */

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

/**
 * @brief Handle the pfk command (egg layed by player)
 * @param data The data to handle
 * @param player_id The id of the player who forked
 */

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

/**
 * @brief Handle the pgt command (player get ressource)
 * @param data The data to handle
 * @param player_id The id of the player who got the ressource
 * @param ressource_number The ressource number got
 */

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

/**
 * @brief Handle the pic command (start incantation)
 * @param data The data to handle
 * @param player_id The id of the player who started the incantation
 * @param x The x position of the player
 * @param y The y position of the player
 * @param level The level of the incantation
 */
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

/**
 * @brief Handle the pie command (end incantation)
 * @param data The data to handle
 * @param x The x position of the incantation
 * @param y The y position of the incantation
 * @param result The result of the incantation
 */

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

/**
 * @brief Handle the pin command (player inventory)
 * @param data The data to handle
 * @param player_id The id of the player
 * @param x The x position of the player
 * @param y The y position of the player
 * @param food The food quantity of the player
 * @param linemate The linemate quantity of the player
 * @param deraumere The deraumere quantity of the player
 * @param sibur The sibur quantity of the player
 * @param mendiane The mendiane quantity of the player
 * @param phiras The phiras quantity of the player
 * @param thystame The thystame quantity of the player
 */
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

/**
 * @brief Handle the plv command (player level)
 * @param data The data to handle
 * @param player_id The id of the player
 * @param level The level of the player
 */
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

/**
 * @brief Handle the pnw command (new player)
 * @param data The data to handle
 * @param player_id The id of the player
 * @param x The x position of the player
 * @param y The y position of the player
 * @param orientation The orientation of the player
 * @param level The level of the player
 * @param team_name The team name of the player
 */
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

/**
 * @brief Handle the ppo command (player position)
 * @param data The data to handle
 * @param player_id The id of the player
 * @param x The x position of the player
 * @param y The y position of the player
 * @param orientation The orientation of the player
 */
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

/**
 * @brief Handle the tna command (name of all teams)
 * @param data The data to handle
 * @param team_name The name of the team
 */

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

/**
 * @brief Handle the pdi command (player died)
 * @param data The data to handle
 * @param player_id The id of the player who died
 */

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

/**
 * @brief Handle the enw command (egg layed by player)
 * @param data The data to handle
 * @param egg_id The id of the egg
 * @param player_id The id of the player who layed the egg
 * @param x The x position of the egg
 * @param y The y position of the egg
 */
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

/**
 * @brief Handle the ebo command (egg hatched)
 * @param data The data to handle
 * @param egg_id The id of the egg
 */

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

/**
 * @brief Handle the edi command (egg died)
 * @param data The data to handle
 * @param egg_id The id of the egg
 */
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


/**
 * @brief Handle the sgt command (time unit)
 * @param data The data to handle
 * @param time_unit The time unit
 */
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

/**
 * @brief Handle the sst command (time unit modification)
 * @param data The data to handle
 * @param time_unit The time unit
 */
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

/**
 * @brief Handle the seg command (end of the game)
 * @param data The data to handle
 * @param team_name The name of the team who won
 */
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

/**
 * @brief Handle the smg command (server message)
 * @param data The data to handle
 * @param message The message
 */

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

/**
 * @brief Handle the suc command (unknown command)
 * @param data The data to handle
 */
void suc_command (const std::string &data)
{
    std::cout << "Handling suc: " << data << std::endl;
}

/**
 * @brief Handle the sbp command (bad parameter)
 * @param data The data to handle
 */
void sbp_command (const std::string &data)
{
    std::cout << "Handling sbp: " << data << std::endl;
}