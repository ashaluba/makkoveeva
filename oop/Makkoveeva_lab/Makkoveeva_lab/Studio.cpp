#include "Studio.h"
#include "Master.h"
#include "Top_master.h"
#include "utils.h"
#include <iostream>
#include <fstream>

Beauty_studio_Makkoveeva::~Beauty_studio_Makkoveeva()
{
    clear();
}

void Beauty_studio_Makkoveeva::add_master(shared_ptr<Master_Makkoveeva> newMaster)
{
    newMaster->create();
    masters.push_back(newMaster);
    wcout << "Master added" << endl;
}

void Beauty_studio_Makkoveeva::show_masters()
{
    if (masters.empty())
        wcout << "There is no masters" << endl;
    else
        for (const auto& master : masters)
        {
            master->show_info();
        }
}

void Beauty_studio_Makkoveeva::load_from_file(ifstream& file)
{
    boost::archive::binary_iarchive ia(file);
    ia >> masters;
    wcout << L"Data loaded successfully" << endl;
}


void Beauty_studio_Makkoveeva::save_to_file(ofstream& file)
{
    boost::archive::binary_oarchive oa(file);
    oa << masters;
    wcout << L"Data saved successfully" << endl;
}


void Beauty_studio_Makkoveeva::clear()
{
    masters.clear();
    wcout << "All masters cleared" << endl;
}