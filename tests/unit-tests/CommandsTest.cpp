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
    MapPtr map = Map::getInstance();

    std::string data = "msz 10 20";
    msz_command(data);

    cr_assert_eq(map->getMapSizeX(), 10, "Expected map size X to be 10, but was %d", map->getMapSizeX());
    cr_assert_eq(map->getMapSizeY(), 20, "Expected map size Y to be 20, but was %d", map->getMapSizeY());
}

Test(bct_command, update_resources)
{
    MapPtr map = Map::getInstance();

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
    GuiPtr gui = GUI::getInstance();
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

Test(plv_command, update_player_level)
{
    GuiPtr gui = GUI::getInstance();
    Player player(1, 0, 0, "TeamA", NORTH, {}, 7);
    gui->getPlayers()[1].push_back(player);

    std::string data = "plv #1 5";
    plv_command(data);

    Player updatedPlayer = gui->getPlayers()[1][0];
    cr_assert_eq(updatedPlayer.getLevel(), 5, "Expected level to be 5, but was %d", updatedPlayer.getLevel());
}


Test(pin_command, update_player_inventory)
{
    GuiPtr gui = GUI::getInstance();
    std::map<Ressources::RessourceType, int> inventory = {
        {Ressources::RessourceType::FOOD, 0},
        {Ressources::RessourceType::LINEMATE, 0},
        {Ressources::RessourceType::DERAUMERE, 0},
        {Ressources::RessourceType::SIBUR, 0},
        {Ressources::RessourceType::MENDIANE, 0},
        {Ressources::RessourceType::PHIRAS, 0},
        {Ressources::RessourceType::THYSTAME, 0}
    };
    Player player(1, 0, 0, "TeamA", NORTH, inventory);
    gui->getPlayers()[1].push_back(player);

    std::string data = "pin #1 10 20 5 4 3 2 1 0 6";
    pin_command(data);

    Player updatedPlayer = gui->getPlayers()[1][0];
    const auto& updatedInventory = updatedPlayer.getInventory();
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::FOOD), 5, "Expected FOOD quantity to be 5, but was %d", updatedInventory.at(Ressources::RessourceType::FOOD));
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::LINEMATE), 4, "Expected LINEMATE quantity to be 4, but was %d", updatedInventory.at(Ressources::RessourceType::LINEMATE));
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::DERAUMERE), 3, "Expected DERAUMERE quantity to be 3, but was %d", updatedInventory.at(Ressources::RessourceType::DERAUMERE));
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::SIBUR), 2, "Expected SIBUR quantity to be 2, but was %d", updatedInventory.at(Ressources::RessourceType::SIBUR));
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::MENDIANE), 1, "Expected MENDIANE quantity to be 1, but was %d", updatedInventory.at(Ressources::RessourceType::MENDIANE));
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::PHIRAS), 0, "Expected PHIRAS quantity to be 0, but was %d", updatedInventory.at(Ressources::RessourceType::PHIRAS));
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::THYSTAME), 6, "Expected THYSTAME quantity to be 6, but was %d", updatedInventory.at(Ressources::RessourceType::THYSTAME));
}

Test(pdr_command, remove_inventory_and_add_to_map)
{
    GuiPtr gui = GUI::getInstance();
    std::map<Ressources::RessourceType, int> inventory = {
        {Ressources::RessourceType::FOOD, 5},
        {Ressources::RessourceType::LINEMATE, 3},
        {Ressources::RessourceType::DERAUMERE, 2},
        {Ressources::RessourceType::SIBUR, 4},
        {Ressources::RessourceType::MENDIANE, 1},
        {Ressources::RessourceType::PHIRAS, 0},
        {Ressources::RessourceType::THYSTAME, 6}
    };
    Player player(1, 10, 20, "TeamA", NORTH, inventory);
    gui->getPlayers()[1].push_back(player);

    std::string data = "pdr #1 2";
    pdr_command(data);

    Player updatedPlayer = gui->getPlayers()[1][0];
    const auto& updatedInventory = updatedPlayer.getInventory();
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::DERAUMERE), 1, "Expected DERAUMERE quantity to be 1, but was %d", updatedInventory.at(Ressources::RessourceType::DERAUMERE));

    MapPtr map = Map::getInstance();
    const auto& resourcesAtPos = map->getResources(10, 20);
    cr_assert_eq(resourcesAtPos.at(Ressources::RessourceType::DERAUMERE), 1, "Expected DERAUMERE quantity on the map to be 1, but was %d", resourcesAtPos.at(Ressources::RessourceType::DERAUMERE));
}

