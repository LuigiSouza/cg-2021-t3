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

#include "Entities/Dart.h"

#include "Handles/HandleMouse.h"
#include "Handles/Point.h"

#include "Panel/Panel.h"

#define PI_div_4 0.785398163397
#define PI_div_2 1.570796326795

int screenWidth = 1024, screenHeight = 768;
Mouse *mouse_state;
Dart *dart;

double gravity = 30.0;

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
   double x2 = (-b - sqrt(discriminant)) / (2 * a);
   return x2;
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

   dart->update(*mouse_state);
   dart->render();

   // Vector2 q1 = quadratic_bezier(p0, p1, p2, t);
   // Vector2 q2;
   // t += 0.005;
   // if (t > 1)
   // {
   //    q2 = quadratic_bezier(p0, p1, p2, t - 0.015);
   //    t = 0;
   // }
   // else
   // {
   //    q2 = quadratic_bezier(p0, p1, p2, t);
   // }
   // float dist_porojectile = Point::distance(q1.x, q1.y, q2.x, q2.y);
   // float proportion = 30.0 / dist_porojectile;
   // q1 = (q1 - q2) * proportion + q2;

   // CV::line(q1.x, q1.y, q2.x, q2.y);
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
   CV::init(&screenWidth, &screenHeight, "More Bloons");

   mouse_state = new Mouse();
   dart = new Dart(200, 350);

   CV::run();
}
