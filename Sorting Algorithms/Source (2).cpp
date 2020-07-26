#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

void PrintV(vector<int> D)
{
	for (int i = 0; i <D.size(); i++)
	{
		cout << D[i] << " ";
	}
	cout << endl << endl;
}
void Merge(vector<int>&Left, vector<int>& Right, vector<int>& Data)
{
	int LS = Left.size();
	int RS = Right.size();
	int a = 0, b = 0, c = 0;

	while (b< LS && c < RS)
	{
		if (Left[b] < Right[c]) 
		{
			Data[a] = Left[b];
			b++;
		}
		else 
		{
			Data[a] = Right[c];
			c++;
		}
		a++;
	}
	while (b < LS) 
	{
		Data[a] = Left[b];
		b++; 
		a++;
	}
	while (c < RS) 
	{
		Data[a] = Right[c];
		c++; 
		a++;
	}
}
list<int> MergeList( list<int> &A, list<int> &B)
{
	list<int> Data;
	auto ai = A.begin(), bi = B.begin();
	while (ai != A.end() && bi != B.end())
	{
		if (*ai < *bi)
		{
			Data.insert(Data.end(),*ai);
			ai++;
		}
		else
		{
			Data.insert(Data.end(), *bi);
			*bi++;
		}
	}
	if (ai == A.end())
	{
		Data.insert(Data.end(), bi, B.end());
	}
	else
	if (bi == B.end())
	{
		Data.insert(Data.end(), ai, A.end());
		ai = B.end();
	}
	return Data;
}
void MergeSort(vector<int> & Data)
{
	if (Data.size() <= 1)
	{
		return;
	}
	int mid = Data.size() / 2;
	vector<int> Left, Right;

	for (int j = 0; j < mid; j++)
	{
		Left.push_back(Data[j]);
	}
	for (int j = 0; j < (Data.size()) - mid; j++)
	{
		Right.push_back(Data[mid + j]);
	}
	MergeSort(Left);
	MergeSort(Right);
	Merge(Left, Right, Data);
}
void MergeSortList(list<int> &Data)
{
	if (Data.size() <= 1)
	{
		return;
	}
	else
	{
		list<int> A, B;
		auto li = Data.begin();
		for (int i = 0; i < Data.size() / 2; i++)   //O(N/2)
		{
			A.insert(A.end(),*li);
			li++;
		}
		for (int i = Data.size()/2; i < Data.size(); i++)  //O(N/2)
		{
			B.insert(B.end(), *li);
			li++;
		}
		MergeSortList(A);
		MergeSortList(B);
		Data = MergeList(A,B);
	}
	//	(log N) : 2 ^ (log N) (or N / 2) 
	// Total complexity = O(LogN)

}
void PrintList(list<int> LD)
{
	for (auto i = LD.begin(); i != LD.end(); i++)  //O(N)
	{
		cout << *i << " ";
	}
	cout << endl << endl;
}
int main()
{
	vector<int> A;
		A.push_back(21);
		A.push_back(13);
		A.push_back(5);
		A.push_back(17);
		A.push_back(9);
		A.push_back(11);
		MergeSort(A);
		PrintV(A);
		list<int> B;
		B.push_back(21);
		B.push_back(13);
		B.push_back(5);
		B.push_back(17);
		B.push_back(9);
		B.push_back(11);
		MergeSortList(B);
		PrintList(B);
	return 0;
}