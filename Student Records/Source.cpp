#include<iostream>
#include"Student.h"
#include<fstream>
using namespace std;
Student* getdata(char filename[],int size);
int DaysInAMonth(int month, int year);
int main()
{
	char filename[] = "student.txt";
	Student *s;
	int size = 0;
	s = getdata(filename,size);
	int d, m, y;
	int choice = 0;
	cout << "Enter 1  to print all the students in the record which are smaller than the given dates." << endl;
	cout << "Enter 2 to print all the students in the record which are greater than the given dates." << endl;
	cout << "Enter 3 print the count of all the students in the record which has the same date of birth to the given date." << endl;
	cout << "Enter 4 print all the students which are in between(d1, d2)." << endl;
	cout << "Enter 5 to Print all the students of the same year" << endl;
	cout << "Enter 6 to print all the students of the same year which are most occurring w.r.t only month in consideration." << endl;
	cin >> choice;
	if (choice == 1)
	{
		Student p;
		cout << "Enter Date (Day Month Year): ";
		cin >> d >> m >> y;
		p.setday(d);
		p.setmonth(m);
		p.setyear(y);
		s->studentwithsmalldate(size,s,p);
	}
	else
	if (choice == 2)
	{
		Student p;
		cout << "Enter Date (Day Month Year): ";
		cin >> d >> m >> y;
		p.setday(d);
		p.setmonth(m);
		p.setyear(y);
		s->studentwithlargdate(size, s, p);
	}
	else
	if (choice == 3)
	{
		s->printsamedob(size,s);
	}
	else
	if (choice == 4)
	{
		int d, m, y;
		int d1, m1, y1;
		cout << "Enter starting date (Day month Year) : ";
		cin >>d >>m >> y;
		cout << "Enter ending date (Day month Year) : ";
		cin >> d1 >> m1 >> y1;
		s->printbetweenrange(size,y,y1,s);
	}
	else
	if (choice == 5)
	{

	}
	return 0;
}
Student* getdata(char filename[],int size)
{
	ifstream fin(filename);
	fin >> size;
	int day=0, month=0, year = 0;
	char name[21],rolln[13];
	Student *s = new Student[size];
	for (int i = 0; i < size; i++)
	{
		fin >> name;
		s[i].setname(name);
		fin >> rolln;
		s[i].setrollnumber(rolln);
		fin >> day >> month >> year;
		s[i].setday(day);
		s[i].setmonth(month);
		s[i].setyear(year);
	}
	fin.close();
	return s;
}
void age_calculator(int bday,int bmonth,int byear,int C_Day, int C_Month, int C_Year)
{
	int Days = C_Day - bday;
	if (Days<0)
	{
		C_Month--;
		Days += DaysInAMonth(C_Month, C_Year);
		if (Days < 0)
		{
			C_Month--;
			Days += DaysInAMonth(C_Month, C_Year);
		}
	}
	int Month = C_Month - bmonth;
	if (Month<0)
	{
		C_Year--;
		Month += 12;
	}
	int Year = C_Year - byear;
	cout << "Age is: " << Year << " years " << Month << " months " << Days << " days " << endl;
}
int DaysInAMonth(int month, int year)
{
	int days = 0;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		days += 30;
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7
		|| month == 8 || month == 10 || month == 12)
	{
		days += 31;
	}
	else if (month == 2 && year % 4 == 0)
	{
		days += 29;
	}
	else
	{
		days += 28;
	}
	return days;
}