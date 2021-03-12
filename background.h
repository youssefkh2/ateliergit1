#ifndef background_H_INCLUDED
#define background_H_INCLUDED

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
SDL_Surface *bg;
SDL_Surface *background;
SDL_Surface *mask;
SDL_Rect camera;
int x_relative;
int y_relative;
SDL_Rect pos;
}background;


void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void scrolling_right (background *b,perssonage *p,SDL_Surface *screen);
void scrolling_left (background *b,perssonage *p,SDL_Surface *screen);

 #endif

