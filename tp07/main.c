#include "traitement.h"
#include "io.h"
#include "images.h"

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
