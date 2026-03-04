#include "student.h"
#include "functii.h"
#include <iostream>
using namespace std;
int main()
{
	student Daria;
	Daria.NumeStud("Daria");
	Daria.NotaMate(8.5);
	Daria.NotaEng(9);
	Daria.NotaIst(6);
	cout << "media notelor studentei Daria este: " << Daria.Medie() << endl;
	

	student Andrei;
	Andrei.NumeStud("Andrei");
	Andrei.NotaMate(6);
	Andrei.NotaEng(7);
	Andrei.NotaIst(10);
	cout << "media notelor studentului Andrei este: " << Andrei.Medie() << endl;

	cout << "compararea numelui:"<< comp_nume(Daria, Andrei) << endl;
	cout << "compararea notelor la MATE:" << comp_mate(Daria, Andrei) << endl;
	cout << "compararea notelor la ENGLEZA:" << comp_eng(Daria, Andrei) << endl;
	cout << "compararea notelor la ISTORIE:" << comp_ist(Daria, Andrei) << endl;
	cout << "compararea mediilor:" << comp_medie(Daria, Andrei) << endl;
	return 0;
}