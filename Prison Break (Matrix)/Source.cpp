#include<fstream>
#include<iostream>
#include"Matrix.h"
#include"Position.h"
#include"Prison.h"
using namespace std;
void Datareader(const char filename[], int &size, matrix *&m);
int main()
{
	matrix *map;
	int size = 0;
	Datareader("Map.txt", size , map);
	for (int i = 0; i < size; i++)
	{
		map[i].print();
		cout << endl;
	}
	Prison a;
	Position *b;
	int s = 0;
	b = a.FindSpeciicPosition(3,map,s);
	for (int i = 0; i < s; i++)
	{
		cout << b[i].rw << "," << b[i].col << endl;
	}
	if (a.EscapeCheck(map,b) == true && b->rw==-1)
	{
		cout << "Prisoner can Escape from Proison !" << endl;
	}
	else
	{
		cout << "Prisoner can not Escape from Proison !" << endl;
	}
	return 0;
}
void Datareader(const char filename[], int &size, matrix *&m)
{
	ifstream fin(filename);
	fin >> size;
	m = new matrix[size];
	for (int i = 0; i < size; i++)
	{
		m[i].loader(fin);
	}
}