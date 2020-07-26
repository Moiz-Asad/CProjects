#pragma once
#include<fstream>
#include<string>
using namespace std;
class PipePressure
{
	int Pressure;
	int Distace;
	static int TotalEntries;
	static int MaxPressure;
	static int MinPressure;
	static int AvgPressure;
public:
	PipePressure();
	void SetDistance(int);
	void SetPressure(int);
	int GetDistance();
	int GetPressure();
	int GetEntries();
	int GetAvg();
	int GetMax();
	int GetMin();
	void SetSize(int);
	void SetMax(PipePressure *p);
	void SetMin(PipePressure *p);
	void SetAvg(PipePressure *p);
	~PipePressure();
};

