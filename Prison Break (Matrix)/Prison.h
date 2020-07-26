#pragma once
#include"Position.h"
#include"Matrix.h"
class Prison
{
public:
	Prison();
	Position* FindSpeciicPosition(float Find, matrix *Map, int &size);
	bool EscapeCheck(matrix *Map, Position *&p);
	bool LRCheck(matrix *&Map, Position *&p);
	bool UpCheck(matrix *&Map, Position *&p);
	bool DownCheck(matrix *&Map, Position *&p);
	~Prison();
};

