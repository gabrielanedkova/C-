#include <iostream>
#include "Browser.h"

int main()
{

	Browser browser;
	char buffer[1024];
	while (!strcmp(buffer,"exit")==0)
	{
		std::cout << '$';
		std::cin >> buffer;
		if (strcmp(buffer, "GO") == 0)
		{
			std::cin >> buffer;
			browser.go(buffer);
		}
		else if (strcmp(buffer, "INSERT") == 0)
		{
			std::cin >> buffer;
			browser.insert(buffer);
		}
		else if (strcmp(buffer, "BACK") == 0)
		{
			browser.back();
		}
		else if (strcmp(buffer, "FORWARD") == 0)
		{
			browser.forward();
		}
		else if (strcmp(buffer, "REMOVE") == 0)
		{
			browser.remove();
		}
		else if (strcmp(buffer, "PRINT") == 0)
		{
			browser.print();
		}
		if (!std::cin.good()) break;
	}
	
	return 0;
}