#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void menu()
{
    cout << "Choose command" << endl
        << "1. Add pipe" << endl
        << "2. Add CS" << endl
        << "3. Show all objects" << endl
        << "4. Edit pipe" << endl
        << "5. Edit CS" << endl
        << "6. Save" << endl
        << "7. Download" << endl
        << "8. Exit " << endl;
}
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
bool check_status(bool& status)
{
    cin >> status;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a boolean format\n";
        cin >> status;
    }
    return status;
}
int check_int(int& int_value)
{
    cin >> int_value;
    while (cin.fail() || int_value <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an integer format  > 0\n";
        cin >> int_value;
    }
    return int_value;
}
int check_workshops(int& workshops_number, int& a_workshops_number)
{
    cin >> workshops_number;
    cin >> a_workshops_number;
    while (cin.fail() || workshops_number < a_workshops_number || workshops_number==0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nThe number of workshops must be >= then active workshops\n";
        cin >> workshops_number;
        cin >> a_workshops_number;
    }
    return workshops_number, a_workshops_number;
}
void createpipe(Pipe& pipe)
{
    cout << "Enter the pipe name: " << endl;
    cin >> ws;
    getline(cin, pipe.name);
    cout << "Enter the pipe length: " << endl;
    cin>>pipe.length;
    while (cin.fail() || pipe.length <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a float format > 0\n";
        cin >> pipe.length;
    }
    cout << "Enter the pipe diameter : " << endl;
    check_int(pipe.diameter);
    cout << "Enter the repair status(1/0): " << endl;
    check_status(pipe.repair);
}
void createCS(CS& station)
{
    cout << "Enter the station name: " << endl;
    cin >> ws;
    getline(cin, station.name);
    cout << "Enter the total number of workshops and then the number of active worckshops: " << endl;
    check_workshops(station.workshops,station.a_workshops);
    cout << "Enter the efficiency status(1-10): " << endl;
    cin>>station.efficiency;
    while (cin.fail() || station.efficiency <= 0 || station.efficiency > 10)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an int number from 1 to 10\n";
        cin >> station.efficiency;
    }
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
        cout << "You haven't any stations to edit";
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
        cout << "You haven't any pipes to edit";
    }
    else
    {
        cout << "Enter a repair status" << endl;
        check_status(pipe.repair);
    }
}
void savepipe(ofstream& fout, Pipe&pipe)
{
 
    if (pipe.name == "None")
    {
        fout << "You haven't any pipes";
    }
    else
    {
        fout << "Your pipe"<<endl;
        fout<<"Name:" << pipe.name << endl;
        fout << "Length:" << pipe.length << endl;
        fout << "Diameter:" << pipe.diameter << endl;
        fout << "Repair status:" << pipe.repair << endl;
    }
}
void saveCS(ofstream& fout, CS& station)
{

    if (station.name == "None")
    {
        fout << "You haven't any stations";
    }
    else
    {
        fout << "Your CS" << endl;
        fout << "Name:" << station.name << endl;
        fout << "Workshops:" << station.workshops << endl;
        fout << "Active workshops:" << station.a_workshops << endl;
        fout << "Efficiency of CS:" << station.efficiency << endl;
    }
}
int main()
{
    Pipe yourpipe;
    CS yourstation;
    
    int option;
    while (1) {
        menu();
        cin >> option;
        if (cin.fail() || option < 1 || option > 8)
        {
            cout << " There is no such command, enter an existing command" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
            continue;
        } 
        switch (option)
        {
        case 1:
        {
            createpipe(yourpipe);
            printpipe(yourpipe);
            break;
        }
        case 2:
        {
            createCS(yourstation);
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
            ofstream out_file;
            out_file.open("output.txt",ios::out);
            if (out_file.is_open())
            {
                savepipe(out_file, yourpipe);
                saveCS(out_file, yourstation);
                cout << "Information about your objects saved in file 'output.txt'" << endl;
            }
            
            break;
        }
        case 7:
        {
            break;
        }
        case 8:
        {
            return 0;
            break;
        }
        }
    }
    return 0;
}