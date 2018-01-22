#include "BST.h"
#include <iostream>

BST::BST()
{
	root = nullptr;
}

void BST::insert(const char* fileName, int size, int fileNum)
{
	File file(fileName, size, fileNum);
	if (!root)
	{
		root = new Node(file);
		return;
	}

	Node* curr = root;
	Node* prev = root;
	while (curr != nullptr)
	{
		prev = curr;
		if (file > *(curr->file))
			curr = curr->left;
		else curr = curr->right;
	}
	if (file > *prev->file)
		prev->left = new Node(file);
	else prev->right = new Node(file);
}

void BST::inOrder(Node* node)
{
	if (!node)
		return;
	inOrder(node->left);
	std::cout << *(node->file);
	inOrder(node->right);
}

void BST::inOrder()
{
	inOrder(root);
}

void BST::clear(Node* root)
{
	if (root)
	{
		clear(root->left);
		clear(root->right);
		delete root;
		root = nullptr;
	}
}

void BST::clear()
{
	clear(root);
	root = nullptr;
}
BST::~BST()
{
	clear(root);
}
void BST::print(std::ofstream& outFile)
{
	print(root, outFile);
}
void BST::print(Node* root, std::ofstream& outFile)
{
	if (root != nullptr)
	{
		print(root->left, outFile);
		outFile << *(root->file);
		print(root->right, outFile);
	}
}

int BST::removeAndDisplaySmallest()
{
	Node* parent = root;
	Node* it = root;
	int fileNum;
	while (it->left != nullptr)
	{
		parent = it;
		it = it->left;
	}
	if (it == root)
	{
		root = it->right;
	}
	if (it->right == nullptr){
		parent->left = nullptr;
	}
	else { 
		parent->left = it->right;
	}
	fileNum = it->file->getFileNum();
	std::cout << *(it->file);
	delete it;
	return fileNum;
}

bool BST::isEmpty()
{
	return root == nullptr;
}
