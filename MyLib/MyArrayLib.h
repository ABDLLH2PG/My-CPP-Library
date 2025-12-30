//My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>

#include "MyInputLib.h"
#include "MyMathLib.h"
#include "MyUtilityLib.h"

using namespace std;

namespace MyArrayLib
{
    // ------------------------------------------------
    // 1. Input / Output Functions:
    // ------------------------------------------------

    void ReadArray(int& arrLength, int arr[100])
    {
        cout << "Enter number of elements:\n";
        cin >> arrLength;

        cout << "\nEnter array elements: \n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Element [" << i + 1 << "] : ";
            cin >> arr[i];
        }
        cout << endl;
    }

    void PrintArray(int arrLength, int arr[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void PrintStringArray(int arrLength, string arr[100])
    {
        cout << "\nArray elements:\n\n";
        for (int i = 0; i < arrLength; i++)
        {
            cout << "Array[" << i << "]: " << arr[i] << "\n";
        }
    }

    // ------------------------------------------------
    // 2. Filling & Generation Functions:
    // ------------------------------------------------

    void FillArrayWithRandomNumbers(int& arrLength, int arr[100])
    {
        cout << "Enter number of elements:\n";
        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = MyUtilityLib::RandomNumber(1, 100);
        }
    }

    void FillArrayFrom1ToN(int& arrLength, int arr[100])
    {
        cout << "How many elements ?\n";
        cin >> arrLength;

        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = i + 1;
        }
    }

    void FillArrayWithKeys(int arrLength, string arr[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            arr[i] = MyUtilityLib::GenerateKey();
        }
    }

    // ------------------------------------------------
    // 3. Search & Count Functions:
    // ------------------------------------------------

    int FindNumberPositionInArray(int arrLength, int arr[100], int Number)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] == Number)
                return i;
        }
        return -1;
    }

    bool IsNumberInArray(int arrLength, int arr[100], int Number)
    {
        return FindNumberPositionInArray(arrLength, arr, Number) != -1;
    }

    int TimesRepeated(int Number, int arrLength, int arr[100])
    {
        int count = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (Number == arr[i])
                count++;
        }
        return count;
    }

    // ------------------------------------------------
    // 4. Statistics & Math Functions:
    // ------------------------------------------------

    int SumArray(int arrLength, int arr[100])
    {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++)
        {
            Sum += arr[i];
        }
        return Sum;
    }

    float ArrayAverage(int arrLength, int arr[100])
    {
        return (float)SumArray(arrLength, arr) / arrLength;
    }

    int PrintMaxNumberInArray(int arrLength, int arr[100])
    {
        int MaxNumber = arr[0];
        for (int i = 1; i < arrLength; i++)
        {
            if (arr[i] > MaxNumber)
                MaxNumber = arr[i];
        }
        return MaxNumber;
    }

    int PrintMinNumberInArray(int arrLength, int arr[100])
    {
        int MinNumber = arr[0];
        for (int i = 1; i < arrLength; i++)
        {
            if (arr[i] < MinNumber)
                MinNumber = arr[i];
        }
        return MinNumber;
    }

    void SumOf2Array(int arrLength, int arr1[100], int arr2[100], int arrSum[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrSum[i] = arr1[i] + arr2[i];
        }
    }

    // ------------------------------------------------
    // 5. Counters Functions:
    // ------------------------------------------------

    int OddCount(int arrLength, int arr[100])
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 != 0) Counter++;
        }
        return Counter;
    }

    int EvenCount(int arrLength, int arr[100])
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] % 2 == 0) Counter++;
        }
        return Counter;
    }

    int PositiveCount(int arrLength, int arr[100])
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] >= 0) Counter++;
        }
        return Counter;
    }

    int NegativeCount(int arrLength, int arr[100])
    {
        int Counter = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] < 0) Counter++;
        }
        return Counter;
    }

    // ------------------------------------------------
    // 6. Array Manipulation:
    // ------------------------------------------------

    void ShuffleArray(int arrLength, int arr[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            MyUtilityLib::Swap(arr[MyUtilityLib::RandomNumber(1, arrLength) - 1], arr[MyUtilityLib::RandomNumber(1, arrLength) - 1]);
        }
    }

    void CopyArrayInReverseOrder(int arrLength, int arrSource[100], int arrDistination[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDistination[i] = arrSource[(arrLength - 1) - i];
        }
    }

    bool IsPalindromeArray(int arrLength, int arr[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] != (arr[arrLength - i - 1]))
            {
                return false;
            }
        }
        return true;
    }

    // ------------------------------------------------
    // 7. Dynamic Array Simulation:
    // ------------------------------------------------

    void AddArrayElement(int Number, int arr[100], int& arrLength)
    {
        arrLength++;
        arr[arrLength - 1] = Number;
    }

    void InputUserNumbersInArray(int arr[100], int& arrLength)
    {
        bool AddMore = true;
        do
        {
            AddArrayElement(MyInputLib::ReadNumber(""), arr, arrLength);
            cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
            cin >> AddMore;
        } while (AddMore);
    }

    void CopyArray(int arrLength, int arrSource[100], int arrDestination[100])
    {
        for (int i = 0; i < arrLength; i++)
        {
            arrDestination[i] = arrSource[i];
        }
    }

    void CopyArrayUsingAddArrayElement(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    // ------------------------------------------------
    // 8. Conditional Copy:
    // ------------------------------------------------

    void CopyOddNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (arrSource[i] % 2 != 0)
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }

    void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            if (MyMathLib::CheckPrime(arrSource[i]) == MyMathLib::enPrimNotPrime::Prime)
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }

    void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& arrDestinationLength)
    {
        for (int i = 0; i < SourceLength; i++)
        {
            if (!IsNumberInArray(arrDestinationLength, arrDestination, arrSource[i]))
            {
                AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
            }
        }
    }

}