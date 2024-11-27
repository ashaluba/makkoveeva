#include "filter.h"
#include "csm.h"
#include "pipem.h"
#include <unordered_map>

using namespace std;

bool checkbyrepair(Pipe& p, bool status)
{
	return p.getrepair() == status;
}
bool checkbyactworkshops(CS& cs, double percent)
{
	if(abs(cs.getpersentofactiveworkshops()-percent)<=5)
	return cs.getpersentofactiveworkshops();
}

unordered_set<int> selectbyfilter(unordered_map<int, Pipe>& map)
{
	unordered_set<int> res;
	cout << "Choose filter:" << endl;
	cout << "1. Name" << endl;
	cout<<"2. Repair status" << endl;
	switch (check(1, 2))
	{
	case 1:
	{
		cout << "Enter name: ";
		string name;
		getline(cin >> ws, name);
		res = findfilter(map, checkbyname, name);
		editselected(map, res);
		break;
	}
	case 2:
	{
		cout << "Enter status: "; 
		bool status = check(0, 1);
		res = findfilter(map, checkbyrepair, status);
		editselected(map, res);
		break;
	}
	default:
		break;
	}
	return res;
}

unordered_set<int> selectbyfilter(unordered_map<int, CS>& map)
{
	unordered_set<int> res;
	cout << "Choose filter:" << endl;
	cout << "1. Name" << endl;
	cout << "2. Percent of active workshops " << endl;
	switch (check(1, 2))
	{
	case 1:
	{
		cout << "Enter name: "; 
		string name;
		getline(cin >> ws, name);
		res = findfilter(map, checkbyname, name);
		cout << "Selected station" << endl;
		for (int id : res)
		{
			map.find(id)->second.showcs();
		}
		break;
	}
	case 2:
	{
		cout << "Enter %: "; 
		double percent = check(0.0, 100.0);
		res = findfilter(map, checkbyactworkshops, percent);
		cout << "Selected station" << endl;
		for (int id : res)
		{
			map.find(id)->second.showcs();
		}
		break;
		break;
	}
	}
	return res;
}
void coutFoundWithId(unordered_set<int>& set)
{
	cout << "Found objects with id: ";
	for (int id : set)
		cout << id << " ";
	cout << endl;
}