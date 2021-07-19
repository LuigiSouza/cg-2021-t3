#include "Balloon.h"

void Balloon::render(void)
{
    CV::color(this->r, this->g, this->b);
    CV::circleFill(pos.x, pos.y, this->size, 10);
    CV::color(0, 0, 0);
}

void Balloon::update(void)
{
}

void Balloon::set_color(float _r, float _g, float _b)
{
    this->r = _r;
    this->g = _g;
    this->b = _b;
}

void Balloon::set_color(int index)
{
    float *rgb = CV::get_color(index);
    this->r = rgb[0];
    this->g = rgb[1];
    this->b = rgb[2];
}

void Balloon::set_random_color(double seed)
{
    srand(seed);
    int r = rand() % 16;
    r = r == 0 ? r + 1 : r; // não pegar a cor preta
    this->set_color(r);
}

Balloon::Balloon(float _x, float _y)
{
    this->pos = Vector2(_x, _y);
    was_pop = false;
    this->r = 1.0;
    this->g = 0.0;
    this->b = 1.0;
}

Balloon::~Balloon()
{
}

float Balloon::size = 10.0;
