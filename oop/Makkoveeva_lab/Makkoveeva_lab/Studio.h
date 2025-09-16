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
	void save_to_file(const wstring& file);
	void load_from_file(const wstring& file);
	void clear();
};
