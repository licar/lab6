// task1_CRectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Triangle.h"
#include "iostream"

using namespace std;

int main()
{
	while (!cin.eof())
	{
		double side1, side2, side3;
		cout << "Enter sides of triangle : " << endl;

		if (cin >> side1 && cin >> side2 && cin >> side3)			
		{
			try
			{
				CTriangle triangle(side1, side2, side3);
				cout << "Area : " << triangle.GetArea() << endl;
				cout << "Perimeter : " << triangle.GetPerimeter() << endl;		
			}
			catch (exception &e)
			{
				cout << e.what() << endl;
			}
		}
	}
}