#include "NumberList.h"
#include <iostream>
using namespace std;

int main()
{
	NumberList v;
	v.Init();
	v.Add(0);
	v.Add(1);
	v.Add(2);
	v.Add(3);
	v.Add(4);
	v.Add(5);
	v.Add(6);
	v.Add(7);
	v.Add(8);
	v.Add(9);
	v.Add(10);
	v.Sort();
	v.Print();
	return 0;
}