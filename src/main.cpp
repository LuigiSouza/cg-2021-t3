/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Pode ser utilizada para fazer desenhos, animacoes, e jogos simples.
//  Tem tratamento de mouse e teclado
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp

//  Todos os arquivos do projeto devem ser .cpp
//
//  Versao 2.0
//
// *********************************************************************/

/***********************************************************************
 *
 * Funções básicas implementadas:
 *
- Inserir/excluir figura.
- Cor da figura.
- Preenchimento da figura.
- Editar tamanho da figura.
- Editar orientação da figura.
- Enviar para frente/traz.
- Salvar em arquivo e carregar de arquivo.

/------------------------------------------------------------------------
 *
 * Funções extras implementadas:
 *
- Sinalizar qual figura está selecionada.
- Rotacionar figura em qualquer ângulo.
- Permitir inserir polígonos quaisquer.
************************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <iostream>
#include <fstream>

#include "gl_canvas2d.h"

#include "Handles/HandleMouse.hpp"
#include "Handles/Point.hpp"

#include "Panel/Panel.hpp"

#define PI_div_4 0.785398163397
#define PI_div_2 1.570796326795

int screenWidth = 1024, screenHeight = 768;
Mouse *mouse_state;

double gravity = 50.0;

// Variable to keep chosen figure when clicking a panel option
bool click = false;

// Variable to track new figure
float new_fig_r = 0, new_fig_g = 1, new_fig_b = 0;

/***********************************************************
*
* Render Functions
*
************************************************************/

void render_cursor_polygon()
{
}

void render_figures()
{
}

void high_light()
{
}

Vector2 quadratic_bezier(Vector2 p0, Vector2 p1, Vector2 p2, double t)
{
   return p0 * ((1 - t) * (1 - t)) + p1 * (2 * (1 - t) * t) + p2 * t * t;
}

double quadratic_bhaskara(double a, double b, double c)
{
   double discriminant = b * b - 4 * a * c;
   double x1 = (-b + sqrt(discriminant)) / (2 * a);
   double x2 = (-b - sqrt(discriminant)) / (2 * a);
   return x1 > 0 ? x1 : x2;
}

/***********************************************************
*
* Load/Create Functions
*
************************************************************/

void dispose()
{
   delete mouse_state;
}

/***********************************************************
*
* Update Functions
*
************************************************************/

void update()
{
}

double t = 0;

/***********************************************************
*
* Canvas Functions
*
************************************************************/

//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render()
{
   CV::clear(0, 0, 0);

   double mousex = mouse_state->getX();
   double mousey = mouse_state->getY();

   Vector2 p0 = Vector2(200, 400);

   double dist = Point::distance(mousex, mousey, p0.x, p0.y);

   double lim_radius = 150;
   double max_mul = std::min(dist, lim_radius);

   Vector2 p1 = Vector2(((mousex - p0.x) / (dist)) * max_mul + p0.x, ((mousey - p0.y) / (dist)) * max_mul + p0.y);

   double time = quadratic_bhaskara(-(0.5 * gravity), (p1.y - p0.y), p0.y);
   std::cout << " p " << p1.x << " time " << time << std::endl;
   Vector2 p2 = Vector2(p0.x + ((p1.x - p0.x) * time), 0);

   p1 = ((p1 - p0) * 4) + p0;

   CV::circleFill(p0.x, p0.y, 2, 10);
   CV::circleFill(p1.x, p1.y, 2, 10);
   CV::circleFill(p2.x, p2.y, 2, 10);

   t += 0.01;
   t = t > 1 ? 0 : t;
   Vector2 q0 = quadratic_bezier(p0, p1, p2, t);
   CV::circleFill(q0.x, q0.y, 5, 10);
}

//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key)
{
   bool fecha = true;
   switch (key)
   {
   case 13: // enter: forces a polygon to finish before clicking in first vertice
      break;
   case 19: // ctrl + s
      break;
   case 27: // finaliza programa após clicar duas vezes
      if (fecha)
      {
         dispose();
         exit(0);
      }
      break;
   case 43: // +
      break;
   case 45: // -
      break;
   case 102: // f
      break;
   case 127: // del
      break;
   case 214:
      mouse_state->setCtrl(true);
      break;
   }
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   // printf("\nLiberou tecla: %d", key);
   switch (key)
   {
   case 214:
      mouse_state->setCtrl(false);
      break;
   }
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
   // printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction, x, y);

   mouse_state->setX(x);
   mouse_state->setY(y);

   update();

   // Left click
   if (button == 0)
   {
      // Release
      if (state == 1)
      {
      }
      // Push
      else if (state == 0)
      {
      }
   }
}

int main(void)
{
   CV::init(&screenWidth, &screenHeight, "Teste trabalho 1");

   mouse_state = new Mouse();

   CV::run();
}
