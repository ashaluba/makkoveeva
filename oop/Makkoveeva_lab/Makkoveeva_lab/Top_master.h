#pragma once
#include "Master.h"

using namespace std;

class Top_master_Makkoveeva : public Master_Makkoveeva {
private:
	wstring comp_courses;
	wstring phone_number;
public:
	Top_master_Makkoveeva();
	Top_master_Makkoveeva(wstring& name, int experience, wstring& speciality, wstring& comp_courses, wstring& phone_number);

	void create() override;
	void show_info() override;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<Master_Makkoveeva>(*this);
		ar& comp_courses;
		ar& phone_number;
	}
};

BOOST_CLASS_EXPORT_KEY(Top_master_Makkoveeva)