#include "Prison.h"
Prison::Prison()
{
}
Position* Prison::FindSpeciicPosition(float Find, matrix *Map,int &size)
{
	int count = 0;
	for (int i = 0; i < Map->getrow(); i++)
	{
		for (int j = 0; j < Map->getcolm(); j++)
		{
			if (Map->vs[i][j] == Find)
			{
				count++;
			}
		}
	}
	Position *p = new Position[count];
	int a = 0;
	for (int i = 0; i < Map->getrow(); i++)
	{
		for (int j = 0; j < Map->getcolm(); j++)
		{
			if (Map->vs[i][j] == Find)
			{
				p[a].rw = i;
				p[a].col = j;
				a++;
			}
		}
	}
	size = a;
	return p;
}
bool Prison::EscapeCheck(matrix *Map,Position *&p)
{
	matrix *temp = Map;
	if (LRCheck(Map, p) == true && p->rw == -1)
	{
		return true;
	}
	else
	if (LRCheck(Map, p) == true)
	{
		return true;
	}
	else
		return false;
}
bool Prison::LRCheck(matrix *&Map, Position *&p)
{
	int a = p->rw;
	int b = p->col;
	if (Map->vs[a][b - 1] == 1 && Map->vs[a][b + 1] == 1)
	{
		return false;
	}
	else
	{
		if (Map->vs[a][b - 1] == 0)
		{
			Map->vs[a][b - 1] = 5;
			p->col = b - 1;
			return true;
		}
		else
		if (Map->vs[a][b - 1] == 3)
		{
			p->rw = -1;
			return true;
		}
		else
		if (Map->vs[a][b + 1] == 0)
		{
			Map->vs[a][b + 1] = 5;
			p->col = b + 1;
			return true;
		}
		return true;
	}
}
bool Prison::UpCheck(matrix *&Map, Position *&p)
{
	int a = p->rw-1;
	int b = p->col;
	int count = 0;
	int i = 0;
	for (i = b - 1; i <= b + 1; i++)
	{
		if (Map->vs[a][i] == 0)
		{
			Map->vs[a][i] = 5;
		}
		else
		if (Map->vs[a][i] == 1)
		{
			count++;
		}
		else
		if (Map->vs[a][i] == 3)
		{
			p->rw = -1;
			return true;
		}
	}
	if (count == 3)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool Prison::DownCheck(matrix *&Map, Position *&p)
{
	int a = p->rw + 1;
	int b = p->col;
	int count=0;
	int i = 0;
	for (i = b - 1; i <= b + 1; i++)
	{
		if (Map->vs[a][i] == 0)
		{
			Map->vs[a][i] = 5;
		}
		else
		if (Map->vs[a][i] == 1)
		{
			count++;
		}
		else
		if (Map->vs[a][i] == 3)
		{
			p->rw = -1;
			return true;
		}
	}
	if (count == 3)
	{
		return false;
	}
	else
	{
		return true;
	}
}
Prison::~Prison()
{
}
