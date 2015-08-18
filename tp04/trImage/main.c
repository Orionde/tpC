#include <stdio.h>
#include <stdlib.h>
#include "entree_sortie.h"

void afficherImage(char *nomFichier)
{
	//sprintf();
	system("eog");
}

int main(void)
{
	int largeur = 400;
	int hauteur = 534;
	unsigned char * copie = LireImagePGM("guadalest.pgm", &largeur, &hauteur);
	EcrireImagePGM("guadalest_copie.pgm", copie, largeur, hauteur);
	free(copie);
	afficherImage("guadalest_copie.pgm");
	return(0);
}
