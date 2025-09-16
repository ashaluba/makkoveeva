#pragma once
#include "Master.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Beauty_studio
{
private:
	vector <Master*> masters;
public:
	~Beauty_studio();
	void add_master();
	void show_masters();
};

