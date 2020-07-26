#include "Student.h"
#include<iostream>
using namespace std;
Student::Student()
{
	name[21] = '\0';
	roll_number[12] = '\0';
	day = 0;
	month = 0;
	year = 0;
}
void Student::setname(char n[])
{
	int i;
	for (i = 0; n[i]!='\0'; i++)
	{
		name[i] = n[i];
	}
	name[i] = '\0';
}

void Student::setrollnumber(char num[])
{
	int i;
	for (i = 0; num[i] != '\0'; i++)
	{
		roll_number[i] = num[i];
	}
	roll_number[i] = '\0';
}
void Student::setday(int d)
{
	if (d < 1 && d > 31)
	{
		day = 0000;
	}
	else
		day = d;
}
void Student::setmonth(int m)
{
	if (m < 1 && m > 12)
	{
		month = 0000;
	}
	else
		month = m;
}
void Student::setyear(int y)
{
	if (y < 1950 && y > 2019)
	{
		year = 0000;
	}
	else
		year = y;
}

void Student::print()
{
	cout << "Name : " << this->name << endl;
	cout << "Roll Number : " << this->roll_number << endl;
	cout << "Date Of Birth : " << this->day <<" , "<< this->month <<" , "<< this->year << endl;
}
void Student::studentwithsmalldate(int s,Student *y,Student p)
{
	for (int i = 0; i < s; i++)
	{
		if (y[i].year < p.year)
		{
			y[i].print();
		}
		else
		if (y[i].year == p.year && y[i].month < p.month)
		{
			y[i].print();
		}
		else
		if (y[i].year == p.year && y[i].month == p.month && y[i].day < p.day)
		{
			y[i].print();
		}
	}
}
void Student::studentwithlargdate(int s, Student *y, Student p)
{
	for (int i = 0; i < s; i++)
	{
		if (y[i].year > p.year)
		{
			y[i].print();
		}
		else
		if (y[i].year == p.year && y[i].month > p.month)
		{
			y[i].print();
		}
		else
		if (y[i].year == p.year && y[i].month == p.month && y[i].day > p.day)
		{
			y[i].print();
		}
	}
}
void Student::printsamedob(int s, Student *y)
{
	int rep = 0;
	int count = 0;
	for (int i = 0; i < s; i++)
	{
		for (int j = i+1; j < s; j++)
		{
			if (y[i].year == y[j].year && y[i].month == y[j].month && y[i].day== y[j].day)
			{
				count++;
			}
		}
		if (count>rep)
		{
			rep = count;
		}
	}
	cout << "No. of students with same Date od Birth :" << rep << endl;
}
void Student::printbetweenrange(int size,int year,int yeare,Student *p)
{
	if (year > yeare)
	{
		int temp = 0;
		temp = yeare;
		yeare = year;
		yeare = temp;
	}
	for (int i = 0; i < size; i++)
	{
		if (p[i].year<yeare && p[i].year>yeare)
		{
			p[i].print();
		}
	}
}
void Student::printsameyear(int size, Student *p)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (p[i].year == p[j].year)
			{
				p[i].print();
			}
		}
	}
}
void Student::printsameyearmonth(int size, Student *p)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (p[i].year == p[j].year && p[i].month == p[j].month)
			{
				p[i].print();
			}
		}
	}
}
Student::~Student()
{
}
