#ifndef _BROWSER_H_
#define _BROWSER_H_
#include "DoublyLinkedList.h"
#include "Iterator.h"

class Browser
{
public:
	Browser();
	Browser(const Browser&) = default;
	Browser& operator=(const Browser&) = default;
	~Browser() = default;
	void print()const;
	void go(const char* URL);
	void insert(const char* URL);
	bool back();
	bool forward();
	void remove();
private:
	DoublyLinkedList tabs;
	Iterator current;

};
#endif