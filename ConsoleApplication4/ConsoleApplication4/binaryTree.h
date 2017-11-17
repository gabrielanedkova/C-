/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gabriela Nedkova
* @idnumber 45097
* @task 3
* @compiler VC
*
*/
#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <iostream>  
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
struct Node
{
	string word;
	int mark;
	int height;
	Node* left;
	Node* right;
	Node(string word, int mark, Node* left = nullptr, Node* right = nullptr)
		:mark(mark)
		, word(word)
		, left(left)
		, right(right)
	{};
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void clear(Node*& root);
	void insert(string word, int mark){ return insert(root, word, mark); };
	int* search(string word) { int* arr = search(root, word);  return arr;};
	void traverse(){ return traverse(root); };


private:
	Node* root;
	int getBalance(Node* root);
	void traverse(Node* root);
	void insert(Node*& root, string word, int mark);
	int* search(Node*& root, string word);
	int height(const Node* root) const;
	Node* leftRotate(Node* x);
	Node* rightRotate(Node* y);

};

#endif