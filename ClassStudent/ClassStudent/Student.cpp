#include "stdafx.h"
#include "Student.h"


CStudent::CStudent(string name, string surname, string patronimyc, int age)
{
	if (!CheckIsValidName(name) || (!CheckIsValidName(surname)))
	{
		throw invalid_argument("Uncorrect name/surname");
	}
	if (!CheckIsValidAge(age))
	{
		throw out_of_range("Uncorrect age");
	}
	
	swap(m_name, name);
	swap(m_surname, surname);
	swap(m_patronimyc, patronimyc);
	swap(m_age, age);
}

CStudent::~CStudent()
{
}

void CStudent::Rename(string name, string surname, string patronimyc)
{
	if (!CheckIsValidName(name) || (!CheckIsValidName(surname)))
	{
		throw invalid_argument("Uncorrect name/surname");
	}

	swap(m_name, name);
	swap(m_surname, surname);
	swap(m_patronimyc, patronimyc);
}

void CStudent::SetAge(int age)
{
	if (!CheckIsValidAge(age))
	{
		throw out_of_range("Uncorrect age");
	}
	swap(m_age, age);
}

bool CStudent::CheckHasSpace(string const &name)
{
	for (auto letter : name)
	{
		if (letter == ' ')
		{
			return true;
		}
	}
	return false;
}

bool CStudent::CheckIsValidName(string const &name)
{
	if (name.length() == 0 || CheckHasSpace(name))
	{
		return false;
	}
	return true;
}

bool CStudent::CheckIsValidAge(int age)
{
	if (age < 14 || age > 60)
	{
		return false;
	}
	return true;
}

string CStudent::GetName() const
{
	return m_name;
}

string CStudent::GetSurname() const
{
	return m_surname;
}

string CStudent::GetPatronimyc() const
{
	return m_patronimyc;
}

int CStudent::GetAge() const
{
	return m_age;
}

