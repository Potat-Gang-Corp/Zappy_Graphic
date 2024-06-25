/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** IUpdatable
*/

#pragma once

#ifndef IUPDATABLE_HPP
    #define IUPDATABLE_HPP

class IUpdatable {
    public:
        virtual void Update(float deltaTime) = 0;
        virtual ~IUpdatable() = default;
};

#endif // IUPDATABLE_HPP

