#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include "../gl_canvas2d.h"
#include "../Handles/HandleMouse.h"

class GameState
{
public:
    virtual void render(void) = 0;
    virtual void update(Mouse mouse) = 0;
    virtual void dispose(void) = 0;
};

#endif