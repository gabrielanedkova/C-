/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gabriela Nedkova
* @idnumber 45097
* @task 2
* @compiler VC
*
*/
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>

using namespace std;

template <class T>
class Queue
{
	class Node
	{
	public:
		T data;
		Node* next;
	};
public:
	Queue();
	Queue(Queue const & rhs);
	Queue& operator=(Queue<T> const& rhs);
	~Queue();
	void handleRequest(int& currenTime, int& currentFloor, char& currentDir);
	void enqueue(T data);
	void dequeue();
	void dequeue(int num);
	void dequeue(Node& num);
	T& top(){ return head->data; };
	void copyData(Queue<T> const& rhs);
	bool isEmpty();

private:
	Node* head;
	Node* tail;
};

template <class T>
Queue<T>::Queue()
{
	head = nullptr;
	tail = nullptr;
}

template <class T>
Queue<T>::Queue(const Queue<T> &rhs)

{
	copyData(rhs);
}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
	if (this != &rhs)
	{
		copyData(rhs);
	}
	return *this;
}

template <class T>
Queue<T>::~Queue()
{
	Node* temp;
	if (!isEmpty()){
		while (head->next != nullptr)
		{
			temp = head;
			head = head->next;
			delete[] temp;
		}
	}
	delete[] head;
}

template <class T>
void Queue<T>::copyData(Queue<T> const & rhs)
{
	if (rhs.head == nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = rhs.head;
		Node* temp;
		temp = rhs.head;
		head = nullptr;
		while (temp != nullptr)
		{
			enqueue(temp->data);
			temp = temp->next;
		}
		tail = rhs.tail;
	}
}

template <class T>
bool Queue<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}

template <class T>
void Queue<T>::enqueue(T data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = nullptr;
	if (isEmpty())
	{
		head = tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;

}
template <class T>
void Queue<T>::dequeue(Node& num)
{
	if (!isEmpty())
	{
		Node* temp = new Node;
		temp = head;
		while (temp !nullptr)
		{
			if (temp == num)
			{
				Node* tmp = temp->next;
				if (temp->next != nullptr)
					temp->next = tmp->next;
				else {
					head->next = nullptr;
					head = tail;
				}
				delete[] tmp;
			}
			temp = temp->next;
		}
	}
}

template <class T>
void Queue<T>::dequeue(int num)
{
	if (!isEmpty())
	{
		if (num == 1)
			dequeue();
		else
		{
			Node* temp = new Node;
			temp = head;
			for (int i = 1; i < num; i++)
			{
				if (i == num - 1)
				{
					Node* tmp = temp->next;
					if (temp->next != nullptr)
						temp->next = tmp->next;
					else {
						head->next = nullptr;
						head = tail;
					}
					delete[] tmp;
				}
				temp = temp->next;
			}
		}
	}
}

template <class T>
void Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		Node* temp = new Node;
		temp = head;
		head = head->next;
		delete[] temp;
	}
}


template <class T>
void Queue<T>::handleRequest(int& currentTime, int& currentFloor, char& currentDir)
{
	if (currentTime == -1)
		currentTime = head->data.time;
	Request priorityRequest = top();
	Node* tmp = new Node;
	tmp = head->next;
	if (currentFloor < priorityRequest.floor)
	{
		int findIndex = -1;
		int counter = 1;
		int t = 0;
		while (tmp != nullptr)
		{
			counter++;

			if (tmp->data.floor < priorityRequest.floor && tmp->data.floor > currentFloor)
			{
				t = (5 * (tmp->data.floor - currentFloor)) + currentTime;
				if (tmp->data.time <= t)
				{
					priorityRequest = tmp->data;
					findIndex = counter;
				}
			}
			tmp = tmp->next;
		}

		if (findIndex != -1)
		{
			currentTime += (5 * (priorityRequest.floor - currentFloor));
			currentFloor = priorityRequest.floor;
			cout << currentTime << " " << currentFloor << " " << "up" << endl;
			currentDir = 'u';
			dequeue(findIndex);
			delete[] tmp;
			return;
		}
	}
	else if (currentFloor > priorityRequest.floor)
	{
		int t = 0;
		int findIndex = -1;
		int counter = 1;
		while (tmp != nullptr)
		{
			counter++;

			if (tmp->data.floor > priorityRequest.floor && tmp->data.floor < currentFloor)
			{
				t = (5 * (currentFloor - tmp->data.floor)) + currentTime;
				if (tmp->data.time <= t)
				{
					priorityRequest = tmp->data;
					findIndex = counter;
				}
			}
			tmp = tmp->next;
		}

		if (findIndex != -1)
		{
			currentTime += (5 * (currentFloor - priorityRequest.floor));
			currentFloor = priorityRequest.floor;
			currentDir = 'd';
			cout << currentTime << " " << currentFloor << " " << " down" << endl;
			dequeue(findIndex);
			delete[] tmp;
			return;
		}
	}

	int  mod = (5 * (priorityRequest.floor - currentFloor));
	if (mod > 0)
		currentTime += mod;
	else if (mod == 0 && priorityRequest.time > currentTime)
	{
		currentTime = priorityRequest.time;
	}
	else
		currentTime -= mod;
	dequeue(1);
	cout << currentTime << " " << priorityRequest.floor;
	if (priorityRequest.floor > currentFloor)
		cout << " up" << endl;
	else if (priorityRequest.floor == currentFloor)
	{
		if (currentDir == 'u')
			cout << " up" << endl;
		else cout << " down" << endl;

	}
	else cout << " down" << endl;
	currentFloor = priorityRequest.floor;
	tmp = head;
	int counter = 1;
	while (tmp != nullptr)
	{
		if (tmp->data.floor == currentFloor && tmp->data.time <= currentTime)
		{
			tmp = tmp->next;
			dequeue(counter);
			continue;
		}
		tmp = tmp->next;
		counter++;
	}
	delete[] tmp;
}
#endif

