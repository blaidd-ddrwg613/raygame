#include "Game.h"

Game::Game()
= default;

void Game::Init()
{
    InitWindow(wWidth, wHeight, wTitle.c_str());
    player = {wWidth / 2.0f, wHeight / 2.0f, 50, 50, RED};

    Vector2 cameraOffset = {wWidth / 2.0f, wHeight / 2.0f};
    Vector2 cameraTarget = {player.GetX(), player.GetY()};
    camera = {cameraOffset, cameraTarget, 0 , 1.0f };
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
    camera.Update(player.GetPlayerPos(), 0, 1.0f);
    player.Update(deltaTime);
}

void Game::DrawGame()
{
    BeginDrawing();
    BeginMode2D(camera.GetCamera2D());

    ClearBackground(WHITE);

    DrawRectangle(-5000, wHeight / 2, 10000, 500, GRAY);
    DrawRectangle(-500, wHeight / 2 - 150, 1000, 50, PURPLE);
    DrawRectanglePro(player.getPlayerRect(), {player.GetPlayerOrigin().x, player.GetPlayerOrigin().y}, 0, player.GetColor());

    EndMode2D();
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