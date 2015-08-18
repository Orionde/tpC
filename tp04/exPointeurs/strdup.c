#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

char* m_strdup(char* s)
{
	int i = strlen(s);
	char *str;
	str = malloc(i * sizeof(char));
	for(i = 0 ; i < strlen(s); i++)
		str[i] = s[i];

	return(str);
	free(str);
}

int main(void)
{
	char chaine[] = "Exemple de chaine a copier" ;
	char* copie = m_strdup(chaine);
	printf("%s\n", copie);
	return(0);
}
