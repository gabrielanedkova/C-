#include "Browser.h"

Browser::Browser()
{
	Tab first("about:blank");
	tabs.push_back(first);
	current = tabs.begin();
}

void Browser::print()const
{
	for (auto i = tabs.begin(); i != tabs.end(); ++i)
	{
		if (i == current){
			std::cout << ">";
		}
		std::cout << *i;
	}
	if (tabs.end() == current){
		std::cout << ">";
	}
	std::cout << *tabs.end();

}

void Browser::go(const char* URL)
{
	current->go(URL);
}

void Browser::insert(const char* URL)
{
	tabs.insertAfter(current, URL);
	++current;
}

bool Browser::back()
{
	if (current != tabs.begin())
	{
		--current;
		return true;
	}
	return false;
}
bool Browser::forward()
{
	if (current != tabs.end())
	{
		++current;
		return 
			true;
	}
	return false;

}
void Browser::remove()
{
	Iterator removed = current;
	if (current == tabs.end())
	{
		if (current != tabs.begin())
			--current;
	}
	
	else ++current;
	tabs.remove(removed);

}

