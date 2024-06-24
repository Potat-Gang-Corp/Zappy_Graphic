/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** main
*/

#include "GUI.hpp"
#include "Server.hpp"

// int main(int argc, char **argv) {
//     // Initialisation de la fenêtre
//     InitWindow(800, 600, "Connexion au serveur");

//     // Variables pour gérer les champs de saisie
//     char port[6] = "12345"; // Buffer pour le texte du port
//     char host[16] = "127.0.0.1"; // Buffer pour le texte de l'adresse IP
//     bool editPort = false; // Mode d'édition pour le port
//     bool editHost = false; // Mode d'édition pour l'adresse IP

//     Rectangle portBox = { 200, 200, 400, 50 }; // Rectangle du champ de saisie du port
//     Rectangle hostBox = { 200, 300, 400, 50 }; // Rectangle du champ de saisie de l'adresse IP

//     SetTargetFPS(60); // Régler la fréquence d'images

//     while (!WindowShouldClose()) { // Boucle principale

//         // Gestion de la saisie du port
//         if (CheckCollisionPointRec(GetMousePosition(), portBox)) {
//             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                 editPort = true;
//                 editHost = false;
//             }
//         }

//         if (editPort) {
//             int key = GetKeyPressed();
//             while (key > 0) {
//                 if ((key >= 48) && (key <= 57) && (strlen(port) < 5)) {
//                     int len = strlen(port);
//                     port[len] = (char)key;
//                     port[len+1] = '\0';
//                 }

//                 key = GetKeyPressed();
//             }

//             if (IsKeyPressed(KEY_BACKSPACE) && strlen(port) > 0) {
//                 port[strlen(port) - 1] = '\0';
//             }

//             if (IsKeyPressed(KEY_ENTER)) {
//                 editPort = false;
//             }
//         }

//         // Gestion de la saisie de l'adresse IP
//         if (CheckCollisionPointRec(GetMousePosition(), hostBox)) {
//             if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//                 editHost = true;
//                 editPort = false;
//             }
//         }

//         if (editHost) {
//             int key = GetKeyPressed();
//             while (key > 0) {
//                 if (((key >= 48) && (key <= 57)) || key == 46) {
//                     int len = strlen(host);
//                     if (len < 15) {
//                         host[len] = (char)key;
//                         host[len+1] = '\0';
//                     }
//                 }

//                 key = GetKeyPressed();
//             }

//             if (IsKeyPressed(KEY_BACKSPACE) && strlen(host) > 0) {
//                 host[strlen(host) - 1] = '\0';
//             }

//             if (IsKeyPressed(KEY_ENTER)) {
//                 editHost = false;
//             }
//         }

//         // Dessiner l'interface
//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         DrawText("Entrez le port et l'adresse IP, puis appuyez sur ENTER", 100, 100, 20, DARKGRAY);

//         DrawRectangleRec(portBox, LIGHTGRAY);
//         if (editPort) {
//             DrawRectangleLines((int)portBox.x, (int)portBox.y, (int)portBox.width, (int)portBox.height, RED);
//         } else {
//             DrawRectangleLines((int)portBox.x, (int)portBox.y, (int)portBox.width, (int)portBox.height, DARKGRAY);
//         }
//         DrawText(port, (int)portBox.x + 5, (int)portBox.y + 8, 40, MAROON);

//         DrawRectangleRec(hostBox, LIGHTGRAY);
//         if (editHost) {
//             DrawRectangleLines((int)hostBox.x, (int)hostBox.y, (int)hostBox.width, (int)hostBox.height, RED);
//         } else {
//             DrawRectangleLines((int)hostBox.x, (int)hostBox.y, (int)hostBox.width, (int)hostBox.height, DARKGRAY);
//         }
//         DrawText(host, (int)hostBox.x + 5, (int)hostBox.y + 8, 40, MAROON);

//         EndDrawing();
//         if (IsKeyPressed(KEY_O)) {
//             break;
//         }
//     }

//     // Fermer la fenêtre avant de démarrer le serveur

//     // Convertir les entrées en std::string
//     std::string portStr(port);
//     std::string hostStr(host);

//     // Initialiser et démarrer le serveur et l'interface graphique
//     GUI gui;
//     Server server;
//     if (server.connect_server(portStr, hostStr) != 0) {
//         std::cerr << "Failed to connect to server" << std::endl;
//         return 1;
//     }

//     std::thread listeningThread(&Server::listening, &server);
//     std::thread gameThread(&GUI::run, &gui);

//     gameThread.join();
//     server.stop();
//     listeningThread.join();
//     return 0;
// }

int main(int argc, char **argv) 
{
    GuiPtr gui = GUI::getInstance();
    ServerPtr server = Server::getInstance();
    std::string port, host;
    if (argc == 5) {
        port = argv[2];
        host = argv[4];
        gui->setHostPort(port, host);
    }

    std::thread listeningThread(&Server::listening, server);
    std::thread gameThread(&GUI::run, gui);

    gameThread.join();
    server->stop();
    listeningThread.join(); 
    return 0;
}

