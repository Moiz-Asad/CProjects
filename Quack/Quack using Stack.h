#pragma once
#include<stack>
#include<iostream>
using namespace std;
template<typename T>
class Quack
{
	stack<int> Ss;
	stack<int> Sh;
	stack<int> Sq;
	int size;
public:
	Quack();
	bool IsEmpty();
	T Pop();
	T Pull();
	void Push(T v);
	~Quack()
	{

	}
};
template<typename T>
Quack<T>::Quack()
{
	size = 0;
}
template<typename T>
bool Quack<T>::IsEmpty()
{
	if (size == 0)
	{
		retuen true;
	}
	return false;
}
template<typename T>
T Quack<T>::Pop()
{
	T temp;
	temp = Ss.top();
	Ss.pop();
	size--;
	return temp;
}
template<typename T>
T Quack<T>::Pull()
{
	if (Sq.empty())
	{
		int s = size/2;
		for (int i = 0; i < s; i++)
		{
			Sh.push(Ss.top());
			size--;
			Ss.pop();
		}
		while (!Ss.empty())
		{
			Sq.push(Ss.top());
			size--;
			Ss.pop();
		}
		while (!Sh.empty())
		{
			Ss.push(Sh.top());
			size++;
			Sh.pop();
		}
		T temp;
		temp = Sq.top();
		Sq.pop();
		size--;
		return temp;
	}
	else
	{
		T temp;
		temp = Sq.top();
		Sq.pop();
		size--;
		return temp;
	}
}
template<typename T>
void Quack<T>::Push(T v)
{
	Ss.push(v);
	size++;
}

