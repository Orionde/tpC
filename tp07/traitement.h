#ifndef traitement_h
#define traitement_h

void miroir(t_image image, char type);
void seuillage(t_image image, unsigned char seuil);
void negatif(t_image image);
void degrade(t_image *image);
void afficherImage(char *nomFichier);

#endif
