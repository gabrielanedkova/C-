#include "File.h"

File::File()
{
	fullPath = nullptr;
};
File::File(const File& rhs)
{
	fullPath = nullptr;
	copyData(rhs);
}

File::File(const char* fileName, int size, int fileNum){
	int len = strlen(fileName) + 1;
	this->fullPath = new char[len];
	strcpy_s(this->fullPath, len, fileName);
	this->size = size;
	this->fileNum = fileNum;

};

File::~File()
{
	delete[] fullPath;
}

File& File::operator= (const File& rhs)
{
	if (this != &rhs)
	{
		copyData(rhs);
	}
	return *this;
}
void File::copyData(const File& rhs)
{
	this->size = rhs.size;
	int len = strlen(rhs.fullPath) + 1;
	delete[] fullPath;
	this->fullPath = new char[len];
	strcpy_s(this->fullPath, len, rhs.fullPath);
	this->fileNum = rhs.fileNum;
}

int File::getFileNum() const
{
	return this->fileNum;
}

void File::setPath(const char* fullPath)
{
	int len = strlen(fullPath) + 1;
	delete[] this->fullPath;
	this->fullPath = new char[len];
	strcpy_s(this->fullPath, len, fullPath);
}

void File::setSize(const int size)
{
	this->size = size;
}
void File::setFileNum(const int fileNum)
{
	this->fileNum = fileNum;
}

std::ostream& operator<<(std::ostream& o, const File& f)
{
	o << f.size << " " << f.fullPath << std::endl;
	return o;
}

std::istream& operator>>(std::istream& i, File& f)
{
	char* path = new char[260];
	i >> f.size;
	i >> path;
	f.setPath(path);

	return i;
}
bool operator>(const File& f1, const File& f2)
{
	if (f1.size < f2.size)
		return false;
	else if (f1.size > f2.size)
		return true;
	else
	{
		return strcmp(f1.fullPath, f2.fullPath) < 0 ? false : true;
	}

}