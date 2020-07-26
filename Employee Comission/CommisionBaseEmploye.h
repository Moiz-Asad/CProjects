#pragma once
#include"ComissionEmploye.h"
#include<iostream>
#include<string>
using namespace std;
class CommisionBaseEmploye
{
	ComissionEmploye e;
	int BaseSalary;
public:
	CommisionBaseEmploye();
	CommisionBaseEmploye(int);
	CommisionBaseEmploye(string ID, string Name, int Hour, int Sallary, int Rate);
	void SetBSalary(int);
	int GetBSalary();
	int SallaryCommisionPlusGrace(ComissionEmploye e);
	~CommisionBaseEmploye();
};

