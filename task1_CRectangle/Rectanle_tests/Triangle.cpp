#pragma once
#include "stdafx.h"
#include "../task1_CRectangle/Triangle.h"
#include <stdexcept>

CTriangle::CTriangle(
	double side1, double side2, double side3)
	:m_side1(side1), m_side2(side2), m_side3(side3)
{
	CheckIsPositiveArgument(side1);
	CheckIsPositiveArgument(side2);
	CheckIsPositiveArgument(side3);

	if (!IsValid())
	{
		throw std::domain_error("Didn't create triangle");
	}
}


CTriangle::~CTriangle()
{
}

double CTriangle::GetSide1() const
{
	return m_side1;
}

double CTriangle::GetSide2() const
{
	return m_side2;
}

double CTriangle::GetSide3() const
{
	return m_side3;
}

double CTriangle::GetPerimeter() const
{
	return (m_side1 + m_side2 + m_side3);
}

double CTriangle::GetArea() const
{
	double const perimetersHalf = GetPerimeter() / 2;
	return sqrt(
		perimetersHalf *
		(perimetersHalf - m_side1) *
		(perimetersHalf - m_side2) *
		(perimetersHalf - m_side3)
		);
}

void CTriangle::CheckIsPositiveArgument(double side) const
{
	if (side < 0)
	{
		throw std::invalid_argument("Argument must not be a negative");
	}
}

bool CTriangle::CheckIsTooBigSide(
	double side1, double side2, double side3) const
{
	return (side1 > side2 + side3);
}

bool CTriangle::IsValid() const
{
	return (
		!CheckIsTooBigSide(m_side1, m_side2, m_side3) &&
		!CheckIsTooBigSide(m_side2, m_side3, m_side1) &&
		!CheckIsTooBigSide(m_side3, m_side1, m_side2)
		);
}