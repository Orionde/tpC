#ifndef image_h
#define image_h
t_image *LireImagePGM(const char* nomFichier);

int ecrireImagePGM(const char *nomFichier, t_image image);

t_image *creerImage(int largeur, int hauteur);

#endif
