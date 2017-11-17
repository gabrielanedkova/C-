/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gabriela Nedkova
* @idnumber 45097
* @task 3
* @compiler VC
*
*/
#include <iostream>  
#include <fstream>
#include <sstream>
#include "binarytree.h"
using namespace std;

int readFromDictionary(char* argv, BinaryTree*& dict)
{
	int longestPhrase = 0;
	ifstream dictionary(argv, ios::in);
	if (!dictionary)
		return 0; 
	string line;
	while (!dictionary.eof())
	{
		getline(dictionary, line);
		int currentLength = 0;
		stringstream ss(line);
		line = "";
		string phrase;
		string token;
		while (ss >> token){
			if (currentLength != 0)
				phrase = line;
			line += token + " ";
			currentLength++;
		}
		if (longestPhrase < currentLength)
			longestPhrase = currentLength;
		phrase.erase(phrase.find_last_not_of(" \n\r\t") + 1);
		dict->insert(phrase, stoi(token));
	
	}
	dictionary.close();
	return longestPhrase - 1;

}
string removeSigns(string& str)
{
	if ((str.back() <= 122 && str.back() >= 97) || str.back() == ' ')
		return str;
	str.erase(str.end() - 1);
	return removeSigns(str);
}

int* find(string* arr, int length, BinaryTree* dict)
{
	int* key = new int[2];
	key[0] = key[1] = 0;
	if (length == 0)
		return key;
	string phrase;
	for (int i = 0; i < length; i++)
	{
		phrase += arr[i] + " ";
	}
	std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
	if (arr[length - 1] != " ");
		phrase.erase(phrase.find_last_not_of(" \n\r\t") + 1);
	key = dict->search(phrase);
	if (key[0] != 0)
		return key;
	else{
		delete[] key;
		return find(arr, length - 1, dict);
	}
}

bool checkSpaces(ifstream& file)
{
	char firstSign;
	char secondSign;
	file.get(firstSign);
	file.get(secondSign);
	file.seekg(-1, ios::cur);
	if ((firstSign == ' ' || firstSign == '\t' || firstSign == '\n') && (secondSign != ' ' && secondSign != '\t' && secondSign != '\n'))
		return true;
	else 
		return false;

}

double searchInFile(char* argv, BinaryTree* dict, int longestPhrase)
{
	int sum = 0;
	ifstream file(argv, ios::in);
	if (!file) 
		return 0;
	string* arr = new string[longestPhrase];
	int cnt = 0;
	for (int i = 0; i < longestPhrase; i++)
	{
		if (file.eof())
			break;
		if (i == 0 || checkSpaces(file))
		{
			file >> arr[i];
			cnt++;
		}
		else
			arr[i] = " ";
		removeSigns(arr[i]);
	}
	int wordsCounter = cnt;
	int* key = find(arr, cnt, dict);
	sum += key[1];
	while (!file.eof())
	{
		if (key[0] == 0)
		{
			for (int i = 0; i < longestPhrase - 1; i++)
				arr[i] = arr[i + 1];
			if (checkSpaces(file))
			{
				file >> arr[longestPhrase - 1];
				wordsCounter++;
			}
			else 
				arr[longestPhrase - 1] = " ";
			removeSigns(arr[longestPhrase - 1]);
			delete[] key;
			key = find(arr, longestPhrase, dict);
			sum += key[1];
		}
		else {
			int i = key[0];
			int j = 0;
			while (i < longestPhrase)
			{
				arr[j] = arr[i];
				i++;
				j++;
			}
			while (j < longestPhrase)
			{
				if (file.eof())
				{
					for (int i = j; j < longestPhrase; j++)
						arr[j] = " ";
					break;
				}
				if (j == 0 || checkSpaces(file))
				{
					file >> arr[j];
					wordsCounter++;
				}
				else
					arr[j] = " ";
				removeSigns(arr[j]);
				j++;
			}
				delete[] key;
				key = find(arr, i, dict);
				sum += key[1];
		}
	}

	int counterArr = 0 + key[0] + 1;
	int counter = longestPhrase - key[0] - 1;
	while (counter > 0)
	{
		string* reminding = new string[counter];
		for (int i = 0; i < counter; i++)
		{
			reminding[i] = arr[counterArr + i];
		}
		
		key = find(reminding, counter, dict);
		if (key[0] > 1)
		{
			counter -= key[0];
			counterArr += key[1];
		}
		else {
			counter--;
			counterArr++;
		}
	}
	delete[] arr;
	delete[] key;
	file.close();
	return (double)sum/wordsCounter;
}

int main(int argc, char* argv[])
{
	if (argc < 3)
		return -1;
	BinaryTree* dict = new BinaryTree;
	int longestPhrase = readFromDictionary(argv[1], dict);
	for (int i = 2; i < argc; i++)
	{
		cout << argv[i] << " " << searchInFile(argv[i], dict, longestPhrase) << endl;
	}
	system("pause");
}