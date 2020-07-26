#include "complex_number.h"
#include<iostream>
using namespace std;


complex_number::complex_number()
{
	real = 0;
	imaginary = 0;
}
complex_number::complex_number(int r, int i)
{
	real = r;
	imaginary = i;
}
void complex_number::real_num(int realnum)
{
	real = realnum;
}
void complex_number::imaginary_num(int imaginarynum)
{
	imaginary = imaginarynum;
}
void complex_number::print()
{
	cout << "(" << real << " , " << imaginary << "i)" << endl;
}
complex_number complex_number::operator + (complex_number c)
{
	complex_number sum;
	sum.real = this->real + c.real;
	sum.imaginary = c.imaginary + this->imaginary;
	return sum;
}
complex_number complex_number::operator -(complex_number c)
{
	complex_number sub;
	sub.real = this->real - c.real;
	sub.imaginary = this->imaginary - c.imaginary;
	return sub;
}
complex_number complex_number::operator *(complex_number c)
{
	complex_number mul;
	mul.real = (this->real*c.real) - (this->imaginary*c.imaginary);
	mul.imaginary = (this->real*c.imaginary) + (this->imaginary*c.real);
	return mul;
}
complex_number complex_number::operator /(complex_number c)
{
	complex_number n;
	n.real = ((this->real*c.real) + (this->imaginary*c.imaginary)) / ((c.real*c.real) + (c.imaginary*c.imaginary));
	n.imaginary = (-1 * (this->real*n.imaginary) + (this->imaginary*n.real)) / ((c.real*c.real) + (c.imaginary*c.imaginary));
	return n;
}
complex_number complex_number::operator !()
{
	complex_number c;
	c.imaginary = this->imaginary*(-1);
	c.real = this->real;
	return c;
}
complex_number complex_number::operator ~()
{
	complex_number n;
	n.real = this->real / ((this->real*this->real) + (this->imaginary*this->imaginary));
	n.imaginary = this->imaginary / ((this->real*this->real) + (this->imaginary*this->imaginary));
	return n;
}
complex_number complex_number::operator ++()
{
	complex_number c;
	c.imaginary = this->imaginary*(-1);
	c.real = this->real*(-1);
	return c;
}
int complex_number::modulus()
{
	int mod = 0;
	mod = (this->real*this->real) + (this->imaginary*this->imaginary);
	return (int)sqrt(mod);
}
complex_number::~complex_number()
{
}
