#include<iostream>
#include<fstream>
#include"DynamicArray.h"
using namespace std;
int main()
{
	DynamicArray d(8,0);
	d.print();
	d.InsertAtEnd(4);
	d.print();
	d.InsertAt(12,3);
	d.print();
	//d.InsertFront(6);
	return 0;
}