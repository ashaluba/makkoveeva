#include <iostream>
#include <fstream>
using namespace std;

struct Pipe
{
    string name = "None";
    float length = 0.0;
    int diameter = 0;
    bool repair = false;
};
struct CS
{
    string name = "None";
    int workshops = 0;
    int a_workshops = 0;
    int efficiency = 0;
};
int check_int(int& int_value)
{
    cin >> int_value;
    while (cin.fail() || cin.peek() != '\n' || int_value <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an integer format  > 0\n";
        cin >> int_value;
    }
    return int_value;
}
float check_float(float& float_value)
{
    cin >> float_value;
    while (cin.fail() || cin.peek() != '\n' || float_value <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a float format > 0\n";
        cin >> float_value;
    }
    return float_value;
}
int check_int2(int& efficiency_value)
{
    cin >> efficiency_value;
    while (cin.fail() || cin.peek() != '\n' || efficiency_value <= 0 || efficiency_value > 10)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an int number from 1 to 10\n";
        cin >> efficiency_value;
    }
    return efficiency_value;
}
int check_int3(int& workshops_number, int& a_workshops_number)
{
    cin >> workshops_number;
    cin >> a_workshops_number;
    while (cin.fail() || cin.peek() != '\n' || workshops_number < a_workshops_number)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nThe number of workshops must be >= then active workshops\n";
        cin >> workshops_number;
        cin >> a_workshops_number;
    }
    return workshops_number, a_workshops_number;
}
bool check_bool(bool& bool_value)
{
    cin >> bool_value;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a boolean format\n";
        cin >> bool_value;
    }
    return bool_value;
}
Pipe AddPipe()
{
    Pipe new_pipe;
    cout << "Enter the pipe name: " << endl;
    cin >> new_pipe.name;
    cout << "Enter the pipe length: " << endl;
    check_float(new_pipe.length);
    cout << "Enter the pipe diameter : " << endl;
    check_int(new_pipe.diameter);
    cout << "Enter the repair status: " << endl;
    check_bool(new_pipe.repair);
    return new_pipe;
}
void PrintAddPipe(Pipe& new_pipe)
{
    cout << endl << "Your pipe" << endl;
    if (new_pipe.name == "None")
    {
        cout << "No pipes available!\n";
    }
    else
    {
        cout << "Name: " << new_pipe.name 
             << "\tLength: " << new_pipe.length
             << "\tDiameter: " << new_pipe.diameter 
             << "\tRepair: " << new_pipe.repair << endl;
    }
}

CS AddCS()
{
    CS new_station;
    cout << "Enter the station name: " << endl;
    cin >> new_station.name;
    cout << "Enter the total number of workshops and then the number of active worckshops: " << endl;
    check_int3(new_station.workshops,new_station.a_workshops);
    cout << "Enter the efficiency status: " << endl;
    check_int2(new_station.efficiency);
    return new_station;
}
void PrintAddCS(CS& new_station)
{
    cout << endl << "Your CS " << endl;
    if (new_station.name == "None")
    {
        cout << "You haven't any stations\n";
    }
    else
    {
        cout << "Name: " << new_station.name 
             << "\tWorkshops: " << new_station.workshops
             << "\tActive workshops: " << new_station.a_workshops 
             << "\tEfficiency of CS: " << new_station.efficiency << "/10" << endl;
    }
}
void EditCS(CS& new_station)
{
    if (new_station.name == "None")
    {
        cout << "You haven't any stations to edit\n";
    }
    else
    {
        cout << "Enter a new number of workshops and active workshops" << endl;
        check_int3(new_station.workshops, new_station.a_workshops);
    }
}
void EditPipe(Pipe& new_pipe)
{
    if (new_pipe.name == "None")
    {
        cout << "You haven't any stations to edit\n";
    }
    else
    {
        cout << "Enter a repair status" << endl;
        check_bool(new_pipe.repair);
    }
}
int main()
{
    Pipe pipe0;
    CS station0;
    int option;
    while (true) {
        cout << "Choose command" << endl
            << "1. Add pipe" << endl
            << "2. Add CS" << endl
            << "3. Show all objects" << endl
            << "4. Edit pipe" << endl
            << "5. Edit CS" << endl
            << "6. Save" << endl
            << "7. Download" << endl
            << "8. Exit " << endl;
        cin >> option;
        if (cin.fail() || option < 1 || option > 8)
        {
            cout << " There is no such command" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (option)
        {
        case 1:
        {
            pipe0 = AddPipe();
            PrintAddPipe(pipe0);
            break;
        }
        case 2:
        {
            station0 = AddCS();
            PrintAddCS(station0);
            break;
        }
        case 3:
        {
            PrintAddPipe(pipe0);
            PrintAddCS(station0);
            break;
        }
        case 4:
        {
            EditPipe(pipe0);
            PrintAddPipe(pipe0);
            break;
        }
        case 5:
        {
            EditCS(station0);
            PrintAddCS(station0);
            break;
        }
        case 6:
        {
            cout << "slwo" << endl;
            break;
        }
        case 7:
        {
            cout << "slwo" << endl;
            break;
        }
        case 8:
        {
            return false;
            break;
        }
        }
    }
    return 0;
}