#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "entree_sortie.h"

void degrade(unsigned char* image, int largeur, int hauteur)
{
	int i, j, a;
	a = 0;
	
	for(i = 0 ; i < hauteur ; i++)
	{
		for(j = 0 ; i < largeur ; j++)
		{
			image[a] = j;
			a++;
		}
	//	a++;
	}
}

unsigned char* creerImg(int largeur, int hauteur)
{
	unsigned char *mem = malloc(
		(largeur * hauteur) * sizeof(unsigned char)
		+ 15 *sizeof(unsigned char));
	return(mem);
}

void afficherImage(char *nomFichier)
{
	char str[256];
	sprintf(str, "eog %s &", nomFichier);
	system(str);
}

int main(void)
{
	int largeur = 400;
	int hauteur = 534;
	unsigned char *mem = creerImg(largeur, hauteur);
	degrade(mem, largeur, hauteur);
	//EcrireImagePGM("degrade.pgm", mem, largeur, hauteur);
	//free(mem);
	//afficherImage("degrade.pgm");
	return(0);
}
