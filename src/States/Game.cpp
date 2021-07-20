#include "Game.h"

void Game::render_background(void)
{
    int i;
    float j;
    for (i = *screenHeight, j = 0; i >= 0; i--, j += (255.f / *screenHeight) / 255.f)
    {
        CV::color(j, j * 1.375, 1);
        CV::line(0, i, *screenWidth, i);
    }
}

void Game::render(void)
{
    render_background();
    cannon->render(this->difficult == EnumBotao::Facil);

    for (auto it = balloons.begin(); it != balloons.end(); ++it)
        (*it)->render();
}

void Game::update(Mouse mouse)
{
    if (mouse.pushed(0))
        cannon->dragCannon(mouse);
    else if (mouse.released(0))
        cannon->shotDart();

    cannon->update(mouse);
    for (auto it = balloons.begin(); it != balloons.end(); ++it)
        (*it)->update(cannon->getDartArrow());
}

void Game::dispose(void)
{
    delete cannon;
    for (auto it = balloons.begin(); it != balloons.end(); ++it)
    {
        Balloon *aux = *it;
        balloons.erase(it);
        delete aux;
    }
    balloons.clear();
}

Game::Game(int *_screenWidth, int *_screenHeight)
{
    this->screenWidth = _screenWidth;
    this->screenHeight = _screenHeight;

    change_state = false;

    cannon = new Cannon(200, 350);
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        {
            if (balloons_grid[i][j] == 0)
                continue;
            Balloon *balloon = new Balloon(350 + (10 * 2 * Balloon::getSize()) - (j * 2 * Balloon::getSize()), 100 + (10 * 2 * Balloon::getSize()) - (i * 2 * Balloon::getSize()));
            balloon->set_random_color(((i + 1) * 5) * ((j + 2) * 7));
            balloons.push_back(balloon);
        }
}

Game::~Game()
{
}
