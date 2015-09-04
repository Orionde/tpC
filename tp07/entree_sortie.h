#ifndef entree_sortie_h
#define entree_sortie_h

t_image *creerImage(int largeur, int hauteur);
t_image *lireImagePGM(const char* nomFichier);
int ecrireImagePGM(const char *nomFichier, t_image image);

#endif
