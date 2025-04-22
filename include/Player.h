#pragma once

#include "raylib.h"
#include "raymath.h"

class Player
{
public:
    Player();

    Player(float x, float y, float width, float height, Color color)
        { playerRect = { x, y, width, height }; this->color = color; };

    float GetX() { return playerRect.x; };
    float GetY() { return  playerRect.y; };
    float GetWidth() { return playerRect.width; };
    float GetHeight() { return playerRect.height; };
    Vector2 GetMovementVector() { return movementVector; };
    Vector2 GetPlayerOrigin() { return playerOrigin; };
    Vector2 GetPlayerPos() { return { playerRect.x, playerRect.y }; };
    Rectangle getPlayerRect() { return playerRect; }
    Color GetColor() { return color; }

    void SetX(float x) { playerRect.x = x; };
    void SetY(float y) { playerRect.y = y; };
    void SetWidth(float width) { playerRect.width = width; };
    void SetHeight(float height) { playerRect.height = height; };
    void SetColor(Color color) { this->color = color; }
    void SetMovementVector(Vector2 movementVector) { this->movementVector = movementVector; }

    void Update(float deltaTime);

private:

    void CalculateMovementVector();

    Rectangle playerRect{};
    Vector2 playerOrigin{ playerRect.x / 2,playerRect.y / 2};
    Color color{};
    Vector2 movementVector;
    float baseMovementSpeed = 10;
    float speedMultiplier = 50;
    float movementSpeed = baseMovementSpeed * speedMultiplier;

};
