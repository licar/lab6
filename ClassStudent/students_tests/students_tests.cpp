// students_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../ClassStudent/Student.h"

BOOST_AUTO_TEST_CASE(CanMakeStudent)
{
	CStudent student("max", "pox", "lox", 23);
	CStudent student1("dan", "pox", "lox", 60);
	CStudent student2("dan", "pox", "lox", 14);
	CStudent student3("max", "pox", "", 40);
}

BOOST_AUTO_TEST_CASE(CantMakeStudent)
{
	BOOST_CHECK_THROW(CStudent student("", "pox", "lox", 23), invalid_argument);
	BOOST_CHECK_THROW(CStudent student1("max", "", "lox", 40), invalid_argument);
	BOOST_CHECK_THROW(CStudent student2("max", "pox", "lox", 61), out_of_range);
	BOOST_CHECK_THROW(CStudent student3("max", "pox", "lox", 13), out_of_range);
	BOOST_CHECK_THROW(CStudent student("m x", "pox", "lox", 23), invalid_argument);
	BOOST_CHECK_THROW(CStudent student4(" ", "pox", "lox", 40), invalid_argument);
	BOOST_CHECK_THROW(CStudent student5("max", " ", "lox", 40), invalid_argument);
	BOOST_CHECK_THROW(CStudent student6("max", "p x", "lox", 40), invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestFieldsOfCStudent)
{
	CStudent student("max", "pox", "lox", 23);
	BOOST_CHECK_EQUAL(student.GetName(), "max");
	BOOST_CHECK_EQUAL(student.GetSurname(), "pox");
	BOOST_CHECK_EQUAL(student.GetPatronimyc(), "lox");
	BOOST_CHECK_EQUAL(student.GetAge(), 23);
}

BOOST_AUTO_TEST_CASE(TestCanSetName)
{
	CStudent student("lax", "koks", "vox", 33);
	student.Rename("max", "lax", "gaks");

	BOOST_CHECK_EQUAL(student.GetName(), "max");
	BOOST_CHECK_EQUAL(student.GetSurname(), "lax");
	BOOST_CHECK_EQUAL(student.GetPatronimyc(), "gaks");
}

BOOST_AUTO_TEST_CASE(TestCantSetName)
{
	CStudent student("lax", "koks", "vox", 33);
	{
		BOOST_CHECK_THROW(student.Rename("", "lax", "gaks"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "lax");
		BOOST_CHECK_EQUAL(student.GetSurname(), "koks");
		BOOST_CHECK_EQUAL(student.GetPatronimyc(), "vox");
	}
	{
		BOOST_CHECK_THROW(student.Rename("m x", "lax", "gaks"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "lax");
		BOOST_CHECK_EQUAL(student.GetSurname(), "koks");
		BOOST_CHECK_EQUAL(student.GetPatronimyc(), "vox");
	}
	{
		BOOST_CHECK_THROW(student.Rename(" sd", "lax", "gaks"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "lax");
		BOOST_CHECK_EQUAL(student.GetSurname(), "koks");
		BOOST_CHECK_EQUAL(student.GetPatronimyc(), "vox");
	}
	{
		BOOST_CHECK_THROW(student.Rename("sd", " ", "gaks"), invalid_argument);
		BOOST_CHECK_EQUAL(student.GetName(), "lax");
		BOOST_CHECK_EQUAL(student.GetSurname(), "koks");
		BOOST_CHECK_EQUAL(student.GetPatronimyc(), "vox");
	}
}

BOOST_AUTO_TEST_CASE(TestCanSetAge)
{
	CStudent student("lax", "koks", "vox", 33);
	{
		student.SetAge(21);
		BOOST_CHECK_EQUAL(student.GetAge(), 21);
	}
	{
		student.SetAge(60);
		BOOST_CHECK_EQUAL(student.GetAge(), 60);
	}
	{
		student.SetAge(14);
		BOOST_CHECK_EQUAL(student.GetAge(), 14);
	}
}

BOOST_AUTO_TEST_CASE(TestCantSetAge)
{
	CStudent student("lax", "koks", "vox", 33);
	{
		BOOST_CHECK_THROW(student.SetAge(61), out_of_range);
		BOOST_CHECK_EQUAL(student.GetAge(), 33);
	}
	{
		BOOST_CHECK_THROW(student.SetAge(13), out_of_range);
		BOOST_CHECK_EQUAL(student.GetAge(), 33);
	}
	{
		BOOST_CHECK_THROW(student.SetAge(-2), out_of_range);
		BOOST_CHECK_EQUAL(student.GetAge(), 33);
	}
}