#include <fstream>
#include "ExamData.h"

struct Node
{
public:
	Node();
	Node(ExamData examData);
	Node(Node* node, ExamData examData);

	Node* prev;
	Node* next;
	ExamData data;
};