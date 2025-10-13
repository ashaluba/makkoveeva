#pragma once
#include "Master.h"
#include "Top_master.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/export.hpp>

using namespace std;

class Beauty_studio_Makkoveeva
{
private:
	vector <shared_ptr<Master_Makkoveeva>> masters;
	
public:
	~Beauty_studio_Makkoveeva();
	void add_master(shared_ptr<Master_Makkoveeva> T);
	void show_masters();
	void save_to_file(ofstream& file);
	void load_from_file(ifstream& file);
	void clear();
};
