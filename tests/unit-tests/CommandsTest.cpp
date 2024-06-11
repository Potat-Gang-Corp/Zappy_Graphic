/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Player
*/

#include "Player.hpp"
#include "GUI.hpp"
#include "Commands.hpp"
#include "Map.hpp"
#include <criterion/criterion.h>

Test(msz_command, update_map_size)
{
    Map* map = Map::getInstance();

    std::string data = "msz 10 20";
    msz_command(data);

    cr_assert_eq(map->getMapSizeX(), 10, "Expected map size X to be 10, but was %d", map->getMapSizeX());
    cr_assert_eq(map->getMapSizeY(), 20, "Expected map size Y to be 20, but was %d", map->getMapSizeY());
}

Test(bct_command, update_resources)
{
    Map* map = Map::getInstance();

    std::string data = "bct 5 5 10 5 3 2 4 1 6";
    bct_command(data);

    ResourceMap resources = map->getResources(5, 5);

    cr_assert_eq(resources[Ressources::RessourceType::FOOD], 10, "Expected 10 FOOD, but got %d", resources[Ressources::RessourceType::FOOD]);
    cr_assert_eq(resources[Ressources::RessourceType::LINEMATE], 5, "Expected 5 LINEMATE, but got %d", resources[Ressources::RessourceType::LINEMATE]);
    cr_assert_eq(resources[Ressources::RessourceType::DERAUMERE], 3, "Expected 3 DERAUMERE, but got %d", resources[Ressources::RessourceType::DERAUMERE]);
    cr_assert_eq(resources[Ressources::RessourceType::SIBUR], 2, "Expected 2 SIBUR, but got %d", resources[Ressources::RessourceType::SIBUR]);
    cr_assert_eq(resources[Ressources::RessourceType::MENDIANE], 4, "Expected 4 MENDIANE, but got %d", resources[Ressources::RessourceType::MENDIANE]);
    cr_assert_eq(resources[Ressources::RessourceType::PHIRAS], 1, "Expected 1 PHIRAS, but got %d", resources[Ressources::RessourceType::PHIRAS]);
    cr_assert_eq(resources[Ressources::RessourceType::THYSTAME], 6, "Expected 6 THYSTAME, but got %d", resources[Ressources::RessourceType::THYSTAME]);
}

Test(ppo_command, update_player_position)
{
    GUI* gui = GUI::getInstance();
    std::map<Ressources::RessourceType, int> inventory;
    Player player(1, 0, 0, "TeamA", NORTH, inventory, 1);
    gui->AddPlayer(player);

    std::string data = "ppo #1 25 20 2";
    ppo_command(data);

    auto& players = gui->getPlayers();
    Player& updatedPlayer = players[1][0];
    cr_assert_eq(updatedPlayer.getPosX(), 25, "Expected X position to be 25, but was %d", updatedPlayer.getPosX());
    cr_assert_eq(updatedPlayer.getPosY(), 20, "Expected Y position to be 20, but was %d", updatedPlayer.getPosY());
    cr_assert_eq(updatedPlayer.getOrientation(), EAST, "Expected orientation to be SOUTH, but was %d", updatedPlayer.getOrientation());
}
