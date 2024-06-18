/*******************************************************************************************
*
*   raylib [shaders] example - basic lighting
*
*   NOTE: This example requires raylib OpenGL 3.3 or ES2 versions for shaders support,
*         OpenGL 1.1 does not support shaders, recompile raylib to OpenGL 3.3 version.
*
*   NOTE: Shaders used in this example are #version 330 (OpenGL 3.3).
*
*   Example originally created with raylib 3.0, last time updated with raylib 4.2
*
*   Example contributed by Chris Camacho (@codifies) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2024 Chris Camacho (@codifies) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#include "rlgl.h"
#include "raymath.h"  

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);  // Enable Multi Sampling Anti Aliasing 4x (if available)
    InitWindow(screenWidth, screenHeight, "raylib [shaders] example - basic lighting");

    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 2.0f, 4.0f, 6.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.5f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    // Load basic lighting shader
    Shader shader = LoadShader(TextFormat("assets/lighting.vs", GLSL_VERSION),
                               TextFormat("assets/lighting.fs", GLSL_VERSION));
    // Get some required shader locations
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    // NOTE: "matModel" location name is automatically assigned on shader loading, 
    // no need to get the location again if using that uniform name
    //shader.locs[SHADER_LOC_MATRIX_MODEL] = GetShaderLocation(shader, "matModel");
    
    // Ambient light level (some basic lighting)
    int ambientLoc = GetShaderLocation(shader, "ambient");
    float ambient[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    SetShaderValue(shader, ambientLoc, ambient, SHADER_UNIFORM_VEC4);

    // Load the model
    Model model = LoadModel("assets/mine1.glb");

    // Apply rotation to correct the model orientation
    // Matrix rotation = MatrixRotateX(DEG2RAD);
    // model.transform = MatrixMultiply(model.transform, rotation);

    // Assign the shader to each material in the model
    for (int i = 0; i < model.materialCount; i++) {
        model.materials[i].shader = shader;
    }

    // int animsCount = 0;
    // ModelAnimation *anims = LoadModelAnimations("assets/mine5.glb", &animsCount);
    // int animFrameCounter = 0;


    // Load skybox shader and textures
    // Shader skyboxShader = LoadShader("skybox.vs", "skybox.fs");
    //     Texture2D skyboxTexture = LoadTexture("skybox.png");
    //     Model skybox = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
    //     skybox.materials[0].shader = skyboxShader;
    //     skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = skyboxTexture;
    //     int cubemapValue[1] = { MATERIAL_MAP_CUBEMAP };
    //     SetShaderValue(skyboxShader, GetShaderLocation(skyboxShader, "environmentMap"), cubemapValue, SHADER_UNIFORM_INT);

    // Create lights
    Light lights[MAX_LIGHTS] = { 0 };
    lights[0] = CreateLight(LIGHT_POINT, (Vector3){ -2, 1, -2 }, Vector3Zero(), YELLOW, shader);
    lights[1] = CreateLight(LIGHT_POINT, (Vector3){ 2, 1, 2 }, Vector3Zero(), RED, shader);
    lights[2] = CreateLight(LIGHT_POINT, (Vector3){ -2, 1, 2 }, Vector3Zero(), GREEN, shader);
    lights[3] = CreateLight(LIGHT_POINT, (Vector3){ 2, 1, -2 }, Vector3Zero(), BLUE, shader);

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_ORBITAL);

        // if (IsKeyDown(KEY_SPACE))
        // {
            // animFrameCounter++;
            // UpdateModelAnimation(model, anims[0], animFrameCounter);
            // if (animFrameCounter >= anims[0].frameCount) animFrameCounter = 0;
        // }

        // Update the shader with the camera view vector (points towards { 0.0f, 0.0f, 0.0f })
        float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
        SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
        
        // Check key inputs to enable/disable lights
        if (IsKeyPressed(KEY_Y)) { lights[0].enabled = !lights[0].enabled; }
        if (IsKeyPressed(KEY_R)) { lights[1].enabled = !lights[1].enabled; }
        if (IsKeyPressed(KEY_G)) { lights[2].enabled = !lights[2].enabled; }
        if (IsKeyPressed(KEY_B)) { lights[3].enabled = !lights[3].enabled; }
        
        // Update light values (actually, only enable/disable them)
        for (int i = 0; i < MAX_LIGHTS; i++) UpdateLightValues(shader, lights[i]);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                // Draw skybox
                // rlDisableBackfaceCulling();
                // rlDisableDepthMask();
                    // DrawModel(skybox, Vector3Zero(), 1.0f, WHITE);
                // rlEnableBackfaceCulling();
                // rlEnableDepthMask();     // Enable backface culling again

                // Draw model
                DrawModel(model, (Vector3){0.0f, 1.0f, 0.0f}, 1.0f, WHITE);
                // DrawModel(model, (Vector3){1.0f, 1.0f, 1.0f}, 0.5f, WHITE);

                for (int i = 0; i < model.boneCount; i++)
                {
                    // DrawCube(anims[0].framePoses[animFrameCounter][i].translation, 0.2f, 0.2f, 0.2f, RED);
                }

                // Draw spheres to show where the lights are
                for (int i = 0; i < MAX_LIGHTS; i++)
                {
                    if (lights[i].enabled) DrawSphereEx(lights[i].position, 0.2f, 8, 8, lights[i].color);
                    else DrawSphereWires(lights[i].position, 0.2f, 8, 8, ColorAlpha(lights[i].color, 0.3f));
                }

                DrawGrid(10, 1.0f);

            EndMode3D();

            DrawFPS(10, 10);

            DrawText("Use keys [Y][R][G][B] to toggle lights", 10, 40, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadShader(shader);      // Unload shader
    UnloadModel(model);        // Unload model
    // UnloadShader(skyboxShader);// Unload skybox shader
    // UnloadTexture(skyboxTexture); // Unload skybox texture
    // UnloadModel(skybox);       // Unload skybox

    CloseWindow();             // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
