#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

class CS
{
private:
    
    int id;
    string name;
    int workshops = 0;
    int a_workshops;
    int efficiency;
public:
    CS();
    int getid();
    string getname();
    void createcs();
    void showcs();
    static int maxid;
    double getpersentofactiveworkshops();
    CS(ifstream& file);
    void savecs(ofstream& file);
    void editcs(int new_num);
    int getworkshops();
    int geta_workshops();
    void seta_workshops(int new_new);
    
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
void deletecs(unordered_map<int, CS>& stations);