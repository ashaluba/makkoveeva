#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pipe
{
public:
    int getid();
    int getdiameter() const;
    int getlength() const;
    string getname() const;
    bool getstatus() const;

    void setname(string& new_name);
    void setlength(int& new_length);
    void setdiameter(int& new_diameter);
    void setstatus(bool& new_repair);

    void createpipe();


private:
    int id;
    string name;
    int length;
    int diameter = 0;
    bool repair=0;
};


