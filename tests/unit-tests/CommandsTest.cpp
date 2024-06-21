/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Player
*/

#include "Player.hpp"
#include "Commands.hpp"
#include "Window.hpp"
#include "PlayerManager.hpp"
#include "Map.hpp"
#include <criterion/criterion.h>

Test(msz_command, update_map_size)
{
    MapPtr map = Map::getInstance();

    std::string data = "msz 10 20\n";
    msz_command(data);

    cr_assert_eq(map->getMapSizeX(), 10, "Expected map size X to be 10, but was %d", map->getMapSizeX());
    cr_assert_eq(map->getMapSizeY(), 20, "Expected map size Y to be 20, but was %d", map->getMapSizeY());
}

Test(bct_command, update_resources)
{
    MapPtr map = Map::getInstance();

    std::string data = "bct 5 5 10 5 3 2 4 1 6\n";
    bct_command(data);

    ResourceMap resources = map->getResources(5, 5);

    cr_assert_eq(resources[Resource::RessourceType::FOOD], 10, "Expected 10 FOOD, but got %d", resources[Resource::RessourceType::FOOD]);
    cr_assert_eq(resources[Resource::RessourceType::LINEMATE], 5, "Expected 5 LINEMATE, but got %d", resources[Resource::RessourceType::LINEMATE]);
    cr_assert_eq(resources[Resource::RessourceType::DERAUMERE], 3, "Expected 3 DERAUMERE, but got %d", resources[Resource::RessourceType::DERAUMERE]);
    cr_assert_eq(resources[Resource::RessourceType::SIBUR], 2, "Expected 2 SIBUR, but got %d", resources[Resource::RessourceType::SIBUR]);
    cr_assert_eq(resources[Resource::RessourceType::MENDIANE], 4, "Expected 4 MENDIANE, but got %d", resources[Resource::RessourceType::MENDIANE]);
    cr_assert_eq(resources[Resource::RessourceType::PHIRAS], 1, "Expected 1 PHIRAS, but got %d", resources[Resource::RessourceType::PHIRAS]);
    cr_assert_eq(resources[Resource::RessourceType::THYSTAME], 6, "Expected 6 THYSTAME, but got %d", resources[Resource::RessourceType::THYSTAME]);
}

Test(plv_command, update_player_level)
{
    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    Player player(1, 0, 0, "TeamA", NORTH, {}, 7);
    playerManager->getPlayers()[1].push_back(player);

    std::string data = "plv #1 5\n";
    plv_command(data);

    Player updatedPlayer = playerManager->getPlayers()[1][0];
    cr_assert_eq(updatedPlayer.getLevel(), 5, "Expected level to be 5, but was %d", updatedPlayer.getLevel());
}


Test(pin_command, update_player_inventory)
{
    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    std::map<Resource::RessourceType, int> inventory = {
        {Resource::RessourceType::FOOD, 0},
        {Resource::RessourceType::LINEMATE, 0},
        {Resource::RessourceType::DERAUMERE, 0},
        {Resource::RessourceType::SIBUR, 0},
        {Resource::RessourceType::MENDIANE, 0},
        {Resource::RessourceType::PHIRAS, 0},
        {Resource::RessourceType::THYSTAME, 0}
    };
    Player player(1, 0, 0, "TeamA", NORTH, inventory);
    playerManager->getPlayers()[1].push_back(player);

    std::string data = "pin #1 10 20 5 4 3 2 1 0 6\n";
    pin_command(data);

    Player updatedPlayer = playerManager->getPlayers()[1][0];
    const auto& updatedInventory = updatedPlayer.getInventory();
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::FOOD), 5, "Expected FOOD quantity to be 5, but was %d", updatedInventory.at(Resource::RessourceType::FOOD));
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::LINEMATE), 4, "Expected LINEMATE quantity to be 4, but was %d", updatedInventory.at(Resource::RessourceType::LINEMATE));
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::DERAUMERE), 3, "Expected DERAUMERE quantity to be 3, but was %d", updatedInventory.at(Resource::RessourceType::DERAUMERE));
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::SIBUR), 2, "Expected SIBUR quantity to be 2, but was %d", updatedInventory.at(Resource::RessourceType::SIBUR));
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::MENDIANE), 1, "Expected MENDIANE quantity to be 1, but was %d", updatedInventory.at(Resource::RessourceType::MENDIANE));
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::PHIRAS), 0, "Expected PHIRAS quantity to be 0, but was %d", updatedInventory.at(Resource::RessourceType::PHIRAS));
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::THYSTAME), 6, "Expected THYSTAME quantity to be 6, but was %d", updatedInventory.at(Resource::RessourceType::THYSTAME));
}

Test(pdr_command, remove_inventory_and_add_to_map)
{
    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    std::map<Resource::RessourceType, int> inventory = {
        {Resource::RessourceType::FOOD, 5},
        {Resource::RessourceType::LINEMATE, 3},
        {Resource::RessourceType::DERAUMERE, 2},
        {Resource::RessourceType::SIBUR, 4},
        {Resource::RessourceType::MENDIANE, 1},
        {Resource::RessourceType::PHIRAS, 0},
        {Resource::RessourceType::THYSTAME, 6}
    };
    Player player(1, 10, 20, "TeamA", NORTH, inventory);
    playerManager->getPlayers()[1].push_back(player);

    std::string data = "pdr #1 2\n";
    pdr_command(data);

    Player updatedPlayer = playerManager->getPlayers()[1][0];
    const auto& updatedInventory = updatedPlayer.getInventory();
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::DERAUMERE), 1, "Expected DERAUMERE quantity to be 1, but was %d", updatedInventory.at(Resource::RessourceType::DERAUMERE));

    MapPtr map = Map::getInstance();
    const auto& resourcesAtPos = map->getResources(10, 20);
    cr_assert_eq(resourcesAtPos.at(Resource::RessourceType::DERAUMERE), 1, "Expected DERAUMERE quantity on the map to be 1, but was %d", resourcesAtPos.at(Resource::RessourceType::DERAUMERE));
}

