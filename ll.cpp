#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
	Node* next;
	int data;
	Node(int data) :data(data), next(nullptr)
	{
	}
};

class LL
{
	Node* first;
	Node* last;

public:
	Node* getFirst()const{
		return first;
	}

	Node* getLast()const{
		return last;
	}
	void add(int data)
	{
		if (!first)
		{
			first = new Node(data);
			last = first;
			return;
		}
		Node* newNode = new Node(data);
		last->next = newNode;
		last = last->next;
	}

	LL() :first(nullptr), last(nullptr){};
	friend ostream& operator<<(ostream& o, LL list)
	{
		Node* curr = list.first;
		while (curr != list.last)
		{
			o << curr->data << "->";
			curr = curr->next;
		}
		o << list.last->data << endl;
		return o;
	}
};

LL longestSubList(const LL& l)
{
	Node* curr = l.getFirst();
	Node* last = l.getLast();
	int maxIndex = 0;
	int maxLen = 1;
	int curIncLen = 1;
	int curDecStart = 0;
	int curDecLen = 1;
	int curIncStart = 0;
	int curIndex = 0;
	while (curr != last)
	{
		if (curr->data >= curr->next->data)
		{
			++curDecLen;
		}
		else
		{
			if (curDecLen > maxLen)
			{
				maxLen = curDecLen;
				maxIndex = curDecStart;
			}
			curDecStart = curIndex + 1;
			curDecLen = 1;
		}

		if (curr->data <= curr->next->data)
		{
			++curIncLen;
		}
		else
		{
			if (curIncLen > maxLen)
			{
				maxLen = curIncLen;
				maxIndex = curIncStart;
			}
			curIncStart = curIndex + 1;
			curIncLen = 1;
		}
		++curIndex;
		curr = curr->next;
	}
	if (curIncLen > maxLen)
	{
		maxLen = curIncLen;
		maxIndex = curIncStart;
	}
	if (curDecLen > maxLen)
	{
		maxLen = curDecLen;
		maxIndex = curDecStart;
	}
	LL l2;
	int index = 0;
	curr = l.getFirst();
	while (maxLen != 0)
	{
		if (index >= maxIndex)
		{
			l2.add(curr->data);
			--maxLen;
		}
		curr = curr->next;
		++index;
	}
	return l2;
}
int main()
{
	LL l;
	l.add(2);
	l.add(3);
	l.add(2);
	l.add(1);
	l.add(0);
	l.add(3);
	l.add(2);
	LL* l2 = &longestSubList(l);
	cout << *l2;
	system("pause");
}