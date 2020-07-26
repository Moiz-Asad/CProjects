#pragma once
#include<iostream>
using namespace std;
template <typename T>
class Node
{
	Node<T> * Next;
	Node<T> * Prev;
public:
	T Data;
	Node(){}
	Node(T D, Node<T> *N = nullptr, Node<T> *P = nullptr) :Data(D), Next(N),Prev(P){}
	void SetNext(Node<T> *V)
	{
		Next = V;
	}
	Node<T> * GetNext()
	{
		return Next;
	}
	void SetPrev(Node<T> *V)
	{
		Prev = V;
	}
	Node<T> * GetPrev()
	{
		return Prev;
	}
	~Node(){}
};


template <typename T>
class DoublyLinkedList
{
	Node<T> * HeadAddress;
	Node<T> * TailAddress;

public:
	template<typename Type>
	class Itrator
	{
		Node<Type> *P;
	public:
		Itrator()
		{
			P = nullptr;
		}
		Itrator(Node<Type> *Tr)
		{
			P = Tr;
		}
		Itrator(Itrator<Type> &i)
		{
			this->P = i.P;
		}
		Itrator& operator--()
		{
			P = P->GetPrev();
			return *this;
		}
		Itrator& operator++()
		{
			P = P->Next;
			return *this;
		}
		Type operator*()
		{
			return P->Data;
		}
		bool operator==(Itrator<Type> &i)
		{
			return this->P == i.P;
		}
		bool operator!=(Itrator<Type> &i)
		{
			return this->P != i.P;
		}
};
	DoublyLinkedList()
	{
		HeadAddress = nullptr;
		TailAddress = nullptr;
	}
	bool IsEmpty()
	{
		if (HeadAddress == nullptr && TailAddress == nullptr)
		{
			return true;
		}
		return false;
	}
	void InsertAtFront(T Val)
	{
		Node<T> *Temp = new Node<T>(Val);
		if (HeadAddress == nullptr)
		{
			HeadAddress = Temp;
			if (TailAddress == nullptr)
			{
				TailAddress = HeadAddress;
			}
		}
		else
		{
			Temp->SetNext(HeadAddress);
			Temp->SetPrev(HeadAddress->GetNext());
			HeadAddress = Temp;
		}
	}
	bool Swap(int LeftIndex,int RightIndex)
	{
		if (LeftIndex >= RightIndex)
		{
			cout << "Left Index should be less then Right one!" << endl;
			return false;
		}
		else
		{
			Node<T> *S1 = HeadAddress;
			Node<T> *S2 = nullptr;
			for (int i = 0; S1 != nullptr;)
			{
				if (i == LeftIndex)
				{
					S2 = S1;
					for (int j = i; S2 != nullptr; j)
					{
						if (j == RightIndex)
						{
							break;
						}
						else
						{
							S2 = S2->GetNext();
							j++;
						}
					}
					break;
				}
				else
				{
					S1 = S1->GetNext();
					i++;
				}
			}
			swap(S1->Data, S2->Data);
			return true;
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
			P->SetPrev(TailAddress);
			TailAddress->SetNext(P);
			TailAddress = P;
		}
	}
	Node<T>* SearchKey(T Key)
	{
		Node<T>* Temp = HeadAddress;
		while (Temp != nullptr)
		{
			if (Temp->Data == Key)
			{
				return Temp;
			}
			Temp = Temp->GetNext();
		}
		return nullptr;
	}
	void InsertAfter(T Val,Node<T>* Key)
	{
		Node<T> * Temp = SearchKey(Key->Data);
		if (Temp == nullptr)
		{
			InsertAtEnd(Val);
		}
		else
		{
			Node<T> *R = new Node<T>(Val);
			for (Node<T>* P = HeadAddress; P != nullptr; P = P->GetNext())
			{
				if (P->Data == Temp->Data)
				{
					R->SetPrev(P->GetNext());
					R->SetNext(P->GetNext());
					P->SetNext(R);
				}
			}
		}
	}
	Itrator<T> Begin()
	{
		return Itrator<T>(HeadAddress);
	}
	Itrator<T> End()
	{
		return Itrator<T>(nullptr);
	}
	void InsertBefore(T Val, Node<T>* P)
	{
		Node<T>* Temp = SearchKey(P->Data);
		if (Temp == nullptr)
		{
			
			InsertAtEnd(Val);
		}
		else
		{
			Node<T> *R = new Node<T>(Val);

			for (Node<T>* P = HeadAddress; P != nullptr; P = P->GetNext())
			{
				if (P->GetNext()->Data == Temp->Data)
				{
					R->SetNext(P->GetNext());
					R->SetPrev(P);
					P->SetNext(R);
					break;
				}
			}
		}
	}
	Node<T>* MiddleValue()
	{
		for (Node<T>* P = HeadAddress, *Q = TailAddress; P != nullptr; P = P->GetNext(), Q = Q->GetPrev())
		{
			if (Q == P)
			{
				return P;
			}
			if (P->GetNext() == Q)
			{
				return P;
			}
		}
	}
	friend ostream& operator<<(ostream &, DoublyLinkedList & L)
	{
		for (Node<T>* P = L.HeadAddress; P != nullptr; P = P->GetNext())
		{
			cout << P->Data << " ";
		}
		cout << endl << endl;
		return cout;
	}
	Node<T>* FindKthLastElement(int KValue)
	{
		
		Node<T>* current = HeadAddress;  
		while (KValue > 0)
		{
			current = current->GetNext();
			KValue--;
		}
		Node<T>* En = HeadAddress;
		while (current)
		{
			current = current->GetNext();
			En = En->GetNext();
		}
		return En;
	}
	void DeleteAtFront()
	{
		if (!IsEmpty())
		{
			Node<T> * R = HeadAddress;
			HeadAddress = HeadAddress->GetNext();
			if (IsEmpty())
			{
				HeadAddress = nullptr;
				TailAddress = nullptr;
			}
			delete R;
			HeadAddress->SetPrev(nullptr);
		}
		else
			return;
	}
	void DeleteAtTail()
	{
		if (!IsEmpty())
		{
			Node<T> * R = TailAddress;
			TailAddress = TailAddress->GetPrev();
			if (IsEmpty())
			{
				HeadAddress = nullptr;
				TailAddress = nullptr;
			}
			delete R;
			TailAddress->SetNext(nullptr);
		}
		else
			return;
	}
	~DoublyLinkedList()
	{
		delete HeadAddress;
	}
};

