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
    Model model = LoadModel("assets/player.glb");

    // Apply rotation to correct the model orientation
    // Matrix rotation = MatrixRotateX(DEG2RAD);
    // model.transform = MatrixMultiply(model.transform, rotation);

    // Assign the shader to each material in the model
    for (int i = 0; i < model.materialCount; i++) {
        model.materials[i].shader = shader;
    }

    // Load animations
    int animsCount = 0;
    ModelAnimation *anims = LoadModelAnimations("assets/dying.glb", &animsCount);
    ModelAnimation *dyingAnim = LoadModelAnimations("assets/mushroom_dance.glb", &animsCount);
    int animFrameCounter = 0;

    // Current animation state
    bool isDying = false;

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

        if (IsKeyPressed(KEY_P))
        {
            isDying = !isDying;
            animFrameCounter = 0;  // Reset animation frame counter when switching animations
        }

        animFrameCounter++;
        if (isDying)
        {
            UpdateModelAnimation(model, dyingAnim[0], animFrameCounter);
            if (animFrameCounter >= dyingAnim[0].frameCount) animFrameCounter = 0;
        }
        else
        {
            UpdateModelAnimation(model, anims[0], animFrameCounter);
            if (animFrameCounter >= anims[0].frameCount) animFrameCounter = 0;
        }

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

                // Draw model
                DrawModel(model, (Vector3){0.0f, 0.0f, 0.0f}, 0.4f, WHITE);

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
    // UnloadModelAnimations(anims, animsCount);  // Unload animations
    // UnloadModelAnimations(dyingAnim, animsCount);  // Unload dying animation

    CloseWindow();             // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



/*
void GUI::run()
{
    WindowPtr window = Window::getInstance();
    window->setLogInfo("LOG_INFO");
    window->initWindow(1920, 1080, "raylib [core] example - 3d camera free", 144);
    CameraWrapper camera;
    MapPtr map = Map::getInstance();
    map->setMapSize(10, 10);
    window->loadModels();
    float updateInterval = 1.0f / _freq;
    float lastUpdateTime = GetTime();
    map->addResource(0, 0, Ressources::RessourceType::FOOD, 1);
    map->addResource(0, 0, Ressources::RessourceType::LINEMATE, 1);
    map->addResource(0, 0, Ressources::RessourceType::DERAUMERE, 1);
    map->addResource(0, 0, Ressources::RessourceType::SIBUR, 1);
    map->addResource(0, 0, Ressources::RessourceType::MENDIANE, 1);
    map->addResource(0, 0, Ressources::RessourceType::PHIRAS, 1);
    map->addResource(0, 0, Ressources::RessourceType::THYSTAME, 1);

    Shader shader = LoadShader("assets/lighting.vs", "assets/lighting.fs");
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
    int ambientLoc = GetShaderLocation(shader, "ambient");
    float ambient[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    SetShaderValue(shader, ambientLoc, ambient, SHADER_UNIFORM_VEC4);
    std::vector<Model> _loadedModels = window->getLoadedModels();
    std::vector<Model> resourceModels = window->getResourceModels();
    for (int i = 0; i < _loadedModels.size(); i++) {
        for (int j = 0; j < _loadedModels[i].materialCount; j++) {
            _loadedModels[i].materials[j].shader = shader;
        }
    }
    for (int i = 0; i < resourceModels.size(); i++) {
        for (int j = 0; j < resourceModels[i].materialCount; j++) {
            resourceModels[i].materials[j].shader = shader;
        }
    }
    Light lights[MAX_LIGHTS] = { 0 };
    lights[0] = CreateLight(LIGHT_POINT, (Vector3){ 0, 1, 0 }, Vector3Zero(), WHITE, shader); // Initialiser la lumière à blanche

    float dayDuration = 60.0f; // Durée d'un cycle jour-nuit en secondes

    while (!WindowShouldClose())
    {
        float currentTime = GetTime();
        float timeOfDay = fmod(currentTime, dayDuration) / dayDuration; // Normaliser le temps entre 0 et 1

        // Calculer la couleur de la lumière en fonction du temps de la journée
        float lightIntensity = 1.0f - timeOfDay; // Passe de 1.0 (plein jour) à 0.0 (nuit complète)
        Color lightColor = Color{ (unsigned char)(255 * lightIntensity), (unsigned char)(255 * lightIntensity), (unsigned char)(255 * lightIntensity), 255 };

        // Mettre à jour la lumière
        lights[0].color = lightColor;
        UpdateLightValues(shader, lights[0]);

        camera.update();
        float cameraPos[3] = { camera.getX(), camera.getY(), camera.getZ() };
        SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
        for (int i = 0; i < MAX_LIGHTS; i++) UpdateLightValues(shader, lights[i]);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        camera.BeginMode();
        window->updateMap(map);
        window->DrawMap(map->getMapSizeX(), map->getMapSizeY());
        for (int i = 0; i < MAX_LIGHTS; i++)
        {
            if (lights[i].enabled) DrawSphereEx(lights[i].position, 0.2f, 8, 8, lights[i].color);
        }
        camera.EndMode();
        window->DrawFps(10, 10);
        EndDrawing();
    }
    CloseWindow(); 
    exit(0);
}*/