#ifndef __BALLOON_H__
#define __BALLOON_H__

#include "../Handles/Vector2.h"
#include "../Handles/Algebra.h"
#include "../gl_canvas2d.h"
class Balloon
{
private:
    Vector2 pos;

    static float size;

    float r, g, b;
    bool was_pop;

public:
    Balloon(float _x, float _y);
    ~Balloon();

    void set_random_color(double seed);
    void set_color(int index);
    void set_color(float _r, float _g, float _b);

    void update(Vector2 *dart);
    void render(void);
};

#endif
