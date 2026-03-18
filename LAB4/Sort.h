#include <initializer_list>
#include <cstdarg>//pt va_list, va_start, va_arg, va_end
#pragma once

class Sort
{
private:
    int* v;
    int n;
    void QuickSortRec(int st, int dr, bool ascendent);
public:
    Sort(int nr, int mini, int maxi);
    Sort(std::initializer_list<int> lista);
    Sort(int* vector, int nr_elem);
    Sort(int nr_elem, ...);
    Sort(const char* sir);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
