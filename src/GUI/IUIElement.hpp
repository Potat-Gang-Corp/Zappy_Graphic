/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** IUIElement
*/

#pragma once

#ifndef IUIELEMENT_HPP_
    #define IUIELEMENT_HPP_

class UIElement {
    public:
        virtual void draw() const = 0;
};

#endif /* !IUIELEMENT_HPP_ */
