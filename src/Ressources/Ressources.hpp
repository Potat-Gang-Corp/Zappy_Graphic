/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Ressources
*/

#ifndef RESSOURCES_HPP_
#define RESSOURCES_HPP_

class Ressources {
    public:
        enum class RessourceType {
            FOOD,
            LINEMATE,
            DERAUMERE,
            SIBUR,
            MENDIANE,
            PHIRAS,
            THYSTAME
        };
        Ressources() = default;
        ~Ressources() = default;
};

#endif /* !RESSOURCES_HPP_ */
