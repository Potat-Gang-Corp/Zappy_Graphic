/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Island
*/

#ifndef ISLAND_HPP_
#define ISLAND_HPP_

    #include "AModels.hpp"

class Island : public AModels {
    public:
        Island(int random, int x, int y);
        void onHover() override final;

    private:
};

#endif /* !ISLAND_HPP_ */
