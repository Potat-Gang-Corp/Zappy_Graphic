/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>

class Server {
    public:
        Server() = default;
        ~Server() = default;
        int connect_server(const std::string& host, const std::string& port);
    private:
};

#endif /* !SERVER_HPP_ */