#ifndef __DART_H__
#define __DART_H__

#include "../Handles/HandleMouse.h"
#include "../Handles/Vector2.h"
#include "../Handles/Point.h"

#include "../gl_canvas2d.h"

class Dart
{
private:
    Vector2 prevPos, pos;
    Vector2 p0, p1, p2;

    float force = 1.0;
    float t = 0.0;

    bool it_fell;

    static float max_force;
    static float gravity;
    static float dart_size;

    Vector2 scalePoint(Mouse mouse, float scale);
    Vector2 getPointP1(Mouse mouse);
    Vector2 getPointP2();

public:
    Dart(Vector2 _p0);
    Dart(float _x, float _y);
    ~Dart();

    void reset_dart();

    void update_points(Mouse mouse);
    void update_dart();

    void render();
    void render_dart();
    void render_path();

    bool hitGround();
    Vector2 getPos();
    float getForce();
};

#endif
