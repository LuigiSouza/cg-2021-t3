#include "Botao.h"

Botao::Botao(float _x, float _y, float _larg, float _alt, int function, int *rgb)
{
   altura = _alt;
   largura = _larg;
   x = _x;
   y = _y;
   r = b = 0;
   g = 1;
   this->function = function;
   set_function(function, rgb);
}

void Botao::render()
{
   CV::color(r, g, b);
   CV::rectFill(x, y, x + largura, y + altura);
   CV::color(0, 0, 0);
   if (!isFigure)
      CV::text(x + 5, y + altura / 2, label); //escreve o label do botao mais ou menos ao centro.
   else
      CV::polygon(vx, vy, elems);
}

bool Botao::isInside(Mouse mouse_state)
{
   if (mouse_state.getX() >= x && mouse_state.getX() <= (x + largura) && mouse_state.getY() >= y && mouse_state.getY() <= (y + altura))
   {
      return true;
   }
   return false;
}

void Botao::set_function(int function, int *rgb)
{
   isFigure = false;
   float ang, radius, inc;

   std::string a;

   isFigure = true;
}
