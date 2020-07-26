#include "DynamicArray.h"
#include<iostream>
using namespace std;

DynamicArray::DynamicArray(int s = 0, int v = 0)
{
	size = s;
	if (size != 0)
	{
		Vs = new int[s];
		for (int i = 0; i < s; i++)
		{
			Vs[i] = v;
		}
	}
}
void DynamicArray::print()
{
	for (int i = 0; i < this->size; i++)
	{
		cout << this->Vs[i] << " ";
	}
	cout << endl;
}
int DynamicArray::ValueAt(int i)
{
	return Vs[i];
}
void DynamicArray::SetValueAt(int i, int v)
{
	Vs[i] = v;
}
int DynamicArray::GetSize()
{
	return size;
}
void DynamicArray::RandomInIt(int M)
{
	for (int i = 0; i < size; i++)
	{
		Vs[i] = rand() % M;
	}
}
void DynamicArray::InsertAtEnd(int v)
{
	int *temp = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = Vs[i];
	}
	delete[]Vs;
	temp[size] = v;
	size++;
	Vs = &temp[0];
}
void DynamicArray::InsertAt(int v, int location)
{
	Vs[location] = v;
}
void DynamicArray::InsertFront(int v)
{
	int *temp = new int[size + 1];
	for (int i = size; i>=0 ; i--)
	{
		temp[i] = Vs[i-1];
	}
	temp[0] = v;
	delete[]Vs;
	size++;vd
	Vs = temp;
}
void DynamicArray::DeleteAtEnd()
{
	int *temp = new int[size-1];
	for (int i = 0;i<size-1;i++)
	{
		temp[i] = Vs[i];
	}
	delete[]Vs;
	size--;
	Vs = temp;
}
void DynamicArray::DeleteFront()
{
	int *temp = new int[size - 1];
	for (int i = 0; i<size - 1; i++)
	{
		temp[i] = Vs[i+1];
	}
	delete[]Vs;
	size--;
	Vs = temp;
}
void DynamicArray::DeleteAt(int v)
{
	int *temp = new int[size - 1];
	for (int i = 0; i<size - 1; i++)
	{
		if (i == v)
		{
			for (int j = i+1; j < size; j++)
			{
				Vs[j-1] = Vs[j];
			}
		}
	}
	delete[]Vs;
	size--;
	Vs = temp;
}
void DynamicArray::SortAscend()
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (Vs[i] < Vs[j])
			{
				temp = Vs[j];
				Vs[j] = Vs[i];
				Vs[i] = temp;
			}
		}
	}
}
void DynamicArray::SortDescend()
{
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (Vs[i] > Vs[j])
			{
				temp = Vs[j];
				Vs[j] = Vs[i];
				Vs[i] = temp;
			}
		}
	}
}
void DynamicArray::SortAscendRange(int start, int end)
{
	int temp = 0;
	for (int i = start; i < end; i++)
	{
		for (int j = i + 1; j < end; j++)
		{
			if (Vs[i] < Vs[j])
			{
				temp = Vs[j];
				Vs[j] = Vs[i];
				Vs[i] = temp;
			}
		}
	}
}
void DynamicArray::SortDescenRange(int start, int end)
{
	int temp = 0;
	for (int i = start; i < end; i++)
	{
		for (int j = i + 1; j < end; j++)
		{
			if (Vs[i] > Vs[j])
			{
				temp = Vs[j];
				Vs[j] = Vs[i];
				Vs[i] = temp;
			}
		}
	}
}

void DynamicArray::EvenIndSort()
{
	int temp = 0;
	for (int i = 0; i < size; i=i+2)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (Vs[i] > Vs[j])
			{
				temp = Vs[j];
				Vs[j] = Vs[i];
				Vs[i] = temp;
			}
		}
	}
}
void DynamicArray::OddIndSort()
{
	int temp = 0;
	for (int i = 1; i < size; i = i + 2)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (Vs[i] > Vs[j])
			{
				temp = Vs[j];
				Vs[j] = Vs[i];
				Vs[i] = temp;
			}
		}
	}
}
void DynamicArray::EvenSort()
{
	int temp = 0;
	for (int i = 1; i < size; i = i + 1)
	{
		if (Vs[i] % 2 == 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (Vs[j] % 2 == 0)
				{
					temp = Vs[j];
					Vs[j] = Vs[i];
					Vs[i] = temp;
				}
			}
		}
	}
}
void DynamicArray::OddSort()
{
	int temp = 0;
	for (int i = 1; i < size; i = i + 1)
	{
		if (Vs[i] % 2 != 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (Vs[j] % 2 != 0)
				{
					temp = Vs[j];
					Vs[j] = Vs[i];
					Vs[i] = temp;
				}
			}
		}
	}
}
DynamicArray DynamicArray::leaders()
{
	int count = 0;
	DynamicArray d;
	d.size = 0;
	for (int i = 0; i < size; i++)
	{
		int j;
		for (j = i + 1; j < size; j++)
		{
			if (this->Vs[i] <= this->Vs[j])
			{
				break;
			}
		}
		if (j == size)
		{
			d.Vs[d.size] = this->Vs[i];
			d.size++;
		}
	}
	return d;
}
DynamicArray DynamicArray::unique()
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		int j;
		for (j = 0; j < size; j++)
		{
			if (this->Vs[i] == this->Vs[j])
			{
				break;
			}
		}
		if (i == j)
		{
			count++;
		}
	}
	DynamicArray d; int a = 0;
	d.Vs = new int[count];

		for (int i = 0; i < count; i++)
		{
			int j;
			for (j = 0; j < count; j++)
			{
				if (this->Vs[i] == this->Vs[j])
				{
					break;
				}
			}
			if (i == j)
			{
				d.Vs[a] = Vs[i];
				a++;
			}
	   }
		d.size = count;
		return d;
}

DynamicArray::~DynamicArray()
{
}
