#include "csm.h"
#include "utils.h"
using namespace std;

int CS::getid()
{
	return id;
}

string CS::getname() const
{
	return name;
}

int CS::getworkshops() const
{
	return workshops;
}

int CS::geta_workshops() const
{
	return a_workshops;
}

int CS::getefficiency() const
{
	return efficiency;
}

void CS::setname(string& new_name)
{
	name = new_name;
}

void CS::setworkshops(int& new_workshops)
{
	workshops = new_workshops;
}

void CS::seta_workshops(int& new_a_workshops)
{
	a_workshops = new_a_workshops;
}

void CS::setefficiency(int& new_efficiency)
{
	efficiency = new_efficiency;
}

void CS::createcs()
{
	cout << "ID" <<id << endl;
	cout << "Enter the pipe name: " << endl;
	cin >> ws;
	getline(cin, name);
	cout << "Enter the station length: " << endl;
	workshops = check(1, 10000);
	cout << "Enter the station diameter : " << endl;
	a_workshops = check(1, 10000);
	cout << "Enter the repair status(1/0): " << endl;
	efficiency = check(0, 1);
	
}

