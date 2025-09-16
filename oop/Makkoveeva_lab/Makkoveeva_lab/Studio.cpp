#include "Studio.h"
#include "Master.h"
#include "utils.h"
#include <iostream>
#include <fstream>

Beauty_studio::~Beauty_studio()
{
    clear();
}

void Beauty_studio::add_master()
{
    Master* newMaster = new Master();
    newMaster->create_master();
    masters.push_back(newMaster);
    wcout << "Master added" << endl;
}

void Beauty_studio::show_masters()
{
    if (masters.empty())
        wcout << "There is no masters" << endl;
    else
        for (const auto& master : masters)
        {
            master->show_info();
        }
}

void Beauty_studio::load_from_file(const wstring& file)
{
    wifstream infile(file);
    clear();
    int count;
    infile >> count;
    infile.ignore();
    for (int i = 0; i < count; ++i) {
        Master* newMaster = new Master();
        newMaster->load(infile);
        masters.push_back(newMaster);
    }
    wcout << "Data loaded " << endl;
}

void Beauty_studio::clear()
{
    for (Master* master : masters) {
        delete master;
    }
    masters.clear();
    wcout << "All masters cleared" << endl;
}

void Beauty_studio::save_to_file(const wstring& file)
{
    wofstream outfile(file);
    outfile << masters.size() << endl;
    for (const auto& master : masters) {
        master->save(outfile);
    }
    wcout << "Data saved" << endl;
}

