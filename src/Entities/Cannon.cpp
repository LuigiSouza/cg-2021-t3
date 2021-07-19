#include "Cannon.h"

Cannon::Cannon(float _x, float _y) : dart(_x, _y)
{
    this->pos = Vector2(_x, _y);
}

Cannon::~Cannon()
{
}

void Cannon::update(Mouse mouse)
{
    if (dart.hitGround())
    {
        state = CannonState::Stop;
        dart.reset_dart();
    }
    if (state == CannonState::Drag)
        dart.update_points(mouse);
    if (state == CannonState::Shoot)
        dart.update_dart();
}

void Cannon::render()
{
    CV::color(1, 1, 1);
    CV::circleFill(pos.x, pos.y, size, 10);
    if (state == CannonState::Drag)
        dart.render_path();
    if (state == CannonState::Shoot)
        dart.render_dart();
    CV::color(0, 0, 0);
}

void Cannon::shotDart()
{
    if (state != CannonState::Drag)
        return;
    if (this->dart.getForce() < this->minimum_force)
    {
        state = CannonState::Stop;
        return;
    }
    dart.reset_dart();
    state = CannonState::Shoot;
}

void Cannon::dragCannon(Mouse mouse)
{
    if (state != CannonState::Shoot && Algebra::distance(mouse.getX(), mouse.getY(), pos.x, pos.y) < size)
    {
        state = CannonState::Drag;
    }
}

float Cannon::size = 15.0;
float Cannon::minimum_force = 30.0;
