#pragma once
#include <string>

using namespace std;

class CStudent
{
public:
	CStudent(string name, string surname, string patronimyc, int age);
	~CStudent();
	string GetName() const;
	string GetSurname() const;
	string GetPatronimyc() const;
	int GetAge() const;
	void Rename(string name, string surname, string patronimyc);
	void SetAge(int age);
private:
	bool CheckIsValidName(string const &name);
	bool CheckIsValidAge(int age);
	bool CheckHasSpace(string const &name);

	string m_name, m_surname, m_patronimyc;
	int m_age;
};

