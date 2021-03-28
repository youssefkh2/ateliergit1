#include "background.h"


void initialiser_backround (background *b)
{

b->background=IMG_Load("background.png");
/*screen-w=1000
screen-h=800*/
b->backg.x = 0;
b->backg.y = 0;
b->backg.w = b->background->w;
b->backg.h = b->background->h;

}



void afficher_background (SDL_Surface *screen,background *b)
{
SDL_BlitSurface(b->background,&b->camera,screen,NULL);


// background 
    background=IMG_Load("background.png");
    if(background==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }


// musique
    if ( Mix_OpenAudio ( 44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1 )
    {
        printf ( " %s", Mix_GetError());
    }
    Mix_AllocateChannels(1);
    music= Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(music,-1);

}






void scroll_Left (background * b){
if (b->backg.x != 0)
b->backg.x--;
}
void scroll_Right (background * b){
if (b->backg.w - b->backg.x != CAMERA_W)
b->backg.x++;
}

void scrolling_down (background *b);
{
if (b->backg.y != 0)
b->backg.y--;
}

void scrolling_up (background *b);
{
if (b->backg.h - b->backg.y != CAMERA_H)
b->backg.y++;
}















