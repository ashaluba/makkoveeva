#pragma once
#include <iostream>
#include <string>
using namespace std;

class Master
{
private:
	//�� ������ ���� �������� ���� �������� ������ ��� �����-�������
	wstring name;
	int experience;
	wstring speciality;
public:
	void create_master();
	void show_info();
	void save(wofstream& out);
	void load(wifstream& in);
};

