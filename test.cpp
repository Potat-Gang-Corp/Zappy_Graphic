#include "raylib.h"

int main() {
    // Initialisation de la fenêtre
    InitWindow(800, 600, "Champ de saisie de texte avec Raylib");

    // Variables pour gérer le champ de saisie
    char text[128] = ""; // Buffer pour le texte
    int letterCount = 0; // Nombre de lettres saisies
    bool mouseOnText = false; // Indicateur de survol de la souris
    Rectangle textBox = { 200, 200, 400, 50 }; // Rectangle du champ de saisie
    bool editMode = false; // Mode d'édition

    SetTargetFPS(60); // Régler la fréquence d'images

    while (!WindowShouldClose()) { // Boucle principale

        // Vérifier si la souris est sur le champ de texte
        if (CheckCollisionPointRec(GetMousePosition(), textBox)) {
            mouseOnText = true;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                editMode = true;
            }
        } else {
            mouseOnText = false;
        }

        // Saisie de texte
        if (editMode) {
            int key = GetKeyPressed();
            while (key > 0) {
                if ((key >= 32) && (key <= 125) && (letterCount < 127)) {
                    text[letterCount] = (char)key;
                    text[letterCount+1] = '\0';
                    letterCount++;
                }

                key = GetKeyPressed();
            }

            if (IsKeyPressed(KEY_BACKSPACE)) {
                letterCount--;
                if (letterCount < 0) letterCount = 0;
                text[letterCount] = '\0';
            }

            if (IsKeyPressed(KEY_ENTER)) {
                editMode = false;
            }
        }

        // Dessiner
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Cliquez sur le rectangle et commencez à taper...", 200, 150, 20, DARKGRAY);

        DrawRectangleRec(textBox, LIGHTGRAY);
        if (mouseOnText) {
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
        } else {
            DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
        }

        DrawText(text, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

        if (editMode) {
            if (letterCount < 30) {
                if ((letterCount/2) % 2 == 0) {
                    DrawText("_", (int)textBox.x + 8 + MeasureText(text, 40), (int)textBox.y + 12, 40, MAROON);
                }
            } else {
                DrawText("LIMIT REACHED", 230, 300, 20, RED);
            }
        }

        EndDrawing();
    }

    // Déinitialisation
    CloseWindow();

    return 0;
}
