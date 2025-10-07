#pragma once
#include <iostream>
#include <string>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>

using namespace std;

class Master_Makkoveeva
{
protected:
	wstring name;
	int experience;
	wstring speciality;

public:
	virtual ~Master_Makkoveeva() = default;
	Master_Makkoveeva() : name(L""), experience(0), speciality(L"") {}
	Master_Makkoveeva(wstring name, int experience, wstring speciality);
	virtual void create();
	virtual void show_info();

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& name;
		ar& experience;
		ar& speciality;
	}
};

BOOST_CLASS_EXPORT_KEY(Master_Makkoveeva)