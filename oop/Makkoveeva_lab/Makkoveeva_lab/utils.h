#pragma once
#include <iostream>
using namespace std;

void PrintMenu();

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
    return value;
}