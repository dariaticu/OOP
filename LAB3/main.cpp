#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	cout << Math::Add(5, 3) << endl;
	cout << Math::Add(5, 3, 2) << endl;
	cout << Math::Add(5.5, 3.2) << endl;
	cout << Math::Add(1.1, 2.2, 3.3) << endl;
	cout << Math::Mul(4, 3) << endl;
	cout << Math::Mul(4, 3,2) << endl;
	cout << Math::Mul(2.5,2.0) << endl;
	cout << Math::Mul(1.5,2.0,3.0) << endl;
	
    
    cout << Math::Add(5, 10, 20, 30, 40, 50) << endl;

    const char* s1 = "Salut, ";
    const char* s2 = "Lume!";
    char* concatStr = Math::Add(s1, s2);

    if (concatStr != nullptr) {
        cout << "Add(const char*, const char*): " << concatStr << endl;
        delete[] concatStr;
    }

    // Testare cu nullptr
    char* nullTest = Math::Add(s1, nullptr);
    if (nullTest == nullptr) {
        cout << "Testare nullptr: Functia a returnat corect nullptr." << endl;
    }

    return 0;
}
