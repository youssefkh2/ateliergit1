#include "ennemi.h"
#include <stdio.h>
#include <stdlib.h>


void initEnnemi(enemie *e)
{
    Uint16 largeur, hauteur;
    e->img = IMG_Load("taswira.png");
    if (!e->img) {
        printf("Failed to load \"%s\"\n", "taswira.png");
        printf("IMG_Load: %s\n", IMG_GetError());
    }

   
   largeur = e->img->w / 7;
   hauteur = e->img->h/2;

    e->pos.x = 0;
    e->pos.y = 0;
    
     e->animFrame .x = 0;
     e->animFrame .y = 0;
     e->animFrame .w = largeur;
     e->animFrame .h = hauteur;
     e->direction = 0;

    e->state = 0;
}

//******************************************/
void afficherEnnemie (enemie e,SDL_Surface *screen)
{
SDL_BlitSurface(e.img, NULL, screen, &e.pos);
SDL_Flip(screen);
}
//************************************/
void animerEnnemi(enemie *e)
{
e->posscreen.y =e->direction*e->posscreen.h;//(se positionner dans la ligne correspondant a la direction)
if( e->posscreen.x = e->img->w - e->posscreen.w )//(si dernier frame atteint)
    e->posscreen.x =0;//(revenir au premier frame)
else
    e->posscreen.x = e->posscreen.x + e->posscreen.w; //(avancer au frame suivant)

}
//**************************************************/
void deplacer (enemie *e)
{
int PosMax=10;
int PosMin=2;

if (e->pos.x> PosMax)
    e->direction=1;
else if(e->pos.x<PosMin)
    e->direction=0;

if (e->direction==0)
    e->pos.x++ ;
else
    e->pos.x-- ;
}

//********************
/*int collisionBB( enemie *p,enemie *e)
{
if (p->pos.x + p->pos.w< p->pos.x)||
   (p->pos.x> e->pos.x +e->pos.w)||
   (p->pos.y + p->pos.h< e->pos.y)||
   (p->pos.y> e->pos.y + e->pos.h )
    collisionBB = 0; // pas de collision
else
    collisionBB = 1;

return Collision;
}*/
//*********************//
/*void deplacerIA(enemie *e);*/
//**********************//
