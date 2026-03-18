#include "Sort.h"
#include <iostream>
using namespace std;

int main()
{
    //constructor cu random
    Sort s1(10, 1, 100);
    cout << "--- Exemplu Random ---" << endl;
    s1.Print();
    s1.InsertSort(true); // Sortare crescatoare
    cout << "Dupa InsertSort: ";
    s1.Print();
    cout << "Elemente: " << s1.GetElementsCount() << endl << endl;

    //constructor cu initializer list
    Sort s2 = { 10, 50, 30, 20, 40 };
    cout << "Initializer List" << endl;
    s2.Print();
    s2.BubbleSort(false); // Sortare descrescatoare
    cout << "Dupa BubbleSort (desc): ";
    s2.Print();
    cout << "La indexul 2 avem: " << s2.GetElementFromIndex(2) << endl << endl;

    //constructor din vector existent
    int numere[] = { 100, 5, 20, 1, 75 };
    Sort s3(numere, 5);
    cout << "Exemplu Vector Existent" << endl;
    s3.Print();
    s3.QuickSort(true);
    cout << "Dupa QuickSort: ";
    s3.Print();
    cout << endl;

    //constructor Variadic (count, elemente...)
    Sort s4(5, 2, 5, 1, 7, 0);
    cout << "Exemplu Variadic" << endl;
    s4.Print();
    s4.BubbleSort(true);
    cout << "Dupa BubbleSort: ";
    s4.Print();
    cout << endl;

    //constructor din String
    Sort s5("2,4,1,0,5,100");
    cout << "Exemplu String" << endl;
    s5.Print();
    s5.QuickSort(true);
    cout << "Dupa QuickSort: ";
    s5.Print();

    int poz = 3;
    cout << "La indexul " << poz << " in s5 se afla: " << s5.GetElementFromIndex(poz) << endl;
    return 0;
}