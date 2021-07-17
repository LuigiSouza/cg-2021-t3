#ifndef __DART_H__
#define __DART_H__

#include "../Handles/HandleMouse.h"
#include "../Handles/Vector2.h"
#include "../Handles/Point.h"

#include "../gl_canvas2d.h"

class Dart
{
private:
    Vector2 pos;
    Vector2 p0, p1, p2;

    float force = 1.0;

    static float max_force;
    static float gravity;

    Vector2 scalePoint(Mouse mouse, float scale);
    Vector2 getPointP1(Mouse mouse);
    Vector2 getPointP2();

public:
    Dart(Vector2 _p0);
    Dart(float _x, float _y);
    ~Dart();

    void update(Mouse mouse);
    void render();
    void render_path();

    Vector2 getPos();
};

#endif
