#include "Studio.h"
#include "Master.h"
#include "utils.h"
#include <iostream>
#include <fstream>

void Beauty_studio::add_master()
{
	Master master;
	cin >> master;
	studio.push_back(master);
}
