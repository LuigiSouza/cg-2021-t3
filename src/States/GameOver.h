#ifndef __GAMEOVER_H__
#define __GAMEOVER_H__

#include "GameState.h"

#include "../Panel/Panel.h"

class GameOver : public GameState
{
private:
    Panel *panel;

public:
    void dispose(void);
    void update(Mouse mouse);
    void render(void);

    EnumBotao getDifficult(void);

    GameOver(float x, float y, float width, float height);
    ~GameOver();
};

#endif
