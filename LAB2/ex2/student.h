#pragma once
class student
{
private:
	char nume[20];
	float notaM,notaE,notaI, medie;

public:
	void NumeStud(const char x[]);
	void NotaMate(float a);
	void NotaEng(float b);
	void NotaIst(float c);
	float Medie();

	friend int comp_nume(student s1, student s2);
	friend int comp_mate(student s1, student s2);
	friend int comp_eng(student s1, student s2);
	friend int comp_ist(student s1, student s2);
	friend int comp_medie(student s1, student s2);
};

