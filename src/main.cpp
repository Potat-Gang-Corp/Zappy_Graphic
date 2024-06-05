/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** main
*/

// #include "Raylib.hpp"
#include "Team.hpp"
#include "PlayerData.hpp"
#include "Server.hpp"
#include <raylib.h>

void gameloop(Server &server)
{
    InitWindow(800, 600, "Zappy GUI");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        server.send_data("msz\n");
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
}

int main(int argc, char **argv) 
{
    // Raylib raylib(800, 800, "Zappy", "LOG_NONE");
    if (argc != 5) {
        std::cerr << "USAGE: " << argv[0] << " -p port -h machine" << std::endl;
        return 1;
    }
    std::string port = argv[2];
    std::string host = argv[4];
    
    Server server;
    if (server.connect_server(port, host) != 0) {
        std::cerr << "Failed to connect to server" << std::endl;
        return 1;
    }

    server.listening();

    std::thread gameThread(gameloop, std::ref(server));

    gameThread.join();
    server.stop();
    return 0;
}
