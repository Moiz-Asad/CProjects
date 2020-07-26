#pragma once
#include"Node.h"
using namespace std;

template<class T>
class Tree
{
protected:
	Node<T> *Root;
public:
	virtual void Insert(T) = 0;
};

