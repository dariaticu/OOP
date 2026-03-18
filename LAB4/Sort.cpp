#include "Sort.h"
#include <iostream>
#include <cstdlib> //pt random()
#include <initializer_list>
#include <cstring>
using namespace std;

Sort::Sort(int nr, int mini, int maxi)
{
	n = nr;
	v = new int[n];

	for (int i = 0; i < n; i++)
		v[i] = mini + rand() % (maxi - mini + 1);
}
Sort::Sort(std::initializer_list <int> lista)
{
	n = (int)lista.size();
	v = new int[n];

	// Luăm un pointer către începutul listei de numere
	// const int* deoarece elementele dintr-un initializer_list nu pot fi modificate
	const int* p = lista.begin();
	for (int i = 0; i < n; i++)
		v[i] = p[i];
}
Sort::Sort(int* vector, int nr_elem)
{
	n = nr_elem;
	v = new int[n];
	for (int i = 0; i < n; i++)
		v[i] = vector[i];
}
Sort::Sort(int nr_elem, ...)
{
	n = nr_elem;
	v = new int[n];

	va_list args;
	va_start(args, nr_elem);
	for (int i = 0; i < n; i++)
		v[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(const char * sir)
{
	int index = 0, nr_curent = 0;
	n = 0;
	if (sir[0] != '\0') 
		n = 1; // Dacă există măcar un caracter, avem cel puțin un număr

	for (int i = 0; sir[i] != '\0'; i++) 
		if (sir[i] == ',') 
			n++;
	v = new int[n];
	

	for (int i = 0; sir[i] != '\0'; i++) 
	{
		if (sir[i] == ',')
		{
			v[index] = nr_curent;
			nr_curent = 0;
			index++;
		}
		else
			nr_curent = nr_curent * 10 + sir[i] - '0';
	}
	v[index] = nr_curent;
}

void Sort::InsertSort(bool ascendent)
{
	int i,j, key;
	for (i = 1; i < n; i++)
	{
		key = v[i];
		j = i - 1;
		if (ascendent == true)
		{
			//sort cresc
			while (j >= 0 && v[j] > key)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
		}
		else //sort descresc
		{			
			while (j >= 0 && v[j] < key)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
		}
		v[j + 1] = key;
	}
}
void Sort::QuickSort(bool ascendent)
{
	QuickSortRec(0, n - 1, ascendent);
}
void Sort::QuickSortRec(int st, int dr, bool ascendent)
{
	if (st < dr)
	{
		int m = (st + dr) / 2;
		swap(v[st], v[m]); // punem pivotul la v[st]

		int i = st, j = dr, d = 0;
		while (i < j)
		{
			bool trebuieSchimbat = false;

			// Verificăm dacă elementele v[i] și v[j] sunt în ordine greșită
			if (ascendent) {
				if (v[i] > v[j])
				{
					swap(v[i], v[j]);
					d = 1 - d;
				}
			}
			else {
				if (v[i] < v[j]) 
				{
					swap(v[i], v[j]);
					d = 1 - d;
				}
			}

			i += d;
			j -= (1 - d);
		}

		// Pivotul e acum la poziția i (unde i == j)
		QuickSortRec(st, i - 1, ascendent);
		QuickSortRec(i + 1, dr, ascendent);
	}
}

void Sort::BubbleSort(bool ascendent) {
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;

		// n - i - 1 pentru că ultimele i elemente sunt deja la locul lor
		for (int j = 0; j < n - i - 1; j++) {
			bool trebuieSchimbat = false;

			if (ascendent) {
				if (v[j] > v[j + 1]) trebuieSchimbat = true;
			}
			else {
				if (v[j] < v[j + 1]) trebuieSchimbat = true;
			}

			if (trebuieSchimbat) {
				swap(v[j], v[j + 1]);
				swapped = true;
			}
		}
		// Dacă nu am făcut nicio schimbare în această parcurgere, 
		// înseamnă că vectorul e deja sortat.
		if (swapped == false) {
			break;
		}
	}
}
int Sort::GetElementsCount()
{
	return n;
}
int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < n)
		return v[index];
	return -1;
}
void Sort::Print()
{
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << endl;
}