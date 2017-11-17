#ifndef _NODE_H_
#define _NODE_H_

#include "Tab.h"

struct Node
{
	Node();
	Node(Tab data);
	Node(Node& rhs);
	Node& operator=(const Node& rhs);
	~Node(){};

	void copy(const Node& rhs);

	Tab data;
	Node* previous;
	Node* next;

};

#endif