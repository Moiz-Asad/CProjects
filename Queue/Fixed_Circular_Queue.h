#pragma once
template<class T>
class Fixed_Circular_Queue {
private:
	T *Vs;
	int size;
	int front;
	int rear;
	int Capacity;
public:
	Fixed_Circular_Queue();
	Fixed_Circular_Queue(int s);
	bool  Enqueue(int value);
	bool  Dequeue();
	bool  isFull();
	bool  isEmpty();
	void Display();
	~Fixed_Circular_Queue();

};
template<typename T>
Fixed_Circular_Queue<T>::Fixed_Circular_Queue(int s)
{
	Capacity = s;
	size = 0;
	Vs = new T[Capacity];
	front = -1;
	rear = 0;
}
template<typename T>
void Fixed_Circular_Queue<T>::Display()
{
	for (int i = front; i < size; i++)
	{
		cout << Vs[i] << " ";
	}
}
template<typename T>
bool Fixed_Circular_Queue<T>::Enqueue(int value)
{
	if (isFull())
	{
		return false;
	}
	rear = (rear + 1) % Capacity;
	Vs[rear] = value;
	size++;
	return true;
}
template<typename T>
bool Fixed_Circular_Queue<T>::Dequeue()
{
	if (isEmpty())
	{
		return false;
	}
	front = (front + 1) % Capacity;
	size--;
	if (size == 0)
	{
		front = 0;
		rear = 0;
	}
	return true;
}
template<typename T>
bool Fixed_Circular_Queue<T>::isFull()
{
	if (size == Capacity)
	{
		return true;
	}
	return false;
}
template<typename T>
bool Fixed_Circular_Queue<T>::isEmpty()
{
	if (size == 0 || front == -1)
	{
		return true;
	}
	return false;
}

template<typename T>
Fixed_Circular_Queue<T>::~Fixed_Circular_Queue()
{

}

