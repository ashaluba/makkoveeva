#pragma once
#include <iostream>
using namespace std;

template <typename T>
T check(T min, T max)
{
    T value;
    while ((cin >> value).fail() || cin.peek() != '\n' || min > value || max < value)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a right format\n";
    }
    cerr << value << endl;
    return value;
}
