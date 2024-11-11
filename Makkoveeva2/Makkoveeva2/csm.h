#pragma once
#include <iostream>
#include <string>
using namespace std;

class CS
{
public:
    int getid();
    int getworkshops() const;
    int geta_workshops() const;
    string getname() const;
    int getefficiency() const;

    void setname(string& new_name);
    void setworkshops(int& new_workshops);
    void seta_workshops(int& new_a_workshops);
    void setefficiency(int& new_efficiency);

    void createcs();
private:
    int id;
    string name;
    int workshops = 0;
    int a_workshops;
    int efficiency;
};

