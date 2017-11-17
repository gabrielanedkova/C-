#ifndef _DYNARR_H_
#define _DYNARR_H_

class Vector
{
public:
	Vector();
	//~Vector();
	void push(int );
	void pop();
	int top();
private:
	void resize(int);
 private:
	int capacity;
	int size;
	int* arr;
};

#endif
