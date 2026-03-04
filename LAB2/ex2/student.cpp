#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;

void student::NumeStud(const char x[])
{
	strcpy(nume, x);
}
void student::NotaMate(float a)
{
	if (a < 1 || a>10)
	{
		cout << "Nota nu e valida";
		return;
	}
	notaM = a;
}
void student::NotaEng(float b)
{
	if (b < 1 || b>10)
	{
		cout << "Nota nu e valida";
		return;
	}
	notaE = b;
}
void student::NotaIst(float c)
{
	if (c < 1 || c>10)
	{
		cout << "Nota nu e valida";
		return;
	}
	notaI = c;
}
float student::Medie()
{
	medie = (notaM+notaE+notaI) / 3.0f;
	return medie;
}
