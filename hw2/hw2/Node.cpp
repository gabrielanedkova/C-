#include "Node.h"

Node::Node() : prev(nullptr), next(nullptr)
{
}

Node::Node(ExamData examData) : prev(nullptr), next(nullptr), data(examData)
{
}

Node::Node(Node* node, ExamData examData) : prev(node), next(nullptr), data(examData)
{
}


