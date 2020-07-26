#pragma once
#include<iostream>
using namespace std;
template <typename T>
class CNode
{
	CNode<T> * Next;
	CNode<T> * Prev;
public:
	T Data;
	CNode(){}
	CNode(T D, CNode<T> *N = nullptr, CNode<T> *P = nullptr) :Data(D), Next(N), Prev(P){}
	void SetNext(CNode<T> *V)
	{
		Next = V;
	}
	CNode<T> * GetNext()
	{
		return Next;
	}
	void SetPrev(CNode<T> *V)
	{
		Prev = V;
	}
	CNode<T> * GetPrev()
	{
		return Prev;
	}
	~CNode(){}
};


template <typename T>
class CircularLinkedList
{
	CNode<T> * HeadAddress;
	CNode<T> * TailAddress;
public:
	template<typename Type>
	class Itrator
	{
		CNode<Type> *P;
	public:
		Itrator()
		{
			P = nullptr;
		}
		Itrator(CNode<Type> *Tr)
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
	CircularLinkedList()
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
		CNode<T> *Temp = new CNode<T>(Val);
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
			HeadAddress = Temp;
			HeadAddress->SetPrev(TailAddress);
			TailAddress->SetNext(HeadAddress);
		}
	}
	void InsertAtEnd(T End)
	{
		CNode<T> *P = new CNode<T>(End);
		if (HeadAddress == nullptr)
		{
			TailAddress = HeadAddress = P;
		}
		else
		{
			P->SetPrev(TailAddress);
			TailAddress->SetNext(P);
			TailAddress = P;
			HeadAddress->SetPrev(TailAddress);
			TailAddress->SetNext(HeadAddress);
		}
	}
	CNode<T>* SearchKey(T Key)
	{
		CNode<T>* Temp = HeadAddress;
		while (Temp != TailAddress)
		{
			if (Temp->Data == Key)
			{
				return Temp;
			}
			Temp = Temp->GetNext();
		}
		return TailAddress;
	}
	void InsertAfter(T Val, CNode<T>* Key)
	{
		CNode<T> * Temp = SearchKey(Key->Data);
		if (Temp == TailAddress)
		{
			InsertAtEnd(Val);
		}
		else
		{
			CNode<T> *R = new CNode<T>(Val);
			for (CNode<T>* P = HeadAddress; true; P = P->GetNext())
			{
				if (P->Data == Temp->Data)
				{
					R->SetPrev(P->GetNext());
					R->SetNext(P->GetNext());
					P->SetNext(R);
					break;
				}
				if (P == TailAddress)
				{
					break;
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
		return Itrator<T>(TailAddress);
	}
	void InsertBefore(T Val, CNode<T>* P)
	{
		CNode<T>* Temp = SearchKey(P->Data);
		if (Temp == nullptr)
		{

			InsertAtEnd(Val);
		}
		else
		{
			CNode<T> *R = new CNode<T>(Val);

			for (CNode<T>* P = HeadAddress; P != TailAddress; P = P->GetNext())
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
	CNode<T>* MiddleValue()
	{
		if (HeadAddress->GetNext() == TailAddress)
		{
			return HeadAddress;
		}
		for (CNode<T>* P = HeadAddress, *Q = TailAddress; P != TailAddress; P = P->GetNext(), Q = Q->GetPrev())
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
	friend ostream& operator<<(ostream &, CircularLinkedList<T> & L)
	{
		if (L.HeadAddress == nullptr)
		{
			exit(1);
		}
		for (CNode<T>* P = L.HeadAddress; true ; P = P->GetNext())
		{
			cout << P->Data << " ";
			if (P == L.TailAddress)
			{
				break;
			}
		}
		cout << endl << endl;
		return cout;
	}
	CNode<T>* FindKthLastElement(int KValue)
	{
		KValue--;
			CNode<T>* current = HeadAddress;
			while (KValue > 0)
			{
				current = current->GetNext();
				KValue--;
			}
			CNode<T>* En = HeadAddress;
			while (current!=TailAddress)
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
			CNode<T> * R = HeadAddress;
			HeadAddress = HeadAddress->GetNext();
			if (IsEmpty())
			{
				HeadAddress = nullptr;
				TailAddress = nullptr;
			}
			delete R;
			HeadAddress->SetPrev(TailAddress);
		}
		else
			return;
	}
	void DeleteAtTail()
	{
		if (!IsEmpty())
		{
			CNode<T> * R = TailAddress;
			TailAddress = TailAddress->GetPrev();
			if (IsEmpty())
			{
				HeadAddress = nullptr;
				TailAddress = nullptr;
			}
			delete R;
			TailAddress->SetNext(HeadAddress);
		}
		else
			return;
	}
	~CircularLinkedList()
	{
		delete HeadAddress;
	}
};

