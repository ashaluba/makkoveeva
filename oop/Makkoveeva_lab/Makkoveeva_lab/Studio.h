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

class Beauty_studio
{
private:
	vector <shared_ptr<Master >> masters;
	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& masters;
	}
public:
	~Beauty_studio();
	void add_master(shared_ptr<Master> T);
	void show_masters();
	void save_to_file(ofstream& file);
	void load_from_file(ifstream& file);
	void clear();
};
