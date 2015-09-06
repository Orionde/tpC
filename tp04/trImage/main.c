#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "entree_sortie.h"

void afficherImage(char *nomFichier);

int* Histogramme(unsigned char* image, int largeur, int hauteur)
{
	int histo[256] = {0};
	int i;
	for(i = 0 ; i < (largeur * hauteur) ; i++)
	{
		histo[image[i]]++;
	}
	return(histo);
}

void miroir(unsigned char* image, int largeur, int hauteur, char type)
{
	int i, j, a, f, tmp;
	a = 0;
	j = 0;

	if(type == 1)
	{
		for(i = 0 ; i < hauteur ; i++)
		{
			f = (j + 1) * largeur - 1;
			a = j * largeur;
			while(a < f)
			{
				tmp = image[a];
				image[a] = image[f];
				image[f] = tmp;
				a++;
				f--;
			}
			j++;
		}
	}
	else
	{
		/*for(i = 0 ; i < largeur ; i++)
		{
			//i = numéro de colone
			f = i + largeur * hauteur - largeur; //pixel à échanger (bas du fichier)
			a = i; //idem mais début du fichier
			while(a < f)
			{
				tmp = image[a];
				image[a] = image[f];
				image[f] = tmp;
				a += largeur;
				f -= largeur;
			}
		}*/
		for(i = 0; i < largeur ; i++)
		{
			f = (h - 1) * largeur - 1;
			a = i;
			while(a < f)
			{
				tmp = image[a];
				image[a] = image[f];
				image[f] = image[a];

			}
		}
	}
}

void seuillage(unsigned char *image, int largeur, int hauteur, unsigned char seuil)
{
	int i, j, a;
	a = 0;

	for(i = 0 ; i < hauteur ; i++)
	{
		for(j = 0 ; j < largeur ; j++)
		{
			if(image[a] > seuil)
				image[a] = 255;
			else
				image[a] = 0;
			a++;
		}
	}
}

void negatif(unsigned char* image, int largeur, int hauteur)
{
	int i, j, a;
	a = 0;
	for(i = 0 ; i < hauteur ; i++)
	{
		for(j = 0 ; j < largeur ; j++)
		{
			image[a] = 255 - image[a];
			a++;
		}
	}
}


void degrade(unsigned char* image, int largeur, int hauteur)
{
	int i, j, a;
	a = 0;

	for(i = 0 ; i < hauteur ; i++)
	{
		for(j = 0 ; j < largeur ; j++)
		{
			image[a] = j;
			a++;
		}
	}
}

void noir(unsigned char *image, int largeur, int hauteur)
{	
	int i, j, a;
	a = 0;

	for(i = 0 ; i < hauteur ; i++)
	{
		for(j = 0 ; j < largeur ; j++)
		{
			image[a] = 255;
			a ++;
		}
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
	int largeur = 256;
	int hauteur = 256;
	int seuil = 67;
	unsigned char *mem = creerImg(largeur, hauteur);
	char type = 2;
	int *histo = Histogramme(mem, largeur, hauteur);
	mem = LireImagePGM("guadalest.pgm", &largeur, &hauteur);
	noir(mem, largeur, hauteur);
	//degrade(mem, largeur, hauteur);
//	negatif(mem, largeur, hauteur);
	//seuillage(mem, largeur, hauteur, seuil);
	//miroir(mem, largeur, hauteur, type);

	EcrireImagePGM("guadalest.pgm", mem, largeur, hauteur);
	free(mem);

	afficherImage("guadalest.pgm");
	return(0);
}
