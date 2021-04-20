#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{
SDL_Surface *background;
SDL_Rect pos;
Mix_Music *music;
SDL_Rect pos_camera;

}background;


void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scroll (SDL_Rect * back, int direction );


 #endif	
