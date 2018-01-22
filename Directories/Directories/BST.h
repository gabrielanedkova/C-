#ifndef BST_H
#define BST_H
#include <iostream>
#include "File.h"
class BST
{
private:
	struct Node
	{
		File* file;
		Node* left;
		Node* right;

		Node(File file)
		{
			left = right = nullptr;
			this->file = new File(file);
		}
		Node(const char* fileName, const int size, const int fileNum)
		{
			file = new File(fileName, size, fileNum);
			left = right = nullptr;
		}
		~Node(){
			delete file;
		};
	};
	void clear(Node* root);
	void inOrder(Node* node);
	void print(Node* root, std::ofstream& outFile);
	Node* root;

public:
	BST();
	~BST();
	void insert(const char* fileName, const int size, const int fileNum);
	void print(std::ofstream& outFile);
	void inOrder();
	void clear();
	int removeAndDisplaySmallest();
	bool isEmpty();
};

#endif