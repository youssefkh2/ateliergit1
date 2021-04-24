#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"

int main ()
{
enemie e,p;
int C;

int x,y;
SDL_Surface *background;
SDL_Rect positionecran;

SDL_Init(SDL_INIT_VIDEO);
SDL_Surface  *window;
TTF_Font *police = NULL;
SDL_Color couleurJaune= {255,255,0};
SDL_Surface *texte;
SDL_Rect positiontexte;
window=SDL_SetVideoMode(1500,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  
if(window==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER )!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }

//background
background=IMG_Load("background.png");
    if(background==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }
     
    positionecran.x=-400;
    positionecran.y=-100;
    positionecran.w=background->w;


 TTF_Init();
  police = TTF_OpenFont("/usr/share/fonts/truetype/Nakula/nakula.ttf",40);
texte = TTF_RenderText_Blended(police, "vous etes atteint", couleurJaune);
    positiontexte.x = 930;
    positiontexte.y = 715;

SDL_Event event; /* La variable contenant l'événement */
int continuer = 1; /* Notre booléen pour la boucle */
SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
int collision;

 initEnnemi( &e);

while (continuer) 
{ 
SDL_BlitSurface(background,NULL,window,&positionecran);

afficherEnnemie ( e, window);
deplacer( &e);
animerEnnemi( &e);
C=collisionBB(  &p,&e);
if (C==1)
{
SDL_BlitSurface(texte, NULL,window,&positiontexte);
SDL_Flip(window);
}

}
   
   SDL_Quit();    
	return 0;
}
