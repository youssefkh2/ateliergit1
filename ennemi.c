#include "ennemi.h"


void initEnnemi(Ennemi *e)
{
    Uint16 largeur, hauteur;
    e->img = IMG_Load("taswira.png");
    if (!e->img) {
        printf("Failed to load \"%s\"\n", "taswira.png");
        printf("IMG_Load: %s\n", IMG_GetError());
    }

    largeur = e->img->w / nbAnimationFrames;
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
void afficherEnnemie (Ennemi e,SDL_Surface *screen)
{
     SDL_FillRect(screen, &e.pos, SDL_MapRGB(e.img->format, 0, 0, 0));
     SDL_BlitSurface(e.img, &(e.animFrame), screen, &e.pos);
}
//************************************/
void animerEnnemi(Ennemi *e)
{
e->animFrame.y =e->direction*e->animFrame.h;//(se positionner dans la ligne correspondant a la direction)
if( e->animFrame.x = e->img->w - e->animFrame.w )//(si dernier frame atteint)
    e->animFrame.x =0;//(revenir au premier frame)
else
    e->animFrame.x = e->animFrame.x + e->animFrame.w; //(avancer au frame suivant)

}
//**************************************************/
void deplacer (Ennemi *e)
{
int PosMax=10;
int PosMin=2;

if (e->pos.x> PosMax)
    e->direction=1;
else (e->pos.x<PosMin)
    e->direction=0;

if (e->direction==0)
    e->pos.x++ ;
else
    e->pos.x-- ;
}

//********************
int collisionBB( Ennemi *p,Ennemi *e)
{
if (p->pos.x + p->pos.w< p->pos.x)||
   (p->pos.x> e->pos.x +e->pos.w)||
   (p->pos.y + p->pos.h< e->pos.y)||
   (p->pos.y> e->pos.y + e->pos.h )
    Collision = 0; // pas de collision
else
    Collision = 1;

return Collision;
}
//*********************//
/*void deplacerIA(Ennemi *e);*/
//**********************//
