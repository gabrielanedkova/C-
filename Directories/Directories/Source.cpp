#include <iostream>
#include <string>
#include <windows.h>
#include "BST.h"

int cnt = 0;
int cntFiles = 0;
using namespace std;

void writeInFile(string fileName, BST& tree)
{
	ofstream file(fileName.c_str());
	tree.print(file);
	tree.clear();
	file.close();
}
bool matchesTemplate(const char* fileName, const char* pattern)
{
	int patternLen = strlen(pattern) - 1;
	int fileLen = strlen(fileName) - 1;
	if (fileLen > patternLen)
	{
		while (patternLen >= 0)
		{
			if (pattern[patternLen--] != fileName[fileLen--])
			{
				return false;
			}
		}
		return fileName[fileLen] == '.';
	}
	return false;
}
void mergeFiles()
{
	BST tree;
	File file;
	ifstream *files = new ifstream[cntFiles];
	for (int i = 0; i < cntFiles; ++i)
	{
		string fileName = to_string(i) + ".txt";
		files[i].open(fileName.c_str());
		char* name = new char[260];
		int size;
		files[i] >> size;
		files[i].getline(name, 259);
		tree.insert(name, size, i);
		delete[] name;
	}
	while (!tree.isEmpty())
	{
		int numOfRemoved = tree.removeAndDisplaySmallest();
		int size;
		if (files[numOfRemoved] >> size)
		{
			char* name = new char[260];
			files[numOfRemoved].getline(name, 259);
			tree.insert(name, size, numOfRemoved);
		}

	}
	for (int i = 0; i < cntFiles; ++i)
	{
		files[i].close();
		string fileName = to_string(i) + ".txt";
		remove(fileName.c_str());
	}
	delete[] files;
}
void traverseDirectory(string DATA_DIR, BST& tree, const char* pattern)
{
	HANDLE hFind;
	WIN32_FIND_DATAA data;

	hFind = FindFirstFileA(DATA_DIR.c_str(), &data);

	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY && strcmp(data.cFileName, ".") != 0 && strcmp(data.cFileName, ".."))
			{
				TCHAR file_path[MAX_PATH];
				string st = DATA_DIR.substr(0, DATA_DIR.size() - 1);
				string fullName = st + data.cFileName + "\\*";
				traverseDirectory(fullName, tree, pattern);
			}
			else if (strcmp(data.cFileName, ".") != 0 && strcmp(data.cFileName, ".."))
			{
				
				string st = DATA_DIR.substr(0, DATA_DIR.size() - 1);
				string fullName = st + data.cFileName;
				if (matchesTemplate(fullName.c_str(), pattern))
				{
					tree.insert(fullName.c_str(), data.nFileSizeLow, cntFiles);
					++cnt;
				}
				if (cnt >= 100)
				{
					string name = to_string(cntFiles) + ".txt";
					writeInFile(name, tree);
					++cntFiles;
					cnt = 0;
				}
			}

		} while (FindNextFileA(hFind, &data));
		FindClose(hFind);
	}
}

int main(int argc, char* argv[])
{
	BST tree;
	string dir = argv[1];
	dir = dir + "\\*";
	traverseDirectory(dir, tree, argv[2]);
	mergeFiles();
 }
