#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class matrix
{
	float **vs;
	int colm;
	int rows;
public:
	matrix();
	matrix(float **,int,int);
	void memorycreater();

	void loader(ifstream &rdr);
	void print() const;

	matrix add(const matrix &m) const;
	matrix sub(const matrix &m) const;
	matrix mul(const matrix &m) const;
	matrix div(const matrix &m) const;

	matrix addall(const float value);
	matrix suball(const float value);
	matrix mullall(const float value);
	matrix divall(const float value);

	bool isequal(const matrix &m);
	bool mulcheck();

	void asign(const matrix m);
	void asignneg(const matrix m);

	matrix transpose() const;
	matrix rotatecw() const;
	matrix anticlockrotate() const;

	~matrix();
};

