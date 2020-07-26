#include "PipePressure.h"

int PipePressure::TotalEntries = 0;
int PipePressure::MaxPressure = 0;
int PipePressure::MinPressure = 0;
int PipePressure::AvgPressure = 0;

PipePressure::PipePressure()
{
}
void PipePressure::SetDistance(int a)
{
	Distace = a;
}
void PipePressure::SetPressure(int a)
{
	Pressure = a;
}
int PipePressure::GetDistance()
{
	return Distace ;
}
int PipePressure::GetPressure()
{
	return Pressure ;
}
void PipePressure::SetSize(int a)
{
	TotalEntries = a;
}
void PipePressure::SetMax(PipePressure *p)
{
	int max = p[0].Pressure;
	for (int i = 1; i < TotalEntries; i++)
	{
		if (p[i].Pressure > max)
		{
			max = p[i].Pressure;
		}
	}
	MaxPressure = max;
}
void PipePressure::SetMin(PipePressure *p)
{
	int min = p[0].Pressure;
	for (int i = 1; i < TotalEntries; i++)
	{
		if (p[i].Pressure < min)
		{
			min = p[i].Pressure;
		}
	}
	MinPressure = min;
}
int PipePressure::GetEntries()
{
	return TotalEntries;
}
int PipePressure::GetMax()
{
	return MaxPressure;
}
int PipePressure::GetMin()
{
	return MinPressure;
}
int PipePressure::GetAvg()
{
	return AvgPressure;
}
void PipePressure::SetAvg(PipePressure *p)
{
	int sum = 0;
	for (int i = 0; i < TotalEntries; i++)
	{
		sum += p[i].Pressure;
	}
	AvgPressure = (sum / TotalEntries);
}
PipePressure::~PipePressure()
{
}
