#include <fstream>
#include <iostream>
using namespace std;
class RLEString
{
	struct Node{
		Node* next;
		char letter;
		int times;
		Node(char c, int cnt){
			letter = c;
			times = cnt;
			next = nullptr;
		}
	};
	Node* first;
	Node* last;
	int len;

	void addLetter(char c, int cnt)
	{
		len += cnt;
		if (!first)
		{
			first = last = new Node(c, cnt);
			return;
		}
		Node* newNode = new Node(c, cnt);
		last->next = newNode;
		last = last->next;

		
	}

public:

	RLEString operator+(RLEString const & right) const
	{
		RLEString concat(*this);
		Node* it = right.first;
		if (concat.last->letter == right.first->letter)
		{
			concat.last->times += right.first->times;
			it = it->next;
		}
		while (it != right.last)
		{
			concat.addLetter(it->letter, it->times);
			it = it->next;
		}
		concat.addLetter(it->letter, it->times);
		return concat;
	}

	RLEString(RLEString const & right)
	{
		Node* it = right.first;
		while (it != right.last)
		{
			addLetter(it->letter, it->times);
			it = it->next;
		}
		addLetter(it->letter, it->times);

	}
	RLEString(){ first = last = nullptr; len = 0; };
	friend ostream& operator<<(ostream& os, const RLEString& string)
	{
		Node* it = string.first;
		while (it != string.last)
		{
			os << "(" << it-> letter <<", " << it->times <<") ";
			it = it->next;
		}		
		os << "(" << it->letter << ", " << it->times << ") ";

		return os;
	}

	RLEString(const char* str)
	{
		int i = 1;
		int cnt = 1;
		char c = str[0];
		while (str[i] != '\0')
		{
			if (c != str[i])
			{
				addLetter(c, cnt);
				cnt = 1;
				c = str[i];
			}
			else ++cnt;
			++i;
		}
		addLetter(c, cnt);
	}

	size_t length() const
	{
		Node* it = first;
		size_t length = 0;
		while (it != last)
		{
			length += it->times;
			it = it->next;
		}
		length += it->times;
		return length;
	}

	char& operator[](int i)
	{
		Node* it = first;
		int length = first ->times;
		while (length - 1 < i && it != last)
		{
			it = it->next;
			length += it->times;
		}
		return it->letter;
	}

	void splice(int start, int length) //– изтрива част от представения низ; премахват се length на брой елементи, като се започне от елемента на позиция start;
	{
	
	}
	void insert(const RLEString& rles, int pos)
	{

	}
};


int main()
{
	RLEString str("AAABBCBBC");
	RLEString str1("CCAAABBCBBC");
	RLEString str2 = str + str1;
	cout << str2 << endl;
	cout << str.length() <<endl;
	cout << str[6];
	system("pause");
}