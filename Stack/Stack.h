#pragma once
#include<vector>
using namespace std;
template<class T>
class VStack
{
	vector<T> Vs;
	int ti;
public:
	VStack();
	VStack(int s);
	void Push(T v);
	bool Pop();
	T Top();
	bool IsEmpty();
	bool IsFull();
	~VStack();
};
template<typename T>
VStack<T>::VStack()
{
	ti = 0;
}
template<typename T>
VStack<T>::VStack(int s)
{
	Size = s;
	Vs = new vector<T>[s];
	ti = 0;
}
template<typename T>
void VStack<T>::Push(T v)
{
	Vs.push_back(v);
}
template<typename T>
bool VStack<T>::Pop()
{
	if (!Vs.empty())
	{
		ti--;
		Vs.pop_back();
		return true;
	}
	else
		return false;
}
template<typename T>
T VStack<T>::Top()
{
	return Vs[Vs.size()-1];
}
template<typename T>
bool VStack<T>::IsEmpty()
{
	if (ti == 0)
	{
		return true;
	}
	return false;
}
template<typename T>
bool VStack<T>::IsFull()
{
	if (ti == Vs.size())
	{
		return true;
	}
	return false;
}
template<typename T>
VStack<T>::~VStack()
{
}