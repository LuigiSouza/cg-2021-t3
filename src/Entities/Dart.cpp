#include "Dart.h"

Vector2 Dart::getPointP1(Mouse mouse)
{
    float mousex = mouse.getX();
    float mousey = mouse.getY();
    this->force = Point::distance(mousex, mousey, p0.x, p0.y);
    float max_mul = -std::min(this->force, max_force);
    return Vector2(((mousex - p0.x) / (this->force)) * max_mul + p0.x, ((mousey - p0.y) / (this->force)) * max_mul + p0.y);
}

Vector2 Dart::getPointP2()
{
    float a = -(0.5 * gravity);
    float b = (p1.y - p0.y);
    float c = p0.y;

    double discriminant = b * b - 4 * a * c;
    double time = (-b - sqrt(discriminant)) / (2 * a);

    return Vector2(p0.x + ((p1.x - p0.x) * time), 0);
}

Vector2 Dart::scalePoint(Mouse mouse, float scale)
{
    return ((p1 - p0) * (Point::map(((mouse.getY() - p0.y) / (this->force)) * -1, -1, 1, 1, scale))) + p0;
}

void Dart::reset_dart()
{
    it_fell = false;
    t = 0;
    pos = p0;
}

void Dart::update_points(Mouse mouse)
{
    p1 = getPointP1(mouse);
    p2 = getPointP2();
    p1 = scalePoint(mouse, 6);
}

void Dart::update_dart()
{
    if (it_fell)
        return;

    prevPos = pos;
    t += 0.005;
    if (t <= 1)
    {
        pos = Point::quadratic_bezier(p0, p1, p2, t);
    }
    else
    {
        it_fell = true;
    }
}

void Dart::render()
{
    CV::circleFill(p0.x, p0.y, 2, 10);
    CV::circleFill(p1.x, p1.y, 2, 10);
    CV::circleFill(p2.x, p2.y, 2, 10);
    render_path();
}

void Dart::render_path()
{
    for (double i = 0; i <= 1; i += 0.1)
    {
        Vector2 q0 = Point::quadratic_bezier(p0, p1, p2, i);
        CV::circleFill(q0.x, q0.y, 5, 10);
    }
    pos = Point::quadratic_bezier(p0, p1, p2, t);
}

void Dart::render_dart()
{
    float dist_porojectile = Point::distance(prevPos.x, prevPos.y, pos.x, pos.y);
    float proportion = dart_size / dist_porojectile;
    Vector2 render_dart = (prevPos - pos) * proportion + prevPos;

    CV::line(render_dart.x, render_dart.y, pos.x, pos.y);
}

bool Dart::hitGround()
{
    return it_fell;
}

Vector2 Dart::getPos()
{
    return Vector2(pos);
}

float Dart::getForce()
{
    return std::min(this->force, max_force);
}

Dart::Dart(Vector2 _p0)
{
    p0 = Vector2(_p0);
    it_fell = false;
}

Dart::Dart(float _x, float _y)
{
    p0 = Vector2(_x, _y);
    it_fell = false;
}

Dart::~Dart()
{
}

float Dart::max_force = 150.0;
float Dart::gravity = 30.0;
float Dart::dart_size = 30.0;
