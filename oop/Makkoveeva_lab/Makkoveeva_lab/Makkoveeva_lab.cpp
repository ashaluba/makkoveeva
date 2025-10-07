#include "utils.h"
#include "Top_master.h"
#include "Master.h"
#include "Studio.h"
#include <iostream>
#include <fstream> 
#include <locale>
#include <boost/serialization/access.hpp>

using namespace std;

BOOST_CLASS_EXPORT_IMPLEMENT(Master_Makkoveeva)
BOOST_CLASS_EXPORT_IMPLEMENT(Top_master_Makkoveeva)

void setupLocale() {
	setlocale(LC_ALL, "rus");
	locale::global(locale("rus_rus.866"));
	wcin.imbue(locale("rus_rus.866"));
	wcout.imbue(locale("rus_rus.866"));
}

void PrintMenu()
{
	wcout << "1. Input master" << endl
		<< "2. Input top-masters" << endl
		<< "3. Print masters" << endl
		<< "4. Save to file" << endl
		<< "5. Load from file" << endl
		<< "6. Delete all masters" << endl
		<< "0. Exit" << endl
		<< "Choose action: ";
}

int main()
{
	setupLocale();
	Beauty_studio_Makkoveeva studio;
	while (true)
	{
		PrintMenu();
		int option = check(0, 6);
		switch (option)
		{
		case 1:
		{
			studio.add_master(make_shared<Master_Makkoveeva>());
			break;
		}
		case 2:
		{
			studio.add_master(make_shared<Top_master_Makkoveeva>());
			break;
		}
		case 3:
		{
			studio.show_masters();
			break;
		}
		case 4:
		{
			ofstream file("masters.txt", ios::binary);
			studio.save_to_file(file);
			break;
		}
		case 5:
		{
			ifstream file("masters.txt", ios::binary);
			if (file.is_open()) {
				studio.load_from_file(file);
			}
			else {
				wcout << L"File not found!" << endl;
			}
			break;
		}
		case 6:
		{
			studio.clear();
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}
	return 0;
}