Test(pgt_command, add_inventory_and_remove_from_map)
{
    GuiPtr gui = GUI::getInstance();
    std::map<Ressources::RessourceType, int> inventory = {
        {Ressources::RessourceType::FOOD, 5},
        {Ressources::RessourceType::LINEMATE, 3},
        {Ressources::RessourceType::DERAUMERE, 2},
        {Ressources::RessourceType::SIBUR, 4},
        {Ressources::RessourceType::MENDIANE, 1},
        {Ressources::RessourceType::PHIRAS, 0},
        {Ressources::RessourceType::THYSTAME, 6}
    };
    Player player(1, 10, 20, "TeamA", NORTH, inventory);
    gui->getPlayers()[1].push_back(player);

    MapPtr map = Map::getInstance();
    map->addResource(10, 20, Ressources::RessourceType::DERAUMERE, 1);

    std::string data = "pgt #1 2";
    pgt_command(data);

    Player updatedPlayer = gui->getPlayers()[1][0];
    const auto& updatedInventory = updatedPlayer.getInventory();
    cr_assert_eq(updatedInventory.at(Ressources::RessourceType::DERAUMERE), 3, "Expected DERAUMERE quantity to be 3, but was %d", updatedInventory.at(Ressources::RessourceType::DERAUMERE));

    const auto& resourcesAtPos = map->getResources(10, 20);
    cr_assert_eq(resourcesAtPos.find(Ressources::RessourceType::DERAUMERE), resourcesAtPos.end(), "Expected no DERAUMERE on the map, but found some.");
}

Test(enw_command, add_egg_and_resource_to_map)
{
    GuiPtr gui = GUI::getInstance();
    Player player(1, 0, 0, "TeamA", NORTH, {});
    gui->getPlayers()[1].push_back(player);

    MapPtr map = Map::getInstance();

    std::string data = "enw #123 #1 10 20";
    enw_command(data);

    const auto& resources = map->getResources(10, 20);
    auto it = resources.find(Ressources::RessourceType::EGG);
    cr_assert(it != resources.end(), "Expected to find EGG at (10, 20)");
    cr_assert_eq(it->second, 1, "Expected quantity of EGG to be 1, but was %d", it->second);

    cr_assert_eq(map->getEggX(123), 10, "Expected egg X position to be 10, but was %d", map->getEggX(123));
    cr_assert_eq(map->getEggY(123), 20, "Expected egg Y position to be 20, but was %d", map->getEggY(123));
}

Test(ebo_command, remove_egg_and_resource_from_map)
{
    MapPtr map = Map::getInstance();
    map->addEgg(10, 20, 123);
    map->addResource(10, 20, Ressources::RessourceType::EGG, 1);

    std::string data = "ebo #123";
    ebo_command(data);

    const auto& resources = map->getResources(10, 20);
    auto it = resources.find(Ressources::RessourceType::EGG);
    cr_assert(it == resources.end(), "Expected to not find EGG at (10, 20)");
    
    cr_assert_throw(map->getEggX(123), std::out_of_range, "Expected egg 123 to be removed");
}

Test(edi_command, remove_egg_and_resource_from_map)
{
    MapPtr map = Map::getInstance();
    map->addEgg(10, 20, 123);
    map->addResource(10, 20, Ressources::RessourceType::EGG, 1);

    std::string data = "edi #123";
    edi_command(data);

    const auto& resources = map->getResources(10, 20);
    auto it = resources.find(Ressources::RessourceType::EGG);
    cr_assert(it == resources.end(), "Expected to not find EGG at (10, 20)");

    cr_assert_throw(map->getEggX(123), std::out_of_range, "Expected egg 123 to be removed");
}
