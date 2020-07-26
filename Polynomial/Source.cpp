#include<iostream>
#include"polynomial.h"
#include<fstream>
using namespace std;
polynomial* getdata(char file[], int &size);
int main()
{
	char file[] = "Text.txt";
	int s = 0;
	polynomial*p = getdata(file, s);
	cout << "Enter Operation to perform in Polynomial : ";
	int n1 =0, n2 =0;
	char c, c1, c2, oper;
	cin >> c >> oper >> c1 >> n1 >> oper >> c2 >> n2 ;
	if (oper == '+')
	{
		polynomial *add;
		add = p[0].addition(p[1]);
		add->print();
	}
	else
	if (oper == '-')
	{
		polynomial *sub;
		sub = p[0].subtraction(p[1]);
		sub->print();
	}
	return 0;
}
polynomial* getdata(char file[], int &size)
{
	ifstream fin(file);
	fin >> size;
	polynomial *p = new polynomial[size];
	int *q;
	for (int i = 0; i < size; i++)
	{
		q=p[i].setdata(fin);
		p[i].getter(q);
	}
	return p;
}