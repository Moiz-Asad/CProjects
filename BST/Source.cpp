#include<iostream>
#include<vector>
#include"BST.h"
using namespace std;

int main()
{
	BST<int> Tree,Tree2;
	Tree.Insert(25);
	Tree.Insert(51);
	Tree.Insert(60);
	Tree.Insert(24);
	Tree.Insert(91);
	Tree.Insert(2);
	
	Tree2.Insert(25);
	Tree2.Insert(51);
	Tree2.Insert(60);
	Tree2.Insert(24);
	Tree2.Insert(91);
	Tree2.Insert(2);

	cout << "Total Leaves Count : " << Tree.LeafCounter() << endl;
	cout << "Total Even Count : " << Tree.EvenCount() << endl;
	
	
	BST<int> Tree3;
	Tree3.LoadBST("d.txt");
	Tree3.SaveBST("d.txt");

	if (Tree.CompoareTrees(Tree,Tree2))
	{
		cout << "Both are Equal" << endl;;
	}
	else
	{
		cout << "Both are Not Equal" << endl;;
	}
	Tree.SaveBST("Data.txt");
	return 0;
}