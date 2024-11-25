#include "csm.h"
#include "utils.h"
#include <string>
using namespace std;

int CS::maxid = 1;
int CS::getid()
{
	return id;
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
	maxid++;
	
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

void csmenu(unordered_map<int, CS>& stations)
{
	while (1) {
		cout << "1. Add station " << endl;
		cout << "2. Edit station " << endl;
		cout << "3. Delete station " << endl;
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
			break;
		};
		case 3:
		{
			break;
		};
		case 0:
		{
			return;
		};
		}
	}
}