Test(pgt_command, add_inventory_and_remove_from_map)
{
    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    std::map<Resource::RessourceType, int> inventory = {
        {Resource::RessourceType::FOOD, 5},
        {Resource::RessourceType::LINEMATE, 3},
        {Resource::RessourceType::DERAUMERE, 2},
        {Resource::RessourceType::SIBUR, 4},
        {Resource::RessourceType::MENDIANE, 1},
        {Resource::RessourceType::PHIRAS, 0},
        {Resource::RessourceType::THYSTAME, 6}
    };
    Player player(1, 10, 20, "TeamA", NORTH, inventory);
    playerManager->getPlayers()[1].push_back(player);

    MapPtr map = Map::getInstance();
    map->addResource(10, 20, Resource::RessourceType::DERAUMERE, 1);

    std::string data = "pgt #1 2\n";
    pgt_command(data);

    Player updatedPlayer = playerManager->getPlayers()[1][0];
    const auto& updatedInventory = updatedPlayer.getInventory();
    cr_assert_eq(updatedInventory.at(Resource::RessourceType::DERAUMERE), 3, "Expected DERAUMERE quantity to be 3, but was %d", updatedInventory.at(Resource::RessourceType::DERAUMERE));

    const auto& resourcesAtPos = map->getResources(10, 20);
    cr_assert_eq(resourcesAtPos.find(Resource::RessourceType::DERAUMERE), resourcesAtPos.end(), "Expected no DERAUMERE on the map, but found some.");
}

Test(enw_command, add_egg_and_resource_to_map)
{
    PlayerManagerPtr playerManager = PlayerManager::getInstance();
    Player player(1, 0, 0, "TeamA", NORTH, {});
    playerManager->getPlayers()[1].push_back(player);
    MapPtr map = Map::getInstance();

    std::string data = "enw #123 #1 10 20\n";
    enw_command(data);

    const auto& resources = map->getResources(10, 20);
    auto it = resources.find(Resource::RessourceType::EGG);
    cr_assert(it != resources.end(), "Expected to find EGG at (10, 20)");
    cr_assert_eq(it->second, 1, "Expected quantity of EGG to be 1, but was %d", it->second);

    cr_assert_eq(map->getEggX(123), 10, "Expected egg X position to be 10, but was %d", map->getEggX(123));
    cr_assert_eq(map->getEggY(123), 20, "Expected egg Y position to be 20, but was %d", map->getEggY(123));
}

Test(ebo_command, remove_egg_and_resource_from_map)
{
    MapPtr map = Map::getInstance();
    map->addEgg(10, 20, 123);
    map->addResource(10, 20, Resource::RessourceType::EGG, 1);

    std::string data = "ebo #123\n";
    ebo_command(data);

    const auto& resources = map->getResources(10, 20);
    auto it = resources.find(Resource::RessourceType::EGG);
    cr_assert(it == resources.end(), "Expected to not find EGG at (10, 20)");
    
    cr_assert_throw(map->getEggX(123), std::out_of_range, "Expected egg 123 to be removed");
}

Test(edi_command, remove_egg_and_resource_from_map)
{
    MapPtr map = Map::getInstance();
    map->addEgg(10, 20, 123);
    map->addResource(10, 20, Resource::RessourceType::EGG, 1);

    std::string data = "edi #123\n";
    edi_command(data);

    const auto& resources = map->getResources(10, 20);
    auto it = resources.find(Resource::RessourceType::EGG);
    cr_assert(it == resources.end(), "Expected to not find EGG at (10, 20)");

    cr_assert_throw(map->getEggX(123), std::out_of_range, "Expected egg 123 to be removed");
}

Test(pnw_command, add_new_player_to_gui)
{
    PlayerManagerPtr playerManager = PlayerManager::getInstance();

    std::string data = "pnw #1 10 20 2 3 TeamA\n";
    pnw_command(data);

    auto& player = playerManager->getPlayersSave()[0];
    cr_assert_eq(player.getNumber(), 1, "Expected player ID to be 1, but was %d", player.getNumber());
    cr_assert_eq(player.getPosX(), 10 * 10, "Expected player X position to be 10, but was %d", player.getPosX());
    cr_assert_eq(player.getPosY(), 20 * 10, "Expected player Y position to be 20, but was %d", player.getPosY());
    cr_assert_eq(player.getOrientation(), static_cast<Orientation>(2), "Expected player orientation to be 2, but was %d", static_cast<int>(player.getOrientation()));
    cr_assert_eq(player.getLevel(), 3, "Expected player level to be 3, but was %d", player.getLevel());
    cr_assert_str_eq(player.getTeamName().c_str(), "TeamA", "Expected player team name to be TeamA, but was %s", player.getTeamName().c_str());
}

