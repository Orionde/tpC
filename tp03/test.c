#include <stdio.h>
#include <stdlib.h>

typedef unsigned char t_inter;

int main(void)
{
	t_inter inter = 3;
	printf("%d\n", inter);
	t_inter inter2;
	inter2 = inter;
	printf("inter : %d\ninter2 : %d\n\n", inter, inter2);
	inter >>= 1;
	printf("inter : %d\ninter2 : %d\n\n", inter, inter2);
	if(inter2 > inter)
	{
		inter += 128;
		printf("+128");
	}
	return(0);
}
