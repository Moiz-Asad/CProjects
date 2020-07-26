#include "polynomial.h"
#include<iostream>
#include<fstream>
using namespace std;

polynomial::polynomial()
{
	degree = 0;
	cs = nullptr;
}
polynomial::polynomial(int d,int *c)
{
	degree = d;
	cs = c;
}
int* polynomial::setdata(ifstream &fin)
{
	int d = 0;
	fin >> d;
	this->degree = d;
	int *p = new int[d + 1];
	for (int i = 0; i < d + 1; i++)
	{
		fin >> p[i];
	}
	return p;
}
void polynomial::getter(int *p)
{
	this->cs = &p[0];
}
void polynomial::print()const
{
	for (int i = 0; i<degree+1; i++)
	{
		cout << cs[i] <<" ";
	}
	cout << endl;
}
polynomial* polynomial::addition(polynomial p)
{
	polynomial add;
	if (degree>p.degree)
	{
		add.degree = degree;
	}
	else
	{
		add.degree = p.degree;
	}
	add.cs = new int[degree + 1];
	for (int i = 0; i < degree+1; i++)
	{
		add.cs[i] = cs[i];
	}
	for (int i = 0; i < p.degree + 1; i++)
	{
		add.cs[i] = add.cs[i] + p.cs[i];
	}
	for (int i = 0; i < degree + 1; i++)
	{
		cout<<add.cs[i]<<" ";
	}
	return &add;
}
polynomial* polynomial::subtraction(polynomial &p)
{
	polynomial sub;
	if (degree>p.degree)
	{
		sub.degree = degree;
	}
	else
	{
		sub.degree = p.degree;
	}
	sub.cs = new int[degree + 1];
	for (int i = 0; i < degree + 1; i++)
	{
		sub.cs[i] = cs[i];
	}
	for (int i = 0; i < p.degree + 1; i++)
	{
		sub.cs[i] = sub.cs[i] - p.cs[i];
	}
	for (int i = 0; i < degree + 1; i++)
	{
		cout << sub.cs[i] << " ";
	}
	return &sub;
}
polynomial multiplication(polynomial &p);
polynomial division(polynomial &p);
int evaluate(int f);
polynomial::~polynomial()
{

}

