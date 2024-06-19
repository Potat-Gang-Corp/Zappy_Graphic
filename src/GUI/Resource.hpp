/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Ressources
*/

#pragma once

#ifndef RESSOURCES_HPP_
    #define RESSOURCES_HPP_

    #include "AModels.hpp"
    #include <array>

class Resource : public AModels {
    public:
        enum class RessourceType {
            FOOD,
            LINEMATE,
            DERAUMERE,
            SIBUR,
            MENDIANE,
            PHIRAS,
            THYSTAME,
            EGG,
            COUNT
        };
        Resource() = default;
        static std::shared_ptr<Resource> getInstance() {
            static std::shared_ptr<Resource> instance(new Resource());
            return instance;
        }
        Resource(Resource::RessourceType type);
        constexpr std::array<RessourceType, static_cast<size_t>(RessourceType::COUNT)> allRessourceTypes() {
            std::array<RessourceType, static_cast<size_t>(RessourceType::COUNT)> values = {
                RessourceType::FOOD,
                RessourceType::LINEMATE,
                RessourceType::DERAUMERE,
                RessourceType::SIBUR,
                RessourceType::MENDIANE,
                RessourceType::PHIRAS,
                RessourceType::THYSTAME,
                RessourceType::EGG
            };
            return values;
        }
};

#endif /* !RESSOURCES_HPP_ */
