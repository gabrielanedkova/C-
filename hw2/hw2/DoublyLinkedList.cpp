#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : first(nullptr), last(nullptr)
{
}

void DoublyLinkedList::push(const ExamData& examData)
{
	if (!first)
	{
		Node* node = new Node(examData);
		first = last = node;
	}
	else
	{
		Node* node = new Node(last, examData);
		last->next = node;
		last = node;
	}
}
void DoublyLinkedList::print()const
{
	if (!first)
		return;
	for (Node* n = first; n != last; n = n->next)
	{
		std::cout << n->data;
	}
	std::cout << last->data;

}
void DoublyLinkedList::printReversed()const
{

}

bool DoublyLinkedList::empty()const
{
	return true;
}
