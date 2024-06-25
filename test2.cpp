/*
** EPITECH PROJECT, 2023
** Zappy_Graphic
** File description:
** test.cpp
*/

#include "raylib.h"
#include <iostream>

// int main(void)
// {
//     // Initialisation de la fenêtre et de l'audio
//     InitWindow(800, 600, "Sound Test");
//     InitAudioDevice();

//     // Chargement du son
//     Sound broadcast = LoadSound("assets/sounds/sound_test.mp3");
//     if (broadcast.frameCount == 0) {
//         std::cerr << "Failed to load sound 'broadcast.ogg'" << std::endl;
//         CloseAudioDevice();
//         CloseWindow();
//         return 1;
//     }

//     // Boucle principale
//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         if (IsKeyPressed(KEY_M)) {
//             PlaySound(broadcast);
//         }

//         EndDrawing();
//     }

//     // Déchargement du son et fermeture de l'audio
//     UnloadSound(broadcast);
//     CloseAudioDevice();
//     CloseWindow();

//     return 0;
// }


#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [audio] example - sound loading and playing");

    InitAudioDevice();      // Initialize audio device

    Sound fxWav = LoadSound("assets/sounds/sound_test.mp3");         // Load WAV audio file
    // Sound fxOgg = LoadSound("resources/target.ogg");        // Load OGG audio file

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) PlaySound(fxWav);      // Play WAV sound
        // if (IsKeyPressed(KEY_ENTER)) PlaySound(fxOgg);      // Play OGG sound
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Press SPACE to PLAY the WAV sound!", 200, 180, 20, LIGHTGRAY);
            DrawText("Press ENTER to PLAY the OGG sound!", 200, 220, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(fxWav);     // Unload sound data
    // UnloadSound(fxOgg);     // Unload sound data

    CloseAudioDevice();     // Close audio device

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
