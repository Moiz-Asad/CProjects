#include "HugeInteger.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	HugeInteger **P;
	int hisize;
	ifstream rdr("t.txt");
	rdr >> hisize;
	P = new HugeInteger*[hisize];
	for (int i = 0; i < hisize; i++)
	{
		P[i] = new HugeInteger(rdr);
	}
	for (int i = 0; i < hisize; i++)
	{
		cout << *P[i] << endl;
	}
	HugeInteger temp,x;
	temp = (*P[0])+(*P[1]);
	cout << temp << endl;
	temp = (*P[0])-(*P[1]);
	cout << temp <<endl;
	cout << ((*P[0]) > (*P[1]))<<endl;
	cout << ((*P[0]) != (*P[1]))<<endl;
	cout << ((*P[0]) >= (*P[1])) << endl;
	cout << ((*P[0]) <= (*P[1])) << endl;
	x = temp;
	cout << x <<endl;
	x = 12;
	temp = 12;
	cout << x << endl;
	temp = (x * temp);
	cout << temp << endl;
	HugeInteger c;
	temp = 16;
	x = 4;
	c = temp / x;
	cout << c <<endl;
	return 0;
}