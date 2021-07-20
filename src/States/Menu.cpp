#include "Menu.h"

void Menu::render(void)
{
    panel->render();
}

void Menu::update(Mouse mouse)
{
    if (mouse.pushed(0))
    {
        Botao *button = panel->buttonClicked(mouse);
        if (!button)
            return;
        switch (button->get_function())
        {
        case EnumBotao::Jogar:
            this->change_state = true;
            break;
        case EnumBotao::Facil:
            button->set_function(EnumBotao::Dificil);
            this->difficult = EnumBotao::Dificil;
            break;
        case EnumBotao::Dificil:
            button->set_function(EnumBotao::Facil);
            this->difficult = EnumBotao::Facil;
            break;
        }
    }
}

void Menu::dispose(void)
{
}

Menu::Menu(float x, float y, float width, float height)
{
    change_state = false;

    panel = new Panel(x, y, width, height);
    panel->addButton(width / 3, height - 100, 80, 50, EnumBotao::Jogar, 3);
    panel->addButton(width / 3, height - 200, 80, 50, EnumBotao::Facil, 5);

    difficult = EnumBotao::Facil;
}

Menu::~Menu()
{
}
