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
#include "Player.hpp"
#include "Commands.hpp"
#include "GameEngine.hpp"

void Commands::msz(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string x;
    std::string y;
    iss >> command >> x >> y;
    GameEngine::getInstance()->setMapSize(std::stof(x), std::stof(y));
}

void Commands::bct(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    int x, y;
    int food, linemate, deraumere, sibur, mendiane, phiras, thystame;
    GameEnginePtr gameMap = GameEngine::getInstance();

    iss >> command >> x >> y >> food >> linemate >> deraumere >> sibur >> mendiane >> phiras >> thystame;

    gameMap->UpdateTileResources(x, y, {food, linemate, deraumere, sibur, mendiane, phiras, thystame, 0});
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

    GameEnginePtr PlayerManager = GameEngine::getInstance();
    PlayerManager->getPlayers()[std::stoi(player_id)]->removeInventory(std::stoi(ressource_number), 1);
    PlayerManager->addResourceTail(PlayerManager->getPlayers()[std::stoi(player_id)]->getPosition().x / 10, PlayerManager->getPlayers()[std::stoi(player_id)]->getPosition().z / 10, std::stoi(ressource_number), 1);
}

void Commands::pgt(const std::string &data)
{
    // ressources collected by player
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string ressource_number;
    iss >> command >> player_id >> ressource_number;
    player_id = player_id.substr(1);

    GameEnginePtr playerManager = GameEngine::getInstance();
    playerManager->getPlayers()[std::stoi(player_id)]->addInventory(std::stoi(ressource_number), 1);
    playerManager->removeResourceTail(playerManager->getPlayers()[std::stoi(player_id)]->getPosition().x / 10, playerManager->getPlayers()[std::stoi(player_id)]->getPosition().z / 10, std::stoi(ressource_number), 1);
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

    GameEnginePtr playerManager = GameEngine::getInstance();
    auto &player = playerManager->getPlayers()[std::stoi(player_id)];
    player->addInventory(0, std::stoi(food));
    player->addInventory(1, std::stoi(linemate));
    player->addInventory(2, std::stoi(deraumere));
    player->addInventory(3, std::stoi(sibur));
    player->addInventory(4, std::stoi(mendiane));
    player->addInventory(5, std::stoi(phiras));
    player->addInventory(6, std::stoi(thystame));
}

void Commands::plv(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string level;
    iss >> command >> player_id >> level;
    player_id = player_id.substr(1);
    GameEnginePtr playerManager = GameEngine::getInstance();
    auto &player = playerManager->getPlayers()[std::stoi(player_id)];
    player->setPlayerLevel(std::stoi(level));
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
    Player player(std::stoi(player_id), player.getPosition(), player.getOrientation(), team_name, std::stoi(level));
    GameEnginePtr playerManager = GameEngine::getInstance();
    playerManager->AddPlayer(std::stoi(player_id), std::stoi(x), std::stoi(y), player.getOrientation(), team_name, std::stoi(level));
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

    GameEnginePtr PlayerManager = GameEngine::getInstance();
    auto &player = PlayerManager->getPlayers()[std::stoi(player_id)];
    player->setPosition(Vector3{(float)std::stoi(x) * 10.0f, 0.0f, (float)std::stoi(y) * 10.0f});
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

    // GameEnginePtr playerManager = GameEngine::getInstance();
    // playerManager->addResourceTail(std::stoi(x), std::stoi(y), 7, 1);

    //_inventory[]
    // MapPtr map = Map::getInstance();
    // map->addResource(std::stoi(x), std::stoi(y), Resource::RessourceType::EGG, 1);
    // map->addEgg(std::stoi(x), std::stoi(y), std::stoi(egg_id));
}

void Commands::ebo(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command >> egg_id;
    egg_id = egg_id.substr(1);

    // GameEnginePtr playerManager = GameEngine::getInstance();
    // playerManager->removeResourceTail(playerManager->getPlayers()[std::stoi(egg_id)]->getPosition().x / 10, playerManager->getPlayers()[std::stoi(egg_id)]->getPosition().z / 10, 7, 1);
//     MapPtr map = Map::getInstance();
//     map->removeResource(map->getEggX(std::stoi(egg_id)), map->getEggY(std::stoi(egg_id)),  Resource::RessourceType::EGG, 1);
//     map->removeEgg(std::stoi(egg_id));
}

void Commands::edi(const std::string &data)
{
    std::istringstream iss(data);
    std::string command;
    std::string egg_id;
    iss >> command >> egg_id;
    egg_id = egg_id.substr(1);
    // MapPtr map = Map::getInstance();
    // map->removeResource(map->getEggX(std::stoi(egg_id)), map->getEggY(std::stoi(egg_id)),  Resource::RessourceType::EGG, 1);
    // map->removeEgg(std::stoi(egg_id));
}

void Commands::sgt(const std::string &data)
{
    std::cout << "Handling sgt: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string time_unit;
    iss >> command >> time_unit;
    // GUI::getInstance()->setFreq(std::stoi(time_unit));
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