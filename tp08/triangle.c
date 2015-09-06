#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **tab = (int **)malloc(8 * sizeof(int *));
	int i = 0;
	int j = 0;
	while(i < 8)
	{
		tab[i] = (int *)malloc((i + 1) * sizeof(int));
		i++;
	}
	
	i = 0;
	
	while(i < 8)
	{
		j = 0;
		while(j <= i)
		{
			if(j == 0 || j == i)
				tab[i][j] = 1;
			else
				tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while(i < 8)
	{
		j = 0;
		while(j <= i)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	return(0);
}
