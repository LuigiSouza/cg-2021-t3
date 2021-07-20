#include "Menu.h"

void Menu::render(void)
{
    panel->render();
}

void Menu::update(Mouse mouse)
{
}

void Menu::dispose(void)
{
}

Menu::Menu(float x, float y, float width, float height)
{
    panel = new Panel(x, y, width, height);
}

Menu::~Menu()
{
}
