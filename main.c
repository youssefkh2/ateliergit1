#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"

int main ()
{
enemie e;
SDL_Init(SDL_INIT_VIDEO);
SDL_Surface  *window;
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
SDL_Event event; /* La variable contenant l'événement */
int continuer = 1; /* Notre booléen pour la boucle */
SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
void initEnnemi(enemie *e);
while (continuer) 
{ 
void afficherEnnemie (enemie e,SDL_Surface *screen);
void afficherEnnemie (enemie e,SDL_Surface *screen);
void animerEnnemi(enemie *e);

}
   
   SDL_Quit();    
	return 0;
}
