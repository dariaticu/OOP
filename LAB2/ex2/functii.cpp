#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

int comp_nume(student s1,student s2)
{
	if (strcmp(s1.nume, s2.nume) > 0)
		return 1;
	else if (strcmp(s1.nume, s2.nume) == 0)
		return 0;
	return -1;
}

int comp_mate(student s1, student s2)
{
	if (s1.notaM > s2.notaM)
		return 1;
	else
		if (s1.notaM == s2.notaM)
			return 0;
	return -1;
}

int comp_eng(student s1, student s2)
{
	if (s1.notaE > s2.notaE)
		return 1;
	else
		if (s1.notaE == s2.notaE)
			return 0;
	return -1;
}
int comp_ist(student s1, student s2)
{
	if (s1.notaI > s2.notaI)
		return 1;
	else
		if (s1.notaI == s2.notaI)
			return 0;
	return -1;
}
int comp_medie(student s1, student s2)
{
	if (s1.medie > s2.medie)
		return 1;
	else
		if (s1.medie == s2.medie)
			return 0;
	return -1;
}