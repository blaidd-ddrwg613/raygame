#pragma once

#include <string>
#include "raylib.h"
#include "raymath.h"
#include "Utils.h"

class Player
{
public:
    Player();
    Player(std::string texturePath);

    Vector2 GetPosition() { return position; };
    Texture2D GetTexture() { return playerTexture; }
    float GetMovementSpeed() { return baseMoveSpeed; }

    void SetPosition(Vector2 pos) { position = pos; }
    void SetTexture(Texture2D texture2D) { playerTexture = texture2D; }
    void SetMovementSpeed(float speed) { baseMoveSpeed = speed; }
    void SetMovementMultiplier(float multiplier) { speedMultiplier = multiplier; }

    void Update(float deltaTime);
    void Draw();


private:

    Texture2D playerTexture;
    Vector2 position;
    Rectangle frameRect;

    Vector2 moveDir;
    float baseMoveSpeed = 10;
    float speedMultiplier = 50;
    float movementSpeed = baseMoveSpeed * speedMultiplier;

    void UpdateMovementDir();

};