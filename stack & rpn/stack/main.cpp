#include <iostream>  
#include "stack.h"
using namespace std;

int main()
{
	Stack<int> st;
	int size = 50;
	char* str = new char[size];
	std::cout << "Enter string: ";
	cin >> str;
	
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '+')
			{	
				int a = st.top();
				st.pop();
				a += st.top();
				st.pop();
				st.push(a);
			}
		else if (str[i] == '-')
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			b -= a;
			st.pop();
			st.push(b);
		}
		else if (str[i] == '*')
		{
			int a = st.top();
			st.pop();
			a *= st.top();
			st.pop();
			st.push(a);
		}
		else if (str[i] == '/')
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			b /= a;
			st.pop();
			st.push(b);
		}
		else {
			st.push(str[i] - 48);
		}
	}
	
	cout << st.top();
	system("pause");
}