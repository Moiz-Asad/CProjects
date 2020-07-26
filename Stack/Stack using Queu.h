#pragma once
#include<iostream>
#include<queue>
using namespace std;

// ====> Class ADT
template<class T>
class Stack
{
	queue<T> Vs;
	queue<T> Ts;
public:

	Stack();
	void Push(T v);
	T Pop();
	T Top();
	bool IsEmpty();
	~Stack();
};

// Functions Definition
template<typename T>
Stack<T>::Stack()
{
}
template<typename T>
void Stack<T>::Push(T v)
{
	// Move Data from Vs to Ts stack
	T n;
	while (!Vs.empty())
	{
		n = Vs.front();
		Ts.push(n);
		Vs.pop();
	}

	// Insering Coming element
	Vs.push(v);

	// Move Data from Ts to Vs 
	while (!Ts.empty())
	{
		n = Ts.front();
		Vs.push(n);
		Ts.pop();
	}
}
template<typename T>
T Stack<T>::Pop()
{ 
	if (!Vs.empty())
	{
		T n = Vs.front();
		Vs.pop();
		return n;
	}
	else
	{
		exit(1);
	}
}
template<typename T>
T Stack<T>::Top()
{
	return Vs.top();
}
template<typename T>
bool Stack<T>::IsEmpty()
{
	if (Vs.empty())
	{
		return true;
	}
	return false;
}
template<typename T>
Stack<T>::~Stack()
{
}