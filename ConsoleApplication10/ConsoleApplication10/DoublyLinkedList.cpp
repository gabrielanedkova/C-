#include "DoublyLinkedList.h"
#include "Iterator.h"
#include "Node.h"

DoublyLinkedList::DoublyLinkedList() : first(nullptr), last(nullptr), size(0)
{

}

DoublyLinkedList::~DoublyLinkedList()
{
	while (!empty()) pop_front();
}

int DoublyLinkedList::getSize()const
{
	return size;
}
bool DoublyLinkedList::empty()const
{
	return size == 0;
}

void DoublyLinkedList::push_front(const Tab& value)
{
	if (first == nullptr)
	{
		init(value);
	}
	else
	{
		Node* node = new Node;
		node->data = value;
		node->next = first;
		node->previous = nullptr;
		first->previous = node;
		first = node;
	}
	size++;
}

void DoublyLinkedList::pop_front()
{
	if (!empty())
	{
		Node* temp = first;
		first = first->next;
		if (first == nullptr)
			last = nullptr;
		else 
			first->previous = nullptr;
		--size;
		delete temp;
	}
}

void DoublyLinkedList::push_back(const Tab& value)
{
	if (last == nullptr)
	{
			init(value);
	}
	else
	{
		Node* node = new Node;
		node->data = value;
		node->next = nullptr;
		node->previous = last;
		last->next = node;
		last = node;
	}
	size++;
}

void DoublyLinkedList::pop_back()
{
	if (!empty())
	{
		Node* temp = last;
		last = last->previous;
		if (last == nullptr)
			first = nullptr;
		else last->next = nullptr;
		--size;
		delete temp;
	}
}

Tab& DoublyLinkedList::front()const
{
		return first->data;
}

Tab& DoublyLinkedList::back()const
{
		return last->data;
}

void DoublyLinkedList::init(const Tab& value)
{
	first = new Node;
	first->data = value;
	first->previous = first->next = nullptr;
	last = first;
}

void DoublyLinkedList::print()const
{
	Node* temp;
	temp = first;
	for (int i = 0; i < size;i++)
	{
		std::cout << temp->data;
		temp = temp->next;
	}
}

Iterator DoublyLinkedList::begin()
{
	return Iterator(first);
}

Iterator DoublyLinkedList::end()
{
	return Iterator(last);
}

const Iterator DoublyLinkedList::begin()const
{
	return Iterator(first);
}

const Iterator DoublyLinkedList::end()const
{
	return Iterator(last);
}

void DoublyLinkedList::insertAfter(Iterator& it, const char* URL)
{
	if (it == last)
	{
		push_back(Tab(URL));
	}
	else{
		Node* previous = it.getNode();
		Node* next = new Node;
		next->data = URL;
		next->next = previous->next;
		next->previous = previous;
		previous->next = next;

		++size;
	}
}

void DoublyLinkedList::remove(Iterator& current)
{
	if (size == 1)
	{
		current.getNode()->data.go("about:bank");
		return;
	}

	Node* removed = current.getNode();
	if (current == begin())
	{
		first = removed->next;
		removed->next->previous = nullptr;
	}
	else if (current == end())
	{
		last = removed->previous;
		removed->previous->next = nullptr;
	}
	else {
		removed->previous->next = removed->next;
		removed->next->previous = removed->previous;
	}
	delete removed;
	--size;

}


