#include <stdlib.h>
#include <stdio.h>
#include "images.h"

t_image *creerImage(int largeur, int hauteur)
{
	t_image *image = malloc(sizeof(t_image));
	image->largeur = largeur;
	image->hauteur = hauteur;
	image->pixels = malloc((hauteur * largeur + 15) * sizeof(unsigned char));
	return image;
}

int ecrireImagePGM(const char *nomFichier, t_image image)
{
	FILE *f =  fopen(nomFichier, "w");
	fprintf(f, "P5\n%d %d\n255\n", image.largeur, image.hauteur);

	if(f)
	{
		fwrite(image.pixels, ((image.hauteur * image.largeur)*sizeof(unsigned char)), 1, f);
		fclose(f);
		return OK;
	}
	else
		return ERREUR;
}

t_image *lireImagePGM(const char* nomFichier)
{
	FILE *f = fopen(nomFichier, "r");
	if(f)
	{
		t_image *image;
		int largeur;
		int hauteur;

		fseek(f, 3, SEEK_SET);
		fscanf(f, "%d %d", &largeur, &hauteur);

		printf("%d %d\n", largeur, hauteur);

		image = creerImage(largeur, hauteur);

		fread(image->pixels - 5, ((largeur * hauteur) * sizeof(unsigned char)), 1, f);

		image->hauteur = hauteur;
		image->largeur = largeur;
		return image;
	}
	else
		return NULL;
}
