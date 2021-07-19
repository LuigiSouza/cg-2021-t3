#ifndef __CANNON_H__
#define __CANNON_H__

#include "Dart.h"
#include "CannonState.h"

class Cannon
{
private:
    Vector2 pos;
    Vector2 direction[3];

    CannonState state;

    Dart dart;
    static float size;
    static float minimum_force;

    void updateCannon(Mouse mouse);
    /* data */
public:
    void dragCannon(Mouse mouse);
    void shotDart(void);

    Vector2 getDartPos(void);
    Vector2 *getDartArrow(void);

    void render(void);
    void update(Mouse mouse);

    Cannon(float _x, float _y);
    ~Cannon();
};

#endif
