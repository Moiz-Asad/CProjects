#pragma once
class DynamicArray
{
	int size;
	int *Vs;
public:
	DynamicArray(int,int);
	int ValueAt(int);
	void SetValueAt(int, int);
	int GetSize();
	void print();

	void RandomInIt(int);
	int *regrow();

	void InsertAtEnd(int);
	void InsertAt(int, int);
	void InsertFront(int);
	
	void DeleteFront();
	void DeleteAt(int);
	void DeleteAtEnd();

	void SortAscend();
	void SortDescend();
	void SortAscendRange(int, int);
	void SortDescenRange(int, int);

	DynamicArray leaders();
	DynamicArray distinct();
	DynamicArray unique();
	void EvenIndSort();
	void OddIndSort();
	void EvenSort();
	void OddSort();
	
	
	~DynamicArray();
};

