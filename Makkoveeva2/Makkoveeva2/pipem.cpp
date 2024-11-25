#include "pipem.h"
#include "utils.h"
#include <string>
#include<unordered_map>
using namespace std;

int Pipe::maxid = 1;
int Pipe::getid() 
{
	return id;
}

void Pipe::createpipe()
{
	cout << "Enter the pipe name: " << endl;
	getline(cin>>ws, name);
	cout << "Enter the pipe length: " << endl;
	length = check(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	diameter = check(1, 10000);
	cout << "Enter the repair status(1/0): " << endl;
	repair = check(0, 1);
	id = maxid;
	maxid++;
}


void Pipe::showpipe()
{
	if (diameter == 0)
	{
		cout << "You don't have any pipes!\n";
	}
	else
	{
		cout << "ID " << id << endl;
		cout << "Name: " << name << endl;
		cout << " Length: " << length << endl;
		cout << " Diameter: " << diameter << endl;
		cout << " Repair: " << repair << endl;
	}
}
void pipemenu(unordered_map<int, Pipe>& pipes)
{
	while (1) {
		cout << "1. Add pipe " << endl;
		cout << "2. Edit pipe " << endl;
		cout << "3. Delete pipe " << endl;
		cout << "0. Return to menu" << endl;
		int option = check(0, 8);
		switch (option)
		{
		case 1:
		{
			Pipe p;
			p.createpipe();
			pipes.emplace(p.getid(), p);
			break;
		};
		case 2:
		{
			break;
		};
		case 3:
		{
			break;
		};
		case 0:
		{
			return;
		}
		}
	}
}