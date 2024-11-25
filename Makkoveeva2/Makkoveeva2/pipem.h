#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

class Pipe
{
private:
    static int maxid;
    int id;
    string name;
    double length;
    int diameter = 0;
    bool repair;
public:
    int getid();
    void createpipe();
    void showpipe();
};
template <typename T>
void showp(unordered_map<int, T>& map)
{
    for (auto& pair : map)
    {
        pair.second.showpipe();
    }
}
void pipemenu(unordered_map<int, Pipe>& pipes);


