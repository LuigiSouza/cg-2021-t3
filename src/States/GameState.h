#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <string>
#include <list>

#include "../gl_canvas2d.h"
#include "../Handles/HandleMouse.h"

#include "../Panel/Botao.h"

class GameState
{
protected:
    std::string name_state;
    std::string change_state;

    int used_darts, poped_balloons, total_balloons;

    EnumBotao difficult;

public:
    virtual ~GameState() {}

    static int total_darts;

    virtual void render(void) = 0;
    virtual void update(Mouse mouse) = 0;

    virtual void reset(EnumBotao difficult)
    {
        this->difficult = difficult;
        this->change_state = name_state;
    }

    EnumBotao getDifficult(void)
    {
        return this->difficult;
    }

    std::string get_changeState(void)
    {
        return change_state;
    }

    std::list<int> getPoints(void)
    {
        return {used_darts, poped_balloons, total_balloons};
    }

    void setPoints(std::list<int> points)
    {
        auto l_front = points.begin();

        used_darts = *l_front;
        std::advance(l_front, 1);
        poped_balloons = *l_front;
        std::advance(l_front, 1);
        total_balloons = *l_front;
    }
};

#endif
