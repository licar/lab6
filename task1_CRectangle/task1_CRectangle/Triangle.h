#pragma once
class CTriangle
{
public:
	CTriangle(double side1, double size2, double side3);
	~CTriangle();
	
	double GetSide1() const;
	double GetSide2() const;
	double GetSide3() const;
	double GetArea() const;
	double GetPerimeter() const;
private:
	double m_side1;
	double m_side2;
	double m_side3;

	bool IsValid() const;
	bool CheckIsTooBigSide (double side1, double side2, double side3) const;
	void CheckIsPositiveArgument(double side) const;


};

