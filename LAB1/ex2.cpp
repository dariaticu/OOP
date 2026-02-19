#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int nrcuv = 0,i,j;
	char s[101], cuv[101][101], *p, aux[101];
	scanf("%[^\n]", s);
	
	p = strtok(s, " ");
	while (p != NULL)
	{
		strcpy(cuv[nrcuv], p);
		nrcuv++;
		p = strtok(NULL, " ");
	}
	
	for (i = 0; i < nrcuv; i++)
		for (j = i + 1; j < nrcuv; j++)
			if(strlen(cuv[i])<strlen(cuv[j]))
			{
				strcpy(aux, cuv[i]);
				strcpy(cuv[i], cuv[j]);
				strcpy(cuv[j], aux);
			}
			else 
			if(strlen(cuv[i])==strlen(cuv[j]))
				if (strcmp(cuv[i], cuv[j]) > 0)
				{
					strcpy(aux, cuv[i]);
					strcpy(cuv[i], cuv[j]);
					strcpy(cuv[j], aux);
				}
			
	for (i = 0; i < nrcuv; i++)
		printf("%s", cuv[i]), printf("\n");
	return 0;
}
//scanf citeste pana la primul spatiu
//I went to the library yesterday