/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gabriela Nedkova
* @idnumber 45097
* @task 1
* @compiler VC
*
*/

#include <iostream>  
#include <fstream>
#include <iomanip>
#include "stack.h"
#include <sstream>
using namespace std;

bool isNumber(char* str)
{
	bool point = false;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (i == 0 && str[i] == '-'&& strlen(str) > 1)
			continue;
		if (str[i] == '.' || str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' ||
			str[i] == '8' || str[i] == '9' || (i == len - 1 && i != 0  && str[i] == 'f'))
		{
			if (str[i] == '.' && point == true)
				return false;
			else if (str[i] == '.') point = true;
		}
		else return false;
	}
	return true;

}

const char* calculate(Stack<char*>& st, double& res)
{
	Stack<double> result;
	while (!st.isEmpty())
	{
		if (isNumber(st.top()))
		{
			result.push(atof(st.top()));
			st.pop();
		}
		else if (result.getSize() >= 2)
		{
			double a = result.top();
			result.pop();
			double b = result.top();
			result.pop();
			if (strcmp(st.top(), "+") == 0)
				result.push(a + b);
			else if (strcmp(st.top(), "*") == 0)
				result.push(a * b);
			else if (strcmp(st.top(), "-") == 0)
				result.push(a - b);
			else if (strcmp(st.top(), "/") == 0)
			{
				if (b == 0)
				{
					return "Error";
				}
				result.push(a / b);
			}
			else return "Error";
			st.pop();
		}
		else return "Error";
	}
	if (result.getSize() == 1)
	{
		res = result.top();
		return "";
	}
	return "Error";
}
bool setOperators(char* fileName2, Stack<char*> prefix)
{
	ifstream file(fileName2, ios::in);
	if (!file)
	{
		return false;
	}
	string line;
	string newOp;
	string oldOp;
	int size = 0;
	while (!file.eof())
	{
		size++;
		getline(file, line);
	}
	file.clear();
	file.seekg(0, ios::beg);
	for (int i = 0; i < size; i++)
	{
		getline(file, line);
		istringstream ss(line);
		getline(ss, oldOp, ' ');
		getline(ss, newOp, ' ');
		prefix.changeElement(oldOp.c_str(), newOp.c_str());
	}
	return true;
}

char* prefixToPostfix(Stack<char*> st)
{
	Stack<char*> s;
	while (!st.isEmpty())
	{
		if (isNumber(st.top()))
		{
			char* temp = st.top();
			s.push(temp);
			st.pop();
		}
		else if (s.getSize() >= 2)
		{
			char* operand1 = s.top();
			s.pop();
			char* operand2 = s.top();
			s.pop();
			char* op = st.top();
			st.pop();
			char* push = new char[strlen(operand1) + strlen(operand2) + strlen(op) + 4];
			strcpy(push, operand1);
			strcat(push, " ");
			strcat(push, operand2);
			strcat(push, " ");
			strcat(push, op);
			s.push(push);
		}
		else return "Error";
	}
	if (s.getSize() > 1)
		return "Error";
	return s.top();
}
char* fillStack(Stack<char*>& prefix, char* fileName1)
{
	ifstream file1(fileName1, ios::in);
	if (!file1)
	{
		return "Cannot open file";
	}
	string line;
	string token;
	getline(file1, line);
	file1.close();
	istringstream ss(line);
	while (std::getline(ss, token, ' '))
	{
		char* t = new char[token.length() + 2];
		strncpy(t, token.c_str(), strlen(t));
		t[strlen(t)] = 0;
		if (strlen(t) <= 1)
			if (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/')
				return "Error";
		prefix.push(t);
	}
	return nullptr;
}
int main()
{	
	Stack<char*> prefix;
	char* fileName1 = new char[256];
	char* fileName2 = new char[256];
	cin.getline(fileName1, 256);
	cin.getline(fileName2, 256);

	char* fill = fillStack(prefix, fileName1);
	if (fill != 0)
	{
		cout << fill << endl;
		return -1;
	}
	char* postfix = prefixToPostfix(prefix);
	if (strcmp(postfix, "Error") != 0)
	{
		bool flag = setOperators(fileName2, prefix);
		double res = 0;
		const char* r = calculate(prefix, res);
		if (flag == false)
		{
			cout << "Cannot open file" << endl;
			return -1;
		}
		if (strcmp(r, "Error") != 0)
		{
			cout << postfix << endl;
			cout << setprecision(5) << fixed << res << endl;
		}
		else cout << r << endl;
	}
	else cout << postfix << endl;

	delete[] fileName1;
	delete[] fileName2;
	system("pause");
	return 0;
}