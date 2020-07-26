#include<iostream>
#include"MyString.h"
using namespace std;
int main()
{
	MyString d,b;
	d.setter(7,"abcdef");
	b.setter(4, "ghi");
	d.Print();
	b.Print();
	int res=d.find_first('o');
	if (res == 97)
	{
		cout << "Not found!"<<endl;
	}
	else
	{
		cout << res << endl;
	}
	return 0;
}