#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int option;
    int name;
    int length;
    int diameter;
    string repair;
    cout << "1. Добавить трубу" << endl
        << "2. Добавить КС" << endl
        << "3. Просмотр всех объектов" << endl
        << "4. Редактировать трубу" << endl
        << "5. Редактировать КС" << endl
        << "6. Выход" << endl;
    cin >> option;

    switch (option)
    {
    case 1: //add pipe
    {

        cout << "Введите название:" << endl;
        cin >> name;
        cout << "Введите длину:" << endl;
        cin >> length;
        cout << "Введите диаметр:" << endl;
        cin >> diameter;
        cout << "Введите признак 'в ремонте':" << endl;
        cin >> repair;
        break;
    }
    case 2: //add cs
    {
        cout << "iwed" << endl;
        break;
    }
    case 3: //edit pipe
    {
        cout << "jdku" << endl;
        break;
    }
    case 4: //edit cs
    {
        cout << "jeiw" << endl;
        break;
    }
    case 5: //save
    {
        cout << "slwo" << endl;
        break;
    }
    }

}