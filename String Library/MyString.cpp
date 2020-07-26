#include "MyString.h"
#include<iostream>
using namespace std;

MyString::MyString()
{
	ptr = nullptr;
	size = 0;
}
MyString::MyString(char* s)
{
	ptr = s;
}
void MyString::copy(char *c,const char*p)
{
	int i;
	for (i = 0; p[i] != '\0'; i++)
	{
		c[i] = p[i];
	}
	c[i] = '\0';
}
void MyString::setter(int siz,char *p)
{
	this->size = siz;
	this->ptr = new char[this->size];
	this->ptr = p;
}
MyString::MyString(int s)
{
	this->size = integerlength(s+1);
	this->ptr = new char[this->size];
	int i = 0;
	int rem = 0;
	while (i < this->size)
	{
		rem = s % 10;
		s = s / 10;
		ptr[i] = rem;

		i++;
	}
}
int MyString::integerlength(int c)
{
	int i=0, rem = 0;
	while (1)
	{
		rem = c % 10;
		c = c / 10;
		if (c == rem)
		{
			break;
		}
		i++;
	}
	return i;
}
MyString:: MyString(const MyString *m)
{
	this->size = m->size;
	this->ptr = new char[this->size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = m->ptr[i];
	}
	ptr[this->size] = '\0';
}
char ToUpper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c + 32;
	}
	else
		return c;
}
int MyString::Cmp(const MyString p)const
{
	int l1 = this->size;
	int l2 = p.size;
	for (int i = 0; i < this->size; i++)
	{
		if (ToUpper(this->ptr[i]) > ToUpper(p.ptr[i]))
		{
			return 1;
		}
		else
		if (ToUpper(this->ptr[i]) < ToUpper(p.ptr[i]))
		{
			return -1;
		}
	}
	return 0;
}

int MyString::stringlenght(const char *p)
{
	int i;
	for (i = 0; p[i] != '\0'; i++);
	return i;
}
void MyString::Print()
{
	if (this->ptr)
		cout << ptr << endl;
	else
		cout << "Empty string!!!"<<endl;
}
MyString  MyString::Concat(const MyString &s2)
{
	MyString m;
	m.size = this->size + s2.size;
	m.ptr = new char[m.size];
	int s = 0;
	for (int i = 0; this->ptr[i] != '\0'; i++)
	{
		m.ptr[s] = this->ptr[i];
		s++;
	}
	for (int i = 0; s2.ptr[i] != '\0'; i++)
	{
		m.ptr[s] = s2.ptr[i];
		s++;
	}
	return m;
}
MyString  MyString::Concat(char c)
{
	MyString m;
	m.size = this->size + 1;
	m.ptr = new char[m.size];
	int s = 0;
	for (int i = 0; this->ptr[i] != '\0'; i++)
	{
		m.ptr[s] = this->ptr[i];
			s++;
	}
	m.ptr[s] = c;
	s++;
	m.ptr[s] = '\0';
	return m;
}
bool MyString::Equal(const MyString *m)
{
	int i;
	if (stringlenght(m->ptr) != stringlenght(this->ptr))
	{
		return false;
	}
	for (i = 0; i < this->size; i++)
	{
		if (this->ptr[i] == m->ptr[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
void MyString::SetString(const char* p)
{
	this->size = stringlenght(p)+1;
	this->ptr = new char[this->size];
	copy(this->ptr,p);
}
char * MyString::Trim()
{
	char *p;
	p = new char[this->size];
	int i = 0, j = 0;

	while (this->ptr[i] != '\0')
	{
		if (this->ptr[i] != ' ')
		{
			p[j] = this->ptr[i];
		}
		else
		{
			j--;
		}

		i++; 
		j++;
	}
	p[j] = '\0';
	return p;
}
int * MyString::SubStringSearch(const char *substr, int &count)const
{
	int i,j,temp=0;
	for (i = 0; this->ptr[i] != '\0'; i++)
	{
		j = 0;
		if (this->ptr[i] == substr[j])
		{
			temp = i + 1;
			while (this->ptr[i] == substr[j])
			{
				i++;
				j++;
			}

			if (substr[j] == '\0')
			{
				count++;
				exit(0);
			}
			else
			{
				i = temp;
				temp = 0;
			}
		}
	}
	if (temp == 0)
	{
		cout << "The substring is not found" << endl;
	}
	int *arr = new int[count+1];
	int c=0;
	for (i = 0; this->ptr[i] != '\0'; i++)
	{
		j = 0;
		if (this->ptr[i] == substr[j])
		{
			temp = i + 1;
			while (this->ptr[i] == substr[j])
			{
				i++;
				j++;
			}

			if (substr[j] == '\0')
			{
				arr[c] = temp;
				c++;
				exit(0);
			}
			else
			{
				i = temp;
				temp = 0;
			}
		}
	}
	return arr;
}
MyString* MyString::Split(char d, int *arr)
{
	int c = 0;
	for (int i = 0; this->ptr[i] != '\0'; i++)
	{
		if (this->ptr[i] == ' ' || this->ptr[i] == '\n' || this->ptr[i] == '.')
		{
			c++;
		}
	}
	arr = new int[c];
	MyString *f;
	f = new MyString[c];
	int t = 0,a=0;
	for (int i = 0; this->ptr[i] != '\0'; i++)
	{
		t++;
		if (this->ptr[i] == ' ' || this->ptr[i] == '\n' || this->ptr[i] == '.')
		{
			arr[a] = t;
			t = 0;
			a++;
		}
	}
	for (int i = 0; i < a; i++)
	{
		f[i].ptr = new char[arr[i]];
	}
	int temp = 0,g=0;
	for (int i = 0; this->ptr[i] != '\0'; i++)
	{
		if (this->ptr[i] == ' ' || this->ptr[i] == '\n' || this->ptr[i] == '.')
		{
			for (int k = 0; this->ptr[i] != ' '; k++,g++)
			{
				f[i].ptr[g] = this->ptr[k];
			}
		}
	}
	return f;
}
char MyString::index(const int i)const
{
	return this->ptr[i];
}
int MyString::find_first(const char ch)const
{
	for (int i = 0; this->ptr[i] != '\0'; i++)
	{
		if (this->ptr[i] == ch)
		{
			return i+1;
		}
	}
	return 'a';
}
int MyString::find_last(const char ch)
{
	for (int i = stringlenght(this->ptr); i>=0; i--)
	{
		if (this->ptr[i] == ch)
		{
			return i + 1;
		}
	}
	return '~';
}
MyString::~MyString()
{
}