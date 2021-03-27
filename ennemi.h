#ifndef ENNEMI_H
#define ENNEMI_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "ennemi.h"

typedef struct enemie
{
SDL_Surface *img;
SDL_Rect pos;
SDL_Rect animFrame;
int direction;
int state;
}enemie;



void initEnnemi(Ennemi *e);
void afficherEnnemie (Ennemi *e,SDL_Surface *screen);
void animerEnnemi(Ennemi *e);
void deplacer(Ennemi *e);//deplacement aleatoire
int collisionBB(personne p,Ennemi e);
void deplacerIA(Ennemi *e);


#endif
