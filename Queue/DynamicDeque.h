#pragma once
template<class T>
class DynamicDeque {
private:
	T *Vs;
	int size;
	int front;
	int rear;
	void DynamicGrow();
	void copy(T *s);
public:
	DynamicDeque();
	DynamicDeque(int s);
	void  insert_front(int value);
	void  insert_rear(int value);
	void  delete_front();
	void  delete_rear();
	bool  isFull();
	bool  isEmpty();
	int  get_Front();
	int  get_Rear();
	~DynamicDeque();

};
template<typename T>
DynamicDeque<T>::DynamicDeque()
{
	front = -1;
	rear = -1;
}
template<typename T>
DynamicDeque<T>::DynamicDeque(int s)
{
	size = s;
	Vs = new T[size];
	front = -1;
	rear = 0;
}
template<typename T>
void DynamicDeque<T>::insert_front(int value)
{
	if (isFull())
	{
		DynamicGrow();
	}
	if (front == 0)
	{
		front = size - 1;
	}
	else
	if (front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		front = front - 1;
	}
	Vs[front] = value;
}
template<typename T>
void DynamicDeque<T>::insert_rear(int value)
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
	}
	Vs[rear] = value;
}
template<typename T>
void DynamicDeque<T>::delete_front()
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
	if (front == size - 1)
	{
		front = 0;
	}
	else
	{
		front = front + 1;
	}
}
template<typename T>
void DynamicDeque<T>::copy(T *s)
{
	int i = 0;
	while (i < rear)
	{
		s[i] = Vs[i];
	}
}
template<typename T>
void DynamicDeque<T>::DynamicGrow()
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
	if (rear == size-1 && front == 0)
	{
		copy(Temp);
	}
	delete[]Vs;
	Vs = Temp;
	Temp = nullptr;
	size *= 2;
}
template<typename T>
void DynamicDeque<T>::delete_rear()
{
	if (isEmpty())
	{
		cout << "DeQue Underflows!" << endl;
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
	}
}
template<typename T>
bool DynamicDeque<T>::isFull()
{
	if ((front == 0 && rear == size - 1) || front == rear + 1)
	{
		return true;
	}
	return false;
}
template<typename T>
bool DynamicDeque<T>::isEmpty()
{
	if (front == -1)
	{
		return true;
	}
	return false;
}
template<typename T>
int DynamicDeque<T>::get_Front()
{
	if (isEmpty())
	{
		cout << " DeQue Underflows!" << endl;
		return -1;
	}
	else
		return Vs[front];
}
template<typename T>
int DynamicDeque<T>::get_Rear()
{
	if (isEmpty() || rear < 0)
	{
		cout << " DeQue Underflows!" << endl;
		return -1;
	}
	else
		return Vs[rear];
}
template<typename T>
DynamicDeque<T>::~DynamicDeque()
{

}

