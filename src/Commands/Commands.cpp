/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** Commands.cpp
*/

#include <iostream>
#include <sstream>
#include <ostream>

void msz_command(const std::string& data)
{
    std::cout << "Handling msz: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string x;
    std::string y;
    iss >> command;
    iss >> x;
    iss >> y;
    std::cout << "X: " << x << "Y: " << y << std::endl;
}

void bct_command(const std::string& data)
{
    std::cout << "Handling bct: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
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
    iss >> x;
    iss >> y;
    iss >> food;
    iss >> linemate;
    iss >> deraumere;
    iss >> sibur;
    iss >> mendiane;
    iss >> phiras;
    iss >> thystame;
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

void pbc_command(const std::string& data)
{
    //broadcast player id message
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
    std::cout << "Handling pnw: " << data << std::endl;
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
    std::cout << "Player id: " << player_id << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "Orientation: " << orientation << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Team name: " << team_name << std::endl;
}

void ppo_command(const std::string& data)
{
    std::cout << "Handling ppo: " << data << std::endl;
    std::istringstream iss(data);
    std::string command;
    std::string player_id;
    std::string x;
    std::string y;
    std::string orientation;
    iss >> command;
    iss >> player_id;
    iss >> x;
    iss >> y;
    iss >> orientation;
    std::cout << "Player id: " << player_id << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "Orientation: " << orientation << std::endl;
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
