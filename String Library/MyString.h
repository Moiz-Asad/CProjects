#pragma once
class MyString
{
private:
	char *ptr;																   // Char pointer
	int size;																  // array size
	int stringlenght(const char *p);										 // string length finder
	void copy(char *,const char*p);											// Deep copy function
	int integerlength(int );											   // No of elements count in a integer number
public:
	void setter(int siz, char *p);										 // Set values of private attributes
	MyString();															// Default constructor
	MyString(char* s);												   // constructor with char pointer as input
	MyString(int);													  // constructor convrt int to character array
	MyString(const MyString *m);									 // copy constructor
	MyString* Split(char ,int *);									// split sentece in separate words
	MyString* Tokenize(char* ds, int *count);					   //
	bool Equal(const MyString *);								  // comparing two strings 
	int Cmp(const MyString )const;								 // comparing two strings (three possible returns -1,0,1)
	void SetString(const char* p);								// set value of string to private attributes
	char * Trim();											   // Remove spaces from left and reight
	int * SubStringSearch(const char *substr,int &count)const;// Search substring in string
	MyString  Concat(const MyString &s2);					 // Merge two strings
	MyString  Concat(char c);								// Add single character in a string
	char index(const int i)const;						  // return char at specific index
	int find_first(const char ch)const;					 // return first index of char found
	int find_last(const char ch);						// return last index char found
	int* find_all(char ch, int &c);					   //
	void remove_first(char ch);						  //
	void remove_last(char ch);						 //
	void remove_all(char ch);						//
	void remove_at(int i);						   //
	void insert_at(int i, char ch);				  //
	void insert_at(int i, MyString sub);		 // 
	void clear();								//
	int length();							   //
	int Atoi();								  //
	MyString Itoa(int num);					 //
	void Print();							// Print char arrays
	~MyString();
};

