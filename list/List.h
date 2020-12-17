#pragma once
#include <iostream>
using namespace std;

template<class T>
class List
{
private:
	T* data;
	int* links;

	int head;
	int size;
	int count;
	
	int find_empty();

public:
	List(int _s = 1);
	List(List<T>& _l);
	~List();

	bool IsEmpty() { return (head == -1); }
	bool IsFull() { return (count == size); }
	int GetSize() { return size; }
	int GetCount() { return count; }

	void clear();

	T& operator[](const int index);

	void push_back(T data);
	T pop_back();
	void push_front(T data);
	T pop_front();

	template <class O>
	friend ostream& operator << (ostream& ostr, List<O>& _l);
};

template<class T>
ostream& operator<<(ostream& ostr, List<T>& _l)
{
	for (int i = 0; i < _l.GetCount(); i++)
		ostr << _l[i] << " ";
	return ostr;
}

template<class T>
inline int List<T>::find_empty()
{
	int p = 0;
	while (links[p] != -2)
		p++;
	return p;
}

template<class T>
inline List<T>::List(int _s)
{
	size = _s;
	count = 0;

	this->links = new int[_s];
	this->data = new T[_s];

	for (int i = 0; i < _s; i++)
	{
		this->links[i] = -2;
		this->data[i] = 0;
	}

	head = -1;
}

template<class T>
inline List<T>::List(List<T>& _l)
{
	size = _l.size;
	count = _l.count;

	this->links = new int[size];
	this->data = new int[size];

	for (int i = 0; i < size; i++)
	{
		this->links[i] = _l.links[i];
		this->data[i] = _l.data[i];
	}

	head = _l.head;
}

template<class T>
inline List<T>::~List()
{
	clear();
	size = 0;
	delete[] links;
	delete[] data;
}

template<class T>
inline void List<T>::clear()
{
	for (int i = 0; i < count; i++)
	{
		this->links[i] = -2;
		this->data[i] = 0;
	}

	head = -1;
	count = 0;
}

template<class T>
inline T& List<T>::operator[](const int index)
{
	if (index < 0 || index >= count)
		throw length_error("incorrect index");

	int counter = 0;
	int temp = head;

	while (temp != -1)
	{
		if (counter == index)
			return this->data[temp];
		temp = this->links[temp];
		counter++;
	}
}

template<class T>
inline void List<T>::push_back(T data)
{
	if (IsFull())
		throw logic_error("list is full");

	if (IsEmpty())
	{
		head = 0;
		this->data[0] = data;
		this->links[0] = -1;
	}
	else
	{
		int last = head;

		for (int i = 0; i < count; i++)
			if (this->links[last] != -1)
				last = this->links[last];
			else
				break;

		int temp = 0;
		for (int i = 0; i < size; i++)
			if (this->links[i] == -2)
			{
				temp = i;
				break;
			}

		this->data[temp] = data;
		this->links[last] = temp;
		this->links[temp] = -1;
	};

	count++;
}

template<class T>
inline T List<T>::pop_back()
{
	if (IsEmpty())
		throw logic_error("list is empty");

	T result = 0;
	
	if (this->links[head] == -1)
	{
		result = data[head];
		this->links[head] = -2;
		head = -1;
	}
	else
	{
		int last = head;
		int prev = 0;

		for (int i = 0; i < count; i++)
			if (this->links[last] != -1)
			{
				prev = last;
				last = this->links[last];
			}
			else
			{
				result = data[last];
				this->links[last] = -2;
				this->links[prev] = -1;
			}
	}
	count--;
	return result;
}

template<class T>
inline T List<T>::pop_front()
{
	if (IsEmpty())
		throw logic_error("list is empty");

	T result = 0;

	if (this->links[head] == -1)
	{
		result = data[head];
		this->links[head] = -2;
		head = -1;
	}
	else
	{
		result = data[head];
		int first = this->links[head];
		this->links[head] = -2;
		head = first;
	}
	count--;
	return result;
}

template<class T>
inline void List<T>::push_front(T data)
{
	if (IsFull())
		throw logic_error("list is full");

	if (IsEmpty())
	{
		head = 0;
		this->data[0] = data;
		this->links[0] = -1;
	}
	else
	{
		int temp = find_empty();

		this->data[temp] = data;
		this->links[temp] = head;
		head = temp;
	}
	count++;
}
