#ifndef AGENCE_H_INCLUDED
#define AGENCE_H_INCLUDED

typedef struct 
{
 SDL_Surface *imageP[3][7];//////ça depend kadeh men taswiraa 
SDL_Rect posP;
SDL_Surface imgVie[4];
SDL_Rect posV;
int ligne;
int colonne;
int score;
double vitesse, acceleration,vitesse_max_perso;
}Personne;


void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p);
void movePerso(Perso *p,Uint32 dt) ;
void animerPerso (Personne* p);
void saut (Personne* p);
#endif // AGENCE_H_INCLUDED
