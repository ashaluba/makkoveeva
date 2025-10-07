#include "Top_master.h"
#include "utils.h"
#include <iostream>
#include <fstream>
using namespace std;

Top_master::Top_master() : Master() {}

Top_master::Top_master(wstring& name, int experience, wstring& speciality, wstring& comp_courses, wstring& phone_number):Master(name, experience, speciality), comp_courses(comp_courses), phone_number(phone_number){}

void Top_master::create()
{
	wcout << "Enter master's name: " << endl;
	getline(wcin >> ws, name);
	wcout << "Enter master's experience : " << endl;
	experience = check(1, 40);
	wcout << "Enter master's speciality: " << endl;
	getline(wcin >> ws, speciality);
	wcout << "Enter master's comppleted courses: " << endl;
	getline(wcin >> ws, comp_courses);
	wcout << "Enter master's phone number: " << endl;
	getline(wcin >> ws, phone_number);
}

void Top_master::show_info()
{
	wcout << "Master's name: " << name << endl;
	wcout << "Master's experience: " << experience << endl;
	wcout << "Master's speciality: " << speciality << endl;
	wcout << "Master's comppleted courses: " << comp_courses << endl;
	wcout << "Master's phone number: " << phone_number << endl;
}

void Top_master::load(wifstream& in)
{
	getline(in, name);
	in >> experience;
	in.ignore();
	getline(in, speciality);
	getline(in, comp_courses);
	getline(in, phone_number);
}

void Top_master::save(wofstream& out)
{
	out << name << endl;
	out << experience << endl;
	out << speciality << endl;
	out << comp_courses << endl;
	out << phone_number << endl;
}

