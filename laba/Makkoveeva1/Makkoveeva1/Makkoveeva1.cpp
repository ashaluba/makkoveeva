#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void menu()
{
    cout << "\nChoose command" << endl
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
    string name ;
    int length;
    int diameter=0;
    bool repair;
};
struct CS
{
    string name ;
    int workshops =0;
    int a_workshops;
    int efficiency;
};
int check_int(int min_int, int max_int)
{
    int value;
    while ((cin >> value).fail()||cin.peek()!='\n' || min_int > value || max_int < value)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a right format\n";
    }
    return value;
}

void createpipe(Pipe& pipe)
{
    cout << "Enter the pipe name: " << endl;
    cin >> ws;
    getline(cin, pipe.name);
    cout << "Enter the pipe length: " << endl;
    pipe.length=check_int(1,10000);
    cout << "Enter the pipe diameter : " << endl;
    pipe.diameter=check_int(1,10000);
    cout << "Enter the repair status(1/0): " << endl;
    pipe.repair=check_int(0,1);
}
void createCS(CS& station)
{
    cout << "Enter the station name: " << endl;
    cin >> ws;
    getline(cin, station.name);
    cout << "Enter the number of workshops" << endl;
    station.workshops = check_int(1, 10000);
    cout << "Enter the number of active workshops(must be < total workshops): " << endl;
    station.a_workshops=check_int(0,station.workshops);
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
void printpipe(const Pipe& pipe)//!!
{
    cout << endl << "Your pipe" << endl;
    if (pipe.diameter == 0)
    {
        cout << "You don't have any pipes!\n";
    }
    else
    {
        cout << "Name: " << pipe.name 
             << " Length: " << pipe.length
             << " Diameter: " << pipe.diameter 
             << " Repair: " << pipe.repair << endl;
    }
}
void printCS(const CS& station)//!!
{
    cout << endl << "Your CS " << endl;
    if (station.workshops == 0)
    {
        cout << "You don't have any stations\n";
    }
    else
    {
        cout << "Name: " << station.name 
             << " Workshops: " << station.workshops
             << " Active workshops: " << station.a_workshops 
             << " Efficiency of CS: " << station.efficiency << "/10" << endl;
    }
}
void editCS(CS& station)
{
    if (station.workshops == 0)
    {
        cout << "You don't have any stations to edit";
    }
    else
    {
        cout << "Enter a new number of active workshops( must be < total workshops)" << endl;
       station.a_workshops=check_int(0,station.workshops);
    }
}
void editpipe(Pipe& pipe)
{
    if (pipe.diameter == 0)
    {
        cout << "You don't have any pipes to edit";
    }
    else
    {
        cout << "Enter a repair status(0 or 1)" << endl;
        pipe.repair=check_int(0,1);
    }
}
void savepipe(ofstream& fout, Pipe&pipe)
{
    if (pipe.diameter == 0)
    {
        cout << "You don't  have any pipes to save \n";
    }
    else
    {
        fout << "Your pipe"<<endl;
        fout<< pipe.name << endl;
        fout << pipe.length << endl;
        fout << pipe.diameter << endl;
        fout << pipe.repair << endl;
        cout << "Information about your pipe saved in file 'data.txt'" << endl;
    }
}
void saveCS(ofstream& fout, CS& station)
{
    if (station.workshops == 0)
    {
        cout << "You don't have any stations to save";
    }
    else
    {
        fout << "Your CS" << endl;
        fout << station.name << endl;
        fout <<  station.workshops << endl;
        fout << station.a_workshops << endl;
        fout  << station.efficiency << endl;
        cout << "Information about your station saved in file 'data.txt'" << endl;
    }
}
void getpipe(ifstream& fin, Pipe& pipe)
{
    cout << "Your pipe" << endl;
    getline(fin, pipe.name);
    cout << "Name: ";
    cout << pipe.name;
    fin >> pipe.length;
    cout << " Length: " << pipe.length;
    fin >> pipe.diameter;
    cout << " Diameter : "<<pipe.diameter;
    fin >> pipe.repair;
    cout << " Repair status: " << pipe.repair << endl;;
}
void getCS(ifstream& fin, CS& station)
{
        cout << "\nYour CS" << endl;
        getline(fin, station.name);
        cout << "Name:";//!!
        cout << station.name;
        fin >> station.workshops;
        cout <<" Workshops:"<<station.workshops;
        fin >> station.a_workshops;
        cout << " Active workshops :"<<station.a_workshops;
        fin >> station.efficiency;
        cout << " Efficiency of CS:"<<station.efficiency<< endl;
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
            ofstream fout;
            fout.open("data.txt",ios::out);
            if (fout.is_open())
            {
                savepipe(fout, yourpipe);
                saveCS(fout, yourstation);
               
            }
            fout.close();
            break;
        }
        case 7:
        {
            ifstream fin("data.txt");
            string str;
            int flagp = 0;
            int flagc = 0;
            while (getline(fin, str))
            {
                if (str == "Your pipe") 
                {
                    getpipe(fin, yourpipe);
                    flagp += 1;
                    cout << "Data about pipe added" << endl;
                }
                if (str == "Your CS")
                {
                    getCS(fin, yourstation);
                    flagc += 1;
                    cout << "Data about cs added" << endl;
                }
                
             }
            if (flagp == 0)
            {
                cout << "No data about pipe in file" << endl;
            }
            if (flagc == 0)
            {
                cout << "No data about cs in file" << endl;
            }
            
            
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