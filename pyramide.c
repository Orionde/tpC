#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
void pyramide(int hauteur);
void printCar(int nb, char car);

void printCar(int nb, char car)
{
	int i;
	for(i = 0 ; i < nb; i++)
	{
		printf("%c",car);
	}
}
void pyramide(int hauteur)
{
	int esp = hauteur - 1;
	int car = 1;
	int repet = 1;
	while(repet <= hauteur)
	{
		printCar(esp, ' ');
		printCar(car, '*');
		esp--;
		car += 2;
		repet++;
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	int nombre;
	if(argc == 2)
	{
		nombre = atoi(argv[1]);
		pyramide(nombre);
		return(0);
	}
	else
	{
		printf("Saisie non valide\n");
		return(-1);
	}
}
