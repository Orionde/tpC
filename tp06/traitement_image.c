#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define OK 0
#define ERREUR 1

typedef struct Image
{
	unsigned char* pixels;
	unsigned int largeur;
	unsigned int hauteur;
} t_image ;

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

t_image *creerImage(int largeur, int hauteur)
{
	t_image *image;
	image->largeur = largeur;
	image->hauteur = hauteur;
	image->pixels = malloc((hauteur * largeur + 15) * sizeof(unsigned char));
	return image;
}

///////////////////////////////////////////////////////////////////////////////

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
///////////////////////////////////////////////////////////////////////////////

/*t_image *LireImagePGM(const char* nomFichier)
{
	FILE *f = fopen(nomFichier, "w");
	t_image *image;
	int largeur = 0;
	int hauteur = 0;
	
	fseek(f, 3, SEEK_SET);
	fscanf(f, "%d %d", &largeur, &hauteur);
	
	image = creerImage(largeur, hauteur);
	fread(image->pixels, (largeur * hauteur + 1), 1, f);
	image->hauteur = hauteur;
	image->largeur = largeur;

	return image;

}*/

t_image *LireImagePGM(const char* nomFichier)
{
	FILE *f = fopen(nomFichier, "w");
	t_image *image;
	int largeur = 0;
	int hauteur = 0;
	
	fseek(f, 3, SEEK_SET);
	fscanf(f, "%d %d", &largeur, &hauteur);
	
	image = creerImage(largeur, hauteur);
	fread(image->pixels, (largeur * hauteur + 1), 1, f);
	image->hauteur = hauteur;
	image->largeur = largeur;

	return image;

}

///////////////////////////////////////////////////////////////////////////////

void afficherImage(char *nomFichier)
{
	char str[256] = {0};
	sprintf(str, "eog %s &", nomFichier);
	system(str);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

int main()
{
	t_image *img = LireImagePGM("guadalest.pgm");
	
	//img.hauteur = hauteur;
	//img.largeur = largeur;
	
	//img.pixels = creerImage(largeur, hauteur);
	//degrade(img);
	
	//negatif(img);
	//miroir(img, 1);


	//ecrireImagePGM("truc.pgm", img);
	//afficherImage("truc.pgm");

	//free(img->pixels);

	return(0);
}
