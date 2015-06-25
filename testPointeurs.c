#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]);
void test(int *a);

//On récupère un pointeur, vu qu'on a envoyé une adresse
void test(int *a)
{
	*a = 5;
}

int main(int argc, char * argv[])
{//argc et argv sont les paramètres en entrée du prog. argc = nb arguments, argv = valeur
	int a = argc;

	printf("Nombre de paramètres : %d\n", a);
	printf("Valeur du Paramètre 1 : %s\n", argv[1]);
	
	int *b = &a; //b est un pointeur qui contient l'adresse de a
	printf("Valeur de a : %d\n", a);
	printf("Valeur de b : %p\n\n", b);

	printf("Adresse de a : %p\n", b);
	printf("Adresse de b : %p\n", &b);
	test(&a);//On envoie l'adresse de a à la fonction

	printf("\nNouvelle valeur de a : %d\n", a);
	return 0;
}
