/*Да се напише програма, която създава файл с пряк достъп, съдържащ информация за
студентите от един курс.Всяка компонента на файла да съдържа : факултетен номер, име
и среден успех на студент.Факултетните номера са от 42900 до 45150. Програмата да
може да извършва следните действия :
-вмъкване на компонента за новозаписан студент
- изтриване на компонента за студент
- промяна на полето "среден успех" на компонента, зададена чрез факултетен номер на студент
- извеждане на екрана на компонентите на файла
- записване на файла в текстовия файл print.txt
- намиране на студентите с указан успех.*/

#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

#include <string>
class Animal
{
public:
	std::string m_name;

	// We're making this constructor protected because
	// we don't want people creating Animal objects directly,
	// but we still want derived classes to be able to use it.
	Animal(std::string name)
		: m_name(name)
	{
	}

	std::string getName() { return m_name; }
	virtual const char* speak() = 0;
};


class Dog : public Animal
{
public:
	Dog(std::string name)
		: Animal(name)
	{
	}

	   const char* speak() { return "Woof"; }
};

class Jonny : public Dog
{
public:
	Jonny(std::string name) : Dog(name)
	{

	}
	const char* speak() { return "Jonny"; }

};
void report(Animal &animal)
{
	std::cout << animal.getName() << " says " << animal.speak() << '\n';
}


int main()
{
	char x;
	ofstream stream("file.txt", ios::in | ios::binary| ios::ate);
	stream.write("222222" , 6);
	cout << stream.rdstate();
	system("pause");

	return 0;
}