#include "Cannon.h"

Cannon::Cannon(float _x, float _y) : dart(_x, _y)
{
    this->pos = Vector2(_x, _y);
    this->direction[0] = pos;
    this->direction[1] = Vector2(pos.x - minimum_force / 2.0, pos.y + minimum_force);
    this->direction[2] = Vector2(pos.x + minimum_force / 2.0, pos.y + minimum_force);
    this->state = CannonState::Stop;
}

Cannon::~Cannon()
{
}

void Cannon::updateCannon(Mouse mouse)
{
    float mousex = mouse.getX();
    float mousey = mouse.getY();
    float force = Algebra::distance(mousex, mousey, pos.x, pos.y);
    float max_mul = -minimum_force;
    float pointx = ((mousex - pos.x) / (force)) * max_mul + pos.x;
    float pointy = ((mousey - pos.y) / (force)) * max_mul + pos.y;

    Vector2 rotate = Algebra::rotate((pointx - pos.x) / 2, (pointy - pos.y) / 2, PI_div_2);
    rotate.set(rotate.x + pointx, rotate.y + pointy);
    direction[1] = rotate;

    rotate = Algebra::rotate((pointx - pos.x) / 2, (pointy - pos.y) / 2, -PI_div_2);
    rotate.set(rotate.x + pointx, rotate.y + pointy);
    direction[2] = rotate;
}

void Cannon::update(Mouse mouse)
{
    if (dart.hitGround())
    {
        state = CannonState::Stop;
        dart.reset_dart();
    }
    if (state == CannonState::Drag)
    {
        dart.update_points(mouse);
        updateCannon(mouse);
    }
    if (state == CannonState::Shoot)
        dart.update_dart();
}

void Cannon::render(void)
{
    CV::color(1, 1, 1);
    CV::circleFill(pos.x, pos.y, size, 10);

    float cannon_x[3] = {
        direction[0].x,
        direction[1].x,
        direction[2].x};
    float cannon_y[3] = {
        direction[0].y,
        direction[1].y,
        direction[2].y};
    CV::polygonFill(cannon_x, cannon_y, 3);

    if (state == CannonState::Drag)
        dart.render_path();
    if (state == CannonState::Shoot)
        dart.render_dart();
    CV::color(0, 0, 0);
}

Vector2 Cannon::getDartPos(void)
{
    return dart.getPos();
}

Vector2 *Cannon::getDartArrow(void)
{
    return dart.getArrow();
}

void Cannon::shotDart(void)
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
