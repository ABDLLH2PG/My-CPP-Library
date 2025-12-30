//My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace MyInputLib
{
	// ------------------------------------------------
	// String & Char:
	// ------------------------------------------------

	string ReadString(string Message)
	{
		string S1 = "";

		cout << Message << endl;
		getline(cin >> ws, S1);

		return S1;
	}

	char ReadChar(string Message)
	{
		char Character = 'a';
		cout << Message << endl;
		cin >> Character;

		return Character;
	}

	// ------------------------------------------------
	// Integers:
	// ------------------------------------------------

	int ReadNumber(string Message)
	{
		int Number;
		cout << Message << endl;
		cin >> Number;

		return Number;
	}

	bool ValidateNumberInRange(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	int ReadPositiveNumber(string Message)
	{
		int Number = 0;

		do
		{
			Number = ReadNumber(Message);

		} while (Number <= 0);

		return Number;
	}

	int ReadNumberInRange(int From, int To)
	{
		string Msg = "Please enter a number between " + to_string(From) + " and " + to_string(To) + ":";
		int Number = ReadNumber(Msg);

		while (!ValidateNumberInRange(Number, From, To))
		{
			Number = ReadNumber("Number is out of range, " + Msg);
		}

		return Number;
	}

	// ------------------------------------------------
	// Doubles:
	// ------------------------------------------------

	double ReadDoubleNumber(string Message)
	{
		double Number;
		cout << Message << endl;
		cin >> Number;
		return Number;
	}

	double ReadDoubleInRange(double From, double To, string Message)
	{
		double Number = ReadDoubleNumber(Message);

		while (Number < From || Number > To)
		{
			cout << "Number is out of range. ";
			Number = ReadDoubleNumber(Message);
		}
		return Number;
	}

	// ------------------------------------------------
	// Special Types:
	// ------------------------------------------------

	bool ReadConfirm(string Message)
	{
		char Answer = 'y';
		cout << Message << " (y/n)? ";
		cin >> Answer;

		return (Answer == 'y' || Answer == 'Y');
	}

}