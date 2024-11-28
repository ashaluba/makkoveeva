#include "pipem.h"
#include "utils.h"
#include "filter.h"
#include<unordered_map>
using namespace std;

int Pipe::maxid = 0;


int Pipe::getid() 
{
	return id;
}
string Pipe::getname()
{
	return name;
}
bool Pipe::getrepair()
{
	return repair;
}
void Pipe::editpipe(bool new_rep) {
	this->repair = new_rep;
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

void deletep(unordered_map<int, Pipe>& pipes)
{
			pipes.clear();
			cout << "All pipes deleted" << endl;
			return;
}
void pipemenu(unordered_map<int, Pipe>& pipes)
{
	while (1) {
		cout << "1. Add pipe " << endl;
		cout << "2. Edit pipe " << endl;
		cout << "3. Delete pipes " << endl;
		cout << "4. Filter" << endl;
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
			maineditpipe(pipes);
			break;
		};
		case 3:
		{
			deletep(pipes);
			break;
		};
		case 4:
		{
			selectbyfilter(pipes);
			break;
		};
		case 0:
		{
			return;
		};
		}
	}
}