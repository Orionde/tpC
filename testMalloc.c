#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])

{

	int nombreDAmis = 5;
	char* ageAmis = NULL; // Ce pointeur va servir de tableau après l'appel du malloc

	ageAmis = malloc(nombreDAmis * sizeof(int)); // On alloue de la mémoire pour le tableau

	if (ageAmis == NULL) // On vérifie si l'allocation a marché ou non
	{
		exit(0); // On arrête tout
	}

	int len = sizeof(ageAmis);
	printf("%d", len);

	free(ageAmis);
	return 0;

}
