#include "Game.h"

Game::Game()
{}

void Game::Init()
{
    InitWindow(wWidth, wHeight, wTitle.c_str());
//    player = {TEXTURE_PATH + "/player/idle.png"};
    player = {TEXTURE_PATH + "/player/idle.png"};
}

void Game::RunLoop()
{
    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        ProcessInput();
        UpdateGame();
        DrawGame();

    }
}

void Game::ProcessInput()
{

}

void Game::UpdateGame()
{
    player.Update(deltaTime);
}

void Game::DrawGame()
{
    BeginDrawing();

    ClearBackground(DARKPURPLE);

    DrawRectangle(-5000, wHeight / 2, 10000, 500, GRAY);
    DrawRectangle(-500, wHeight / 2 - 150, 1000, 50, PURPLE);

    player.Draw();

    EndDrawing();
}

void Game::ToggleVsync()
{
    vSyncEnabled = !vSyncEnabled;
    targetFps = vSyncEnabled ? GetMonitorRefreshRate(1) : 0;

    if (targetFps != 0)
    {
        SetTargetFPS(targetFps);
    }
}

void Game::Shutdown()
{
    CloseWindow();
}