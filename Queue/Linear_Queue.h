#pragma once

//=======> ADT
template<class T>
class Linear_Queue 
{
private:
	T *Vs;
	int size;
	int front;
	int rear;
	void DynamicGrow();
	void copy(T *s);
public:
	Linear_Queue();
	void  Enqueue(int value);
	void  Dequeue();
	bool  isFull();
	void Display();
	bool  isEmpty();
	~Linear_Queue();

};
template<typename T>
Linear_Queue<T>::Linear_Queue()
{
	size = 1;
	front = 0;
	rear = 0;
	Vs = new T[size];
}

template<typename T>
void Linear_Queue<T>::Enqueue(int value)
{
	if (isFull())
	{
		DynamicGrow();
	}
	Vs[rear] = value;
	rear++;
}
template<typename T>
void Linear_Queue<T>::Display()
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << Vs[i] << " ";
	}
	cout << endl;
}
template<typename T>
void Linear_Queue<T>::copy(T *s)
{
	int i = 0;
	while (i < rear)
	{
		s[i] = Vs[i];
		i++;
	}
}
template<typename T>
void Linear_Queue<T>::DynamicGrow()
{
	T *Temp;
	Temp = new T[size * 2];
	if (front + 1 == rear)
	{
		int Tsize = (size * 2) - 1;
		copy(Temp);
		for (int j = size - 1; j >= front; j--)
		{
			Temp[Tsize] = Vs[j];
			Tsize--;
		}
		front = Tsize + 1;
	}
	else
	if (rear == size - 1 && front == 0)
	{
		copy(Temp);
	}
	delete[]Vs;
	Vs = Temp;
	Temp = nullptr;
	size *= 2;
}
template<typename T>
void Linear_Queue<T>::Dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is Empty!" << endl;
		return;
	}
	rear--;
}
template<typename T>
bool Linear_Queue<T>::isFull()
{
	if (rear == size)
	{
		return true;
	}
	return false;
}
template<typename T>
bool Linear_Queue<T>::isEmpty()
{
	if (size == 1)
	{
		return true;
	}
	return false;
}
template<typename T>
Linear_Queue<T>::~Linear_Queue()
{

}

