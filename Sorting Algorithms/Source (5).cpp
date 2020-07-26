#include<iostream>
#include<list>
#include<vector>
using namespace std;
void PrintLL(const vector<int> &LD)
{
	for (auto i = LD.begin(); i != LD.end(); i++)    //O(n)
	{
		cout << *i << " ";
	}
	cout << endl << endl;
}
void PrintLL(const list<int> &LD)
{
	for (auto i = LD.begin(); i != LD.end(); i++)          //O(n)
	{
		cout << *i << " ";
	}
	cout << endl << endl;
}
void Insertion_Sort(vector<int> & Data)
{
	int S = Data.size();
	for (int i = 0; i < S - 1; i++)                  //O(n)
	{
		int temp = Data[i + 1];
		int j = i;
		while (j >= 0 && temp <= Data[j])        //O(n)
		{
			Data[j + 1] = Data[j];
			--j;
		}
		Data[j + 1] = temp;
	}
	// Time Complecity = n*n = O(n^2)
}
void Insertion_Sort(list<int> & L)
{
	auto Position = L.begin();
	auto Insert = L.begin();
	Position++;
	for (Position; Position != L.end();Position++)     //O(n)
	{
		Insert = L.begin();
		for (Insert; Insert != Position; Insert++)     //O(n)
		{
			if (*Insert > *Position)
			{
				iter_swap(Position, Insert);
			}
		}
	}
	// Time Complecity = n*n = O(n^2)
}
int main()
{
		vector<int> L;
		L.push_back(12);
		L.push_back(99);
		L.push_back(121);
		L.push_back(45);
		L.push_back(14);
		L.push_back(342);
		L.push_back(11);
		L.push_back(9);
		Insertion_Sort(L);
		cout << "Sort By Vector : ";
		PrintLL(L);
		list<int> La;
		La.push_back(12);
		La.push_back(99);
		La.push_back(121);
		La.push_back(45);
		La.push_back(14);
		La.push_back(342);
		La.push_back(11);
		La.push_back(9);
		Insertion_Sort(La);
		cout << "Sort By List : ";
		PrintLL(La);
	return 0;
}