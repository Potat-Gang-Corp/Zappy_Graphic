#include "raylib.h"

// Fonction pour vérifier la collision entre un rayon et une boîte englobante
bool CheckCollisionRayBox(Ray ray, BoundingBox box) {
    float tmin = (box.min.x - ray.position.x) / ray.direction.x;
    float tmax = (box.max.x - ray.position.x) / ray.direction.x;
    
    if (tmin > tmax) {
        float temp = tmin;
        tmin = tmax;
        tmax = temp;
    }

    float tymin = (box.min.y - ray.position.y) / ray.direction.y;
    float tymax = (box.max.y - ray.position.y) / ray.direction.y;

    if (tymin > tymax) {
        float temp = tymin;
        tymin = tymax;
        tymax = temp;
    }

    if ((tmin > tymax) || (tymin > tmax)) return false;

    if (tymin > tmin) tmin = tymin;
    if (tymax < tmax) tmax = tymax;

    float tzmin = (box.min.z - ray.position.z) / ray.direction.z;
    float tzmax = (box.max.z - ray.position.z) / ray.direction.z;

    if (tzmin > tzmax) {
        float temp = tzmin;
        tzmin = tzmax;
        tzmax = temp;
    }

    if ((tmin > tzmax) || (tzmin > tmax)) return false;

    if (tzmin > tmin) tmin = tzmin;
    if (tzmax < tmax) tmax = tzmax;

    return true;
}

int main(void) {
    // Initialisation
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib 3D Hover Example");

    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Charger le modèle
    Model model = LoadModel("assets/island_farm.glb");
    Vector3 modelPosition = { 0.0f, 0.0f, 0.0f };

    // Calculer la boîte englobante du modèle
    // BoundingBox modelBoundingBox = GetModelBoundingBox(model);
    BoundingBox modelBoundingBox = GetMeshBoundingBox(model.meshes[0]);
    
    modelBoundingBox.min.x *= 0.06f;
    modelBoundingBox.min.y *= 0.06f;
    modelBoundingBox.min.z *= 0.06f;
    modelBoundingBox.max.x *= 0.06f;
    modelBoundingBox.max.y *= 0.06f;
    modelBoundingBox.max.z *= 0.06f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Mise à jour

        // Désactiver les mouvements de la caméra par la souris
        Vector2 mousePosition = GetMousePosition();
        Ray ray = GetMouseRay(mousePosition, camera);

        // Vérifier la collision avec le modèle
        bool hover = CheckCollisionRayBox(ray, modelBoundingBox);

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Dessiner le modèle
                DrawModel(model, modelPosition, 0.06f, WHITE);
                // DrawBoundingBox(modelBoundingBox, BLACK);

                if (hover) {
                    DrawModelWires(model, modelPosition, 0.06f, BLACK);
                }

            EndMode3D();

            DrawText("Passez la souris sur le modèle pour un effet de hover", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    // Décharger le modèle
    UnloadModel(model);

    // Dé-initialisation
    CloseWindow();

    return 0;
}
