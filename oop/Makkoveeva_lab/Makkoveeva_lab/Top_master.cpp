#include "Top_master.h"
#include "utils.h"
#include <iostream>
#include <fstream>
using namespace std;

Top_master_Makkoveeva::Top_master_Makkoveeva() : Master_Makkoveeva() {}

Top_master_Makkoveeva::Top_master_Makkoveeva(wstring& name, int experience, wstring& speciality, wstring& comp_courses, wstring& phone_number):Master_Makkoveeva(name, experience, speciality), comp_courses(comp_courses), phone_number(phone_number){}

void Top_master_Makkoveeva::create()
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

void Top_master_Makkoveeva::show_info()
{
	wcout << "Master's name: " << name << endl;
	wcout << "Master's experience: " << experience << endl;
	wcout << "Master's speciality: " << speciality << endl;
	wcout << "Master's comppleted courses: " << comp_courses << endl;
	wcout << "Master's phone number: " << phone_number << endl;
}
