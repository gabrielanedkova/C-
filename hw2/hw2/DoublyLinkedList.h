#include "Node.h"

class DoublyLinkedList
{
public:
	DoublyLinkedList();
	~DoublyLinkedList(){};
	void push(const ExamData& examData);
	void print()const;
	void printReversed()const;
	bool empty()const;
private:
	Node* first;
	Node* last;
};