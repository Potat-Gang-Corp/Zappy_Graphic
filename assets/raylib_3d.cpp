#include <raylib.h>
#include <rlgl.h> // Inclusion de l'API bas-niveau pour les fonctions rlPushMatrix et rlPopMatrix
#include <iostream>



int main(void) {
    // Initialisation de la fenêtre
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "Chargement d'un modèle OBJ avec texture");

    // Chargement du modèle OBJ
    Model model = LoadModel("src/cottage_obj.obj");

    // Chargement de la texture MTL (correction : c'est .mtl, pas .mlt)
    // Texture2D texture = LoadTexture("/home/msafwane/Downloads/uploads_files_2033848_OBJ/OBJ/RubberDuck_LOD0.mtl"); // Chargez la texture appropriée référencée dans le fichier .mtl

    // Application de la texture au modèle
    // model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    // Définition de la caméra
    Camera camera = { 0 };
    camera.position = (Vector3){ 3.0f, 3.0f, 3.0f };
    camera.target = (Vector3){ 0.0f, 1.5f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Mode de caméra (libre)
    int cameraMode = CAMERA_ORTHOGRAPHIC;

    SetTargetFPS(60); // Fixer le taux de rafraîchissement de l'écran

    // Boucle principale
    while (!WindowShouldClose()) {
        // Mise à jour de la caméra
        UpdateCamera(&camera, cameraMode);

        // Début du dessin
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // Dessin du modèle
        DrawModel(model, (Vector3){ 0.0f, 0.0f, 0.0f }, 0.02f, WHITE);

        EndMode3D();

        // Fin du dessin
        EndDrawing();
    }

    // Libération de la mémoire
    // UnloadTexture(texture);
    UnloadModel(model);

    // Fermeture de la fenêtre
    CloseWindow();

    return 0;
}
