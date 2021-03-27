#include "background.h"
int main (int argc, char *argv[])
{

background b;
SDL_Event event;
SDL_Surface *screen;


if (SDL_Init (SDL_INIT_VIDEO) == -1) {
printf ("Can't init SDL: %s\n", SDL_GetError ());
return EXIT_FAILURE;
}
screen = SDL_SetVideoMode (CAMERA_W, CAMERA_H, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);



initialiser_backround (&b, "background.png");
afficher_background (screen,b);
SDL_Flip (screen);


int continuer = 0;
SDL_EnableKeyRepeat (SDL_DEFAULT_REPEAT_DELAY,
SDL_DEFAULT_REPEAT_INTERVAL);
while (!continuer) {
   while (SDL_PollEvent (&event)){
    switch (event.type) {
   case SDL_QUIT:
  continuer = 1;
break;
  case SDL_KEYDOWN:
  switch (event.key.keysym.sym)
 {
 case SDLK_LEFT:
 scrollToLeft (&b);
break;
 case SDLK_RIGHT:
 scrollToRight (&b);
break;
case SDLK_UP:
 scrollToup (&b);
break;
case SDLK_DOWN:
 scrollTodown (&b);
break;

  }
    break;
  }
}
afficher_background (screen,b);
SDL_Flip (screen);
}
SDL_FreeSurface(screen);
SDL_FreeSurface(b.background);
}





