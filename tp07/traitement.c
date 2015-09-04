#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "images.h"
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////

void degrade(t_image *image)
{
	int l;
	int h;
	int i = 0;

	for(h = 0 ; h < image->hauteur ; h++)
	{
		for(l = 0; l < image->largeur ; l++)
		{
			image->pixels[i] = (255.0 * l / (image->largeur - 1));
			i++;
		}
	}
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void afficherImage(char *nomFichier)
{
	char str[256] = {0};
	sprintf(str, "eog %s &", nomFichier);
	system(str);
}

