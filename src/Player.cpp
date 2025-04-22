#include "Player.h"

Player::Player()
= default;

void Player::Update(float deltaTime)
{
    CalculateMovementVector();

    movementVector = Vector2Normalize(movementVector);

    playerRect.x += movementVector.x * movementSpeed * deltaTime;
    playerRect.y += movementVector.y * movementSpeed * deltaTime;
}

void Player::CalculateMovementVector()
{
    movementVector.x = 0;
    movementVector.y = 0;
    
    if (IsKeyDown(KEY_W))
    {
        movementVector.y = -1;
    }
    if (IsKeyDown(KEY_S))
    {
        movementVector.y = 1;
    }
    if (IsKeyDown(KEY_A))
    {
        movementVector.x = -1;
    }
    if (IsKeyDown(KEY_D))
    {
        movementVector.x = 1;
    }
}