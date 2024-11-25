#include "pipem.h"
#include "csm.h"
#include "utils.h"
#include <string>
#include <iostream>
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