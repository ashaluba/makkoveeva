#include "pipem.h"
#include "utils.h"
using namespace std;

int Pipe::getid()
{
	return id;
}

string Pipe::getname() const
{
	return name;
}

int Pipe::getlength() const
{
	return length;
}

int Pipe::getdiameter() const
{
	return diameter;
}

bool Pipe::getstatus() const
{
	return repair;
}

void Pipe::setname(string& new_name)
{
	name = new_name;
}

void Pipe::setlength(int& new_length)
{
	length = new_length;
}

void Pipe::setdiameter(int& new_diameter)
{
	diameter = new_diameter;
}

void Pipe::setstatus(bool& new_repair)
{
	repair = new_repair;
}

void Pipe::createpipe()
{
	cout << "ID" << id << endl;
	cout << "Enter the pipe name: " << endl;
	cin >> ws;
	getline(cin, name);
	cout << "Enter the pipe length: " << endl;
	length = check(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	diameter = check(1, 10000);
	cout << "Enter the repair status(1/0): " << endl;
	repair = check(0, 1);
}



