#pragma once
template<class T>
class DeQueue {
private:
	T *Vs;
	int size;
	int front;
	int rear;
public:
	DeQueue();
	DeQueue(int s);
	void  insert_front(int value);
	void  insert_rear(int value);
	void  delete_front();
	void  delete_rear();
	bool  isFull();
	bool  isEmpty();
	int  get_Front();
	int  get_Rear();
	~DeQueue();

};
template<typename T>
DeQueue<T>::DeQueue(int s)
{
	front = -1;
	rear = -1;
}
template<typename T>
DeQueue<T>::DeQueue(int s)
{
	size = s;
	Vs = new T[size];
	front = -1;
	rear = 0;
}
template<typename T>
void DeQueue<T>::insert_front(int value)
{
	if (isFull())
	{
		cout << "DeQue Completely Filled!" << endl;
		return;
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
void DeQueue<T>::insert_rear(int value)
{
	if (isFull())
	{
		cout << "DeQue Completely Filled!" << endl;
		return;
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
void DeQueue<T>::delete_front()
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
void DeQueue<T>::delete_rear()
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
bool DeQueue<T>::isFull()
{
	if ((front == 0 && rear == size - 1) || front == rear + 1)
	{
		return true;
	}
	return false;
}
template<typename T>
bool DeQueue<T>::isEmpty()
{
	if (front == -1)
	{
		return true;
	}
	return false;
}
template<typename T>
int DeQueue<T>::get_Front()
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
int DeQueue<T>::get_Rear()
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
DeQueue<T>::~DeQueue()
{

}

