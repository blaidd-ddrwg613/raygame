#pragma once

#include <iostream>

#include "raylib.h"
#include "raymath.h"
#include "Camera.h"
#include "Player.h"

class Game
{
public:
    Game();
    void Init();
    void RunLoop();
    void Shutdown();

    int GetTargetFps() { return targetFps; }
    int GetWindowWidth() { return wWidth; }
    int GetWindowHeight() { return wHeight; }
    float GetDeltaTime() { return deltaTime; }
    bool IsVsyncEnabled() { return vSyncEnabled; }
    void SetWindowWidth(int width) { wWidth = width; }
    void SetWindowHeight(int height) { wHeight = height; }
    void SetFps(int fps) { targetFps = fps; };

    rayGame::Camera camera;
    Player player;

private:
    void ProcessInput();
    void UpdateGame();
    void DrawGame();
    void ToggleVsync();

    int wWidth = 1080;
    int wHeight = 720;
    int targetFps = 0;
    std::string wTitle = "Raylib Window";
    float deltaTime = 0;

    bool vSyncEnabled = false;

};
