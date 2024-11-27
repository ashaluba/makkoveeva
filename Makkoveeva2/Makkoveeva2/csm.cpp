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
void CS::seta_workshops(int new_new) {
	this->a_workshops = new_new;
}
int CS::getworkshops() {
	return this->workshops;
}

int CS::geta_workshops()  {
	return this->a_workshops;
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
void edit_cs(unordered_map<int, CS>& stations) {
	int cs_id;
	int new_num;
	if (stations.empty()) {
		cout << "No CSS" << endl;
	}
	else {
		cout << "Enter id of cs to edit " << endl;
		cs_id = check(0, numeric_limits<int>::max());

		if (stations.count(cs_id) == 1) {
			while (1) {
				cout << "Enter new number of active workshops (0 to exit): ";
				cin >> new_num;
				if (new_num == 0) {
					break;
				}
				if (new_num >= 0 && new_num <= stations[cs_id].getworkshops()) {
					stations[cs_id].seta_workshops(new_num);
				}
				else {
					cout << "Active workshops must be between 0 and " << stations[cs_id].getworkshops() << endl;
				}
			}
		}
		else {
			cout << "No CS with this ID." << endl;
		}
	}
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
void CS::editcs(int new_num)
{
	this->a_workshops = new_num;
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
			edit_cs(stations);
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
