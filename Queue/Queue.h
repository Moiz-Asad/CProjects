#pragma once
template<class T>
class Queue {
private:
	T *Vs;
	int size;
	int front;
	int rear;

public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	Queue(int s)
	{
		Vs = new T[s];
		size = s;
		front = s;
		rear = 0;
	}
	T Peek()
	{
		if (!IsEmpty())
		{
			return Vs[front];
		}
	}
	bool IsFull()
	{
		if (front == 0 && rear == size - 1)
		{
			return true;
		}
		return false;
	}

	bool IsEmpty()
	{
		if (front == -1)
		{
			return true;
		}
		else
			return false;
	}

	void EnQueue(T value, bool En = true)
	{
		if (IsFull())
		{
			En = false;
		}
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			rear++;
			Vs[rear] = value;
		}
	}
	T DeQueue(bool De = true)
	{
		T value;
		if (IsEmpty())
		{
			De = false;
			}
		else
		{
			value = Vs[front];
			if (front >= rear)
			{
				front = -1;
				rear = -1;
			}
			else
			{
				front++;
			}
			return(value);
		}
	}
};