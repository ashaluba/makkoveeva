#pragma once
#include <iostream>
#include <string>
using namespace std;

class Master
{
private:
	//во второй лабе добавить сюда название салона как класс-потомок
	string name;
	int experience;
	string speciality;
public:
	void create_master();
	void show_info();
	void save(ofstream& out);
	void load(ifstream& in);
};

