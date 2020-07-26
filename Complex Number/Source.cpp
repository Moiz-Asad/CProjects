#include<iostream>
#include"complex_number.h"
#include<fstream>
using namespace std;

complex_number * read_data(char filename[]);

int main()
{
	char filename[] = "number.txt";
	complex_number *c;
	complex_number n;
	c = read_data(filename);
	int n1, n2;
	char c0, c1, c2, oper;
	cout << "Enter command : ";
	cin >> c0 >> oper >> c1 >> n1 >> oper >> c2 >> n2;
	if (oper == '+')
	{
		n = c[n1 - 1] + c[n2 - 1];
		n.print();
	}
	else
	if (oper == '-')
	{
		n = c[n1 - 1] - c[n2 - 1];
		n.print();
	}
	else
	if (oper == 'x')
	{
		n = c[n1 - 1] * c[n2 - 1];
		n.print();
	}
	else
	if (oper == '!')
	{
		n = !c[n1 - 1];
		n.print();
	}
	else
	if (oper == '/')
	{
		n = c[n1 - 1] / c[n2 - 1];
		n.print();
	}
	else
	if (oper == '~')
	{
		n = ~c[n1 - 1];
		n.print();
	}
	else
	if (oper == '@')
	{
		n = ++c[n1 - 1];
		n.print();
	}
	else
	if (oper == '%')
	{
		int mod = 0;
		mod = c[n1 - 1].modulus();
		cout << mod << endl;
	}
	return 0;
}
complex_number * read_data(char filename[])
{
	ifstream in(filename);
	int size = 0;
	in >> size;
	int real;
	int imag;
	complex_number *compl = new complex_number[size];
	for (int i = 0; i < size; i++)
	{
		in >> real;
		compl[i].real_num(real);
		in >> imag;
		compl[i].imaginary_num(imag);
	}
	return compl;
}