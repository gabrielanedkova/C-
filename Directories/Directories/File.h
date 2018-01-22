#ifndef FILE_H
#define FILE_H
#include <fstream>
class File
{
private:
	int size;
	char* fullPath;
	int fileNum;
public:

	File();
	File(const File& rhs);
	File(const char* fileName, int size, int fileNum);
	~File();

	void setPath(const char* fullPath);
	void setSize(const int size);
	void setFileNum(const int fileNum);
	File& operator= (const File& rhs);
	void copyData(const File& rhs);
	int getFileNum() const;

	friend std::ostream& operator<<(std::ostream& o, const File& f);
	friend std::istream& operator>>(std::istream& i, File& f);
	friend bool operator>(const File& f1, const File& f2);

};

#endif