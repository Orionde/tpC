#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0  // utilisé en interne dans le module entree_sortie.c 
#define OK 0  // les 2 codes retour possibles ...
#define ERREUR 1  // ... de EcrireImagePGM

typedef struct Image
{
	unsigned char* pixels ;
	unsigned int largeur ;
	unsigned int hauteur ;
} t_image ;

//////////////////////////////////////////////////////////////////////////////

void miroir(t_image image, char type)
{
	int i = 0;
	int j = 0;
	int fin = 0;
	int debut;
	int tmp;

	if(type == 1)
	{
		for(i = 0 ; i < image.hauteur ; i++)
		{
			fin = (j + 1) * image.largeur - 1;
			debut = j * image.largeur;
			while(debut < fin)
			{
				tmp = image.pixels[debut];
				image.pixels[debut] = image.pixels[fin];
				image.pixels[fin] = tmp;
				debut ++;
				fin--;
			}
			j++;//Pour savoir sur quelle ligne on est
		}
	}
	else
	{
		fin = image.hauteur * (image.largeur - 1);
		for(i = 0 ; i < image.largeur ; i++)
		{
			while(i < fin)
			{
				tmp = image.pixels[i];
				image.pixels[i] = image.pixels[fin];
				image.pixels[fin] = tmp;

				debut ++;
				fin --;
			}
			j++;
		}
	}
}


void seuillage(t_image image, unsigned char seuil)
{
	int h, l;
	int i = 0;

	for(h = 0 ; h < image.hauteur ; h++)
	{
		for(l = 0; l < image.largeur ; l++)
		{
			if(image.pixels[i] < seuil)
				image.pixels[i] = 0;
			else
				image.pixels[i] = 255;
			i++;
		}
	}
}

void negatif(t_image image)
{
	int h, l;
	int i = 0;

	for(h = 0 ; h < image.hauteur ; h++)
	{
		for(l = 0; l < image.largeur ; l++)
		{
			image.pixels[i] = 255 - image.pixels[i];
			i++;
		}
	}
}

void degrade(t_image image)
{
	int l;
	int h;
	int i = 0;

	for(h = 0 ; h < image.hauteur ; h++)
	{
		for(l = 0; l < image.largeur ; l++)
		{
			image.pixels[i] = (255.0 * l / (image.largeur - 1));
			i++;
		}
	}
}

unsigned char* creerImage(int largeur, int hauteur)
{
	return(malloc((hauteur * largeur + 15) * sizeof(unsigned char)));
}


void afficherImage(char *nomFichier)
{
	char str[256] = {0};
	sprintf(str, "eog %s &", nomFichier);
	system(str);
}

int main()
{
	int largeur = 300;
	int hauteur = 300;
	t_image img;
	//img.pixels = LireImagePGM("guadalest.pgm", &largeur, &hauteur);
	
	img.hauteur = hauteur;
	img.largeur = largeur;
	
	img.pixels = creerImage(largeur, hauteur);
	degrade(img);
	
	negatif(img);
	//miroir(img, 1);


	ecrireImagePGM("truc.pgm", img);
	afficherImage("truc.pgm");

	free(img.pixels);

	return(0);
}
