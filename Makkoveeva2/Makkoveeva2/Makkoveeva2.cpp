#include "pipem.h"
#include "csm.h"
#include "filter.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


int main()
{
    unordered_map<int, Pipe> pipes;
    unordered_map<int, CS> stations;
    while (1)
    {
        cout << "\nChoose command" << endl
            << "1. Pipe commands" << endl
            << "2. CS commands" << endl
            << "3. Show all objects" << endl
            << "4. Save" << endl
            << "5. Download" << endl
            << "6. Search" << endl//ВЫБИРАЕМ С ПОМОЩЬЮ ФИЛЬТРА КАКИЕ-ТО ТРУБЫ, А ПОТОМ ПРИМЕНЯЕМ ДЕЙСТВИЕ КО ВСЕМ ВЫБРАННЫМ
            << "0. Exit " << endl;
        int option = check(0, 8);
        switch (option)
        {
        case 1:
        {
            pipemenu(pipes);
            break;
        }
        case 2:
        {
            csmenu(stations);
            break;
        }
        case 3:
        {
            showall(pipes, stations);
            break;
        }
        case 4:
        {
            save(pipes, stations);
            break;
        }
        case 5:
        {
            download(pipes, stations);
            break;
        }
        case 6:
        {
            break;
        }
        case 0:
        {
            return 0;
            break;
        }
        }
    }
    return 0;

}
