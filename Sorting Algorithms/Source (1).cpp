#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;
void PrintV(string msg, vector<int> D)
{
	cout << msg;
	for (int i = 0; i <D.size(); i++)
	{
		cout << D[i] << " ";
	}
	cout << endl << endl;
}

void BubbleSortBool(vector<int> Data)
{
	bool Swap = true;
	while (Swap)     //O(N) worst case
	{
		Swap = false;
		for (int i = 0; i < Data.size() - 1; i++)  //O(N)
		{
			if (Data[i]>Data[i + 1])
			{
				Data[i] = Data[i] + Data[i + 1];
				Data[i + 1] = Data[i] - Data[i + 1];
				Data[i] = Data[i] - Data[i + 1];
				Swap = true;
			}
		}
	}
	PrintV("Data After Sorting using bool : ", Data);
	//Total Complexity O(N*N) = O(N^2)
}
void BubbleSort(vector<int> Data)
{
	for (int i = 0; i < Data.size(); i++)      //O(N)
	{
		for (int j = 0; j < Data.size() - 1; j++)   //O(N)
		{
				if (Data[j] > Data[j + 1])
				{
					Data[j] = Data[j] + Data[j + 1];
					Data[j + 1] = Data[j] - Data[j + 1];
					Data[j] = Data[j] - Data[j + 1];
				}
		}
	}
	PrintV("Data After Simple Sorting : ", Data);
	//Total Complexity O(N*N) = O(N^2)
}
void BubbleSortDW(vector<int> Data)
{
	int Loop, i = 0;
	do
	{
		for (i = 0, Loop = 0; i < Data.size() - 1; i++)  //O(N)
		{
			if (Data[i] > Data[i + 1])
			{
				Data[i] = Data[i] + Data[i + 1];
				Data[i + 1] = Data[i] - Data[i + 1];
				Data[i] = Data[i] - Data[i + 1];
				Loop++;
			}
		}
	} 
	while (Loop != 0);			//O(N)
	PrintV("Bubble Sorting using Do While : ", Data);
	//Total Complexity O(N*N) = O(N^2)
}
void PrintList(string msg, list<int> LD)
{
	cout << msg;
	for (auto i = LD.begin(); i != LD.end(); i++)  //O(N)
	{
		cout << *i << " ";
	}
	cout << endl << endl;
	//Total Complexity O(N)  (no printing cost)
}
void BubbleSortListNest(list<int> D)
{
	for (auto i = D.begin(); i != D.end() ; i++)  //O(N)
	{
		for (auto j = D.begin(); j != i; j++)  //O(N)
		{
			if (*i < *j)
			{
				iter_swap(i, j);
			}
		}
	}
	PrintList("Bubble Sort Nested : ", D);  //(no printing cost)
	//Total Complexity O(N*N) = O(N^2)
}

bool ISwap(list<int> &LD)
{
	bool swap = false;
	auto Prev = LD.begin(), Next = LD.begin();
	Next++;
	while (Next != LD.end())    //O(N)
	{
		if (*Prev > *Next)
		{
			iter_swap(Prev, Next);
			swap = true;
		}
		Next++;
		Prev++;
	}
	return swap;    //O(N)
}
void BubbleSortDW(list<int> LD)
{
	bool Swap = false;
	do
	{
		Swap = ISwap(LD);   //O(N)
	} 
	while (Swap);               //O(N)
	PrintList("Bubble Sorting List : ", LD);    //no printing cost
	//Total Complexity O(N*N) = O(N^2)	
}
void BubbleSortListBool(list<int> Data)
{
	bool Swap = false;
	do
	{
		Swap = ISwap(Data);    //O(N)
	} while (Swap);                //O(N)
	PrintList("Bubble Sort Bool : ", Data); // no printing cost
	//Total Complexity O(N*N) = O(N^2)
}





void BubbleSortListDNest(list<int> D)
{
	for (auto i = D.begin(); i != D.end(); i++) //O(N)
	{
		for (auto j = D.begin(); j != i; j++) //O(N)
		{
			if (*i < *j)
			{
				swap(*i, *j);
			}
		}
	}
	PrintList("Bubble Sort Nested : ", D);  // no printing cost
	//Total Complexity O(N*N) = O(N^2)
}

bool DISwap(list<int> &LD)
{
	bool Swap = false;
	auto Prev = LD.begin(), Next = LD.begin();
	Next++;
	while (Next != LD.end())    //O(N)
	{
		if (*Prev > *Next)
		{
			swap(*Prev, *Next);
			Swap = true;
		}
		Next++;
		Prev++;
	}
	return Swap;   //O(N)
}
void BubbleSortDDW(list<int> LD)
{
	bool Swap = false;
	do
	{
		Swap = DISwap(LD);
	} while (Swap);
	PrintList("Bubble Sorting List Pointer : ", LD);
}
void BubbleSortListDBool(list<int> Data)
{
	bool Swap = false;
	do
	{
		Swap = DISwap(Data);  //O(N)
	} 
	while (Swap);   //O(N)
	PrintList("Bubble Sort Bool : ", Data);   //no printuing cost
	//Total Complexity O(N*N) = O(N^2)
}


int main()
{
	vector<int> D;
	D.push_back(12);
	D.push_back(33);
	D.push_back(5);
	D.push_back(31);
	D.push_back(1);
	D.push_back(22);
	D.push_back(78);
	D.push_back(8);
	D.push_back(7);
	D.push_back(16);
	D.push_back(2);
	PrintV("Data Entered : ",D);
	BubbleSort(D);
	BubbleSortBool(D);
	BubbleSortDW(D);
	
	list<int> ListD;
	ListD.push_back(12);
	ListD.push_back(33);
	ListD.push_back(5);
	ListD.push_back(31);
	ListD.push_back(1);
	ListD.push_back(22);
	ListD.push_back(78);
	ListD.push_back(8);
	ListD.push_back(7);
	ListD.push_back(16);
	ListD.push_back(2);

	PrintList("Linked List Data >>>>", ListD);
	
	cout << "Linked List Data Swaping" << endl << endl;
	BubbleSortDW(ListD);
	BubbleSortListNest(ListD);
	BubbleSortListBool(ListD);
	
	cout << "Linked List Pointer Swaping" << endl << endl;
	BubbleSortDDW(ListD);
	BubbleSortListDBool(ListD);
	BubbleSortListDNest(ListD);

	return 0;
}