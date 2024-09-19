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

int check_int(int& int_data)
{
    cin >> int_data;
    while (cin.fail() || cin.peek() != '\n' || int_data <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an integer data  > 0\n";
        cin >> int_data;
    }
    return int_data;
}
float check_float(float& float_data)
{
    cin >> float_data;
    while (cin.fail() || cin.peek() != '\n' || float_data <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a double data > 0\n";
        cin >> float_data;
    }
    return float_data;
}
bool check_bool(bool& bool_data)
{
    cin >> bool_data;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a boolean data\n";
        cin >> bool_data;
    }
    return bool_data;
}


Pipe AddPipe()
{
    Pipe new_pipe;
    cout << endl << "Adding a new pipe..." << endl;
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
    cout << endl << "Info about your pipe..." << endl;
    if (new_pipe.name == "None")
    {
        cout << "No pipes available!\n";
    }
    else
    {
        cout << "Name: " << new_pipe.name << "\tLength: " << new_pipe.length
            << "\tDiameter: " << new_pipe.diameter << "\tRepair: " << new_pipe.repair << endl;
    }
}

int main()
{
    Pipe pipe0;
   
    int option;
    while (true){
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
            cout << "jdku" << endl;
            break;
        }
        case 3: 
        {
            cout << "jeiw" << endl;
            break;
        }
        case 4: 
        {
            cout << "slwo" << endl;
            break;
        }
        case 5: 
        {
            cout << "slwo" << endl;
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