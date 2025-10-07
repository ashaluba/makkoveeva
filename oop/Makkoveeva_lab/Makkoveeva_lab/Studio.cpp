#include "Studio.h"
#include "Master.h"
#include "Top_master.h"
#include "utils.h"
#include <iostream>
#include <fstream>

Beauty_studio::~Beauty_studio()
{
    clear();
}

void Beauty_studio::add_master(shared_ptr<Master> T)
{
    shared_ptr<Master> newMaster = T;
    newMaster->create();
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

//void Beauty_studio::load_from_file(const wstring& file)
//{
//    wifstream infile(file);
//    clear();
//    int count;
//    infile >> count;
//    infile.ignore();
//    for (int i = 0; i < count; ++i) {
//        shared_ptr<Top_master>newMaster = make_shared<Master>();
//        newMaster->load(infile);
//        masters.push_back(newMaster);
//    }
//    wcout << "Data loaded " << endl;
//}
void Beauty_studio::load_from_file(ifstream& file)
{
    boost::archive::binary_iarchive ia(file);
    ia >> *this;
    wcout << L"Data loaded successfully" << endl;
}

//void Beauty_studio::save_to_file(const wstring& file)
//{
//    wofstream outfile(file);
//    outfile << masters.size() << endl;
//    for (const auto& master : masters) {
//        master->save(outfile);
//    }
//    wcout << "Data saved" << endl;
//}

void Beauty_studio::save_to_file(ofstream& file)
{
    boost::archive::binary_oarchive oa(file);
    oa << *this;
    wcout << L"Data saved successfully" << endl;
}


void Beauty_studio::clear()
{
    masters.clear();
    wcout << "All masters cleared" << endl;
}