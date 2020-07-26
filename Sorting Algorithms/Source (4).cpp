#include<iostream>
#include<list>
#include<vector>
using namespace std;
void PrintLL(const list<int> &LD)
{
		for (auto i = LD.begin(); i != LD.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl << endl;
}
void PrintVL(const vector<int> &LD)
{
		for (auto i = LD.begin(); i != LD.end(); i++)
		{
			cout << *i << " ";
		}
		cout << endl << endl;
}

void SelectionSort(list<int> &Data)
{
		auto Temp = Data.begin();
		while (Temp!=Data.end())   //O(N)
		{
			auto Min = Temp;
			auto r = Temp;
			while (r != Data.end())   //O(N)
			{
				if (*Min > *r)
				{
					Min = r;
				}
				r++;
			}
			iter_swap(Temp,Min);
			Temp++;
		}
	//N*N = O(N^2)
}
void SelectionSortVector(vector<int> &Data)
{
	int in = 0;
	int s = Data.size();
	while (in < s)  	//= O(N)
	{
		int min = in;
		for (int i = in + 1; i < s; i++) //N*N = O(N^2)
		{
			if (Data[i] < Data[min])
			{
				min = i;
			}
		}
		Swap(Data[in], Data[min]);
		in++;
	}
	// O(N)+O(N^2)  =  o(N^2)

}
int main()
{
	list<int> L;
	L.push_back(12);
	L.push_back(99);
	L.push_back(121);
	L.push_back(45);
	L.push_back(14);
	L.push_back(342);
	L.push_back(11);
	L.push_back(9);
	SelectionSort(L);
	PrintVL(L);

	list<int> LA;
	LA.push_back(12);
	LA.push_back(99);
	LA.push_back(121);
	LA.push_back(45);
	LA.push_back(14);
	LA.push_back(342);
	LA.push_back(11);
	LA.push_back(9);
	SelectionSortVector(LA);
	PrintLL(LA);
	return 0;
}