#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_
#include "Tab.h"
#include "Iterator.h"

struct Node;
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& rhs) = default;
	DoublyLinkedList& operator=(const DoublyLinkedList& rhs) = default;
	~DoublyLinkedList();
	int getSize()const;
	bool empty()const;
	void push_front(const Tab& value);
	void pop_front();
	void push_back(const Tab& value);
	void pop_back();
	Tab& front()const;
	Tab& back()const;
	void print()const;
	void insertAfter(Iterator& node, const char* URL);
	void remove(Iterator& current);
	Iterator begin();
	Iterator end();
	const Iterator begin()const;
	const Iterator end()const;


private:
	void init(const Tab& value);
	void copy();

	Node* first;
	Node* last;
	int size;
};

#endif