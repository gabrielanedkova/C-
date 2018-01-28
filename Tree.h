#include"Node.h"
class Tree
{

private:
	Node* root;

	void destroy(const Node* root); 
	void print(Node* node);
	int height(Node* node);
	int max(int a, int b);
	int cntLeafes(Node* root);
	int elCnt(Node* node);
	int subtreeWithNelements(Node* node, int N, int& num);

public:
	Tree();
	~Tree();
	void add(const int data);
	void print();
	void printPretty();
	int height();
	void insert(const int data);
	int cntLeafes();
	int elCnt();
	int subtreeWithNelements(int N);


};