#include "Node.h"

Node::Node(Tab data) : data(data), previous(nullptr), next(nullptr)
{
}

Node::Node() : previous(nullptr), next(nullptr)
{
}

Node::Node(Node& rhs)
{
	copy(rhs);
}

Node& Node::operator=(const Node& rhs)
{
	if (&rhs != this)
	{
		copy(rhs);
	}
	return *this;
}

void Node::copy(const Node& rhs)
{
	data = rhs.data;
	previous = rhs.previous;
	next = rhs.next;
}