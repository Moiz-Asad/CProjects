#pragma once
#include<iostream>
#include<stack>
using namespace std;

// ====> Class ADT
template<class T>
class MyQueue
{
	stack<T> Vs;
	stack<T> Ts;
public:

	MyQueue();
	void EnQueue(T v);
	T DeQueue();
	T Front();
	bool IsEmpty();
	~MyQueue();
};

// Functions Definition
template<typename T>
MyQueue<T>::MyQueue()
{
}
template<typename T>
void MyQueue<T>::EnQueue(T v)
{
	// Move Data from Vs to Ts MyQueue
	T n;
	while (!Vs.empty())
	{
		n = Vs.top();
		Ts.push(n);
		Vs.pop();
	}

	// Insering Coming element
	Vs.push(v);

	// Move Data from Ts to Vs 
	while (!Ts.empty())
	{
		n = Ts.top();
		Vs.push(n);
		Ts.pop();
	}
}
template<typename T>
T MyQueue<T>::DeQueue()
{
	if (!Vs.empty())
	{
		T n = Vs.top();
		Vs.pop();
		return n;
	}
	else
	{
		exit(1);
	}
}
template<typename T>
T MyQueue<T>::Front()
{
	return Vs.top();
}
template<typename T>
bool MyQueue<T>::IsEmpty()
{
	if (Vs.empty())
	{
		return true;
	}
	return false;
}
template<typename T>
MyQueue<T>::~MyQueue()
{
}