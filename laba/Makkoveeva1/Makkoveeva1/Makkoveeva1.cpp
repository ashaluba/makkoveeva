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

//Pipe AddPipe()
//{
//    Pipe new_pipe;
//    cout << endl << "Adding a new pipe..." << endl;
//    cout << "Enter the name of the pipe: ";
//    cin.ignore();
//    getline(cin, new_pipe.pipe_name);
//    cout << "Enter the length of the pipe (in metres): ";
//    check_double(new_pipe.pipe_length);
//    cout << "Enter the pipe diameter (in millimetres): ";
//    check_int(new_pipe.pipe_diameter);
//    cout << "Enter the repair status: ";
//    check_bool(new_pipe.pipe_repair);
//    return new_pipe;
//}



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
            cout << "iwed" << endl;
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