#include <iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
	Node(int data) :data(data), left(nullptr), right(nullptr)
	{

	}
};

class Queue
{
	struct QueueNode
	{
		QueueNode* next;
		Node* data;
		QueueNode(Node* data) :data(data), next(nullptr)
		{
			
		}
	};
	QueueNode* first;
	QueueNode* last;
public:
	Queue() :first(nullptr), last(nullptr)
	{

	}
	void pushBack(Node* n)
	{
		if (!first)
		{
			first = new QueueNode(n);
			last = first;
			return;
		}
		QueueNode* newNode = new QueueNode(n);
		last->next = newNode;
		last = last->next;
	}
	Node* popFront()
	{
		if (isEmpty())
			return nullptr;
		QueueNode* temp = first;
		Node* front = temp->data;
		if (first == last)
		{
			first = last = nullptr;
		}
		else
		{
			first = first->next;
		}
		delete temp;
		return front;
	}
	bool isEmpty()
	{
		return (first == nullptr);
	}
};
class Tree
{
	Node* root;
	void sumOfeL(Node* leaf, unsigned int K, int depth, int& sum)
	{
		if (leaf == nullptr)
			return;
		if (depth > K)
			return;
		if (depth == K)
		{
			sum += leaf->data;
		}
		sumOfeL(leaf->left, K, depth + 1, sum);
		sumOfeL(leaf->right, K, depth + 1, sum);
	}


public:
	void add(int n)
	{
		if (!root)
		{
			root = new Node(n);
			return;
		}
		Queue q;
		q.pushBack(root);
		Node* curr = nullptr;
		while (!q.isEmpty())
		{
			curr = q.popFront();
			if (!curr->left)
			{
				curr->left = new Node(n);
				break;
			}
			if (!curr->right)
			{
				curr->right = new Node(n);
				break;
			}
			q.pushBack(curr->left);
			q.pushBack(curr->right);
		}
	}
	Tree():root(nullptr)
	{
	}
		void sumOfeL(unsigned int K, int& sum)
	{
		sumOfeL(root, K, 0, sum);
	}

};

int sumOfeL(Tree t, unsigned int K)
{
	int sum = 0;
	t.sumOfeL(K, sum);
	return sum;
}
int main()
{
	int n = rand() % 100;
	Tree t;
	t.add(3);
	t.add(-10);
	t.add(-11);
	t.add(0);
	t.add(5);
	t.add(6);
	t.add(9);
	cout << sumOfeL(t, 2) << endl;
	system("pause");
}