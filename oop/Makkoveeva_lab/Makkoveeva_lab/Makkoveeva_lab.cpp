#include "utils.h"
#include "Master.h"
#include "Studio.h"
#include <iostream>
using namespace std;

void PrintMenu()
{
	cout << "1. Input master" << endl
		<< "2. Print masters" << endl
		<< "3. Save to file" << endl
		<< "4. Load from file" << endl
		<< "5. Delete all masters" << endl
		<< "0. Exit" << endl
		<< "Choose action: ";
}

int main()
{
	Beauty_studio studio;
	while (true)
	{
		PrintMenu();
		int option = check(0, 5);
		switch (option)
		{
		case 1:
		{
			studio.add_master();
			break;
		}
		case 2:
		{
			studio.show_masters();
			break;
		}
		case 3:
		{
			studio.save_to_file("masters.txt");
			break;
		}
		case 4:
		{
			studio.load_from_file("masters.txt");
			break;
		}
		case 5:
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

