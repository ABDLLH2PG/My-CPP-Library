//My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <cmath>
using namespace std;

namespace MyMathLib
{
	const float PI = 3.141592653589793238;

	// ------------------------------------------------
	// Enums Definitions:
	// ------------------------------------------------

	enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };
	enum enOddOrEven { Odd = 1, Even = 2 };
	enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

	// ------------------------------------------------
	// Basic Math Functions:
	// ------------------------------------------------

	float MyABS(float Number)
	{
		if (Number > 0)
			return Number;
		else
			return Number * -1;
	}

	float GetFractionPart(float Number)
	{
		return Number - int(Number);
	}

	float MyRound(float Number)
	{
		int IntPart;
		IntPart = int(Number);

		float FractionsPart = GetFractionPart(Number);

		if (abs(FractionsPart) >= 0.5)
		{
			if (Number > 0)
				return ++IntPart;
			else
				return --IntPart;
		}

		else
			return IntPart;
	}

	float MyFloor(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}

	float MyCeil(float Number)
	{
		if (abs(GetFractionPart(Number)) > 0)
		{
			if (Number > 0)
				return int(Number) + 1;
			else
				return int(Number);
		}
		else
			return Number;
	}

	int MySqrt(float Number)
	{
		return pow(Number, 0.5);
	}

	// ------------------------------------------------
	// Numbers Function:
	// ------------------------------------------------

	float CalculateHalfNumber(int Num)
	{
		return (float)Num / 2;
	}

	float SimpleCalculator(float Number1, float Number2, enOperationType OpType)
	{
		switch (OpType)
		{
		case enOperationType::Add:
			return Number1 + Number2;
		case enOperationType::Subtract:
			return Number1 - Number2;
		case enOperationType::Multiply:
			return Number1 * Number2;
		case enOperationType::Divide:
			return Number1 / Number2;
		default:
			return 0;
		}
	}
	
	int MaxOf2Numbers(int Num1, int Num2)
	{
		if (Num1 > Num2)
			return Num1;
		else
			return Num2;
	}

	int MaxOf3Numbers(int Num1, int Num2, int Num3)
	{
		return MaxOf2Numbers(MaxOf2Numbers(Num1, Num2), Num3);
	}

	int SumOfDigits(int Number)
	{
		int Sum = 0, Remainder = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Sum = Sum + Remainder;
		}

		return Sum;
	}

	int ReverseNumber(int Number)
	{
		int Remainder = 0, Number2 = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;
	}

	int CountDigitFrequency(short DigitToCheck, int Number)
	{
		int FreqCount = 0, Remainder = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;

			if (DigitToCheck == Remainder)
			{
				FreqCount++;
			}
		}

		return FreqCount;
	}

	bool IsPalindromeNumber(int Number)
	{
		return Number == ReverseNumber(Number);
	}

	// ------------------------------------------------
	// Check Numbers Function:
	// ------------------------------------------------

	enOddOrEven CheckOddOrEven(int Number)
	{
		if (Number % 2 != 0)
			return enOddOrEven::Odd;
		else
			return enOddOrEven::Even;
	}

	enPrimNotPrime CheckPrime(int Number)
	{
		if (Number <= 1) return enPrimNotPrime::NotPrime;

		int M = round(Number / 2);

		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimNotPrime::NotPrime;
		}

		return enPrimNotPrime::Prime;
	}

	bool isPerfectNumber(int Number)
	{
		int Sum = 0;

		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}

		return Number == Sum;
	}

	// ------------------------------------------------
	// Advanced Math Logic:
	// ------------------------------------------------

	long Power(int Base, int Exponent)
	{
		if (Exponent == 0)
		{
			return 1;
		}

		long Result = 1;

		for (int i = 1; i <= Exponent; i++)
		{
			Result = Result * Base;
		}

		return Result;
	}

	long Factorial(int Number)
	{
		if (Number < 0)
			return 0;

		long Result = 1;

		for (int Counter = Number; Counter >= 1; Counter--)
		{
			Result = Result * Counter;
		}

		return Result;
	}

	// ------------------------------------------------
	// Area Function:
	// ------------------------------------------------

	float CalculateRectangleArea(float Width, float Length)
	{
		return Width * Length;
	}

	float RectangleAreaBySideAndDiagonal(float SideLength, float Diagonal)
	{
		return SideLength * sqrt(pow(Diagonal, 2) - pow(SideLength, 2));
	}

	float CalculateTriangleArea(float Base, float Height)
	{
		return (Base / 2) * Height;
	}

	float CircleArea(float Radius)
	{
		return pow(Radius, 2) * PI;
	}

	float CircleAreaByDiameter(float Diameter)
	{
		return (PI * pow(Diameter, 2)) / 4;
	}

	float CircleAreaInscribedInSquare(float SquareSide)
	{
		return (PI * pow(SquareSide, 2)) / 4;
	}

	float CircleAreaByCircumference(float Circumference)
	{
		return pow(Circumference, 2) / (4 * PI);
	}

	float CalculateCircleAreaInscribedInIsoscelesTriangle(float TriangleSide, float TriangleBase)
	{
		return PI * (pow(TriangleBase, 2) / 4) * ((2 * TriangleSide - TriangleBase) / (2 * TriangleSide + TriangleBase));
	}

	float CalculateCircumCircleAreaByTriangleSides(float SideA, float SideB, float SideC)
	{
		float SemiPerimeter = (SideA + SideB + SideC) / 2;
		float Radius = (SideA * SideB * SideC) / (4 * sqrt(SemiPerimeter * (SemiPerimeter - SideA) * (SemiPerimeter - SideB) * (SemiPerimeter - SideC)));
		return PI * pow(Radius, 2);
	}
	
}