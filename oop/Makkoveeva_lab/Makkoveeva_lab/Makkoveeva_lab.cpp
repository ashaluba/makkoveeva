#include "utils.h"
#include "Master.h"
#include "Studio.h"
#include <iostream>
using namespace std;



int main()
{
	Beauty_studio studio;
	int option = check(0, 4);
	while (1)
	{
		PrintMenu();
		
		switch (option)
		{
		case 1:
		{
			studio.add_master;
			break;
		}
		case 2:
		{
			for (auto& st : studio)
				cout << st << endl;
			break;
		}
		case 3:
		{
			/*ofstream fout;
			fout.open("data.txt", ios::out);
			if (fout.is_open())
			{
				fout << group.size() << endl;
				for (Student& st : group)
					SaveStudent(fout, st);
				fout.close();
			}
			break;*/
		}
		case 4:
		{
			/*ifstream fin;
			fin.open("data.txt", ios::in);
			if (fin.is_open())
			{
				int count;
				fin >> count;
				while (count--)
				{
					group.push_back(LoadStudent(fin));
				}
				fin.close();
			}
			break;*/
		}
		case 0:
		{
			return 0;
		}
		}
	}
	return 0;
}

