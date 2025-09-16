#include "Master.h"
#include "utils.h"
#include <iostream>
#include <fstream>
using namespace std;

void Master::create_master()
{
	cout << "Enter master's name: " << endl;
	getline(cin >> ws, name);
	cout << "Enter master's experience : " << endl;
	experience = check(1, 40);
	cout << "Enter master's speciality: " << endl;
	getline(cin >> ws, speciality);
}
void Master::show_info()
{
	cout << "Master's name: " << name << endl;
	cout << "Master's experience: " << experience << endl;
	cout << "Master's speciality: " << speciality << endl;
}