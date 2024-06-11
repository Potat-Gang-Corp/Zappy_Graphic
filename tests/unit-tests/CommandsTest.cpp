/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Player
*/

#include "Player.hpp"
#include "GUI.hpp"
#include "Commands.hpp"
#include <criterion/criterion.h>

Test(ppo_command, update_player_position)
{
    GUI* gui = GUI::getInstance();
    std::map<Ressources::RessourceType, int> inventory;
    Player player(1, 0, 0, "TeamA", NORTH, inventory);
    gui->getPlayers()[1].push_back(player);

    std::string data = "ppo #1 10 20 2";
    ppo_command(data);

    Player updatedPlayer = gui->getPlayers()[1][0];
    cr_assert_eq(updatedPlayer.getPosX(), 10, "Expected X position to be 10, but was %d", updatedPlayer.getPosX());
    cr_assert_eq(updatedPlayer.getPosY(), 20, "Expected Y position to be 20, but was %d", updatedPlayer.getPosY());
    cr_assert_eq(updatedPlayer.getOrientation(), SOUTH, "Expected orientation to be SOUTH, but was %d", updatedPlayer.getOrientation());
}
