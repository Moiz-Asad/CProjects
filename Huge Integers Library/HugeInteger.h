#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class HugeInteger
{
	int *vs;
	int size;
	bool sign;
	void sethi(string &s);
	int digit_count(int);
	HugeInteger addition(const HugeInteger& c);
	HugeInteger subtraction(const HugeInteger& c);
	HugeInteger multiply(const HugeInteger& c);
	HugeInteger divide(const HugeInteger& c);
	bool less(const HugeInteger& c);
	bool greater(const HugeInteger& c);

public:

	//==============Constructors==============//

	HugeInteger();
	HugeInteger(HugeInteger const &m);
	HugeInteger(ifstream & rdr);
	HugeInteger(int num);

	//================I/O=====================//

	friend ostream& operator<<(ostream& COUT, const HugeInteger &hi);
	friend istream& operator>>(istream& CIN, HugeInteger &hi);      

	int operator[](int)const;								      
	int& operator[](int);					

	//==============Bool====================//
	
	bool operator==(const HugeInteger& H2);	       
	bool operator!=(const HugeInteger& H2);	      
	bool operator<(const HugeInteger& H2);		     
	bool operator>(const HugeInteger& H2);		    
	bool operator<=(const HugeInteger& H2);	   
	bool operator>=(const HugeInteger& H2);	  

	//=================Operation=================//

	HugeInteger operator+(const HugeInteger& H2);
	HugeInteger operator-(const HugeInteger& H2);
	HugeInteger operator*(const HugeInteger& H2);
	HugeInteger operator/(const HugeInteger& H2);
	HugeInteger operator%(const HugeInteger& H2);
	
	HugeInteger operator=(const HugeInteger& H2);
	HugeInteger operator++()const;
	HugeInteger operator--()const;
	void operator++(int);
	void operator--(int);
	HugeInteger& operator+=(const HugeInteger& H2);
	HugeInteger& operator-=(const HugeInteger& H2);
	
	//===================Other===================//
	
	HugeInteger trim();
	
	~HugeInteger();
};
