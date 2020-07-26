#pragma once
template<typename Type>
struct Node
{
	Type Data;
	Node * LeftChildTree;
	Node * RightChildTree;
	Node(Type D)
	{
		Data = D;
		LeftChildTree = nullptr;
		RightChildTree = nullptr;
	}
};

