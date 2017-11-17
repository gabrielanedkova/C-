#ifndef _TAB_H_
#define  _TAB_H_
#include <iostream>

class Tab
{
public:
	Tab();
	Tab(const char* URL);
	Tab(const Tab& rhs);
	Tab& operator=(const Tab& rhs);
	~Tab();
	bool go(const char* URL);
	friend std::ostream& operator<< (std::ostream& out, const Tab& tab);
	friend bool operator> (const Tab &t1, const Tab &t2);
	friend bool operator<= (const Tab &t1, const Tab &t2);
	friend bool operator< (const Tab &t1, const Tab &t2);
	friend bool operator>= (const Tab &t1, const Tab &t2);
	friend bool operator== (const Tab &t1, const Tab &t2);
	friend bool operator!= (const Tab &t1, const Tab &t2);

private:
	char* URL;
	int dateTime;
	void setURL(const char* URL);
	void setTime();

};

#endif