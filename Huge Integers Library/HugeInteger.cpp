#include "HugeInteger.h"
#include <string>
#include <fstream>
using namespace std;

HugeInteger::HugeInteger()
{
	this->size = 0;
	vs = nullptr;
}
HugeInteger::HugeInteger(ifstream & rdr)
{
	string s;
	rdr >> s;
	if (s[0] == '-')
	{
		sign = true;
	}
	else
	{
		sign = false;
	}
	if (s[0] == '-' || s[0] == '+')
	{
		this->size = s.length() - 1;
	}
	else
	{
		this->size = s.length();
	}
	vs = new int[size];
	for (int i = 0, di = size - 1; i < size, di >= 0; i++)
	{
		if (s[i] == '-' || s[i] == '+')
		{
			continue;
		}
		vs[di] = s[i] - '0';
		di--;
	}
}
HugeInteger::HugeInteger(int num)
{
	this->size = digit_count(num);
	this->vs = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->vs[i] = num % 10;
		num = num / 10;
	}
	trim();
}
int HugeInteger::digit_count(int n)
{
	int count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	if (n == 0)
	{
		return count + 1;
	}
	else
		return count;
}
HugeInteger::HugeInteger(HugeInteger const &m)
{
	this->size = m.size;
	this->sign = m.sign;
	this->vs = new int[size];
	for (int i = 0; i < m.size; i++)
	{
		this->vs[i] = m.vs[i];
	}
}
void HugeInteger::sethi(string &s)
{
	this->size = s.length();
	vs = new int[size];
	for (int i = 0, di = size - 1; i < size; i++, di--)
	{
		vs[di] = s[i] - '0';
	}
}
istream& operator>>(istream& CIN, HugeInteger &hi)
{
	string s;
	cin >> s;
	hi.sethi(s);
	return cin;
}
ostream& operator<<(ostream& COUT, const HugeInteger &hi)
{
	if (hi.sign==true)
	{
		cout << "-";
	}
	for (int i = hi.size - 1; i >= 0; i--)
	{
		cout << hi[i];
	}
	return COUT;
}
int HugeInteger::operator[](int i)const
{
	if (i >= size)
	{
		return 0;
	}
	return vs[i];
}
int& HugeInteger::operator[](int i)
{
	return vs[i];
}

//=============================Boolean====================================//

