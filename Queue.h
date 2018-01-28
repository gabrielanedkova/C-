#include "Tree.h"

class Queue
{
private:
	struct QueueNode
	{
		QueueNode* next;
		Node* data;
		QueueNode(Node* data) :data(data), next(nullptr){};
	};

	QueueNode* first;
	QueueNode* last;
	void add(Node* root);
public:
	Queue(Node* root);
	Queue(){};
	~Queue();
	void enqueue(Node* node);
	Node* dequeue();
	bool isEmpty(){ return first == nullptr; };
}; 