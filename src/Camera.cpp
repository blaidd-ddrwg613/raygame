#include "Camera.h"

void rayGame::Camera::Update(Vector2 target, float rotation, float zoom)
{
    camera2D.target = target;
    camera2D.rotation = rotation;
    camera2D.zoom = zoom;
}
