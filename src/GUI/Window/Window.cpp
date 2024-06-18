/*
** EPITECH PROJECT, 2024
** Zappy_Graphic
** File description:
** Window
*/

#include "Window.hpp"

Window::Window(int mapSizeX, int mapSizeY)
{
    _islands.push_back("assets/island_farm.glb");
    _islands.push_back("assets/island_tree.glb");
    _islands.push_back("assets/low_poly_island.glb");
}

Window::Window()
{
    _islands.push_back("assets/island_farm.glb");
    _islands.push_back("assets/island_tree.glb");
    _islands.push_back("assets/low_poly_island.glb");
}

Window::~Window()
{
    for (const auto& model : _loadedModels) {
        UnloadModel(model);
    }
}

void Window::loadModels()
{
    for (const auto& island : _islands) {
        _loadedModels.push_back(LoadModel(island.c_str()));
    }

    _resourceModels.push_back(LoadModel("assets/potato.glb"));
    _resourceModels.push_back(LoadModel("assets/mine1.glb"));
    _resourceModels.push_back(LoadModel("assets/mine2.glb"));
    _resourceModels.push_back(LoadModel("assets/mine3.glb"));
    _resourceModels.push_back(LoadModel("assets/mine4.glb"));
    _resourceModels.push_back(LoadModel("assets/mine5.glb"));
    _resourceModels.push_back(LoadModel("assets/mine6.glb"));
}

void Window::setLogInfo(const std::string &log)
{
    static const std::unordered_map<std::string, int> logLevels = {
        {"LOG_ALL", LOG_ALL},
        {"LOG_TRACE", LOG_TRACE},
        {"LOG_DEBUG", LOG_DEBUG},
        {"LOG_INFO", LOG_INFO},
        {"LOG_WARNING", LOG_WARNING},
        {"LOG_ERROR", LOG_ERROR},
        {"LOG_FATAL", LOG_FATAL}
    };

    auto it = logLevels.find(log);
    if (it != logLevels.end()) {
        SetTraceLogLevel(it->second);
    } else {
        SetTraceLogLevel(LOG_NONE);
    }
    // LOG_ALL, LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR, LOG_FATAL
}

void Window::initWindow(int height, int width, const std::string &WindowName, int fps)
{
    _screenH = height;
    _screenW = width;
    _fps = fps;
    InitWindow(_screenH, _screenW, WindowName.c_str()); 
    SetTargetFPS(_fps);
}

void Window::DrawMap(int mapSizeX, int mapSizeY)
{
    for (float i = 0; i < mapSizeX; i++) {
        for (float j = 0; j < mapSizeY; j++) {
            int randomIndex = rand() % _loadedModels.size();
            Vector3 modelPosition = { (float)(i) * 10, 0.0f, (float)(j) * 10 };
            float modelScale = 0.2f;

            BoundingBox box = GetModelBoundingBox(_loadedModels[0]);
            box.min.x *= modelScale;
            box.min.y *= modelScale;
            box.min.z *= modelScale;

            box.max.x *= modelScale;
            box.max.y *= modelScale;
            box.max.z *= modelScale;

            box.min.x += modelPosition.x;
            box.min.y += modelPosition.y;
            box.min.z += modelPosition.z;

            box.max.x += modelPosition.x;
            box.max.y += modelPosition.y;
            box.max.z += modelPosition.z;

            DrawModel(_loadedModels[0], modelPosition, modelScale, WHITE);
            // DrawBoundingBox(box, RED);
        }
    }
}

void Window::updateMap(std::shared_ptr<Map> map)
{
    for (int x = 0; x < map->getMapSizeX(); x++) {
        for (int y = 0; y < map->getMapSizeY(); y++) {
            ResourceMap& resources = map->getResources(x, y);
            Vector3 basePosition = {(float)(x * 10 - 2), 0.0f, (float)(y * 10 - 2.2)};
            
            int modelIndex = 0;
            for (const auto& resource : resources) {
                if (resource.second > 0) {
                    Vector3 resourcePosition = basePosition;
                    resourcePosition.y = 0.1f;
                    float randomCoefficientX = 0.3f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (1.7f - 0.3f);
                    float randomCoefficientZ = 0.3f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (1.7f - 0.3f);

                    resourcePosition.x += (modelIndex % 3) * /*randomCoefficientX*/ 1.0f;
                    resourcePosition.z += (modelIndex / 3) * /*randomCoefficientZ*/ 1.0f;
                    int index = static_cast<int>(resource.first);
                    DrawModel(_resourceModels[index], resourcePosition, 0.09f, WHITE);
                    modelIndex++;
                }
            }
        }
    }
}

void Window::DrawFps(int x, int y)
{
    DrawFPS(x, y);
}
