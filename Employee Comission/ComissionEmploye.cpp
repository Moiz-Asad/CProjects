#include "ComissionEmploye.h"
#include<iostream>
using namespace std;

ComissionEmploye::ComissionEmploye()
{
	Sallary = 0;
	Rate = 0;
}
ComissionEmploye::ComissionEmploye(string ID,string Name,int Hour,int Sallary,int Rate)
{
	this->ID = ID;
	this->hour = Hour;
	this->Name = Name;
	this->Sallary = Sallary;
	this->Rate = Rate;
}
void ComissionEmploye::SetName(string a)
{
	this->Name = a;
}
void ComissionEmploye::SetID(string a)
{
	this->ID = a;
}
void ComissionEmploye::SetHour(int a)
{
	this->hour = a;
}
void ComissionEmploye::SetRate(int a)
{
	this->Rate = a;
}
void ComissionEmploye::SetSallary(int a)
{
	this->Sallary = a;
}
string ComissionEmploye::GetName()
{
	return this->Name;
}
string ComissionEmploye::GetID()
{
	return this->ID;
}
int ComissionEmploye::GetHour()
{
	return this->hour;
}
int ComissionEmploye::GetRate()
{
	return this->Rate;
}
int ComissionEmploye::GetSallary()
{
	return this->Sallary;
}
int ComissionEmploye::GraceSallary()
{
	int mul = 0;
	mul = hour*Rate;
	return mul;
}
void ComissionEmploye::infoprint()
{
	cout << "Name : " << Name << endl;
	cout << "ID : " << ID << endl;
	cout << "Rate : " << Rate << endl;
	cout << "Sallary : " << Sallary << endl;
	cout << "Working Hour : " << hour << endl;
	cout << "Total Sallary : " << GraceSallary() << endl;
}
ComissionEmploye::~ComissionEmploye()
{
}
