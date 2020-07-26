#pragma once
template<class T>
class Growable_Circular_Queue {
private:
	T *Vs;
	int size;
	int front;
	int rear;
	int Capacity;
	void DynamicGrow();
	void copy(T *s);
public:
	Growable_Circular_Queue();
	Growable_Circular_Queue(int s);
	void  Enqueue(int value);
	void  Dequeue();
	bool  isFull();
	void Display();
	bool  isEmpty();
	int  get_Front();
	int  get_Rear();
	~Growable_Circular_Queue();

};
template<typename T>
Growable_Circular_Queue<T>::Growable_Circular_Queue()
{
	Capacity = 1;
	Vs = new T[Capacity];
	size = 0;
	front = -1;
	rear = -1;
}
template<typename T>
Growable_Circular_Queue<T>::Growable_Circular_Queue(int s)
{
	size = 0;
	Capacity = s;
	Vs = new T[Capacity];
	front = -1;
	rear = 0;
}
template<typename T>
void Growable_Circular_Queue<T>::Display()
{
	for (int i = size-1; i >= 0; i--)
	{
		cout << Vs[i] << " ";
	}
	cout << endl;
}

template<typename T>
void Growable_Circular_Queue<T>::Enqueue(int value)
{
	if (isFull())
	{
		DynamicGrow();
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	if (rear == size - 1)
	{
		rear = 0;
	}
	else
	{
		rear = rear + 1;
		size++;
	}
	Vs[rear] = value;
}
template<typename T>
void Growable_Circular_Queue<T>::copy(T *s)
{
	int i = 0;
	while (i < rear)
	{
		s[i] = Vs[i];
		i++;
	}
}
template<typename T>
void Growable_Circular_Queue<T>::DynamicGrow()
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
void Growable_Circular_Queue<T>::Dequeue()
{
	if (isEmpty())
	{
		cout << "Queue Underflows!" << endl;
		return;
	}
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	if (rear == 0)
	{
		rear = size - 1;
	}
	else
	{
		rear = rear - 1;
		size--;
	}
}
template<typename T>
bool Growable_Circular_Queue<T>::isFull()
{
	if ((front == 0 && rear == size - 1) || front == rear + 1)
	{
		return true;
	}
	return false;
}
template<typename T>
bool Growable_Circular_Queue<T>::isEmpty()
{
	if (front == -1)
	{
		return true;
	}
	return false;
}
template<typename T>
int Growable_Circular_Queue<T>::get_Front()
{
	if (isEmpty())
	{
		cout << " Queue Underflows!" << endl;
		return -1;
	}
	else
		return Vs[front];
}
template<typename T>
int Growable_Circular_Queue<T>::get_Rear()
{
	if (isEmpty() || rear < 0)
	{
		cout << " Queue Underflows!" << endl;
		return -1;
	}
	else
		return Vs[rear];
}

template<typename T>
Growable_Circular_Queue<T>::~Growable_Circular_Queue()
{

}