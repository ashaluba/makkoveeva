#pragma once
#include "utils.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

template<typename T, typename P>
using Filter = bool(*)(T& val, P param);
template<typename T>
bool checkbyname(T& val, string name)
{
	size_t pos = val.getname().find(name);
	if (pos != string::npos) return true;
	else return false;
}
bool checkbyrepair(Pipe& p, bool status);
bool checkbyactworkshops(CS& cs, double percent);

template<typename T, typename P>
unordered_set<int> findfilter(unordered_map<int, T>& map, Filter<T, P> f, P param)
{
	unordered_set<int> res;
	
	for (auto& [id, val] : map)
	{
		if (f(val, param))
			res.emplace(id);
	}
	return res;
}
//лемъеряъ рнкэйн с оепбнцн ббедеммнцн ID оепедекюрэ
template<typename T>
unordered_set<int> selectbyid(unordered_map<int, T>& map, unordered_set<int>& set)
{
	unordered_set<int> res;
	while (1)
	{
		cout << "1.Enter pipe's idto edit\n0.Exit" << endl;
		int option = check(0,1);
		switch (option)
		{
		case 1:
		{
			int id;
			cin >> id;
			if (set.size() == 0)
			{
				if (map.contains(id))
					res.emplace(id);
			}
			else
				if (map.contains(id) and set.contains(id))
					res.emplace(id);
			break;
		};
		case 0:
		{
			return res;
			break;
		};
		}
	}
	return res;
}
template<typename T>
void maineditpipe(unordered_map<int, T>& map)
{
	unordered_set<int> res = selectbyid(map, res);
	if (res.size() != 0)
	{
		cout << "Enter what status you want to set" << endl;
		bool new_rep = check(0, 1);
		for (const int& id : res) {
			map.find(id)->second.editPipe(new_rep);
		}
	}
	else
	{
		cout << "No objects" << endl;
	}
}
template<typename T>
void maineditcs(unordered_map<int, T>& map)
{
	unordered_set<int> res = selectbyid(map, res);
	if (res.size() != 0)
	{
		editselected(map, res);
	}
	else
	{
		cout << "No objects" << endl;
	}
}

unordered_set<int> selectbyfilter(unordered_map<int, CS>& map);
unordered_set<int> selectbyfilter(unordered_map<int, Pipe>& map);
template<typename T>
void editselected(unordered_map<int, T>& map, unordered_set<int>& set)
{
	cout << "1. Edit" << endl;
	cout << "2. Delete" << endl;
	cout << "3. Show selected" << endl;
	cout << "0. Exit" << endl;
	switch (check(0, 3))
	{
	case 1:
	{
		cout << "Input new repair: ";
		bool new_rep = check(0, 1);
		for (const int& id : set) {
			map.find(id)->second.editPipe(new_rep);
		}
		break;
	}
	case 2:
	{
		for (int id : set)
			map.erase(id);
		break;
	}
	case 3:
	{
		cout << "Selected pipes" << endl;
		for (int id : set)
		{
			map.find(id)->second.showpipe();
		}
		break;
	};
	case 0:
	{
		break;
	};
	}
}
void coutFoundWithId(unordered_set<int>& set);
