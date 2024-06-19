/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** ModelsLoader.hpp
*/


#pragma once

#ifndef MODELSLOADER_HPP_
    #define MODELSLOADER_HPP_

    #include <iostream>
    #include <raylib.h>
    #include <vector>
    #include <memory>
    #include <map>

class ModelsLoader {
    public:
        ModelsLoader();
        ~ModelsLoader() = default;
        Model getModel(std::string filename);
        static std::shared_ptr<ModelsLoader> getInstance() {
            static std::shared_ptr<ModelsLoader> instance(new ModelsLoader());
            return instance;
        }

    private:
        std::map<std::string, Model> _models;
};

typedef std::shared_ptr<ModelsLoader> ModelsLoaderPtr;

#endif /* !MODELSLOADER_HPP_ */