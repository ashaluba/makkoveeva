#pragma once
#include "Master.h"

using namespace std;

class Top_master : public Master {
private:
	wstring comp_courses;
	wstring phone_number;
public:
	Top_master();
	Top_master(wstring& name, int experience, wstring& speciality, wstring& comp_courses, wstring& phone_number);

	void create() override;
	void show_info() override;
	void load(wifstream& in) override;
	void save(wofstream& out) override;

	template<class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& boost::serialization::base_object<Master>(*this);
		ar& comp_courses;
		ar& phone_number;
	}
};

BOOST_CLASS_EXPORT_KEY(Top_master)