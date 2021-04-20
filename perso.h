#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>


typedef struct 
{
 SDL_Surface *imageP[3][3];
SDL_Rect posP;
SDL_Surface *imgVie[4];
int numvie;
SDL_Rect posV;
int ligne;
int colonne;
int up;
int score;
double vitesse, acceleration;
}Personne;


void initPerso(Personne *p);
void initPerso1(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen, TTF_Font *police);
void movePerso(Personne *p,Uint32 dt) ;
void animerPerso (Personne* p);
void saut(Personne* p,int dt,int posinit);

