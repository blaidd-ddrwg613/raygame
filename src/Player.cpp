#include "Player.h"

Player::Player()
{

}

Player::Player(std::string texturePath) : position({250, 300})
{
    if (playerTexture.id != 0)
    {
        SetTexture(LoadTexture(texturePath.c_str()));
    } else
    {
        SetTexture(LoadTexture(INVALID_RESOURCE_PATH.c_str()));
    }

    frameRect = Rectangle{ 0, 0, playerTexture.width / 10.0f, (float)playerTexture.height };
}

void Player::Update(float deltaTime)
{
    UpdateMovementDir();

    Vector2Normalize(moveDir);

    position.x += moveDir.x * movementSpeed * deltaTime;
    position.y += moveDir.y * movementSpeed * deltaTime;
}

void Player::Draw()
{
//    DrawTexture(playerTexture, 250, 300, WHITE);
    DrawTextureRec(playerTexture, frameRect, {position.x, position.y}, WHITE);
}

void Player::UpdateMovementDir()
{
    moveDir.x = 0;
    moveDir.y = 0;

    if (IsKeyDown(KEY_W))
    {
        moveDir.y -= 1;
    }
    if (IsKeyDown(KEY_A))
    {
        moveDir.x -= 1;
    }
    if (IsKeyDown(KEY_S))
    {
        moveDir.y += 1;
    }
    if (IsKeyDown(KEY_D))
    {
        moveDir.x += 1;
    }
}