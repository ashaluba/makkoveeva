#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

class CS
{
private:
    static int maxid;
    int id;
    string name;
    int workshops = 0;
    int a_workshops;
    int efficiency;
public:
    int getid();
    void createcs();
    void showcs();
};
template <typename T>
void showc(unordered_map<int, T>& map)
{
    for (auto& pair : map)
    {
        pair.second.showcs();
    }
};
void csmenu(unordered_map<int, CS>& stations);