/*
** EPITECH PROJECT, 2024
** Zappy_Mathis
** File description:
** Main
*/

#include "GameEngine.hpp"
#include "Server.hpp"

int main(int argc, char **argv)
{
    if (argc != 5) {
        std::cerr << "USAGE: " << argv[0] << " -p port -h machine" << std::endl;
        return 1;
    }
    std::string port = argv[2];
    std::string host = argv[4];

    std::shared_ptr<GameEngine> gameEngine = GameEngine::getInstance();

    Server server;

    if (server.connect_server(port, host) != 0) {
        std::cerr << "Failed to connect to server" << std::endl;
        return 1;
    }

    std::thread listeningThread(&Server::listening, &server);
    std::thread gameThread(&GameEngine::Run, gameEngine);

    gameThread.join();
    gameEngine->Shutdown();
    listeningThread.join(); 

    return 0;
}


