//My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace MyUtilityLib
{
	// --------------------------------------------------------------
	// System & Screen Utilities:
	// --------------------------------------------------------------
    
	void ResetScreen()
	{
		system("cls");
		system("color 0F");
	}

	enum ScreenColor { Green = 1, Yellow = 2, Red = 3 };

	void SetScreenColor(ScreenColor ScreenColor)
	{
		switch (ScreenColor)
		{
		case ScreenColor::Green:
			system("color 2F");
			break;
		case ScreenColor::Yellow:
			system("color 6F");
			break;
		case ScreenColor::Red:
			system("color 4F");
			break;
		}
	}
	
	// --------------------------------------------------------------
	// Formatting Utilities:
	// --------------------------------------------------------------
	
	string Tabs(short NumberOfTabs)
	{
		string t = "";
		for (int i = 1; i <= NumberOfTabs; i++)
		{
			t = t + "\t";
		}
		return t;
	}

	string ColumnSeparator(int i)
	{
		if (i < 10)
			return "   |";
		else
			return "  |";
	}

    // --------------------------------------------------------------
    // General Utilities (Swap, Random, Keys)
    // --------------------------------------------------------------

    void Swap(int& Num1, int& Num2)
    {
        int Temp;
        Temp = Num2;
        Num2 = Num1;
        Num1 = Temp;
    }

    void SeedRand()
    {
        srand((unsigned)time(NULL));
    }

    int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

    char GetRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
        case enCharType::SmallLetter:
            return (char)RandomNumber(97, 122);
        case enCharType::CapitalLetter:
            return (char)RandomNumber(65, 90);
        case enCharType::SpecialCharacter:
            return (char)RandomNumber(33, 47);
        case enCharType::Digit:
            return (char)RandomNumber(48, 57);
        default:
            return (char)RandomNumber(65, 90);
        }
    }

    string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    string GenerateKey()
    {
        string Key = "";
        Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
        Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
        return Key;
    }

    // --------------------------------------------------------------
    // Encryption / Decryption
    // --------------------------------------------------------------

    string EncryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    string DecryptText(string Text, short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

}