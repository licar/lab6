// Rectanle_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../task1_CRectangle/Triangle.h"

using namespace std;

BOOST_AUTO_TEST_CASE(CanCreateNormalTriangle)
{
	CTriangle t(3, 2, 1);
}

BOOST_AUTO_TEST_CASE(CantCreateTriangleWithNegativeSides)
{
	BOOST_CHECK_THROW(CTriangle t(-42, 0, 2), invalid_argument);
	BOOST_CHECK_THROW(CTriangle t(2, -12, 2), invalid_argument);
	BOOST_CHECK_THROW(CTriangle t(25, -1, -1), invalid_argument);
	BOOST_CHECK_THROW(CTriangle t(-11, -3, -3), invalid_argument);
}

BOOST_AUTO_TEST_CASE(CanCreateDegenerateTriangle)
{
	CTriangle t(4, 2, 3); 
	CTriangle t1(7, 5, 3);
	CTriangle t2(1, 1, 2);
}

BOOST_AUTO_TEST_CASE(CanCreateRightDegenerateTriangle)
{
	CTriangle t(0, 2, 2);
	CTriangle t1(3, 0, 3);
	CTriangle t2(1, 1, 0);
	CTriangle t3(0, 0, 0);
}

BOOST_AUTO_TEST_CASE(CantCreateImpossibleTriangle)
{
	BOOST_CHECK_THROW(CTriangle t(5, 2, 2), domain_error);
	BOOST_CHECK_THROW(CTriangle t(7, 15, 7), domain_error);
	BOOST_CHECK_THROW(CTriangle t(13, 13, 42), domain_error);
}

BOOST_AUTO_TEST_CASE(TestSideProperties)
{
	CTriangle t(43, 55, 13);
	BOOST_CHECK_EQUAL(t.GetSide1(), 43);
	BOOST_CHECK_EQUAL(t.GetSide2(), 55);
	BOOST_CHECK_EQUAL(t.GetSide3(), 13);
}

BOOST_AUTO_TEST_CASE(TestPerimeter)
{
	BOOST_CHECK_EQUAL(CTriangle(1, 2, 3).GetPerimeter(), 6);
	BOOST_CHECK_EQUAL(CTriangle(2, 4, 2).GetPerimeter(), 8);
	BOOST_CHECK_EQUAL(CTriangle(0, 2, 2).GetPerimeter(), 4);
}

BOOST_AUTO_TEST_CASE(TestArea)
{
	BOOST_CHECK_EQUAL(CTriangle(3, 4, 5).GetArea(), 6);
	BOOST_CHECK_EQUAL(CTriangle(3, 6, 3).GetArea(), 0);
	BOOST_CHECK_EQUAL(CTriangle(1, 1, 0).GetArea(), 0);
	BOOST_CHECK_EQUAL(CTriangle(0, 0, 0).GetArea(), 0);
}