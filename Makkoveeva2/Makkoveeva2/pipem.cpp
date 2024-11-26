#include "pipem.h"
#include "utils.h"
#include <string>
#include<unordered_map>
using namespace std;

int Pipe::maxid = 0;


int Pipe::getid() 
{
	return id;
}
Pipe::Pipe()
{
	id = ++maxid;
	name = "None";
	diameter = 0;
	length = 0;
	repair = false;
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
}

void Pipe::showpipe()
{
	if (diameter == 0)
	{
		cout << "You don't have any pipes\n";
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

void Pipe::savepipe(ofstream& file)
{
	file << "Pipe" << endl;
	file << id << endl;
	file << name << endl;
	file << length << endl;
	file << diameter << endl;
	file << repair << endl;
}
Pipe::Pipe(ifstream& file)
{
	file >> this->id;
	file.ignore(10000, '\n');
	getline(file >> ws, this->name);
	file >> this->length;
	file >> this->diameter;
	file >> this->repair;
}

void Pipe::edit()
{
	repair = !repair;
}
void deletep(unordered_map<int, Pipe>& pipes)
{
	while (1)
	{
		cout << "1. Delete selected pipes " << endl;
		cout << "2. Delete all pipes " << endl;
		cout << "0. Exit " << endl;
		int option = check(0, 2);
		switch (option)
		{
		case 1:
		{
			break;
		};
		case 2:
		{
			pipes.clear();
			cout << "All pipes deleted" << endl;
			return;
			break;
		};
		case 0:
		{
			return;
		};
		}
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
			deletep(pipes);
			break;
		};
		case 0:
		{
			return;
		};
		}
	}
}