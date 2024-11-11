#pragma once
#include <iostream>
#include <string>

class CS
{
public:
    int getid();
    string getname() const;
    int getworkshops() const;
    int getactworkshops() const;

private:
    string name;
    int workshops = 0;
    int a_workshops;
    int efficiency;
};