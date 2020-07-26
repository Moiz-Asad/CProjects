#include "Position.h"
#include<iostream>
using namespace std;

Position::Position()
{
	this->rw = 0;
	this->col = 0;
}
Position::Position(int r,int c)
{
	this->rw = r;
	this->col = c;
}
void Position::PrintPosition()
{
	cout << "(" << this->rw << " , " << this->col << ")" << endl;
	
}
Position::~Position()
{
}