bool HugeInteger::operator==(const HugeInteger& H2)
{
	if (*this > H2 || *this < H2)
	{
		return false;
	}
	else
		return true;
}
bool HugeInteger::operator!=(const HugeInteger& H2)
{
	if (*this == H2)
	{
		return false;
	}
	return true;
}
bool HugeInteger::less(const HugeInteger& H2)
{
	if (this->size > H2.size)
	{
		return true;
	}
	else
	if (this->size == H2.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->vs[i] < H2.vs[i])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return false;
	}
}
bool HugeInteger::greater(const HugeInteger& H2)
{
	if (this->size > H2.size)
	{
		return true;
	}
	else
	if (this->size == H2.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->vs[i] > H2.vs[i])
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return false;
	}
}
bool HugeInteger::operator<(const HugeInteger& H2)
{
	if (this->sign == true && H2.sign == false)
	{
		return true;
	}
	else
	if (this->sign == false && H2.sign == true)
	{
		return false;
	}
	else
	if (this->sign == true && H2.sign == true)
	{
		if ((this->less(H2)) == true)
		{
			return true;
		}
		else
			return false;
	}
	else
	{
		if ((this->less(H2)) == false)
		{
			return true;
		}
		else
			return false;
	}
}
bool HugeInteger::operator>(const HugeInteger& H2)
{
	if (this->sign == true && H2.sign == false)
	{
		return false;
	}
	else
	if (this->sign == false && H2.sign == true)
	{
		return true;
	}
	else
	if (this->sign == true && H2.sign == true)
	{
		if ((this->less(H2)) == true)
		{
			return false;
		}
		else
			return true;
	}
	else
	{
		if ((this->less(H2)) == false)
		{
			return false;
		}
		else
			return true;
	}
}
bool HugeInteger::operator<=(const HugeInteger& H2)
{
	if (*this>H2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool HugeInteger::operator>=(const HugeInteger& H2)
{
	if (*this<H2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//=============================Operations=================================//

HugeInteger HugeInteger::addition(const HugeInteger& c)
{
	HugeInteger res;
	res.size = this->size + 1;
	res.vs = new int[res.size];
	int carry = 0;
	for (int i = 0; i < res.size-1; i++)
	{
		res[i] = ((*this)[i] + c[i] + carry) % 10;
		carry = ((*this)[i] + c[i] + carry) / 10;
	}
	res[res.size-1] = carry;
	res = res.trim();
	return res;
}
HugeInteger HugeInteger::subtraction(const HugeInteger& c)
{
	HugeInteger res = *this;
	for (int i = 0; i < res.size; i++)
	{
		if (res.vs[i]<c[i])
		{
			res.vs[i] = res.vs[i] + 10;
			res.vs[i + 1] = res.vs[i + 1] - 1;
		}
		res.vs[i] = res.vs[i] - c[i];
	}
	res = res.trim();
	return res;
}
HugeInteger HugeInteger::multiply(const HugeInteger& c)
{
	int z = 0;
	HugeInteger res = z;
	for (HugeInteger i = 0; i <= c; i++)
	{
		res += *this;
	}
	return res;
}
HugeInteger HugeInteger::divide(const HugeInteger& c)
{
	HugeInteger v;
	return v;
}
HugeInteger HugeInteger::operator+(const HugeInteger& H2)
{
	if (this->sign == H2.sign)
	{
		HugeInteger sum = this->addition(H2);
		sum.sign = this->sign;
		return sum;
	}
	else
	{
		HugeInteger sum = this->subtraction(H2);
		sum.sign = this->sign;
		return sum;
	}
}
HugeInteger HugeInteger::operator-(const HugeInteger& H2)
{
	if (this->sign == H2.sign)
	{
		HugeInteger sum = this->subtraction(H2);
		sum.sign = this->sign;
		return sum;
	}
	else
	{
		HugeInteger sum = this->addition(H2);
		sum.sign = this->sign;
		return sum;
	}
}
HugeInteger HugeInteger::operator*(const HugeInteger& H2)
{
	if (this->sign == H2.sign)
	{
		HugeInteger mul = this->multiply(H2);
		mul.sign = false;
		return mul;
	}
	else
	{
		HugeInteger mul = this->multiply(H2);
		mul.sign = true;
		return mul;
	}
}
HugeInteger HugeInteger::operator/(const HugeInteger& H2)
{
	HugeInteger res=0,i=0;
	while (res <= *this)
	{
		res += H2;
		i++;
	}
	i += 1;
	return i;
}
HugeInteger HugeInteger::operator=(const HugeInteger& H2)
{
	delete[]vs;
	this->vs = nullptr;
	this->sign = H2.sign;
	this->size = H2.size;
	this->vs = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->vs[i] = H2.vs[i];
	}
	return *this;
}
HugeInteger HugeInteger::operator++()const
{
	HugeInteger h,c;
	h.vs = new int[1];
	h.size = 1;
	h.vs[0] = 1;
	c = *this;
	c = c.addition(h);
	return h;
}

HugeInteger HugeInteger::operator--()const
{
	HugeInteger h, c;
	h.vs = new int[1];
	h.size = 1;
	h.vs[0] = 1;
	c = *this;
	c = c.subtraction(h);
	return c;
}
void HugeInteger::operator++(int)
{
	HugeInteger h;
	h.vs = new int[1];
	h.size = 1;
	h.vs[0] = 1;
	*this=this->addition(h);
}
void HugeInteger::operator--(int)
{
	HugeInteger h;
	h.vs = new int[1];
	h.size = 1;
	h.vs[0] = 1;
	*this = this->subtraction(h);
}
HugeInteger& HugeInteger::operator+=(const HugeInteger& H2)
{
	*this = this->addition(H2);
	return *this;
}
HugeInteger& HugeInteger::operator-=(const HugeInteger& H2)
{
	*this = this->subtraction(H2);
	return *this;
}
HugeInteger HugeInteger::trim()
{
	int c = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (vs[i] == 0)
		{
			c++;
		}
		else
			break;
	}

	this->size = this->size - c;
	if (size == 0)
	{
		this->size += 1;
		this->vs[0] = 0;
	}
	return *this;
}
HugeInteger::~HugeInteger()
{
}