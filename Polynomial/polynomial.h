#pragma once
#include<fstream>
using namespace std;
class polynomial
{
private:
	int *cs;
	int degree;
public:
	polynomial();
	polynomial(int d, int *c);
	int* setdata(ifstream &);
	void getter(int *);
	polynomial *addition(polynomial p);
	polynomial *subtraction(polynomial &p);
	polynomial *multiplication(polynomial &p);
	polynomial *division(polynomial &p);
	int evaluate(int f);
	void print()const;
	~polynomial();
};

