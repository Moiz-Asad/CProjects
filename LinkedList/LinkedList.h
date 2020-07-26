#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T Data;
	Node<T> * Next;
	Node(){}
	Node(T D, Node<T> *N = nullptr) :Data(D), Next(N){}
	void SetNext(Node<T> *V)
	{
		Next = V;
	}
	Node<T> * GetNext()
	{
		return Next;
	}
	~Node(){}
};


template <typename T>
class LinkedList
{
	Node<T> * HeadAddress;
	Node<T> * TailAddress;

public:
	LinkedList()
	{
		HeadAddress = nullptr;
		TailAddress = nullptr;
	}
	void InsertAtFront(T Val)
	{
		HeadAddress = new Node<T>(Val, HeadAddress);
		if (TailAddress == nullptr)
		{
			TailAddress = HeadAddress;
		}
	}
	void InsertAtEnd(T End)
	{
		Node<T> *P = new Node<T>(End);
		if (HeadAddress == nullptr)
		{
			TailAddress = HeadAddress = P;
		}
		else
		{
			TailAddress->SetNext(P);
			TailAddress = P;
		}
	}
	Node<T>* GetNext()
	{
		return HeadAddress->GetNext();
	}
	void SetHead(Node<T>* P)
	{
		HeadAddress = P;
	}
	Node<T>* GetHead()
	{
		return HeadAddress;
	}
	T GetData()
	{
		return Data;
	}
	friend ostream& operator<<(ostream & ,LinkedList & L)
	{
		for (Node<T>* P = L.HeadAddress; P != nullptr; P = P->GetNext())
		{
			cout << P->Data << " ";
		}
		cout << endl;
		return cout;
	}
	~LinkedList(){}
};

