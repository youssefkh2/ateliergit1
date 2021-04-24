#include "ennemi.h"
#include <stdio.h>
#include <stdlib.h>


void initEnnemi(enemie *e)
{
    Uint16 largeur, hauteur;
    e->img = IMG_Load("police.jpeg");
    if (!e->img) {
        printf("Failed to load \"%s\"\n", "taswira.png");
        printf("IMG_Load: %s\n", IMG_GetError());
    }

   
   largeur = e->img->w / 7;
   hauteur = e->img->h/1;

    e->posscreen.x = 0;
    e->posscreen.y = 0;
    
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
SDL_BlitSurface(e.img, &e.animFrame, screen, &e.posscreen);
SDL_Flip(screen);
}
//************************************/
void animerEnnemi(enemie *e)
{
e->animFrame.y =e->direction*e->animFrame.h;//(se positionner dans la ligne correspondant a la direction)
if( e->animFrame.x = e->img->w - e->animFrame.w )//(si dernier frame atteint)
    e->animFrame.x =0;//(revenir au premier frame)
else
    e->animFrame.x = e->animFrame.x + e->animFrame.w; //(avancer au frame suivant)

}
//**************************************************/
void deplacer (enemie *e)
{
int PosMax=10;
int PosMin=2;

if (e->posscreen.x> PosMax)
    e->direction=1;
else if(e->posscreen.x<PosMin)
    e->direction=0;

if (e->direction==0)
    e->posscreen.x++ ;
else
    e->posscreen.x-- ;
}

//********************
int collisionBB( enemie *p,enemie *e)
{
int collision;
if ((p->posscreen.x + p->posscreen.w< p->posscreen.x)||
   (p->posscreen.x> e->posscreen.x +e->posscreen.w)||
   (p->posscreen.y + p->posscreen.h< e->posscreen.y)||
   (p->posscreen.y> e->posscreen.y + e->posscreen.h ))
    collision = 0; // pas de collision
else
    collision = 1;

return collision;
}
//*********************//
/*void deplacerIA(enemie *e);*/
//**********************//
