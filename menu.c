#include<stdio.h>
#include"SDL/SDL.h"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>



int main(void)
{

// initialisation de variable
    SDL_Surface *screen;
int volume=MIX_MAX_VOLUME;
    SDL_Surface *texte;
    SDL_Surface *background;
    SDL_Rect positionecran;
    SDL_Surface *play;
    SDL_Surface *playmotion;
    SDL_Surface *playclic;
    SDL_Surface *exit;
    SDL_Surface *continu;
    SDL_Surface *new;
    SDL_Surface *moins;
    SDL_Surface *plus;
    SDL_Surface *exitmotion;
    SDL_Surface *exitclic;
    SDL_Surface *option;
    SDL_Surface *optionclic;
    SDL_Surface *optionmotion;
    SDL_Rect positionplay;
    SDL_Rect positionmoins;
    SDL_Rect positioncontinu;
    SDL_Rect positionplus;
    SDL_Rect positionon;
    SDL_Rect positionoff;
    SDL_Surface *backoption;
    SDL_Surface *back;
SDL_Surface *backmotion;
    SDL_Rect positionoption;
    SDL_Rect positiontexte;
SDL_Rect positionback;
    SDL_Rect positionbackoption;
    SDL_Rect positionexit;
    Mix_Chunk *son;
    Mix_Music *music;
    SDL_Surface *on;
    SDL_Surface *off;
    SDL_Surface *t[18];
    /*SDL_Surface *sprite;
    SDL_Rect right[5],left[5];  //tableau
    SDL_Rect positionsprite;*/
    int x, y;
    int position=3;
    char pause;
    int a,b;
    int resolution=0;
    int verif=0;
    int test=0,f=0;
    SDL_Event event;
    SDL_Event event2;
    TTF_Font *police = NULL;
    SDL_Color couleurJaune= {255,255,0};
int num=0;
    /*le tableau des images */
   t[0]=IMG_Load("background.png");
    t[1]=IMG_Load("1.png");
    t[2]=IMG_Load("2.png");
    t[3]=IMG_Load("3.png");
    t[4]=IMG_Load("4.png");
    t[5]=IMG_Load("5.png");
    t[6]=IMG_Load("6.png");
    t[7]=IMG_Load("7.png");
    t[8]=IMG_Load("8.png");
    t[9]=IMG_Load("9.png");
    t[10]=IMG_Load("10.png");
    t[11]=IMG_Load("11.png");
    t[12]=IMG_Load("12.png");
    t[13]=IMG_Load("13.png");
    t[14]=IMG_Load("14.png");
    t[15]=IMG_Load("15.png");
    t[16]=IMG_Load("16.png");
    t[17]=IMG_Load("17.png");
    positionecran.x=-130;
    positionecran.y=0;
    //positionecran.w=background->w;
    int i=0,j;


    /* Chargement de la police */
  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER )!=0)
    {
        printf("Unable to inizialize SDL: %s \n",SDL_GetError());
        return 1;
    }
    TTF_Init();
    police = TTF_OpenFont("/usr/share/fonts/truetype/Nakula/nakula.ttf",40);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
    texte = TTF_RenderText_Blended(police, "WINK OF LIGHT", couleurJaune);
    positiontexte.x = 945;
    positiontexte.y = 745;
    
// musique
    if ( Mix_OpenAudio ( 44100, MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) == -1 )
    {
        printf ( " %s", Mix_GetError());
    }
    Mix_AllocateChannels(1);
    music= Mix_LoadMUS("music.mp3");
	Mix_VolumeMusic(volume);
    Mix_PlayMusic(music,-1);

    //son bref
    son = Mix_LoadWAV("mouse_clic.wav");


  

