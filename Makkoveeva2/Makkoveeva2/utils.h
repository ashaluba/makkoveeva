#pragma once
#include <iostream>
#include "pipem.h"
#include "csm.h"
#include <unordered_map>
#include <string>
using namespace std;

template <typename T>
T check(T min, T max)
{
    T value;
    while ((cin >> value).fail() || cin.peek() != '\n' || min > value || max < value)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a right number from "<<min<<" to "<<max<<"\n";
    }
    return value;
}

void showall(unordered_map<int, Pipe> pipes, unordered_map<int, CS> stations);
void save(unordered_map<int, Pipe>& pipes,  unordered_map<int, CS>& stations);

void download(unordered_map<int, Pipe>& pipes, unordered_map<int, CS>& stations);

template<typename T>
void load(ifstream& file, unordered_map<int, T>& map)
{
    T object(file);
    map.emplace(object.getid(), object);
}
