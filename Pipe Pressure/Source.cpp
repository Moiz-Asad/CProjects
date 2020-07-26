#include<iostream>
#include<fstream>
#include<string>
#include"PipePressure.h"
using namespace std;
PipePressure* DataReader(string File,PipePressure *Data, int &size);
void print(PipePressure *Data, int size);
int main()
{
	int size = 0;
	PipePressure *Measurement = nullptr;
	Measurement = DataReader("pipepressure.txt", Measurement, size);
	Measurement->SetSize(size);
	Measurement->SetMax(Measurement);
	Measurement->SetMin(Measurement);
	Measurement->SetAvg(Measurement);
	print(Measurement, size);
	return 0;
}
PipePressure* DataReader(string File,PipePressure *Data, int &size)
{
	int a, b;
	ifstream in(File);
	in >> size;
	Data = new PipePressure[size];
	for (int i = 0; i < size; i++)
	{
		in >> a;
		Data[i].SetDistance(a);
		in >> b;
		Data[i].SetPressure(b);
	}
	in.close();
	return Data;
}
void print(PipePressure *Data, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Distance : " << Data[i].GetDistance() << endl;
		cout << "Pressure :" << Data[i].GetPressure() << endl;
	}
	cout << "Entries :" << Data->GetEntries() << endl;
	cout << "MaxPressure : " << Data->GetMax() << endl;
	cout << "MinPressure : " << Data->GetMin() << endl;
	cout << "Average Pressure : " << Data->GetAvg() << endl;
}