// image bouton-
    moins=IMG_Load("moins.png");
    if(moins==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionmoins.x=700;  // 550 pos 1
    positionmoins.y=260;


 //image bouton+
    plus=IMG_Load("plus.png");

    positionplus.x=1000;
    positionplus.y=260;
/*ouverture fenetre option
    fenetre=SDL_SetVideoMode(400,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(fenetre==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }*/
// background option
    backoption=IMG_Load("backgroundoption.png");
    if(backoption==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }
    positionbackoption.x=450;
    positionbackoption.y=10;
    positionbackoption.w=backoption->w;
// ouverture fenetre
    screen=SDL_SetVideoMode(1500,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("Unable to set video mode : %s",SDL_GetError());
        return 1;
    }
// background
    background=IMG_Load("background.png");
    if(background==NULL)
    {
        printf("Unable to load bitmap: %s\n",SDL_GetError());
        return 1;
    }
    SDL_BlitSurface(background,NULL,screen,&positionecran);
         
    positionecran.x=-130;
    positionecran.y=0;
    positionecran.w=background->w;
// image play
    play=IMG_Load("play.png");
    if(play==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }


    positionplay.x=120;
    positionplay.y=134;
   
// image exit
    exit=IMG_Load("exit.png");
    if(exit==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionexit.x=120;
    positionexit.y=511;
//image continue
   continu=IMG_Load("continunot.png");
    if(exit==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positioncontinu.x=120;
    positioncontinu.y=259;

// image exitmotion
    exitmotion=IMG_Load("exitmotion.png");
    if(exitmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    // image exitclic
    exitclic=IMG_Load("exitclic.png");
    if(exitclic==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }

// image option
    option=IMG_Load("option.png");
    if(option==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    positionoption.x=120;
    positionoption.y=384;
// image optionmotion1
    optionmotion=IMG_Load("optionmotion.png");
    if(optionmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
// image optionclic1
    optionclic=IMG_Load("optionclic.png");
    if(optionclic==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }


// image playmotion
    playmotion=IMG_Load("playmotion.png");
    if(playmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }

// image back
    back=IMG_Load("backclic.png");
    if(back==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
 positionback.x=685;
    positionback.y=425;

// image backmotion
    backmotion=IMG_Load("backmotion.png");
    if(backmotion==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
// image play clic
    playclic=IMG_Load("playclic.png");
    if(playclic==NULL)
    {
        printf("Unable to load detective : %s\n",SDL_GetError());
        return 1;
    }
    /* new background
    new=IMG_Load("backgroundoption.png");
    if(new==NULL)
    {
        printf("Unable to load new: %s\n",SDL_GetError());
        return 1;
    }*/
//bonton on pour la resolution
    on=IMG_Load("on.png");
    if(on==NULL)
    {
        printf("Unable to load on: %s\n",SDL_GetError());
        return 1;
    }
    positionon.x=850;
    positionon.y=150;
//bonton off pour la resolution
    off=IMG_Load("off.png");
    if(off==NULL)
    {
        printf("Unable to load offf: %s\n",SDL_GetError());
        return 1;
    }
    positionoff.x=900;
    positionoff.y=150;


      SDL_BlitSurface(background,NULL,screen,&positionecran);
         SDL_Flip(screen);
      SDL_BlitSurface(play,&positionecran,screen,&positionplay);
SDL_Flip(screen);
       SDL_BlitSurface(option,&positionecran,screen,&positionoption);
SDL_Flip(screen);
        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
SDL_Flip(screen);
      SDL_BlitSurface(continu,&positionecran,screen,&positioncontinu);
SDL_Flip(screen);
      /*SDL_BlitSurface(backoption,&positionecran,screen,&positionbackoption);
SDL_Flip(screen);*/
        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
SDL_Flip(screen);


















    int done=1;
    SDL_EnableKeyRepeat(30,0);
    while (done)

    {
    

 SDL_BlitSurface(t[num],NULL,screen,&positionecran);

if(num==17)
num=0;
else num++;
SDL_BlitSurface(play,&positionecran,screen,&positionplay);

       SDL_BlitSurface(option,&positionecran,screen,&positionoption);

        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);

      SDL_BlitSurface(continu,&positionecran,screen,&positioncontinu);

      
        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
//SDL_Flip(screen);






 
 
        

        f=0;
        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT :
            
                done=0 ;
                break;
            
          
            case SDL_KEYUP:
            {
if(event.key.keysym.sym==SDLK_ESCAPE)
	done=0;

                //deplacement du clavier down
                if(event.key.keysym.sym==SDLK_DOWN)
                {
                    switch (position)
                    {
                    case 2 :
                    {SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position =0;
                        break;
                    }
                    case 0 :
                    {   SDL_BlitSurface(play,&positionecran,screen,&positionplay);

                        SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                        Mix_PlayChannel(-1, son, 0);
                        position =1;
                        break;
                    }
                    case 1 :
                    {SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                        SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                        Mix_PlayChannel(-1, son, 0);
                        position=2;
                        break;
                    }
                    case 3:
                    {
                        
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position =0;
                        break;
                    }
                    }
                }
                //deplacement du clavier up
         if (event.key.keysym.sym == SDLK_o) 
{
  Mix_PlayChannel(-1, son, 1); 
  SDL_BlitSurface(backoption,NULL,screen, &positionbackoption);
  SDL_Flip(screen);
 SDL_BlitSurface(moins,&positionecran,screen,&positionmoins);
                        
                        SDL_BlitSurface(plus,&positionecran,screen,&positionplus);
                     
                      SDL_BlitSurface(back,&positionecran,screen,&positionback);
                       
                        SDL_BlitSurface(on,&positionecran,screen,&positionon);
                          
                       
                            SDL_BlitSurface(off,&positionecran,screen,&positionon);
                        SDL_Flip(screen);
}

                

else if (event.key.keysym.sym == SDLK_f)
{
	 screen=SDL_SetVideoMode(1920,950,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
}
else if (event.key.keysym.sym == SDLK_g)
{
 screen=SDL_SetVideoMode(1500,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
}

 else if (event.key.keysym.sym == SDLK_e) 
{
done=0;
}

else if ( event.key.keysym.sym == SDLK_UP )
                {
                    switch (position)
                    {
                    case 1 :
                    { SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position=0;
                        break;

                    }
                    case 2 :
                    {SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                        SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                        
                        Mix_PlayChannel(-1, son, 0);

                        position =1;
                        break;
                    }
                    case 0 :
                    {SDL_BlitSurface(play,&positionecran,screen,&positionplay);
                        SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                        Mix_PlayChannel(-1, son, 0);

                        position=2;
                        break;
                    }
                    case 3:
                    {
                        SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                        Mix_PlayChannel(-1, son, 0);
                        position =0;
                        break;
                    }
                    }


                }
               
                j=0;
                SDL_Flip(screen);
                break;
            }
            case SDL_MOUSEMOTION :
            {
                x=event.motion.x;
                y=event.motion.y;
                if (x >=positionplay.x && x<= positionplay.x+play->w && y >=positionplay.y && y <= positionplay.y+play->h )
                {
                    SDL_BlitSurface(playmotion,&positionecran,screen,&positionplay);
                   SDL_Flip(screen);
                SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                 SDL_Flip(screen);
                 SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
               SDL_Flip(screen);
                    Mix_PlayChannel(-1, son, 0);




                }
           
               
   

                else if ( x >=positionoption.x && x<=positionoption.x+option->w && y >=positionoption.y && y <= positionoption.y+option->h )
                {
                    SDL_BlitSurface(optionmotion,&positionecran,screen,&positionoption);
                    SDL_Flip(screen);
                     SDL_BlitSurface(play,&positionecran,screen,&positionplay);
                   SDL_Flip(screen);
                     SDL_BlitSurface(exit,&positionecran,screen,&positionexit);
                       SDL_Flip(screen);
                    Mix_PlayChannel(-1, son, 0);
                }
                else if ( x >=positionexit.x && x<=positionexit.x+exit->w && y >=positionexit.y && y <= positionexit.y+exit->h )
                {
                    SDL_BlitSurface(exitmotion,&positionecran,screen,&positionexit);
                       SDL_Flip(screen);
                     SDL_BlitSurface(play,&positionecran,screen,&positionplay);
                   SDL_Flip(screen);
                    SDL_BlitSurface(option,&positionecran,screen,&positionoption);
                    SDL_Flip(screen);
                    Mix_PlayChannel(-1, son, 0);
                }

                break;

            }
            case SDL_MOUSEBUTTONDOWN:
            {
                a=event.button.x;
                b=event.button.y ;
              
                if ( a >=positionplay.x && a<=positionplay.x+play->w && b >=positionplay.y && b <= positionplay.y+play->h )
                {
                    SDL_BlitSurface(playclic,&positionecran,screen,&positionplay);
                    SDL_Flip(screen);
                    SDL_Delay(500);
                    test=1;
                    done=0;

                }
                else if( a >=positionoption.x && a<=positionoption.x+option->w && b >=positionoption.y && b <=  positionoption.y+option->h )
                {
                    SDL_BlitSurface(optionclic,&positionecran,screen,&positionoption);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    while (f==0)
                    {
                        SDL_BlitSurface(backoption,NULL,screen,&positionbackoption);
                        
                        SDL_BlitSurface(moins,&positionecran,screen,&positionmoins);
                        
                        SDL_BlitSurface(plus,&positionecran,screen,&positionplus);
                      
                      SDL_BlitSurface(back,&positionecran,screen,&positionback);
                      
                        
                         SDL_BlitSurface(on,&positionecran,screen,&positionon);
                          
                       
                            SDL_BlitSurface(off,&positionecran,screen,&positionoff);
                        SDL_Flip(screen);
                            

                        while(SDL_PollEvent(&event2))
                        {


                            switch (event2.type)
                            {
                            case SDL_QUIT :
                            {
                                done=0 ;
                                break;
                            }
                            case SDL_MOUSEBUTTONUP :
                            {
                                x=event2.button.x;
                                y=event2.button.y;
                                if (x >=positionplus.x && x<=positionplus.x+plus->w && y >=positionplus.y && y <= positionplus.y+plus->h )
                                    // change volume music
                                {
                                   	if(volume<128)
					{	volume+=33;
                                    		Mix_VolumeMusic(volume);
					}
                                }
                                else if (x >=positionmoins.x && x<=positionmoins.x+moins->w && y >=positionmoins.y && y <= positionmoins.y+moins->h )
                                {
					if(volume>0)
					{	volume-=33;
                                   		 Mix_VolumeMusic(volume);
					}
                                }
                                
                              
                             
                                  // appuye sur back
                                  else if ( x>=positionback.x && x<=positionback.x+back->w && y >= positionback.y && y<=positionback.y+back->h)
                                      { 
                                      SDL_BlitSurface(background,NULL,screen,&positionecran);
         
      SDL_BlitSurface(play,&positionecran,screen,&positionplay);

       SDL_BlitSurface(option,&positionecran,screen,&positionoption);

        SDL_BlitSurface(exit,&positionecran,screen,&positionexit);

      SDL_BlitSurface(continu,&positionecran,screen,&positioncontinu);

      
        SDL_BlitSurface(texte, NULL,screen,&positiontexte);
SDL_Flip(screen); 
                                           

                                           
                                              }
                               /* else if ( x<positionbackoption.x && x>positionbackoption.x+backoption->w && y < positionbackoption.y && y>positionbackoption.y+backoption->h)
                                    //appuye hors de la fenetre
                                    f=1;*/
                                //resolution full screen
                               else if(x>positionon.x && x<positionon.x+on->w && y>positionon.y && y<positionon.y+on->h )
                                {
                                    if (resolution==0)
                                    {
                                        SDL_BlitSurface(on,&positionecran,screen,&positionon);
                                       
                                        screen=SDL_SetVideoMode(1920,950,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
                                        /*SDL_WM_ToggleFullScreen(screen);*/
                                       
                                       resolution=1;
                                    }
                                    else if (resolution==1)
                                    {
                                        SDL_BlitSurface(off,&positionecran,screen,&positionon);
                                        
                                         screen=SDL_SetVideoMode(1500,1000,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
                                        resolution=0;
                                    
                                        /*SDL_WM_IconifyWindow();*/
                                       
                                    }
                                }

                                break;}
                            /*

                            }
                            }
                            SDL_Flip(fenetre);

                        }
                    }
                }*/
                 if ( a >positionexit.x && a<positionexit.x+exit->w && b >positionexit.y && b < positionexit.y+exit->h )
                {
                    SDL_BlitSurface(exitclic,&positionecran,screen,&positionexit);
                   SDL_Flip(screen);
                    done =0;
                }
                break;
            }

 
         

            }


          


        }
     

   /* // boucle du background clic play
    if(test==1)
        while(done==0)
        {
            SDL_BlitSurface(new,NULL,screen,&positionecran);
            SDL_Flip(screen);

            while(SDL_PollEvent(&event2))
            {
                switch (event2.type)
                {
                case SDL_QUIT: 
                {
                    done=1 ;
                    break;
                }
                }
            }*/
        }


//liberer les surfaces
}
}
}
}

   SDL_FreeSurface(background);
    SDL_FreeSurface(play);
 SDL_FreeSurface(back);
   /* SDL_FreeSurface(new);*/
    SDL_FreeSurface(option);
    SDL_FreeSurface(exit);
    SDL_FreeSurface(continu);
    SDL_FreeSurface(on);
    SDL_FreeSurface(off);
    SDL_FreeSurface(moins);
    SDL_FreeSurface(plus);
    SDL_Delay(10); 
    pause=getchar();
    Mix_FreeChunk(son);
    TTF_CloseFont(police);
    TTF_Quit();
    Mix_FreeMusic(music);
    SDL_Quit();
    return 0;
}
