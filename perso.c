#include <stdio.h>
#include <stdlib.h>
#include "perso.h"
void initPerso(Personne *p)
{
    int x,y;
    p->imageP[0][0]=IMG_Load("0.png");//right
    p->imageP[0][1]=IMG_Load("1.png");
    p->imageP[0][2]=IMG_Load("2.png");
    p->imageP[0][3]=IMG_Load("3.png");
    p->imageP[0][4]=IMG_Load("4.png");
    p->imageP[0][5]=IMG_Load("5.png");
    p->imageP[0][6]=IMG_Load("6.png");
    p->imageP[1][0]=IMG_Load("7.png");//left
    p->imageP[1][1]=IMG_Load("8.png");
    p->imageP[1][2]=IMG_Load("9.png");
    p->imageP[1][3]=IMG_Load("10.png");
    p->imageP[1][4]=IMG_Load("11.png");
    p->imageP[1][5]=IMG_Load("12.png");
    p->imageP[1][6]=IMG_Load("13.png");
    p->imageP[2][0]=IMG_Load("14.png");//lfouk
    p->imageP[2][1]=IMG_Load("15.png");
    p->imageP[2][2]=IMG_Load("16.png");
    p->imageP[2][3]=IMG_Load("17.png");
    p->imageP[2][4]=IMG_Load("18.png");
    p->imageP[2][5]=IMG_Load("19.png");
    p->imageP[2][6]=IMG_Load("20.png");
    p->imageP[3][0]=IMG_Load("21.png");//louta
    p->imageP[3][1]=IMG_Load("22.png");
    p->imageP[3][2]=IMG_Load("23.png");
    p->imageP[3][3]=IMG_Load("24.png");
    p->imageP[3][4]=IMG_Load("25.png");
    p->imageP[3][5]=IMG_Load("26.png");
    p->imageP[3][6]=IMG_Load("27.png");
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
    p->vitesse_max_perso=20;///mouch suur !!

}

void afficherPerso(Personne p, SDL_Surface * screen)
{
    SDL_Color couleur= {255,255,255};
    SDL_Surface *texte;
    int x,y;
    SDL_BlitSurface(p.imageP[p.ligne][p.colonne],NULL,screen,&p.posP);
    SDL_BlitSurface(p.imgVie[p.numvie],NULL,screen,&p.posV);

    printf("score= %d ",p.score);
    texte = TTF_RenderText_Blended(police, "?", couleur);//score yetbadel printf..
    positiontexte.x = 500;
    positiontexte.y =100;




}
void movePerso(Perso *p,Uint32 dt)
{

    if (p->acceleration%2==0)
        p->vitesse=5;
    if(p->acceleration%2==1)
    {
        if(p->vitesse<p->vitesse_max_perso)
        {
            p->acceleration+=46;
            p->vitesse+=0.5*p->acceleration*dt/1000*dt/1000+p->vitesse*dt/1000;
        }
    }
    int i,j;
    i=p->ligne;
    j=p->colonne;



    //deplacement du clavier down
    if(i==0)
    {
        posP.x+=30;
      animerPerso (&p);
         j++;

    }//fin if

    j=0;
    else if(i==1)
    {
        posP.x-=30;
       animerPerso (&p);
        j++;


    }//fin if


    else if(i==2)
    {posP.x+=30;
        animerPerso (&p);
        j++;
    }//fin if


case SDL_KEYUP:
    if(i==0 && j==0)
    {
        animerPerso (&p);
    }

    else if(i==1 && j==0)

    {
       animerPerso (& p);
    }







}
void animerPerso (Personne* p)
{ SDL_Surface *screen;

SDL_BlitSurface(p->imageP[p->ligne][p->colonne],&positionecran,screen,&p.posP);
        
        SDL_Flip(screen);


}


