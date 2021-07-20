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
#include <map>

#include "gl_canvas2d.h"

#include "Entities/Cannon.h"
#include "Entities/Balloon.h"

#include "Handles/HandleMouse.h"
#include "Handles/Algebra.h"

#include "States/Game.h"
#include "States/Menu.h"

int screenWidth = 1024, screenHeight = 768;

Mouse *mouse_state;
std::map<std::string, GameState *> state;
std::string current_state = "Menu";

// Variable to keep chosen figure when clicking a panel option
bool click = false;

/***********************************************************
*
* Render Functions
*
************************************************************/

void render_figures()
{
}

void high_light()
{
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
   state[current_state]->update(*mouse_state);
   mouse_state->update();
}

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

   state[current_state]->render();

   update();
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
   printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction, x, y);

   mouse_state->setX(x);
   mouse_state->setY(y);

   if (state != -2)
      mouse_state->setPress(button);

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
   state["Game"] = new Game(&screenWidth, &screenHeight);
   state["Menu"] = new Menu(screenWidth / 4, 100, screenWidth / 2, 600);

   CV::run();
}
