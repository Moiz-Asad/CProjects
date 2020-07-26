#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class matrix
{
	int colm;
	int rows;
public:
	float **vs;
	matrix();
	int getrow();
	int getcolm();
	matrix(const matrix&m);
	void memorycreater();
	void loader(ifstream &rdr);
	void print() const;
	friend ostream& operator << (ostream &out, const matrix &m);


	matrix operator + (const matrix &m) const;
	matrix operator += (const matrix &m) const;

	matrix operator - (const matrix &m) const;
	matrix operator -= (const matrix &m) const;

	matrix operator * (const matrix &m) const;
	matrix operator *= (const matrix &m);

	matrix operator / (const matrix &m) const;

	matrix operator +(const float value);
	matrix operator -(const float value);
	matrix operator *(const float value);
	matrix operator /(const float value);

	matrix operator ++ ();
	matrix operator -- ();
	matrix operator -();

	bool operator == (const matrix &m);
	void matrix::operator =(const matrix &m);
	bool isequal(const matrix &m);
	bool mulcheck();

	void asign(const matrix m);
	void asignneg(const matrix m);

	matrix operator!() const;
	matrix rotatecw() const;
	matrix anticlockrotate() const;

	~matrix();
};

