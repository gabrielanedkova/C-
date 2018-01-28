#include <iostream>
#include <fstream>

struct Node
{
	int num;
	Node* left;
	Node* right;
	Node(int num){
		this->num = num;
		left = right = nullptr;
	}
};

class Queue
{
	struct QueueNode{
		Node* node;
		QueueNode* next;
		QueueNode(Node* node){ this->node = node; next = nullptr; };
	};
public:
	QueueNode* first;
	QueueNode* last;
	Queue(){
		first = last = nullptr;
	}
	bool isEmpty()
	{
		return (first == nullptr);
	}
	void pushBack(Node* node)
	{
		if (!first)
		{
			first = new QueueNode(node);
			last = first;
			return;
		}

		QueueNode* newNode = new QueueNode(node);
		last->next = newNode;
		last = newNode;
	}

	Node* popFront()
	{
		QueueNode* deleteNode = first;
		Node* node = first->node;
		first = first->next;
		delete deleteNode;
		return node;
	}
};
class Tree
{
	Node* root;
	void add(Node* root, int num){
		if (!root)
		{
			root = new Node(num);
			return;
		}
		if (root->num == num)
			return;
		if (root->num > num)
		{
			if (!root->left)
				root->left = new Node(num);
			else  add(root->left, num);
		}
		else {
			if (!root->right)
				root->right = new Node(num);
			else  add(root->right, num);
		}
	}

public:
	Tree(){ root = nullptr; };
	void add(int num)
	{
		if (!root)
			root = new Node(num);
		else add(root, num);
	}

	void writeInFile(const char* name)
	{
		std::ofstream file(name, std::ios::trunc);
		Queue q;
		q.pushBack(root);
		while (!q.isEmpty())
		{
			Node* node = q.popFront();
			file << node->num;
			if (node->left)
				q.pushBack(node->left);
			if (node->right)
				q.pushBack(node->right);
		}
		file.close();
	}
	int countSubtreesWithNel(int N, Node* node, int& counter)
	{
			int cnt = 0;
		if (node)
		{
			cnt = 1 + countSubtreesWithNel(N, node->left, counter) + countSubtreesWithNel(N, node->right, counter);
			if (cnt == N)
				++counter;
			return cnt;
		}
		return 0;
	}
};

int main()
{
	Tree t;
	std::ifstream file("gabi.txt");
	int num;
	while (file >> num)
	{
		t.add(num);
		std::cout << num;
	}
	file.close();
	t.writeInFile("gabi.txt");

	return 0;
}