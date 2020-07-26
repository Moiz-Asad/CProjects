#pragma once
class Student
{
private:
	char name[21];
	char roll_number[13];
	int day;
	int month;
	int year;
public:
	Student();
	void setname(char name[]);
	void setrollnumber(char rolln[]);
	void setday(int);
	void setmonth(int);
	void setyear(int);
	int DaysInAMonth(int, int);
	void age_calculator(int C_Day, int C_Month, int C_Year);
	void print();
	void studentwithsmalldate(int s, Student *y, Student p);
	void studentwithlargdate(int s, Student *y, Student p);
	void printsamedob(int s, Student *y);
	void printbetweenrange(int size, int year, int yeare, Student *p);
	void printsameyear(int size,Student *p);
	void printsameyearmonth(int size, Student *p);
	~Student();
};

