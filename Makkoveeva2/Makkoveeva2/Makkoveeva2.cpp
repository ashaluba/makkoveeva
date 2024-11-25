#include "pipem.h"
#include "csm.h"
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
            << "1. Pipe's actions" << endl
            << "2. CS's actions" << endl
            << "3. Show all objects" << endl
            << "4. Save" << endl
            << "5. Download" << endl
            << "6. Exit " << endl;
        int option = check(1, 8);
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
            
            break;
        }
        case 5:
        {
            
            break;
        }
        case 6:
        {
            return 0;
            break;
        }
        }
    }
    return 0;

}
