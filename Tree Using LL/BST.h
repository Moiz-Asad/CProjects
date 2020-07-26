#pragma once
#include<iostream>
#include"Tree.h"
using namespace std;

template<class T>
class BST : public Tree<T>
{
	void CopyTree(Node<T>* Destin, Node<T>* Sourcr)
	{
		if (Sourcr == nullptr)
		{
			Destin = nullptr;
		}
		else
		{
			Sourcr = new Node<T>;
			Destin->Data = Sourcr->Data;
			CopyTree(Destin->LeftChildTree, Sourcr->LeftChildTree);
			CopyTree(Destin->RightChildTree, Sourcr->RightChildTree);
		}
	}
	void DestroyTreeH(Node<T>* DT)
	{
		if (DT == nullptr)
		{
			return;
		}
		else
		{
			DestroyTreeH(DT->LeftChildTree);
			DestroyTreeH(DT->RightChildTree);
			delete DT;
		}
	}
	void INORDER(Node<T>* p)
	{
		if (p == nullptr)
		{
			return;
		}
		else
		{
			INORDER(p->LeftChildTree);
			cout << p->Data << " ";
			INORDER(p->RightChildTree);
		}
	}
public:
	BST()
	{
		this->Root = nullptr;
	}
	BST(Node<T> *CP)
	{
		CopyTree(this->Root, CP);
	}
	void Insert(T Vs)
	{
		Node<T> *TempNode;
		TempNode = new Node<T>(Vs);
		if (Root == nullptr)
		{
			this->Root = TempNode;
		}
		else
		{
			Node<T> *Temp = Root;
			while (true)
			{
				if (Vs < Temp->Data)
				{
					if (Temp->LeftChildTree == nullptr)
					{
						Temp->LeftChildTree = TempNode;
						break;
					}
					else
					{
						Temp = Temp->LeftChildTree;
					}
				}
				else
				{
					if (Temp->RightChildTree == nullptr)
					{
						Temp->RightChildTree = TempNode;
						break;
					}
					else
					{
						Temp = Temp->RightChildTree;
					}
				}
			}
		}
	}
	void DestroyTree()
	{
		DestroyTreeH(this->Root);
		this->Root = nullptr;
	}
	void PrintInorder()
	{
		INORDER(Root);
		cout << endl;
	}
	Node<T>* MinNode(Node<T>* Tm)
	{
		Node<T>* C = Tm;
		while (C->LeftChildTree != nullptr)
		{
			C = C->LeftChildTree;
		}
		return C;
	}
	void deleteNode(Node<T>* &root, int Val)
	{
		if (root == nullptr)
		{
			return;
		}
		if (Val < root->Data)
		{
			deleteNode(root->LeftChildTree, Val);
		}
		else
		if (Val > root->Data)
		{
			deleteNode(root->RightChildTree, Val);
		}
		else
		{
			if (root->LeftChildTree == nullptr && root->RightChildTree == nullptr)
			{
				delete root;
				root = nullptr;
				return;
			}

			if (root->LeftChildTree == nullptr)
			{
				Node<T> *temp = root->RightChildTree;
				root = nullptr;
				return;
			}
			else if (root->RightChildTree == nullptr)
			{
				Node<T> *temp = root->LeftChildTree;
				delete root;
				root = nullptr;
				return;
			}
			Node<T>* temp = MinNode(root->RightChildTree);
			root->Data = temp->Data;
			deleteNode(root->RightChildTree, temp->Data);
		}
		return;
	}
	bool BinarySearchHelper(Node<T>* R, T Tt)
	{
		if (R == nullptr)
			return false;
		if (R->Data == Tt)
			return true;
		if (R->Data > Tt)
			return BinarySearchHelper(R->LeftChildTree, Tt);
		else
			return BinarySearchHelper(R->RightChildTree, Tt);
	}


	void DupFinder(Node<T>* &Tmp)
	{
		if (Tmp == nullptr)
		{
			return;
		}
		if (BinarySearchHelper(Tmp->RightChildTree, Tmp->Data) == true)
		{
			deleteNode(Tmp->RightChildTree, Tmp->Data);
		}
		DupFinder(Tmp->LeftChildTree);
		DupFinder(Tmp->RightChildTree);
	}
	void DuplicatesRemover()
	{
		DupFinder(Root);
	}
	~BST()
	{
		this->DestroyTree();
	}
};