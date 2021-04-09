#include <stdio.h>
#include <stdlib.h>
#include "perso.h"

int main()
{
    Uint32 dt, t_prev;
    Personnage p;
    int i,j=0;
    int x,y;
    int FPS;
   TTF_Font *police = NULL;
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
        case 'P':
            afficherPerso( p, &screen,&police);
           if(p.vitesse>0)
         p.acceleration=-0.001;
         j++;
          if(p.vitesse<0)
        
            p.acceleration=0;
            p.vitesse=0;
           p.ligne=0;
           p.colonne=0;
            
         
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
                         p.acceleration+=0.005;
                         
              
                       

                    }//fin if
                    
                   
                    else if(event.key.keysym.sym==SDLK_LEFT)
                    {
                        i=1;
                         p.acceleration-=0.01;
                        if(p.vitesse<0)
                        { p.ligne=1;
                        p.colonne=0;}

                    }//fin if

                    else if(event.key.keysym.sym==SDLK_UP)
                    {
                       saut(& p, dt, p.posP.y)


                     }
                   
                   

                    movePerso(&p, dt) ;
                    animerPerso (& p);
                    break;

                case SDL_KEYUP:
                    
                    else if(event.key.keysym.sym==SDLK_RIGHT)
                    {
                        i=0;
                        p.acceleration-=0.001;
                    }
                      movePerso(&p, dt) ;
                    animerPerso (& p);
                   
                   
                   
                   

                    break;
                    break;

                case 'o':
                    break;

                case 'e' :
                    test=1;
                    break;

                }//fin swtich








                dt=SDL_GetTicks()-t_prev;	//à la fin de la boucle de jeu
            if(1000/FPS > dt)
            SDL_Delay(1000/FPS -dt);
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

