#pragma once
class complex_number
{
private:
	int imaginary;
	int real;
public:
	complex_number();
	complex_number(int, int);
	void real_num(int);
	void imaginary_num(int);
	void print();
	complex_number operator +(complex_number);
	complex_number operator -(complex_number);
	complex_number operator *(complex_number);
	complex_number operator !();
	complex_number operator /(complex_number);
	complex_number operator ~();
	complex_number operator ++();
	int modulus();
	~complex_number();
};

