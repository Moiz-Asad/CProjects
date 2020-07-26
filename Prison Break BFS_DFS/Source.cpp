#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
struct Position
{
	int r, c;
};
void ResizeMap(vector<vector<int>> & Map, int r, int c);
void ReadMap(ifstream &in,vector<vector<int>> &Map);
void PrintMap(vector<vector<int>> &Map);
void PrisonerFinder(vector<vector<int>> &Map, Position& Prisoner);
bool PrisonBreakExplore(vector<vector<int>> &Map, stack<Position> &Path,int Pr, int Pc);
bool PrisonBreakBFS(vector<vector<int>> &Map, stack<Position> &Path);
bool PrisonBreakDFS(vector<vector<int>> &Map, stack<Position> &Path);
void UpdateMap(vector<vector<int>> &Map, stack<Position> &Path);
void PrintPath(stack<Position> Path);


void ResizeMap(vector<vector<int>> & Map, int r, int c)
{
	Map.resize(r);
	for (int i = 0; i < r; i++)
	{
		Map[i].resize(c);
	}
}
void ReadMap(ifstream &in, vector<vector<int>> &Map)
{
	for (int i = 0; i < Map.size(); i++)
	{
		for (int j = 0; j < Map[i].size(); j++)
		{
			in >> Map[i][j];
		}
	}
	in.close();
}
void PrintMap(vector<vector<int>> &Map)
{
	for (int i = 0; i < Map.size(); i++)
	{
		for (int j = 0; j < Map[i].size(); j++)
		{
			if (Map[i][j] == 45)
			{
				cout << "-  ";
			}
			else
			{
				cout << Map[i][j] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
void PrisonerFinder(vector<vector<int>> &Map, Position& Prisoner)
{
	for (int i = 0; i < Map.size(); i++)
	{
		for (int j = 0; j < Map[i].size(); j++)
		{
			if (Map[i][j] == 2)
			{
				Prisoner.r = i;
				Prisoner.c = j;
				return;
			}
		}
	}
}
bool PrisonBreakExplore(vector<vector<int>> &Map, stack<Position> &Path, int Pr, int Pc)
{
	if (Pr < 0 || Pr >= Map.size() || Pc < 0 || Pc >= Map[0].size())
	{
		return false;
	}
	if (Map[Pr][Pc] == 1 || Map[Pr][Pc] == 4)
	{
		return false;
	}
	if (Map[Pr][Pc] == 3)
	{
		Position P;
		P.r = Pr;
		P.c = Pc;
		Path.push(P);
		return true;
	}
	Map[Pr][Pc] = 4;
	bool Found = (PrisonBreakExplore(Map, Path, Pr + 1, Pc)
		|| PrisonBreakExplore(Map, Path, Pr - 1, Pc)
		|| PrisonBreakExplore(Map, Path, Pr, Pc + 1)
		|| PrisonBreakExplore(Map, Path, Pr, Pc - 1));

	if (Found)
	{
		Position P;
		P.r = Pr;
		P.c = Pc;
		Path.push(P);
	}
	return Found;
}
bool PrisonBreakBFS(vector<vector<int>> &Map, stack<Position> &Path)
{
	queue<Position> Qp;
	queue<stack<Position>> QPath;
	Position P;
	stack<Position> S;

	PrisonerFinder(Map, P);
	Qp.push(P);
	QPath.push(S);

	while (!Qp.empty())
	{
		P = Qp.front();
		S = QPath.front();
		Qp.pop();
		QPath.pop();

		int Pr, Pc;
		Pr = P.r;
		Pc = P.c;
		if (Pr >= 0 && Pr < Map.size() && Pc >= 0 && Pc < Map.size() && Map[Pr][Pc] == 3)
		{
			S.push(P);
			while (!S.empty())
			{
				Path.push(S.top());
				S.pop();
			}
			return true;
		}
		else
		if (Pr >= 0 && Pr < Map.size() && Pc >= 0 && Pc < Map.size() && Map[Pr][Pc] != 1 && Map[Pr][Pc] != 4)
		{
			S.push(P);
			Map[Pr][Pc] = 4;
			P.r = Pr + 1;
			P.c = Pc + 1;
			Qp.push(P);
			QPath.push(S);

			P.r = Pr - 1;
			P.c = Pc;
			Qp.push(P);
			QPath.push(S);

			P.r = Pr;
			P.c = Pc+1;
			Qp.push(P);
			QPath.push(S);

			P.r = Pr;
			P.c = Pc - 1;
			Qp.push(P);
			QPath.push(S);
		}
		return false;
	}
}
bool PrisonBreakDFS(vector<vector<int>> &Map, stack<Position> &Path)
{
	Position Prisoner;
	PrisonerFinder(Map, Prisoner);
	return PrisonBreakExplore(Map, Path, Prisoner.r, Prisoner.c);
}
void UpdateMap(vector<vector<int>> &Map, stack<Position> &Path)
{
	Position P;
	while (!Path.empty())
	{
		P = Path.top();
		Path.pop();
		Map[P.r][P.c] = '-';
	}
}
void PrintPath(stack<Position> Path)
{
	Position P;
	int i = 1;
	cout << "\nPath:\n\n";
	while (!Path.empty())
	{
		P = Path.top();
		Path.pop();
		cout << "(" << P.r << "," << P.c << ") -> \t";
		if (i % 3 == 0 && i != 0)
		{
			cout << endl;
		}
		i++;
	}
	cout << endl << endl;
}


int main()
{
	ifstream fin("Grid.txt");
	if (!fin.is_open())
	{
		cout << "Prison Break Not Found!\n";
		return 0;
	}
	vector<vector<int>> Map;
	int R, C;
	fin >> R >> C;
	ResizeMap(Map, R, C);
	ReadMap(fin, Map);
	PrintMap(Map);

	stack<Position> Path;
	if (PrisonBreakDFS(Map, Path))
	{
		stack<Position> OPath;
		OPath = Path;
		cout << "Find Path :\n";
		vector<vector<int>> MapContainingPath = Map;
		UpdateMap(MapContainingPath, Path);
		PrintMap(MapContainingPath);
		PrintPath(OPath);
	}
	else
		cout << "Path not found!\n";
	return 0;
}