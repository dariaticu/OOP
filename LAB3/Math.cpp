#include "Math.h"
#include <cstdarg>
#include <cstring>

int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	int suma = 0;
	va_list x;
	va_start(x, count);
	for (int i = 0; i < count; i++)
		suma = suma + va_arg(x, int);
	va_end(x);
	return suma;
}
char* Math::Add(const char* s1, const char* s2)
{
	if (s1 == nullptr or s2 == nullptr)
		return nullptr;

	int n1 = strlen(s1), n2 = strlen(s2);
	char* result = new char[n1 + n2 + 1];
	strcpy_s(result, n1 + n2 + 1, s1); // Pentru GCC/Clang foloseste strcpy
	strcat_s(result, n1 + n2 + 1, s2); // Pentru GCC/Clang foloseste strcat

	return result;
}