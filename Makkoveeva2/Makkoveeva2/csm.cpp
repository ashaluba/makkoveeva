#include "csm.h"
#include "filter.h"
#include "utils.h"
#include <string>
#include <unordered_map>
using namespace std;

int CS::maxid = 0;


int CS::getid()
{
	return id;
}
string CS::getname()
{
	return name;
}
CS::CS()
{
	id = ++maxid;
	name = "None";
	workshops = 0;
	a_workshops = 0;
	efficiency = 0;
}
double CS::getpersentofactiveworkshops()
{
	double p = (a_workshops / workshops) * 100;
	return p;
}

void CS::createcs()
{
	cout << "Enter the station name: " << endl;
	getline(cin>>ws, name);
	cout << "Enter the number of workshops: " << endl;
	workshops = check(1, 10000);
	cout << "Enter the number of active workshops(must be < total workshops) " << endl;
	a_workshops = check(1, workshops);
	cout << "Enter the efficiency status(1-10): " << endl;
	efficiency = check(0, 10);
	id = maxid;
	
}


void CS::showcs()
{
	if (workshops == 0)
	{
		cout << "You don't have any stations\n";
	}
	else
	{
		cout << "ID " << id << endl;
		cout << "Name: " << name << endl;
		cout << " Workshops: " << workshops << endl;
		cout << " Active workshops: " <<a_workshops << endl;
		cout << " Efficiency of CS: " << efficiency << "/10" << endl;
	}
}

void CS::savecs(ofstream& file)
{
	file << "Station" << endl;
	file << id << endl;
	file << name << endl;
	file << workshops << endl;
	file << a_workshops << endl;
	file << efficiency << endl;
}
CS::CS(ifstream& file)
{
	file >> this->id;
	file.ignore(10000, '\n');
	getline(file >> ws, this->name);
	file >> this->workshops;
	file >> this->a_workshops;
	file >> this->efficiency;
}
void deletecs(unordered_map<int, CS>& stations)
{
	stations.clear();
	cout << "All stations deleted" << endl;
	return;
}

void csmenu(unordered_map<int, CS>& stations)
{
	while (1) {
		cout << "1. Add station " << endl;
		cout << "2. Edit station " << endl;
		cout << "3. Delete station " << endl;
		cout << "4. Filter" << endl;
		cout << "0. Exit" << endl;
		int option = check(0, 8);
		switch (option)
		{
		case 1:
		{
			CS p;
			p.createcs();
			stations.emplace(p.getid(), p);
			break;
		};
		case 2:
		{
			//maineditcs(stations);
			break;
		};
		case 3:
		{
			deletecs(stations);
			break;
		};
		case 4:
		{
			selectbyfilter(stations);
			break;
		};
		case 0:
		{
			return;
		};
		}
	}
}
