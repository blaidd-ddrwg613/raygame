#pragma once

#include "raylib.h"

namespace rayGame
{
    class Camera
    {
    public:
        Camera() { camera2D = {{0, 0}, {0, 0}, 0, 1}; };
        Camera(Vector2 offset, Vector2 target, float rotation, float zoom) { camera2D = {offset, target, rotation, zoom}; };

        Vector2 GetTarget() { return camera2D.target; }
        Vector2 GetOffset() { return camera2D.offset; }
        float GetRotation() { return camera2D.rotation; }
        float GetZoom() { return camera2D.zoom; }
        Camera2D GetCamera2D() { return camera2D; }

        void Update(Vector2 target, float rotation, float zoom);

        void SetTarget(Vector2 target) { camera2D.target = target; }
        void SetOffset(Vector2 offset) { camera2D.offset = offset; }
        void SetRotation(float rotation) { camera2D.rotation = rotation; }
        void SetZoom(float zoom) { camera2D.zoom = zoom; }

    private:
        Camera2D camera2D{};
    };
}