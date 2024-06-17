/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description: the main
** main.cpp
*/
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

BoundingBox TransformBoundingBox(BoundingBox box, Matrix transform) {
    Vector3 corners[8] = {
        box.min,
        { box.min.x, box.min.y, box.max.z },
        { box.min.x, box.max.y, box.min.z },
        { box.min.x, box.max.y, box.max.z },
        { box.max.x, box.min.y, box.min.z },
        { box.max.x, box.min.y, box.max.z },
        { box.max.x, box.max.y, box.min.z },
        box.max
    };

    for (int i = 0; i < 8; i++) {
        corners[i] = Vector3Transform(corners[i], transform);
    }

    BoundingBox transformedBox = { corners[0], corners[0] };
    for (int i = 1; i < 8; i++) {
        transformedBox.min = Vector3Min(transformedBox.min, corners[i]);
        transformedBox.max = Vector3Max(transformedBox.max, corners[i]);
    }

    return transformedBox;
}

int main(void)
{
    int map_sizeX = 10;
    int map_sizeY = 10;
    SetTraceLogLevel(LOG_ALL);
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "raylib [models] example - models loading");
    Camera camera = { 0 };
    camera.position = (Vector3){ 15.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    Model model = LoadModel("assets/low_poly_island.glb");
    // Model model = LoadModel("assets/island.obj");
    // for (int i = 0; i < model.materialCount; i++)
    // {
    //     TraceLog(LOG_INFO, "Material %d: %u", i, model.materials[i].maps[MATERIAL_MAP_DIFFUSE].texture.id);
    // }
    // // Texture2D texture = LoadTexture("tree/house.png");
    // // model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    // float scaleFactor = 1.0f;
    // BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    // bounds.min.x *= scaleFactor;
    // bounds.min.y *= scaleFactor;
    // bounds.min.z *= scaleFactor;

    // bounds.max.x *= scaleFactor;
    // bounds.max.y *= scaleFactor;
    // bounds.max.z *= scaleFactor;

    // Matrix modelTransform = MatrixRotateXYZ((Vector3){0.0f, 0.0f, 0.0f});
    // model.transform = modelTransform;

    // BoundingBox transformedBounds = TransformBoundingBox(bounds, modelTransform);

    // bool selected = false;
    DisableCursor();
    SetTargetFPS(144);
    while (!WindowShouldClose())
    {
        // UpdateCamera(&camera, CAMERA_ORTHOGRAPHIC);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        DrawModel(model, (Vector3){0.0f, 0.0f, 0.0f}, 0.1f, WHITE);

        DrawGrid(map_sizeX, 1.0f);
        EndMode3D();
        DrawFPS(10, 10);
        EndDrawing();
    }

    // UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();
    return 0;
}
