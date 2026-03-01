#include "NumberList.h"
#include <iostream>
#include <cmath>
using namespace std;
int i, j;
void NumberList::Init()
{
	count = 0;
}
bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;

	numbers[count] = x;
	count++;
	return true;
}
void NumberList::Sort()
{
	for (i = 0; i < count-1; i++)
		for (j = i+1; j < count; j++)
			if (numbers[i] > numbers[j])
				swap(numbers[i], numbers[j]);
}
void NumberList::Print()
{
	for (i = 0; i < count; i++)
		cout << numbers[i] << " ";
}