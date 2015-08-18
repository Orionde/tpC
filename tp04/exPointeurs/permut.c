#include <stdio.h>
#include <stdlib.h>

void permut(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void)
{
	int a = 5;
	int b = 8;
	printf("a : %d, b : %d\n", a, b);
	permut(&a, &b);
	printf("a : %d, b : %d\n", a, b);
	return(0);
}
