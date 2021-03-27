#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ennemi.h"

int main (int argc, char const *argv[])
{int nbre_vie=100;
int score=0;
SDL_Init(SDL_INIT_VIDEO);
SDL_Window* window =   SDL_CreateWindow("test",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100,  SDL_WINDOW_SHOWN); 
SDL_Event event; /* La variable contenant l'événement */
int continuer = 1; /* Notre booléen pour la boucle */
SDL_WM_SetCaption("Gestion des événements en SDL", NULL);
initEnnemi(Ennemi &e);
int C=collisionBB(personne p,Ennemi e);
while (continuer) 
{ if (C)
       {nbre_vie--; 
        score--;}
        if ((nbre_vie == 0) ou (score <0)) 
        Continuer=0; 
        else
{
        BlitEntity 
        if (event==SDLK_RIGHT) 
                direction =0 ;
        else 
            if(event==SDLK_LEFT)
            direction =1; 
                
        
        if (direction in [0..1])
              {afficherEnnemie (Ennemi &e,SDL_Surface &screen);
              deplacer(Ennemi &e);;
              animerEnnemi(Ennemi &e);}
      }
 
}
   SDL_DestroyWindow(window);
   SDL_Quit();    
	return 0;
}
