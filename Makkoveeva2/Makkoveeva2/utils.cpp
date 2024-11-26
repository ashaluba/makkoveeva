#include "pipem.h"
#include "csm.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
void showall(unordered_map<int, Pipe> pipes, unordered_map<int, CS> stations)
{
	if (pipes.empty())
	{
		cout << "No pipes" << endl;
	}
	else
	{
		for (auto& pair : pipes)
		{
			cout << "Pipes" << endl;
			pair.second.showpipe();
		}
	}
	if (stations.empty())
	{
		cout << "No stations" << endl;
	}
	else
	{
		for (auto& pair : stations)
		{
			cout << "Stations" << endl;
			pair.second.showcs();
		}
	}
}
void save(unordered_map<int, Pipe>& pipes, unordered_map<int, CS>& stations)
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ofstream file(filename);
	if (file.is_open()) 
	{
		for (auto& pair : pipes) {
			pair.second.savepipe(file);
		}
		for (auto& pair : stations) {
			pair.second.savecs(file);
		}
		file.close();
		cout << "The data has been saved" << endl;
	}
	else {
		cout << "Error" << endl;
	}
}

void download(unordered_map<int, Pipe>& pipes, unordered_map<int, CS>& stations)
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ifstream file(filename);
	int countpipe = 0;
	int countcs = 0 ;
	if (file.is_open())
	{
		pipes.clear();
		stations.clear();
		string line;
		while (file>>line)
		{
			if (line == "Pipe") {
				load(file,pipes);
				++countpipe;
			}
			else if (line == "Station") {
				load(file,stations);
				++countcs;
			}
		}
		file.close();
		cout << "The data has been downloaded" << endl;
	}
	else 
	{
		cout << "Error opening file" << endl;
	}
	Pipe::maxid = countpipe;
	CS::maxid = countcs;
}
