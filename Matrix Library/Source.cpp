#include<fstream>
#include<iostream>
#include"matrix.h"
using namespace std;
void Datareader(const char filename[], int &size, matrix *&m);
int main()
{
	matrix *m;
	int size = 0;
	Datareader("Text.txt",size,m);
	for (int i = 0; i < size; i++)
	{
		m[i].print();
		cout << endl;
	}
	cout << "What operations you want to perform."<<endl;
	cout << "Enter 1 for addition of two matrices."<<endl;
	cout << "Enter 2 for subtraction of two matrices." << endl;
	cout << "Enter 3 for multiplication of two matrices." << endl;
	cout << "Enter 4 for division of two matrices." << endl;
	cout << "Enter 5 for addition of matrix with value." << endl;
	cout << "Enter 6 for subtraction of matrix with value." << endl;
	cout << "Enter 7 for multiplication of matrix with value." << endl;
	cout << "Enter 8 for division of matrix with value." << endl;
	cout << "Enter 9 to find transpose of matrix." << endl;
	cout << "Enter 10 to Rotate Clockwise of matrix 90." << endl;
	cout << "Enter 11 to Rotate Clockwise of matrix 180." << endl;
	cout << "Enter 12 to Rotate Clockwise of matrix 270." << endl;
	cout << "Enter 13 to Rotate Anti-Clockwise of matrix 90." << endl;
	cout << "Enter 14 to Rotate Anti-Clockwise of matrix 180." << endl;
	cout << "Enter 15 to Rotate Anti-Clockwise of matrix 270." << endl;
	int choice = 0;
	cout << "Your Choice  : " << endl;
	cin >> choice;
	if (choice == 1)
	{
		if (m[0].isequal(m[1]))
		{
			matrix ad;
			ad = m[0].add(m[1]);
			ad.print();
		}
		else
		{
			cout << "Both Matrices Are not equal (Addition not possible)"<<endl;
		}
	}
	else
	if (choice == 2)
	{
		if (m[0].isequal(m[1]))
		{
			matrix sub;
			sub = m[0].sub(m[1]);
			sub.print();
		}
		else
		{
			cout << "Both Matrices Are not equal (Subtract not possible)" << endl;
		}
	}
	else
	if (choice == 3)
	{
		matrix n;
		n = m[0].mul(m[1]);
		if (n.mulcheck()==false)
		{
			n.print();
		}
		else
		{
			cout << "Multiplication not possible"<<endl;
		}
	}
	else
	if (choice == 4)
	{
		/////
	}
	else
	if (choice == 5)
	{
		matrix n;
		int value = 0;
		cout << "Enter a value : ";
		cin >> value;
		n=m[0].addall(value);
		cout << "Addition Of Value "<<endl;
		n.print();
	}
	else
	if (choice == 6)
	{
		matrix n;
		int value = 0;
		cout << "Enter a value : ";
		cin >> value;
		n = m[0].suball(value);
		cout << "Subtraction Of Value " << endl;
		n.print();
	}
	else
	if (choice == 7)
	{
		matrix n;
		int value = 0;
		cout << "Enter a value : ";
		cin >> value;
		n = m[0].mullall(value);
		cout << "Multiplication Of Value " << endl;
		n.print();
	}
	else
	if (choice == 8)
	{
		matrix n;
		int value = 0;
		cout << "Enter a value : ";
		cin >> value;
		n = m[0].divall(value);
		cout << "Division Of Value " << endl;
		n.print();
	}
	else
	if (choice == 9)
	{
		matrix n;
		n = m[0].transpose();
		cout << "Transpose " << endl;
		n.print();
	}
	else
	if (choice == 10)
	{
		matrix n;
		n = m[0].rotatecw();
		cout << "Rotation 90" << endl;
		n.print();
	}
	else
	if (choice == 11)
	{
		matrix n;
		n = m[0].rotatecw();
		n = m[0].rotatecw();
		cout << "Rotation 180" << endl;
		n.print();
	}
	else
	if (choice == 12)
	{
		matrix n;
		n = m[0].rotatecw();
		n = m[0].rotatecw();
		n = m[0].rotatecw();
		cout << "Rotation 270" << endl;
		n.print();
	}
	else
	if (choice == 13)
	{
		matrix n;
		n = m[0].anticlockrotate();
		cout << "Anti Rotation 90" << endl;
		n.print();
	}
	else
	if (choice == 14)
	{
		matrix n;
		n = m[0].anticlockrotate();
		n = m[0].anticlockrotate();
		cout << "Anti Rotation 180" << endl;
		n.print();
	}
	else
	if (choice == 15)
	{
		matrix n;
		n = m[0].anticlockrotate();
		n = m[0].anticlockrotate();
		n = m[0].anticlockrotate();
		cout << "Anti Rotation 270" << endl;
		n.print();
	}
	return 0;
}
void Datareader(const char filename[],int &size,matrix *&m)
{
	ifstream fin(filename);
	fin >> size;
	m = new matrix[size];
	for (int i = 0; i < size; i++)
	{
		m[i].loader(fin);
	}
}