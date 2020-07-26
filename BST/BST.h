#pragma once
#include<iostream>
#include<vector>

#include<fstream>
using namespace std;

template<typename Type>
class BST
{
	int Size;

	template<typename Type>
	struct Node
	{
		Type Data;
		Node<Type>* Left;
		Node<Type>* Right;

		Node(Type D)
		{
			Data = D;
			Left = nullptr;
			Right = nullptr;
		}
		~Node()
		{
		}
	};
	class iterator
	{
		Node<Type>* n;
	public:
		iterator()
		{
			n = nullptr;
		}
		iterator(Node<Type>* _n)
		{
			n = _n;
		}
		bool operator==(const iterator& i)const
		{
			return n == i.n;
		}
		bool operator!=(const iterator& i)const
		{
			return n != i.n;
		}
		iterator& operator++()
		{
			return *this;
		}
		Type operator*()
		{
			return n->Data;
		}
	};
	Node<Type>* BinarySearchHelper(Node<Type>* R, Type T)
	{
		if (R == nullptr || R->Data == T)
			return R;
		if (R->Data > T)
			return BinarySearchHelper(R->Left, T);
		else
			return BinarySearchHelper(R->Right, T);
	}
	void TraversalLNR(Node<Type>* R)
	{
		if (R == nullptr)
			return;
		TraversalLNR(R->Left);
		cout << R->Data << " ";
		TraversalLNR(R->Right);
	}

	// Attribute ==>
	Node<Type>* Root;

public:
	BST()
	{
		Root = nullptr;
		Size = 0;
	}
	Node<Type>* GetRoot()
	{
		return Root;
	}
	Node<Type>* GetRight()
	{
		return Root->Right;
	}
	Node<Type>* GetLeft()
	{
		return Root->Left;
	}
	iterator BinarySearch(Type T)
	{
		return iterator(BinarySearchHelper(Root, T));
	}

	iterator End()
	{
		return iterator(nullptr);
	}
	iterator Begin()
	{
		return iterator(Root);
	}
	void TravesalLNR()
	{
		TravesalLNR(Root);
	}
	int LeafcountHelper(Node<Type> * Root)
	{
		if (Root == nullptr)
			return 0;
		if (Root->Left == nullptr && Root->Right == nullptr)
			return 1;
		else
			return LeafcountHelper(Root->Left) + LeafcountHelper(Root->Right);
	}
	int LeafCounter()
	{
		return LeafcountHelper(this->Root);
	}
	
	int EvenCOunt(Node<Type>* x)
	{
		if (x == nullptr)
			return 0;

		return EvenCOunt(x->Left) + EvenCOunt(x->Right) + IsEven(x->Data);
	}
	int EvenCount()
	{
		return EvenCOunt(Root);
	}
	int IsEven(int a)
	{
		if (a % 2 == 0)
		{
			return 1;
		}
		return 0;
	}
	void TraversalLNR(Node<Type>* R, vector<int>& Vs)
	{
		if (R == nullptr)
			return;
		TraversalLNR(R->Left, Vs);
		Vs.push_back(R->Data);
		TraversalLNR(R->Right, Vs);
	}

	vector<int> BSTSortAscending()
	{
		vector<int> V;
		TraversalLNR(Root, V);
		return V;
	}

	void TraversalRNL(Node<Type>* R)
	{
		if (R == nullptr)
			return;
		TraversalLNR(R->Right);
		cout << R->Data << " ";
		TraversalLNR(R->Left);
	}

	void TravesalRNL()
	{
		TraversalRNL(Root);
	}

	void RNLSort(Node<Type>* R, vector<int> &Vs, int & i)
	{
		if (R == nullptr)
			return;
		RNLSort(R->Right, Vs, i);
		Vs[i] = R->Data; i++;
		RNLSort(R->Left, Vs, i);
	}

	vector<int> BSTDescendingSort()
	{

		vector<int> Vs(Size);
		int i = 0;
		RNLSort(Root, Vs, i);
		return Vs;
	}

	int TreeSize()
	{
		return TreeSize(Root);
	}

	int TreeSize(Node<Type>* x)
	{
		if (x == nullptr)
			return 0;

		return	TreeSize(x->left) + TreeSize(x->right) + 1;
	}

	int TreeHeight(Node<Type>* x)
	{
		if (x == nullptr)
			return 0;

		return max(TreeHeight(x->left), TreeHeight(x->right)) + 1;
	}
	int TreeHeight()
	{
		return TreeHeight(Root);
	}

	int PrimeCOunt(Node<Type>* x)
	{
		if (x == nullptr)
			return 0;

		return PrimeCOunt(x->left) + PrimeCOunt(x->right) + isPrime(x->Data);
	}
	int PrimeCount()
	{
		return PrimeCOunt(Root);
	}
	int isPrime(int n, int i = 2)
	{
		if (n <= 2)
			return (n == 2) ? 1 : 0;
		if (n % i == 0)
			return 0;
		if (i * i > n)
			return 1; 
		return isPrime(n, i + 1);
	}
	bool CompoareTrees(BST<Type> T, BST<Type> T2)
	{
		if (IsEqual(T.GetRoot(),T2.GetRoot()))
		{
			return true;
		}
		return false;
	}
	bool IsEqual(Node<Type>* N, Node<Type>* N1)
	{
		if (N == nullptr && N1 == nullptr)
		{
			return true;
		}
		if (N == nullptr || N1 == nullptr)
		{
			return false;
		}
		else
			return N->Data == N1->Data && IsEqual(N->Left, N1->Left) && IsEqual(N->Right, N1->Right);
	}
	void InsertRec(Node<Type>* &X, Type V)
	{
		if (X == nullptr)
		{
			X = new Node<Type>(V);
			return;
		}
		if (V < X->Data)
		{
			InsertRec(X->Left, V);
		}
		else
		{
			InsertRec(X->Right, V);
		}
	}
	void SaveBST(string filename)
	{
		ofstream fout(filename);
		SaveBSTFile(Root, fout);
	}
	void SaveBSTFile(Node<Type>* Root, ofstream &fout)
	{
		if (Root == nullptr)
		{
			return;
		}
		else
		{
			fout << Root->Data << " ";
			SaveBSTFile(Root->Left,fout);
			SaveBSTFile(Root->Right,fout);
		}
	}
	void LoadBST(string filename)
	{
		ifstream fin(filename);
		LoadBSTFile(fin);
	}
	void LoadBSTFile(ifstream& Fin)
	{
		int a = 0;
		while (Fin >> a)
		{
			Insert(a);
		}
			
	}
	void Insert(Type V)
	{
		InsertRec(Root, V);
	}
};


