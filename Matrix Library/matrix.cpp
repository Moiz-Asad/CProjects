#include "matrix.h"
#include<iostream>
#include<fstream>
using namespace std;

matrix::matrix()
{
	rows = 0;
	colm = 0;
	vs = 0;
}

matrix::matrix(float **f, int r, int c)
{
	this->rows = r;
	this->colm = c;
	this->memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] = f[i][j];
		}
	}
}
void matrix::memorycreater()
{
	this->vs = new float*[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->vs[i] = new float[colm];
	}
}
void matrix::loader(ifstream &rdr)
{
	rdr >> this->rows >> this->colm;
	this->vs = new float*[this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->vs[i] = new float[colm];
		for (int j = 0; j < this->colm; j++)
		{
			rdr>>this->vs[i][j];
		}
	}
}
void matrix::print() const
{
	for (int i = 0; i < this->rows; i++)
	{
		cout << "  {  ";
		for (int j = 0; j < this->colm; j++)
		{
			
			cout << this->vs[i][j] <<" ";
			
		}
		cout << "  }  ";
		cout << endl;
	}

}
matrix matrix::add(const matrix &m) const
{
	matrix res;
	res.rows = m.rows;
	res.colm = m.colm;
	res.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = this->vs[i][j] + m.vs[i][j];
		}
	}
	return res;
}
matrix matrix::sub(const matrix &m) const
{
	matrix res;
	res.rows = m.rows;
	res.colm = m.colm;
	res.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = this->vs[i][j] - m.vs[i][j];
		}
	}
	return res;
}
matrix matrix::mul(const matrix &m) const
{
	matrix res;
	
	if (this->colm == m.rows)
	{
		int sum=0;
		res.rows = this->rows;
		res.colm = m.colm;
		res.memorycreater();
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < m.colm; j++)
			{
				sum = 0;
				for (int k = 0; k < this->colm; k++)
				{
					sum = sum + (this->vs[i][k] * m.vs[k][j]);
				}
				res.vs[i][j] = sum;
			}
		}
		return res;
	}
	else
	{
		res.rows = 0;
		res.colm = 0;
		return res;
	}
	
}
bool matrix::mulcheck()
{
	if (this->rows == 0 || this->colm == 0)
	{
		return true;
	}
	else
		return false;
}
matrix matrix::div(const matrix &m) const
{
	matrix res;
	return res;
}

matrix matrix::addall(const float value)
{
	matrix res;
	res.rows = this->rows;
	res.colm = this ->colm;
	res.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = this->vs[i][j] + value;
		}
	}
	return res;
}
matrix matrix::suball(const float value)
{
	matrix res;
	res.rows = this->rows;
	res.colm = this->colm;
	res.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = this->vs[i][j] - value;
		}
	}
	return res;
}
matrix matrix::mullall(const float value)
{
	matrix res;
	res.rows = this->rows;
	res.colm = this->colm;
	res.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = this->vs[i][j] * value;
		}
	}
	return res;
}
matrix matrix::divall(const float value)
{
	matrix res;
	res.rows = this->rows;
	res.colm = this->colm;
	res.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = this->vs[i][j] / value;
		}
	}
	return res;
}
bool matrix::isequal(const matrix &m)
{
	if (this->rows == m.rows && this->colm == m.colm)
	{
		return true;
	}
	else
	{
		return false;
	}
}

matrix matrix::transpose() const
{
	matrix trp;
	trp.rows = this->colm;
	trp.colm = this->rows;
	trp.memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			trp.vs[i][j] = this->vs[j][i];
		}
	}
	return trp;
}
matrix matrix::rotatecw() const
{
	matrix res;
	res.rows = this->colm;
	res.colm = this->rows;
	int c = 0;
	int b = 0;
	res.memorycreater();
	for (int i = colm-1; i >= 0; i--)
	{
		b = 0;
		for (int j = 0; j < this->rows; j++)
		{
			res.vs[c][b] = this->vs[j][i];
			b++;
		}
		c++;
	}
	return res;
}
matrix matrix::anticlockrotate() const
{
	matrix res;
	res.rows = this->colm;
	res.colm = this->rows;
	int c = 0;
	int b = 0;
	res.memorycreater();
	for (int i = colm - 1; i >= 0; i--)
	{
		b = 0;
		for (int j = 0; j < this->rows; j++)
		{
			res.vs[j][i] = this->vs[c][b];
			b++;
		}
		c++;
	}
	return res;
}

matrix::~matrix()
{
}
