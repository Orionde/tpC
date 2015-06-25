#include <stdio.h>
#include <stdlib.h>

int main(void);
void affichageTab(int tab[], int taille);
int sommeTab(int tab[], int taille);
float moyenValTab(int tab[], int taille);
void supprSup(int tab[], int taille, int valMax);
void tri(int tab[], int taille);
void permut(int *a, int *b);

void permut(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void tri(int tab[], int taille)
{
	int i = 1;
	
	while( i < taille - 1)
	{
		if(tab[i] > tab[i+1])
		{
			permut(&tab[i], &tab[i+1]);
		}
		while(tab[i] < tab[i-1])
		{
			permut(&tab[i], &tab[i-1]);
			i--;
		}
		i++;
	}
}

void supprSup(int tab[], int taille, int valMax)
{
	int i;
	for(i = 0; i < taille ; i++)
	{
		if(tab[i] > valMax)
		{
			tab[i] = 0;
		}
	}
}

float moyenValTab(int tab[], int taille)
{
	int somme = sommeTab(tab, taille);
	return (float)somme /(float) taille;
}

int sommeTab(int tab[], int taille)
{
	int i = 0;
	int somme = 0;
	for(i = 0; i < taille ; i++)
	{
		somme += tab[i];
	}
	return(somme);
}

void affichageTab(int tab[], int taille)
{
	int i = 0;
	for(i = 0 ; i < taille ; i++)
	{
		printf("Valeur de la case %d : %d\n", i, tab[i]);
	}
}

int main(void)
{
	int a[15] = {34, 1, 254, 3, 35, 78, 90, 0, 100, 7, 1, 2, 4, 5, 90};
	/*printf("Première adresse du tableau : %p\n",a);
	printf("Valeur de la première adresse : %d\n", *a);
	printf("Valeur de la deuxième adresse : %d\n",*(a + 1));
	printf("Somme des éléments du tableau : %d\n", sommeTab(a, 4));
	printf("Valeur moyenne : %f\n", moyenValTab(a, 4));
	//affichageTab(a, 4);
	//supprSup(a, 4, 2);
	//affichageTab(a, 4);*/
	tri(a, 15);
	affichageTab(a, 15);
	return 0;
}
