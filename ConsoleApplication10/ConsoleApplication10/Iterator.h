#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include "Node.h"
class Iterator
{
	friend class DoublyLinkedList;
public:
	Iterator();
	Iterator(const Iterator& rhs) = default;
	Iterator& operator=(const Iterator& rhs) = default;
	Iterator(Node* rhs);
	Iterator& operator++();
	Iterator& operator--();
	Iterator operator++(int);
	Iterator operator--(int);
	Tab& operator* ();
	Tab* operator->();
	const Tab& operator* () const;
	const Tab* operator-> () const;
	friend bool operator==(const Iterator& it1, const Iterator& it2);
	friend bool operator!=(const Iterator& it1, const Iterator& it2);

private:
	Node* it;

	Node* getNode();
};

#endif