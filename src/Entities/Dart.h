#ifndef __DART_H__
#define __DART_H__

#include "../Handles/HandleMouse.h"
#include "../Handles/Vector2.h"
#include "../Handles/Algebra.h"

#include "../gl_canvas2d.h"

class Dart
{
private:
    Vector2 prevPos, pos;
    Vector2 p0, p1, p2;

    Vector2 arrow[3];

    float force = 1.0;
    float t = 0.0;
    float sum_t = 0.005;

    bool it_fell;

    static float max_force;
    static float gravity;
    static float dart_size;

    Vector2 scalePoint(Mouse mouse, float scale);
    Vector2 getPointP1(Mouse mouse);
    Vector2 getPointP2(void);

public:
    Dart(Vector2 _p0);
    Dart(float _x, float _y);
    ~Dart();

    void reset_dart(void);

    void update_points(Mouse mouse);
    void update_dart(void);

    void render_reference(void);
    void render_dart(void);
    void render_path(void);

    bool hitGround(void);
    Vector2 getPos(void);
    Vector2 *getArrow(void);
    float getForce(void);
};

#endif
