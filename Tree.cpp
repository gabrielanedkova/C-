#include"Queue.h"
#include <iostream>
using namespace std;
Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	destroy(root);
}

void Tree::destroy(const Node* root)
{
	if (root)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}
void Tree::print()
{
	print(root);
}

void Tree::print(Node* node)
{
	if (node)
	{
		cout << "(" << node->data;
		print(node->left); 
		print(node->right);
		cout << ")";

	}
	else cout << "()";
}

int Tree::height(Node* node)
{
	if (!node)
		return 0;
	return  1 + max(height(node->left),height( node->right));
}
int Tree::max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}
int Tree::height()
{
	return height(root);
}

void Tree::insert(const int data)
{
	Node* child = root;
	Node* parent = root;
	if (!root){
		root = new Node(data);
		return;
	}
	while (child)
	{
		if (data <= child->data)
		{
			parent = child;
			child = child->left;
		}
		else
		{
			parent = child;
			child = child->right;
		}
	}
	if (parent->data >= data)
	{
		Node* newNode = new Node(data);
		parent->left = newNode;
	}
	else {
		Node* newNode = new Node(data);
		parent->right = newNode;
	}
}
void Tree::printPretty()
{
	Queue q;
	q.enqueue(root);
	Node* temp;
	int level = 0;
	int cnt = 1;
	while (!q.isEmpty())
	{
		temp = q.dequeue();
		cout << temp->data << " ";
		q.enqueue(temp->left);
		q.enqueue(temp->right);
		--cnt;
		if (cnt <= 0)
		{
			cout << endl;
			++level;
			cnt = level * 2;
		}

	}
}

int Tree::elCnt(Node* node)
{
	int cnt = 0;
	if (node)
	{ 
		cnt = 1 + elCnt(node->left) + elCnt(node->right);
		return cnt;
	}
	return 0;
}
int Tree::subtreeWithNelements(Node* node, int N, int& num)
{
	int cnt = 0;
	if (node)
	{
		cnt = 1 + subtreeWithNelements(node->left, N, num) + subtreeWithNelements(node->right, N, num);
		if (cnt == N)
			++num;
		return cnt;
	}
	return 0;
}
int Tree::subtreeWithNelements(int N)
{
	int num = 0;
	subtreeWithNelements(root, N, num);
	return num;
}
int Tree::elCnt()
{
	return elCnt(root);
}
int Tree::cntLeafes(Node* leave)
{
	if (!leave->left)
	{
		if (!leave->right)
			return 1;
		else return cntLeafes(leave->right);
	}
	else if (!leave->right)
	{
		return cntLeafes(leave->left);
	}
	else return cntLeafes(leave->left) + cntLeafes(leave->right);
}

int Tree::cntLeafes()
{
	return cntLeafes(root);
}

void Tree::add(const int data)
{
	if (!root)
		root = new Node(data);
	else
	{
		Queue q;
		q.enqueue(root);
 
		while (!q.isEmpty()) {
			Node* temp = q.dequeue();

			if (!temp->left) {
				temp->left = new Node(data);
				break;
			}
			else
				q.enqueue(temp->left);

			if (!temp->right) {
				temp->right = new Node(data);
				break;
			}
			else
				q.enqueue(temp->right);
		}
	}
}
