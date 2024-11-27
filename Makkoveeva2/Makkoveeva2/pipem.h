#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

class Pipe
{
private:

    int id;
    int length;
    double diameter = 0;
    bool repair;
public:
    Pipe();
    int getid();
    string getname();
    bool getrepair();
    void createpipe();
    void showpipe();
    static int maxid;
    Pipe(ifstream& file);
    void savepipe(ofstream& file);
    string name;
    void editpipe(bool new_rep);
   
    

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
void deletep(unordered_map<int, Pipe>& pipes);


