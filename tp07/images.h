#ifndef image_h
#define image_h

#define DEBUG 0
#define OK 0
#define ERREUR 1

typedef struct Image
{
	unsigned char* pixels;
	unsigned int largeur;
	unsigned int hauteur;
} t_image ;

#endif
