#include "Iterator.h"
#include "Node.h"

Iterator::Iterator() : it(nullptr)
{
	 
}

Iterator::Iterator(Node* node) : it(node)
{

}

Iterator& Iterator:: operator++()
{
	it = it->next;
	return *this;
}
Iterator& Iterator::operator--()
{
	it = it->previous;
	return *this;
}
Iterator Iterator::operator++(int)
{
	Iterator temp(*this);
	++(*this);
	return temp;
}
Iterator Iterator::operator--(int)
{
	Iterator temp(*this);
	--(*this);
	return temp;

}

bool operator==(const Iterator& it1, const Iterator& it2)
{
	return (it1.it == it2.it);
}

bool operator!=(const Iterator& it1, const Iterator& it2)
{
	return !(it1 == it2);
}

Node* Iterator::getNode()
{
	return it;
}

Tab& Iterator::operator* ()
{
	return it->data;
}

Tab* Iterator::operator-> ()
{
	return &(operator* ());
}

const Tab& Iterator::operator* ()const
{
	return it->data;
}

const Tab* Iterator::operator-> ()const
{
	return &(operator* ());
}