#include <stdio.h>
#include <stdlib.h>
#include"SDL/SDL.h"
#include "perso.h"
#include <math.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
 



int main()
{
    Uint32 dt, t_prev;
    Personne p,p1;
    int i,j=0;
    int x,y;
     int test=0;
    int FPS;
   TTF_Font *police = NULL;
    SDL_Event event;
    SDL_Surface *screen;
   SDL_Surface *background;
SDL_Rect positionecran;
    char niveau;////play ou option ou exit
//screen
    screen=SDL_SetVideoMode(1500,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);///1500,1000
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

///background
background=IMG_Load("background.png");
    if(background==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }
     
    positionecran.x=-400;
    positionecran.y=-100;
    positionecran.w=background->w;
   initPerso(&p);
    // initPerso(&p1);
    while(test==0)
    {
        
        t_prev=SDL_GetTicks();	//au début de la boucle de jeu
        
       
          SDL_BlitSurface(background,NULL,screen,&positionecran);
           afficherPerso( p, screen,police);
            
          
           if(p.vitesse>0)
         p.acceleration=-0.001;
         p.colonne++;
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
                   { //deplacement du clavier down
                   
                      if(event.key.keysym.sym==SDLK_ESCAPE)
                    {

                       test=1;
                      break;

                      }
                    if(event.key.keysym.sym==SDLK_RIGHT)
                    {
                        p.ligne=0;
                         p.acceleration+=0.005;
                         
              
                       

                    }//fin if
                    
                   
                    else if(event.key.keysym.sym==SDLK_LEFT)
                    {
                        p.ligne=1;
                         p.acceleration-=0.01;
                       

                    }//fin if

                   else if(event.key.keysym.sym==SDLK_UP)
                    {
                       saut(& p, dt, p.posP.y);


                     }
                   
              
                     
                    movePerso(&p, dt) ;
                   animerPerso (& p);
                   
                    }
                    break;

                case SDL_KEYUP:
                   { 
                    if(event.key.keysym.sym==SDLK_DOWN)
                    {
                        p.ligne=0;
                        p.acceleration-=0.001;
                    }
                      
                      movePerso(&p, dt) ;
                   animerPerso (& p);
                    
                    
                   
                  
                   SDL_Flip(screen);
                    }
                    break;
}///switch thenia
                    

                

                

                }//fin while









                dt=SDL_GetTicks()-t_prev;	//à la fin de la boucle de jeu
          /* if(1000/FPS > dt)
            SDL_Delay(1000/FPS -dt);*/
            };
//fin bloucle do
                SDL_FreeSurface(p.imageP[0][0]);
           
            SDL_Delay(10);
            TTF_CloseFont(police);
            TTF_Quit();

            SDL_Quit();
            return 0;
        }

