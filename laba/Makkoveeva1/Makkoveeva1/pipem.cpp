#include "pipem.h"
using namespace std;

void setname(string new_name)
{
	name = new_name;
}
void setdiameter(int new_diameter)
{
	diameter = new_diameter;
}
void setlength(int new_length)
{
	length = new_length;
}
void setstatus(bool new_repair)
{
	repair = new_repair;
}

int Pipe::getid()
{
	return id;
}
string getname()const
{
	return name;
}
int Pipe::getdiameter()const
{
	return diameter;
}
int Pipe::getlength()const
{
	return length;
}
int Pipe::getstatus()const
{
	return repair;
}
istream& operator>>(istream&in, Pipe&pipe)//create pipe
{
	cout << "ID"<<pipe.id<<endl;
	cout << "Enter the pipe name: " << endl;
	cin >> ws;
	getline(cin, pipe.name);
	cout << "Enter the pipe length: " << endl;
	pipe.length = check(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	pipe.diameter = check(1, 10000);
	cout << "Enter the repair status(1/0): " << endl;
	pipe.repair = check(0, 1);
	return in;
}


