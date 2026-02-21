#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int transf(char* s)
{
	int i=0,nr=0,cif;
	for (i = 0; i < strlen(s); i++)
		if(s[i]>='0' && s[i]<='9')
		nr = nr*10 +s[i]-'0';

	return nr;
}

int main()
{
	int suma = 0;
	char s[101];

	FILE* f = fopen("in.txt", "r");
	if (f == NULL)
	{
		printf("%s", "Nu am putut deschide fisierul f");
		return 0;
	}
	while (fgets(s, sizeof(s),f) != NULL)
		suma = suma + transf(s);
	printf("%d", suma);
	return 0;
}