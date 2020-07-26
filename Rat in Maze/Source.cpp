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
void ReadMaze(ifstream &in, vector<vector<int>> &Maze);
void PrintMaze(vector<vector<int>> &Maze);
void PrisonerFinder(vector<vector<int>> &Maze, Position& Prisoner);
bool PathExplorer(vector<vector<int>> &Maze, stack<Position> &Path, int Pr, int Pc);
void UpdateMaze(vector<vector<int>> &Maze, stack<Position> &Path);
void PrintPath(stack<Position> Path);

void PrintMaze(vector<vector<int>> &Maze)
{
	for (int i = 0; i < Maze.size(); i++)
	{
		for (int j = 0; j < Maze[i].size(); j++)
		{
			if (Maze[i][j] == 45)
			{
				cout << "-  ";
			}
			else
			{
				cout << Maze[i][j] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
}
bool PathExplorer(vector<vector<int>> &Maze, stack<Position> &Path, int Pr, int Pc)
{
	if (Pr < 0 || Pr >= Maze.size() || Pc < 0 || Pc >= Maze.size() || Maze[Pr][Pc] == 0 || Maze[Pr][Pc] == 4)
	{
		return false;
	}
	if (Pc == Maze.size() - 1 && Pr == Maze.size() - 1)
	{
		Position P;
		P.r = Pr;
		P.c = Pc;
		Path.push(P);
		return true;
	}
	Maze[Pr][Pc] = 4;
	bool Found = (PathExplorer(Maze, Path, Pr + 1, Pc)
		|| PathExplorer(Maze, Path, Pr - 1, Pc)
		|| PathExplorer(Maze, Path, Pr, Pc + 1)
		|| PathExplorer(Maze, Path, Pr, Pc - 1));

	if (Found)
	{
		Position P;
		P.r = Pr;
		P.c = Pc;
		Path.push(P);
	}
	return Found;
}
bool MazeSearcher(vector<vector<int>> &Maze, stack<Position> &Path, Position Source)
{
	return PathExplorer(Maze, Path, Source.r, Source.c);
}
void UpdateMaze(vector<vector<int>> &Maze, stack<Position> &Path)
{
	Position P;
	while (!Path.empty())
	{
		P = Path.top();
		Path.pop();
		Maze[P.r][P.c] = '-';
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
		cout << "(" << P.r << "," << P.c << ") -> ";
		i++;
	}
	if (i >= Path.size())
	{
		cout << "End";
	}
	cout << endl << endl;
}
int GetN(string FName)
{
	ifstream fin(FName);
	if (!fin.is_open())
	{
		cout << "File Open Error!\n";
		return 0;
	}
	int a;
	int count = 0;
	char b;
	while (fin >> a)
	{
		count++;
		fin.get(b);
		if (b == '\n' || b == '\t')
		{
			break;
		}
	}
	fin.close();
	return count;
}
void ReadMaze(string FName,vector<vector<int>> &Maze)
{
	ifstream fin(FName);
	if (!fin.is_open())
	{
		cout << "File Open Error!\n";
		return;
	}
	// Rows and Columns Read
	int X = GetN(FName);
	if (X != 0)
	{
		// Memory Allocation
		Maze.resize(X);
		for (int i = 0; i < X; i++)
		{
			Maze[i].resize(X);
		}

		// Reading from file
		for (int i = 0; i < Maze.size(); i++)
		{
			for (int j = 0; j < Maze[i].size(); j++)
			{
				fin >> Maze[i][j];
			}
		}
	}
	fin.close();
}

int main()
{
	// Maze Read From File
	vector<vector<int>> Maze;
	ReadMaze("Data.txt",Maze);
	PrintMaze(Maze);

	// Path Saver
	stack<Position> Path;

	// Create Temporary Maze for changes 
	// Setting [0][0] to 2 as source, [N-1][N-1] to 3 as Destin
	vector<vector<int>> TempMaze = Maze;
	TempMaze[0][0] = 2;
	TempMaze[Maze.size() - 1][Maze.size() - 1] = 3;

	// Source Teller
	Position Source;
	Source.r = 0;
	Source.c = 0;

	// Searching Path From Maze
	if (MazeSearcher(TempMaze, Path, Source))
	{
		stack<Position> TempPath;
		TempPath = Path;
		UpdateMaze(TempMaze, Path);
		cout << "Path Found in Maze :" << endl;
		PrintMaze(TempMaze);
		PrintPath(TempPath);
	}
	else
	{
		cout << "Path not found!\n";
	}
	return 0;
}