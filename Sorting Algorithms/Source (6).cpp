#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
void PrintLL(const vector<int> &LD)
{
	for (auto i = LD.begin(); i != LD.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl << endl;
}
void PrintLL(const list<int> &LD)
{
	for (auto i = LD.begin(); i != LD.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl << endl;
}
void bucketSort(vector<int> &V, int n)
{
	vector<vector<int>> b(n);
	for (int i = 0; i < n; i++)
	{
		int bi = n%V[i] - i -1;
		if (bi < 0)
		{
			bi = bi + n;
		}
		b[bi].push_back(V[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		sort(b.begin(), b.end());
	}
	int index = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			V[index++] = b[i][j];
		}
	}
}
void bucketSort(list<int> &V, int n)
{
	vector<list<int>> b(n);
	auto List = V.begin();
	for (int i = 0; i < n; i++)
	{
		b[i].push_back(*List);
		List++;
	}
	for (int i = 0; i < n; i++)
	{
		sort(b.begin(), b.end());
	}
	int index = 0;
	V.clear();
	for (int i = 0; i < n; i++)
	{
		for (auto j = b[i].begin(); j != b[i].end(); j++)
		{
			V.push_back(*j);
		}
	}
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
		int n = L.size();
		bucketSort(L,n);
		cout << "Bucket Sort By Vector : ";
		PrintLL(L);
	
		list<int> P;
		P.push_back(12);
		P.push_back(99);
		P.push_back(121);
		P.push_back(45);
		P.push_back(14);
		P.push_back(342);
		P.push_back(11);
		P.push_back(9);
		int nP = P.size();
		bucketSort(P, n);
		cout << "Bucket Sort By List : ";
		PrintLL(L);
		return 0;
}