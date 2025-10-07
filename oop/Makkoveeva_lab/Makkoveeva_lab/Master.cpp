#include "Master.h"
#include "utils.h"
#include <iostream>
#include <fstream>
using namespace std;

Master::Master(wstring name, int experience, wstring speciality) : name(name), experience(experience), speciality(speciality) {}

void Master::create()
{
	wcout << "Enter master's name: " << endl;
	getline(wcin >> ws, name);
	wcout << "Enter master's experience : " << endl;
	experience = check(1, 40);
	wcout << "Enter master's speciality: " << endl;
	getline(wcin >> ws, speciality);
}

void Master::show_info()
{
	wcout << "Master's name: " << name << endl;
	wcout << "Master's experience: " << experience << endl;
	wcout << "Master's speciality: " << speciality << endl;
}

void Master::save(wofstream& out)
{
	out << name << endl;
	out << experience << endl;
	out << speciality << endl;
}

void Master::load(wifstream& in)
{
	getline(in, name);
	in >> experience;
	in.ignore(); 
	getline(in, speciality);
}

