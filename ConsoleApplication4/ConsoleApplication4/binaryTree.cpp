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
#include "binaryTree.h"

BinaryTree::BinaryTree()
{
	root = nullptr;
}
BinaryTree::~BinaryTree()
{
	clear(root);
}

int BinaryTree::height(const Node* root) const
{
	if (!root) return 0;
	return root->height;
}

int BinaryTree::getBalance(Node* root) 
{
	if (!root)
		return 0;
	return height(root->left) - height(root->right);
}

void BinaryTree::insert(Node*& root,string word, int mark)
{    
	if (!root)
		root = new Node(word, mark);
	else if (root->word > word)
		insert(root->left, word, mark);
	else insert(root->right, word, mark);

	root->height = 1 + max(height(root->left), height(root->right));


	int balance = getBalance(root);

	if (balance > 1 && word < root->left->word){
		root = rightRotate(root);
	}
	else if (balance < -1 && word > root->right->word){
		root = leftRotate(root);
	}
	else if (balance > 1 && word > root->left->word) {
		root->left = leftRotate(root->left);
		root = rightRotate(root);
	}
	else if (balance < -1 && word < root->right->word) {
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
}



void BinaryTree::clear(Node*& root)
{
	if (!root)
		return;
	clear(root->left);
	clear(root->right);
	Node* node = root;
	delete[] node;
}
int* BinaryTree::search(Node*& root,string word)
{
	int* arr = new int [2];
	arr[0] = arr[1] = 0;
	if (!root)
		return arr;
	if (word == root->word)
	{
		int wordsCounter = 0;
		stringstream ss(word);
		string token;
		while (ss >> token)
			wordsCounter++;
		arr[0] = wordsCounter;
		arr[1] = root->mark;
		return arr;
	}
	if (word > root->word)
		return search(root->right, word);
	else 
		return search(root->left, word);
}

void BinaryTree::traverse(Node* root)
{
	if (!root)
		return;
	traverse(root->left);
	cout << root->word<< " "  << root->height << " ";
	traverse(root->right);
}

Node* BinaryTree::rightRotate(Node* prevRoot) {
	Node* newRoot = prevRoot->left;
	Node* newRootRight = newRoot->right;
	newRoot->right = prevRoot;
	prevRoot->left = newRootRight;
	prevRoot->height = max(height(prevRoot->left), height(prevRoot->right)) + 1;
	newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

	return newRoot;

}

Node* BinaryTree ::leftRotate(Node* prevRoot) {
	Node* newRoot = prevRoot->right;
	Node* newRootLeft = newRoot->left;
	newRoot->left = prevRoot;
	prevRoot->right = newRootLeft;
	prevRoot->height = max(height(prevRoot->left), height(prevRoot->right)) + 1;
	newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

	return newRoot;
}
