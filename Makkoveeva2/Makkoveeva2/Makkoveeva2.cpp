#include "pipem.h"
#include "csm.h"
#include "filter.h"
#include "utils.h"
#include <string>
#include <chrono>
#include <format>
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;


int main()
{
    redirect_output_wrapper cerr_out(cerr);
    //string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now);
    ofstream logfile("log");
    if (logfile)
        cerr_out.redirect(logfile);
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
            << "0. Exit " << endl;
        int option = check(0, 5);
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
        case 0:
        {
            return 0;
            break;
        }
        }
    }
    return 0;

}
