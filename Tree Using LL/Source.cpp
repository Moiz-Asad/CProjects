#include<iostream>
#include"BST.h"
using namespace std;
int main()
{
	BST<int> P;
	P.Insert(12);
	P.Insert(34);
	P.Insert(1);
	P.Insert(98);
	P.Insert(9);
	P.Insert(12);
	cout << "Data Inserted : ";
	
	P.PrintInorder();
	cout << "Data After Duplicate Removal : ";
	P.DuplicatesRemover();
	P.PrintInorder();
	cout << "Tree Destried : ";
	P.DestroyTree();
	cout << endl;
	return 0;
}