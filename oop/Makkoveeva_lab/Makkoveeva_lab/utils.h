#pragma once
#include <iostream>
using namespace std;

void PrintMenu()
{
    cout << "1. Input master" << endl
        << "2. Print master" << endl
        << "3. Save to file" << endl
        << "4. Load from file" << endl
        << "0. Exit" << endl
        << "Choose action: ";
}

template <typename T>
T check(T min, T max)
{
    T value;
    while ((cin >> value).fail() || cin.peek() != '\n' || min > value || max < value)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a right number from " << min << " to " << max << "\n";
    }
    cerr << value << endl;
    return value;
}