#pragma once
#include"LinkedList.h"
using namespace std;

template<class T>
class LLStack
{
	LinkedList<T> S;
public:
	LLStack(){}
	void Push(T V)
	{
		S.InsertAtFront(V);
	}
	void Pop()
	{
		if (!IsEmpty())
		{
			S.RemoveFront();
		}
		else
		{
			cout << "Stack is Empty!" << endl;
			return;
		}
	}
	T Top()
	{
		if (!IsEmpty())
		{
			S.GetHeadData();
		}
		else
		{
			cout << "Stack is Empty!" << endl;
			return;
		}
	}
	bool IsEmpty()
	{
		return S.IsEmpty();
	}
	void PrintSTK()
	{
		cout << S;
	}
	~LLStack(){}
};
