#pragma once
#include<iostream>
using namespace std;

template <typename T>
class JosephusGame
{
	template <typename T>
	class CNode
	{
		CNode<T> * Next;
	public:
		T Data;
		CNode(){}
		CNode(T D, CNode<T> *N = nullptr) :Data(D), Next(N){}
		void SetNext(CNode<T> *V)
		{
			Next = V;
		}
		CNode<T> * GetNext()
		{
			return Next;
		}
		~CNode(){}
	};
	CNode<T> * HeadAddress;
	CNode<T> * TailAddress;
	int No_Of_People;
	int Kval;
	void Insert(T E)
	{
		CNode<T> *P = new CNode<T>(E);
		if (HeadAddress == nullptr)
		{
			TailAddress = HeadAddress = P;
		}
		else
		{
			TailAddress->SetNext(P);
			TailAddress = P;
			TailAddress->SetNext(HeadAddress);
		}
	}
	void InitializePeople()
	{
		for (int i = 1; i <= No_Of_People; i++)
		{
			this->Insert(i);
		}
	}
	T JosephusPositionFinder()
	{
		if (HeadAddress != nullptr)
		{
			CNode<T> *SwordMan = HeadAddress;
			CNode<T> *Killed = HeadAddress;
			while (SwordMan->GetNext() != SwordMan)
			{
				// Itrate to Next Non-Killed PLayer and swap the sword
				for (int Iter = 1; Iter < Kval; Iter++)
				{
					Killed = SwordMan;
					SwordMan = SwordMan->GetNext();
				}
				// Player Get Killed by Sword Man
				Killed->SetNext(SwordMan->GetNext());
				cout << "\tKilled : ( " << SwordMan->Data << " )" << endl;
				SwordMan = Killed->GetNext();
			}
			// SwordMan->Data contain the last Sword Containing Man
			return SwordMan->Data;
		}
		else
		{
			cout << "\tThere is no player!" << endl;
			return -1;
		}
	}
	void GameInitialization()
	{
		int v = 0;
		cout << "\tEnter Total Number of People (N):";
		cin >> No_Of_People;
		InitializePeople();
		cout << "\tKilling Difference (K) :";
		cin >> Kval;
		if (No_Of_People > 1 && Kval > 1)
		{
			T Win;
			Win = JosephusPositionFinder();
			cout << "\tPlayer Wins : " << Win << endl << endl;
		}
		else
		{
			cout << endl;
			cout << "\tThere Must be at least Two people to play this Game!" << endl << endl;
			return;
		}
		cout << "=================================================" << endl;
		cout << "|                  GAME FINISHED                |" << endl;
		cout << "=================================================" << endl << endl;
	}
public:
	void Start()
	{
		GameInitialization();
	}
	JosephusGame()
	{
		HeadAddress = nullptr;
		TailAddress = nullptr;
		No_Of_People = 2;
		Kval = 2;
	}
	friend ostream& operator<<(ostream &, JosephusGame<T> & L)
	{
		if (L.HeadAddress == nullptr)
		{
			return cout;
		}
		for (CNode<T>* P = L.HeadAddress; true; P = P->GetNext())
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
	~JosephusGame()
	{
		delete HeadAddress;
		HeadAddress = nullptr;
		TailAddress = nullptr;
	}
};
void GameStart()
{
	JosephusGame<int> G;
	G.Start();
}
int main()
{
	// Data Structure I Used.
	// For This Specified Problem I Used (Circular Singly Linked List) as my Data Structure 

	// Why I Use Circular Singly Linked List ?
	// Answer:
	// The Reason is that in that specified problem the no. of people 
	// are in the form of circle means the next element of list's end 
	// is The start and triversalis in unidirectional. (Single direction)
	// which is Start to next. 

	cout << "=================================================" << endl;
	cout << "|                JOSEPHUS GAME                  |" << endl;
	cout << "=================================================" << endl;
	cout << "|                     MENU                      |" << endl;
	cout << "=================================================" << endl;
	int Choice = 0;
	do
	{
		cout << "\tEnter 1 to Start the Game." << endl;
		cout << "\tEnter 2 to Exit." << endl;
		cout << "\tChoice : ";
		cin >> Choice;
		cout << endl;
		if (Choice != 1 && Choice != 2)
		{
			cout << Choice << "\tNo Such Choice Exists in Menu! Try Again" << endl;
		}
		else
		if (Choice == 1)
		{
			cout << "=================================================" << endl;
			cout << "|                 GAME STARTED                  |" << endl;
			cout << "=================================================" << endl << endl;
			GameStart();
		}
	} while (Choice != 2);
	cout << "=================================================" << endl;
	cout << "|         GAME ENDED THANKS FOR PLAYING         |" << endl;
	cout << "=================================================" << endl << endl;
	return 0;
}