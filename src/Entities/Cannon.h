#ifndef __CANNON_H__
#define __CANNON_H__

#include "Dart.h"
#include "CannonState.h"

class Cannon
{
private:
    Vector2 pos;

    CannonState state;

    Dart dart;
    static float size;
    static float minimum_force;
    /* data */
public:
    void dragCannon(Mouse mouse);
    void shotDart();

    void render();
    void update(Mouse mouse);

    Cannon(float _x, float _y);
    ~Cannon();
};

#endif
