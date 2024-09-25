#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Pipe
{
    string name = "None";
    float length ;
    int diameter;
    bool repair;
};
struct CS
{
    string name = "None";
    int workshops;
    int a_workshops;
    int efficiency;
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
int check_efficiency(int& efficiency_value)
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
int check_workshops(int& workshops_number, int& a_workshops_number)
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
    
    return bool_value;
}
void addpipe(Pipe& pipe)
{
    cout << "Enter the pipe name: " << endl;
    cin >> ws;
    getline(cin, pipe.name);
    cout << "Enter the pipe length: " << endl;
    cin>>pipe.length;
    while (cin.fail() || cin.peek() != '\n' || pipe.length <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a float format > 0\n";
        cin >> pipe.length;
    }
    cout << "Enter the pipe diameter : " << endl;
    check_int(pipe.diameter);
    cout << "Enter the repair status(1/0): " << endl;
    cin >> pipe.repair;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a boolean format\n";
        cin >> pipe.repair;
    }
}
void addCS(CS& station)
{
    cout << "Enter the station name: " << endl;
    cin >> ws;
    getline(cin, station.name);
    cout << "Enter the total number of workshops and then the number of active worckshops: " << endl;
    check_workshops(station.workshops,station.a_workshops);
    cout << "Enter the efficiency status(1-10): " << endl;
    check_efficiency(station.efficiency);
}
void printpipe(Pipe& pipe)
{
    cout << endl << "Your pipe" << endl;
    if (pipe.name == "None")
    {
        cout << "You haven't any pipes!\n";
    }
    else
    {
        cout << "Name: " << pipe.name 
             << "\tLength: " << pipe.length
             << "\tDiameter: " << pipe.diameter 
             << "\tRepair: " << pipe.repair << endl;
    }
}

void printCS(CS& station)
{
    cout << endl << "Your CS " << endl;
    if (station.name == "None")
    {
        cout << "You haven't any stations\n";
    }
    else
    {
        cout << "Name: " << station.name 
             << "\tWorkshops: " << station.workshops
             << "\tActive workshops: " << station.a_workshops 
             << "\tEfficiency of CS: " << station.efficiency << "/10" << endl;
    }
}
void editCS(CS& station)
{
    if (station.name == "None")
    {
        cout << "You haven't any stations to edit\n";
    }
    else
    {
        cout << "Enter a new number of workshops and active workshops" << endl;
        check_workshops(station.workshops, station.a_workshops);
    }
}
void editpipe(Pipe& pipe)
{
    if (pipe.name == "None")
    {
        cout << "You haven't any stations to edit\n";
    }
    else
    {
        cout << "Enter a repair status" << endl;
        check_bool(pipe.repair);
    }
}
int main()
{
    Pipe yourpipe;
    CS yourstation;
    ifstream pipe_file("pipe.txt");
    ifstream station_file("station.txt");
    
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
            addpipe(yourpipe);
            printpipe(yourpipe);
            break;
        }
        case 2:
        {
            addCS(yourstation);
            printCS(yourstation);
            break;
        }
        case 3:
        {
            printpipe(yourpipe);
            printCS(yourstation);
            break;
        }
        case 4:
        {
            editpipe(yourpipe);
            printpipe(yourpipe);
            break;
        }
        case 5:
        {
            editCS(yourstation);
            printCS(yourstation);
            break;
        }
        case 6:
        {
            cout << "slwo" << endl;
            break;
        }
        case 7:
        {
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