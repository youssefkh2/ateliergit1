#ifndef background_H_INCLUDED
#define background_H_INCLUDED
#define CAMERA_W 100
#define CAMERA_H 200


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
SDL_Rect backg;

}background;


void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b);
void scrolling_left (background *b);
void scrolling_up (background *b);
void scrolling_down (background *b);



 #endif

