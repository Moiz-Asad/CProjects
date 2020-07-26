#include "matrix.h"
#include<iostream>
#include<fstream>
using namespace std;
int matrix::getrow()
{
	return this->rows;
}
int matrix::getcolm()
{
	return this->colm;
}
matrix::matrix()
{
	rows = 0;
	colm = 0;
	vs = 0;
}
matrix::matrix(const matrix&m)
{
	this->rows = m.rows;
	this->colm = m.colm;
	this->memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] = m.vs[i][j];
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
			rdr >> this->vs[i][j];
		}
	}
}
ostream& operator << (ostream &out, const matrix &m)
{
	for (int i = 0; i < m.rows; i++)
	{
		out << "  {  ";
		for (int j = 0; j < m.colm; j++)
		{
			out << m.vs[i][j] << " ";
		}
		out << "  }  ";
		out << endl;
	}
	return out;
}
void matrix::print() const
{
	for (int i = 0; i < this->rows; i++)
	{
		cout << "  {  ";
		for (int j = 0; j < this->colm; j++)
		{

			cout << this->vs[i][j] << " ";

		}
		cout << "  }  ";
		cout << endl;
	}
}
matrix matrix::operator + (const matrix &m) const
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
matrix matrix::operator += (const matrix &m) const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] = this->vs[i][j] + m.vs[i][j];
		}
	}
	return *this;
}
matrix matrix::operator - (const matrix &m) const
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
matrix matrix::operator -= (const matrix &m) const
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] = this->vs[i][j] - m.vs[i][j];
		}
	}
	return *this;
}
matrix matrix::operator * (const matrix &m) const
{
	matrix res;

	if (this->colm == m.rows)
	{
		float sum = 0;
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
matrix matrix::operator *= (const matrix &m)
{
	matrix res;
	if (this->colm == m.rows)
	{
		float sum = 0;
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
		for (int i = 0; i < this->rows; i++)
		{
			delete[i]vs;
			vs = nullptr;
		}
		this->rows = res.rows;
		this->colm = res.colm;
		this->vs = res.vs;

		return *this;
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
matrix matrix::operator / (const matrix &m) const
{
	matrix res;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			res.vs[i][j] = (this->vs[i][j]) / (m.vs[i][j]);
		}
	}
	return res;
}
matrix matrix::operator +(const float value)
{
	matrix res;
	res.rows = this->rows;
	res.colm = this->colm;
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
void matrix::operator =(const matrix &m)
{
	for (int i = 0; i < rows; i++)
	{
		delete[]vs[i];
	}
	vs = nullptr;
	this->rows = m.rows;
	this->colm = m.colm;
	this->memorycreater();
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] = m.vs[i][j];
		}
	}
}
matrix matrix::operator -(const float value)
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
matrix matrix::operator *(const float value)
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
matrix matrix::operator /(const float value)
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
matrix matrix::operator ++ ()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] += 1;
		}
	}
	return *this;
}
matrix matrix::operator -- ()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] -= 1;
		}
	}
	return *this;
}
bool matrix::operator == (const matrix &m)
{
	if (this->isequal(m))
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->colm; j++)
			{
				if (this->vs[i][j] == m.vs[i][j])
				{
					continue;
				}
				else
					return false;
			}
		}
		return true;
	}
	else
		return false;
}
matrix matrix::operator -()
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->colm; j++)
		{
			this->vs[i][j] *= -1;
		}
	}
	return *this;
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
matrix matrix::operator ! () const
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
	for (int i = colm - 1; i >= 0; i--)
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
