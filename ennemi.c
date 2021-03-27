#include "ennemi.h"


void initEnnemi(Ennemi *e)
{
    Uint16 largeur, hauteur;
    e->img = IMG_Load("ressources/sonic4.png");
    if (!e->img) {
        printf("Failed to load \"%s\"\n", "ressources/sonic4.png");
        printf("IMG_Load: %s\n", IMG_GetError());
    }

    largeur = e->img->w / nbAnimationFrames;
    hauteur = e->img->h;

    e->pos = (SDL_Rect){ .x = 0, .y = 0, .w = width, .h = height };

    e->animFrame = (SDL_Rect){ .x = 0, .y = 0, .w = largeur, .h = hauteur };

    e->direction = 0;

    e->state = 0;
}

//******************************************/
void afficherEnnemie (Ennemi *e,SDL_Surface *screen)
{
     SDL_FillRect(screen, &e.pos, SDL_MapRGB(e.img->format, 0, 0, 0));
     SDL_BlitSurface(e.img, &(e.animFrame), screen, &e.pos);
}
//************************************/
void animerEnnemi(Ennemi *e)
{
e->pos.y =e->direction;//(se positionner dans la ligne correspondant a la direction)
if( e->pos.x = e->img->w - e->pos.w )//(si dernier frame atteint)
    e->pos.x =0;//(revenir au premier frame)
else
    e->pos.x = e->pos.x + e->pos.w; //(avancer au frame suivant)

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

if (e->direction=0)
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
