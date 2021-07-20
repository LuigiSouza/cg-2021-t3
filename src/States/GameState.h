#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include "../gl_canvas2d.h"
#include "../Handles/HandleMouse.h"

#include "../Panel/Botao.h"

class GameState
{
protected:
    bool change_state;
    EnumBotao difficult;

public:
    virtual void render(void) = 0;
    virtual void update(Mouse mouse) = 0;
    virtual void dispose(void) = 0;

    void setDifficult(EnumBotao difficult)
    {
        this->difficult = difficult;
    }

    EnumBotao getDifficult(void)
    {
        return this->difficult;
    }

    bool get_changeState(void)
    {
        return change_state;
    }
};

#endif
