#pragma once
#include<string>
using namespace std;
class ComissionEmploye
{
	string ID;
	string Name;
	int Sallary;
	int hour;
	int Rate;
public:
	ComissionEmploye();
	ComissionEmploye(string ID, string Name, int Hour, int Sallary, int Rate);
	
	//Setters//
	void SetName(string);
	void SetID(string);
	void SetRate(int);
	void SetSallary(int);
	void SetHour(int);
	//Getters//
	string GetName();
	string GetID();
	int GetRate();
	int GetSallary();
	int GetHour();
	int GraceSallary();
	void infoprint();
	~ComissionEmploye();
};

