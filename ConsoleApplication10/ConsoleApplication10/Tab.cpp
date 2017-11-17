#include <ctime>
#include "Tab.h"

Tab::Tab() : URL(nullptr), dateTime(0)
{
	setURL("about:bank");
	setTime();

}
Tab::Tab(const char* URL) : URL(nullptr), dateTime(0)
{
	setURL(URL);
	setTime();
}
Tab::Tab(const Tab& rhs)
{
	setURL(rhs.URL);
	dateTime = rhs.dateTime;
}
Tab& Tab:: operator=(const Tab& rhs)
{
	if (&rhs != this)
	{
		setURL(rhs.URL);
		dateTime = rhs.dateTime;
	}
	return *this;

}
Tab::~Tab()
{
	delete[] URL;
}
bool Tab::go(const char* URL)
{
	setURL(URL);
	setTime();
	return true;
}

void Tab::setURL(const char* URL)
{
	if (this->URL != nullptr)
		delete[] this->URL;
	int len = strlen(URL) + 1;
	this->URL = new char[len];
	strcpy_s(this->URL, len, URL);
}
void Tab::setTime()
{
	dateTime = static_cast<int>(time(NULL));
}

std::ostream& operator<< (std::ostream& out, const Tab& tab)
{ 
	out << tab.URL << " " << tab.dateTime << std::endl;
	return out;
}
bool operator> (const Tab &t1, const Tab &t2);
bool operator<= (const Tab &t1, const Tab &t2);
bool operator< (const Tab &t1, const Tab &t2);
bool operator>= (const Tab &t1, const Tab &t2);

bool operator== (const Tab &t1, const Tab &t2)
{
	return (strcmp(t1.URL, t2.URL) == 0 && t1.dateTime == t2.dateTime);
}

bool operator!= (const Tab &t1, const Tab &t2)
{
	return !(t1 == t2);
}

