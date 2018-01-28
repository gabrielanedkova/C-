
struct Node
{
	Node* left;
	Node* right;
	int data;
	Node() :left(nullptr), right(nullptr){};
	Node(const int data) :left(nullptr), right(nullptr), data(data){};
};
