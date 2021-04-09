#include <stdio.h>
#include <stdlib.h>
#include "perso.h"
#include <SDL/SDL_ttf.h>
void initPerso(Personne *p)
{
    int x,y;
    p->imageP[0][0]=IMG_Load("0.png");//right
    p->imageP[0][1]=IMG_Load("1.png");
    p->imageP[0][2]=IMG_Load("2.png");
    p->imageP[1][0]=IMG_Load("3.png");//left
    p->imageP[1][1]=IMG_Load("4.png");
    p->imageP[1][2]=IMG_Load("5.png");
    p->imageP[2][0]=IMG_Load("14.png");//lfouk
    p->imageP[2][1]=IMG_Load("15.png");
    p->imageP[2][2]=IMG_Load("16.png");
    p->imageP[2][3]=IMG_Load("17.png");
    p->imageP[2][4]=IMG_Load("18.png");
    p->imageP[2][5]=IMG_Load("19.png");
    p->imageP[2][6]=IMG_Load("20.png");
   
    p->posP.x=0;
    p->posP.y=500;
    p->imgVie[0]=IMG_Load("vie3.png");
    p->imgVie[1]=IMG_Load("vie2.png");
    p->imgVie[2]=IMG_Load("vie1.png");
    p->imgVie[3]=IMG_Load("vie0.png");
    p->posV.x=200;
    p->posV.y=0;
    p->score=0;
    p->numvie=0;
    p->ligne=0;
    p->colonne=0;
    p->vitesse=5;
    p->acceleration=0;
    p->up=0;

}

void afficherPerso(Personne p, SDL_Surface * screen, TTF_Font *police)
{//police
    SDL_Color couleur= {255,255,255};
    SDL_Surface *texte;
SDL_Rect positiontexte;
    int x,y;
	char ch[10];
    SDL_BlitSurface(p.imageP[p.ligne][p.colonne],NULL,screen,&p.posP);
    SDL_BlitSurface(p.imgVie[p.numvie],NULL,screen,&p.posV);

    sprintf(ch, "score= %d ",p.score);
    texte = TTF_RenderText_Blended(police, ch , couleur);
    positiontexte.x = 500;
    positiontexte.y =100;




}
void movePerso(Personne *p,Uint32 dt)
{
    int i,j;
    i=p->ligne;
    j=p->colonne;



    //deplacement du clavier down
    if(i==0)
    {    p->vitesse+=p->acceleration*dt;
        p->posP.x+=0.5*p->acceleration*dt*dt+p->vitesse*dt;
      
        

    }//fin if

    
    else if(i==1)
    { p->vitesse+=p->acceleration*dt;
        p->posP.x-=0.5*p->acceleration*dt*dt+p->vitesse*dt;
    
    }//fin if


    /*else if(i==2)
    { p->vitesse+=p->acceleration*dt;
        p->posP.x+=0.5*p->acceleration*dt*dt+p->vitesse*dt;
    }//fin if*/


case SDL_KEYUP:
    if(i==0 )
    {
        p->vitesse+=p->acceleration*dt;
        p->posP.x-=0.5*p->acceleration*dt*dt+p->vitesse*dt;
    }

   
}
void animerPerso(Personne* p)
{ if(p->colonne==3)
  p->colonne=0;
else
p->colonne++;

}
void saut(Personne* p,int dt,int posinit)
{int x,y;
if(p->posP.y==40)
{
p->posP.y-=10;
 if(p->posP.y!=posinit)
p->posP.x=0.5*p->acceleration*dt*dt+p->vitesse*dt;
}///fin if
if(p->posP.y==posinit)
p->up=0;
}


