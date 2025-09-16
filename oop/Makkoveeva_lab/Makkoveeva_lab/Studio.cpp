#include "Studio.h"
#include "Master.h"
#include "utils.h"
#include <iostream>
#include <fstream>

Beauty_studio::~Beauty_studio()
{
    for (Master* master : masters) {
        delete master;
    }
    masters.clear(); 
}

void Beauty_studio::add_master()
{
    Master* newMaster = new Master(); 
    newMaster->create_master();
    masters.push_back(newMaster);
    cout << "Master added" << endl;
}

void Beauty_studio::show_masters()
{
    if (masters.empty())
        cout << "There is no masters!" << endl;
    else
        for (const auto& master : masters)
        {
            master->show_info();
        }
}
