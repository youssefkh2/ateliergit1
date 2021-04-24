#ifndef ENNEMI_H
#define ENNEMI_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"

typedef enum state state;
enum state{waiting,following,attacking};
typedef struct enemie
{
SDL_Surface *img;
SDL_Rect animFrame;
int direction;
state state;
SDL_Rect posscreen;
}enemie;



void initEnnemi(enemie *e);
void afficherEnnemie (enemie e,SDL_Surface *screen);
void animerEnnemi(enemie *e);
void deplacer(enemie *e);//deplacement aleatoire
int collisionBB(enemie *p,enemie *e);
/*void deplacerIA(enemie *e);*/


#endif
