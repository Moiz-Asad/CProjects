#include "CommisionBaseEmploye.h"
#include"ComissionEmploye.h"

CommisionBaseEmploye::CommisionBaseEmploye()
{
	this->BaseSalary = 0;
}
CommisionBaseEmploye::CommisionBaseEmploye(int s)
{
	this->BaseSalary = s;
}
CommisionBaseEmploye::CommisionBaseEmploye(string ID, string Name, int Hour, int Sallary, int Rate)
{
	e.SetID(ID);
	e.SetName(Name);
	e.SetSallary(Sallary);
	e.SetRate(Rate);
	e.SetHour(Hour);
}
void CommisionBaseEmploye::SetBSalary(int s)
{
	this->BaseSalary = s;
}
int CommisionBaseEmploye::GetBSalary()
{
	return this->BaseSalary;
}
int CommisionBaseEmploye::SallaryCommisionPlusGrace(ComissionEmploye e)
{
	int sum = 0;
	sum = e.GraceSallary();
	sum = sum + BaseSalary;
	return sum;
}
void print();
CommisionBaseEmploye::~CommisionBaseEmploye()
{
}
