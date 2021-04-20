#include "background.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>



void initialiser_backround (background *b)
{
Mix_Music *music;
b->background=IMG_Load("background.png");
b->pos.x = 0;
b->pos.y = 0;
b->pos.w = b->background->w;
b->pos.h = b->background->h;
music= Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);
b->pos_camera.x=0;
b->pos_camera.y=0;
b->pos_camera.w=CAMERA_W;
b->pos_camera.h=CAMERA_H;



}



void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->background,&b->pos_camera,screen,&b->pos);
/*SDL_BlitSurface(&b->pos_camera,screen,&b->pos,NULL);*/
}

void scroll (SDL_Rect *back, int direction)
{  
if (direction==0)
back->x++ ;
else 
if (direction==1)
back->x-- ;
else 
if (direction==2)
back->y++ ;
else 
if (direction==3)
back->y-- ;
}
