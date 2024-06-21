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
#include "PlayerManager.hpp"
#include "Commands.hpp"

void Commands::msz(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string x;
    std::string y;
    iss >> command >> x >> y;
    Map::getInstance()->setMapSize(std::stoi(x), std::stoi(y));
}

void Commands::bct(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    int x, y;
    int food, linemate, deraumere, sibur, mendiane, phiras, thystame;
    MapPtr gameMap = Map::getInstance();

    iss >> command >> x >> y >> food >> linemate >> deraumere >> sibur >> mendiane >> phiras >> thystame;

    gameMap->addResource(x, y, Resource::RessourceType::FOOD, food);
    gameMap->addResource(x, y, Resource::RessourceType::LINEMATE, linemate);
    gameMap->addResource(x, y, Resource::RessourceType::DERAUMERE, deraumere);
    gameMap->addResource(x, y, Resource::RessourceType::SIBUR, sibur);
    gameMap->addResource(x, y, Resource::RessourceType::MENDIANE, mendiane);
    gameMap->addResource(x, y, Resource::RessourceType::PHIRAS, phiras);
    gameMap->addResource(x, y, Resource::RessourceType::THYSTAME, thystame);
}

void Commands::pbc(const std::string &data)
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

void Commands::pdr(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command >> player_id >> ressource_number;
    player_id = player_id.substr(1);


    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    auto &player = playerManager->getPlayers()[std::stoi(player_id)][0];
    player.removeInventory(static_cast<Resource::RessourceType>(std::stoi(ressource_number)), 1);
    Map::getInstance()->addResource(player.getPosX(), player.getPosY(), static_cast<Resource::RessourceType>(std::stoi(ressource_number)), 1);
}

void Commands::pex(const std::string &data)
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

void Commands::pfk(const std::string &data)
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

void Commands::pgt(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command >> player_id >> ressource_number;
    player_id = player_id.substr(1);

    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    auto &player = playerManager->getPlayers()[std::stoi(player_id)][0];
    player.addInventory(static_cast<Resource::RessourceType>(std::stoi(ressource_number)), 1);
    Map::getInstance()->removeResource(player.getPosX(), player.getPosY(), static_cast<Resource::RessourceType>(std::stoi(ressource_number)), 1);
}

void Commands::pic(const std::string &data)
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

void Commands::pie(const std::string &data)
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

void Commands::pin(const std::string &data)
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

    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    auto &player = playerManager->getPlayers()[std::stoi(player_id)][0];
    player.setPosition(std::stoi(x), std::stoi(y), player.getOrientation());
    player.addInventory(Resource::RessourceType::FOOD, std::stoi(food));
    player.addInventory(Resource::RessourceType::LINEMATE, std::stoi(linemate));
    player.addInventory(Resource::RessourceType::DERAUMERE, std::stoi(deraumere));
    player.addInventory(Resource::RessourceType::SIBUR, std::stoi(sibur));
    player.addInventory(Resource::RessourceType::MENDIANE, std::stoi(mendiane));
    player.addInventory(Resource::RessourceType::PHIRAS, std::stoi(phiras));
    player.addInventory(Resource::RessourceType::THYSTAME, std::stoi(thystame));
}

void Commands::plv(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string level;
    iss >> command >> player_id >> level;
    player_id = player_id.substr(1);

    PlayerManager::getInstance()->getPlayers()[std::stoi(player_id)][0].setLevel(std::stoi(level));
}

void Commands::pnw(const std::string &data)
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
    if (Window::getInstance()->getInit() == false) {
        PlayerManager::getInstance()->addSavePlayer(player);
    } else {
        PlayerManager::getInstance()->AddPlayer(player);
    }
}

void Commands::ppo(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string x;
    std::string y;
    std::string orientation;
    iss >> command >> player_id >> x >> y >> orientation;
    player_id = player_id.substr(1);

    PlayerManager::getInstance()->getPlayers()[std::stoi(player_id)][0].setPosition(std::stoi(x), std::stoi(y), static_cast<Orientation>(std::stoi(orientation)));
}

void Commands::tna(const std::string &data)
{
    std::cout << "Handling tna: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string team_name;
    iss >> command;
    iss >> team_name;
    std::cout << "Team name: " << team_name << std::endl;
}

void Commands::pdi(const std::string &data)
{
    std::cout << "Handling pdi: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    iss >> command;
    iss >> player_id;
    std::cout << "Player id: " << player_id << std::endl;
}

void Commands::enw(const std::string &data)
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
    MapPtr map = Map::getInstance();
    map->addResource(std::stoi(x), std::stoi(y), Resource::RessourceType::EGG, 1);
    map->addEgg(std::stoi(x), std::stoi(y), std::stoi(egg_id));
}

void Commands::ebo(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command >> egg_id;
    egg_id = egg_id.substr(1);
    MapPtr map = Map::getInstance();
    map->removeResource(map->getEggX(std::stoi(egg_id)), map->getEggY(std::stoi(egg_id)),  Resource::RessourceType::EGG, 1);
    map->removeEgg(std::stoi(egg_id));
}

void Commands::edi(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command >> egg_id;
    egg_id = egg_id.substr(1);
    MapPtr map = Map::getInstance();
    map->removeResource(map->getEggX(std::stoi(egg_id)), map->getEggY(std::stoi(egg_id)),  Resource::RessourceType::EGG, 1);
    map->removeEgg(std::stoi(egg_id));
}

void Commands::sgt(const std::string &data)
{
    std::cout << "Handling sgt: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string time_unit;
    iss >> command >> time_unit;
    GUI::getInstance()->setFreq(std::stoi(time_unit));
}

void Commands::sst(const std::string &data)
{
    std::cout << "Handling sst: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string time_unit;
    iss >> command;
    iss >> time_unit;
    std::cout << "Time unit: " << time_unit << std::endl;
}

void Commands::seg(const std::string &data)
{
    std::cout << "Handling seg: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string team_name;
    iss >> command;
    iss >> team_name;
    std::cout << "Team name: " << team_name << std::endl;
}

void Commands::smg(const std::string &data)
{
    std::cout << "Handling smg: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string message;
    iss >> command;
    iss >> message;
    std::cout << "Message: " << message << std::endl;
}

void Commands::suc(const std::string &data)
{
    std::cout << "Handling suc: " << data << std::endl;
}

void Commands::sbp(const std::string &data)
{
    std::cout << "Handling sbp: " << data << std::endl;
}