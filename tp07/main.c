#include <stdio.h>
#include <stdlib.h>
#include "images.h"
#include "entree_sortie.h"
#include "traitement.h"

int main()
{
	t_image *img = lireImagePGM("guadalest.pgm");

	//img.hauteur = hauteur;
	//img.largeur = largeur;

	//img.pixels = creerImage(largeur, hauteur);
	//degrade(img);

	//negatif(img);
	//miroir(img, 1);


	//ecrireImagePGM("truc.pgm", img);
	afficherImage("guadalest.pgm");

	//free(img->pixels);

	return(0);
}
