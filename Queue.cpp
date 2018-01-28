#include"Queue.h"

Queue::Queue(Node* root)
{
	add(root);
}

Queue::~Queue()
{

}
void Queue::add(Node* root)
{
	if (!root)
		return;
	enqueue(root);
	add(root->left);
	add(root->right);
}
void Queue::enqueue(Node* node)
{
	if (!node)
		return;
	if (!first)
	{
		first = new QueueNode(node);
		last = first;
	}
	else
	{
		last->next = new QueueNode(node);
		last = last->next;
	}
}

Node* Queue::dequeue()
{
	QueueNode* temp = first;
	Node* data = first->data;
	if (!first->next)
		first = last = nullptr;
	else first = first->next;
	delete temp;
	return data;
}

