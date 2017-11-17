/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Gabriela Nedkova
* @idnumber 45097
* @task 2
* @compiler VC
*
*/
#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;

struct Request
{
	char dir[6];
	int floor;
	int time;
};

int readRequests(char* argv[], Queue<Request> &a)
{
	ifstream ifile(argv[1], ios::in);
	int N;
	int K;
	char str[5];
	Request r;
	ifile >> N >> K;
	for (int i = 0; i < K; i++)
	{
		ifile >> str;
		if (strcmp(str, "go") == 0)
		{
			int floor = 0;
			int time = 0;
			ifile >> floor >> time;
			if (floor < 1 || floor > N || time < 0)
			{
				cout << "Invalid request" << endl;
				ifile.close();
				return 0;
			}
			r.floor = floor;
			r.time = time;
			r.dir[0] = 'f';
			r.dir[1] = '\0';
			a.enqueue(r);

		}
		else if (strcmp(str, "call") == 0)
		{
			int floor = 0;
			int time = 0;
			ifile >> r.dir >> floor >> time;
			if (floor < 1 || floor > N || time < 0 || (strcmp(r.dir, "up") != 0 && strcmp(r.dir, "down") != 0))
			{
				cout << "Invalid request" << endl;
				ifile.close();
				return 0;
			}
			r.time = time;
			r.floor = floor;
			a.enqueue(r);
		}
		else {
			cout << "Invalid request!" << endl;
			ifile.close();
			return 0;
		}
	}
	ifile.close();
	return 1;
}
int main(int argc, char* argv[])
{
	Queue<Request> elevator;
	readRequests(argv, elevator);
	int currentTime = -1;
	int currentFloor = 1;
	char currentDir = 'd';
	while (!elevator.isEmpty())
	{
		elevator.handleRequest(currentTime, currentFloor, currentDir);
	}
	system("pause");
	return 0;
}