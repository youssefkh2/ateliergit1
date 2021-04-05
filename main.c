#include <stdio.h>
#include <stdlib.h>
#include "perso.h"

int main()
{
    Uint32 dt, t_prev;
    Personnage p;
    int i,j=0;

    SDL_Event event;
    SDL_Surface *screen;
    char niveau;////play ou option ou exit
//screen
    screen=SDL_SetVideoMode(1500,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
//init police
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER )!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }
    TTF_Init();
    police = TTF_OpenFont("/usr/share/fonts/truetype/Nakula/nakula.ttf",40);
    do
    {
        int test=0;
        i=p.ligne;
        j=p.colonne;
        t_prev=SDL_GetTicks();	//au début de la boucle de jeu
        initPerso(&p);
        switch(niveau)
        {
        case 'play':
            afficherPerso( p, &screen);
            while(SDL_PollEvent(&event))
            {
                switch (event.type)
                {
                case SDL_KEYDOWN:
                    //deplacement du clavier down
                    if(j==7)
                        j=0;
                    if(event.key.keysym.sym==SDLK_RIGHT)
                    {
                        i=0;
              
                        p.numvie=0;
                        p.score=0;

                    }//fin if
                    else if(event.key.keysym.sym==SDLK_a)
                    {
                        p.acceleration=20;

                    }
                    else if(event.key.keysym.sym==SDLK_d)
                    {
                        i=0;

                    }//fin if
                    j=0;
                    else if(event.key.keysym.sym==SDLK_LEFT)
                    {
                        i=1;

                    }//fin if

                    else if(event.key.keysym.sym==SDLK_q)
                    {
                        i=1;

                    }//fin if
                    else if(event.key.keysym.sym==SDLK_z)
                    {
                        i=2;

                    }//fin if
                    else if(event.key.keysym.sym==SDLK_UP)
                    {
                        i=2;

                    }//fin if

                    movePerso(&p, dt) ;
                    break;

                case SDL_KEYUP:
                    if(event.key.keysym.sym==SDLK_a)
                        p.vitesse=5;
                    p.acceleration=0;
                    else if(event.key.keysym.sym==SDLK_RIGHT)
                    {
                        i=0;
                        j=0;
                    }
                    else if(event.key.keysym.sym==SDLK_d)
                    {
                        i=0;
                        j=0;
                    }
                    else if(event.key.keysym.sym==SDLK_LEFT)

                    {
                        i=1;
                        j=0;
                    }
                    else if(event.key.keysym.sym==SDLK_q)

                    {
                        i=1;
                        j=0;
                    }
                    p.acceleration%2==1;

                    break;
                    break;

                case 'option':
                    break;

                case 'exit' :
                    test=1;
                    break;

                }//fin swtich








                dt=SDL_GetTicks()-t_prev;	//à la fin de la boucle de jeu
            }
            while(test=1)
//fin bloucle do
                SDL_FreeSurface(imageP[0][0]);
            SDL_FreeSurface(exit);
            SDL_FreeSurface(continu);
            SDL_Delay(10);
            TTF_CloseFont(police);
            TTF_Quit();

            SDL_Quit();
            return 0;
        }

