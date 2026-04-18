// My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "MyUtilityLib.h"

using namespace std;

namespace MyMatrixLib
{
    // -----------------------------------------------------------------
    // 1. Filling & Generation Functions
    // -----------------------------------------------------------------

    void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                arr[i][j] = MyUtilityLib::RandomNumber(1, 100);
            }
        }
    }

    void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
    {
        short Counter = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                Counter++;
                arr[i][j] = Counter;
            }
        }
    }

    // -----------------------------------------------------------------
    // 2. Printing & Formatting Functions
    // -----------------------------------------------------------------

    void PrintMatrix(int arr[3][3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                printf(" %0*d     ", 2, arr[i][j]);
            }
            cout << "\n";
        }
    }

    void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MiddleRow = Rows / 2;
        for (int j = 0; j < Cols; j++)
        {
            printf(" %0*d   ", 2, arr[MiddleRow][j]);
        }
        cout << "\n";
    }

    void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
    {
        short MiddleCol = Cols / 2;
        for (int i = 0; i < Rows; i++)
        {
            printf(" %0*d   ", 2, arr[i][MiddleCol]);
        }
        cout << "\n";
    }

    // -----------------------------------------------------------------
    // 3. Summation & Statistics Functions (Rows, Cols, Matrix)
    // -----------------------------------------------------------------

    int RowSum(int arr[3][3], short RowNumber, short Cols)
    {
        int Sum = 0;
        for (short j = 0; j < Cols; j++)
        {
            Sum += arr[RowNumber][j];
        }
        return Sum;
    }

    void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << "\n";
        }
    }

    void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            arrSum[i] = RowSum(arr, i, Cols);
        }
    }

    int ColSum(int arr[3][3], short Rows, short ColNumber)
    {
        int Sum = 0;
        for (short i = 0; i < Rows; i++)
        {
            Sum += arr[i][ColNumber];
        }
        return Sum;
    }

    void PrintEachColSum(int arr[3][3], short Rows, short Cols)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << " Col " << (j + 1) << " Sum = " << ColSum(arr, Rows, j) << "\n";
        }
    }

    void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
    {
        for (int j = 0; j < Cols; j++)
        {
            arrSum[j] = ColSum(arr, Rows, j);
        }
    }

    int SumOfMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int Sum = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                Sum += Matrix1[i][j];
            }
        }
        return Sum;
    }

    // -----------------------------------------------------------------
    // 4. Matrix Operations (Transpose, Multiply)
    // -----------------------------------------------------------------

    void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                arrTransposed[i][j] = arr[j][i];
            }
        }
    }

    void MultiplyTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                MatrixResults[i][j] = (Matrix1[i][j] * Matrix2[i][j]);
            }
        }
    }

    
    // -----------------------------------------------------------------
    // 5. Search & Finding Functions
    // -----------------------------------------------------------------

    short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
    {
        short NumberCount = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] == Number) NumberCount++;
            }
        }
        return NumberCount;
    }

    bool IsNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] == Number) return true;
            }
        }
        return false;
    }

    void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                int Number = Matrix1[i][j];
                if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
                {
                    cout << setw(3) << Number << "     ";
                }
            }
        }
        cout << endl;
    }

    int MinNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int Min = Matrix1[0][0];
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] < Min) Min = Matrix1[i][j];
            }
        }
        return Min;
    }

    int MaxNumberInMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        int Max = Matrix1[0][0];
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] > Max) Max = Matrix1[i][j];
            }
        }
        return Max;
    }

    // -----------------------------------------------------------------
    // 6. Comparison & Boolean Checks
    // -----------------------------------------------------------------

    bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        return (SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols));
    }

    bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                    return false;
            }
        }
        return true;
    }

    bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != 1) return false;
                else if (i != j && Matrix[i][j] != 0) return false;
            }
        }
        return true;
    }

    bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int FirstDiagElement = Matrix[0][0];
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != FirstDiagElement) return false;
                else if (i != j && Matrix[i][j] != 0) return false;
            }
        }
        return true;
    }

    bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        short MatrixSize = Rows * Cols;
        // Count zeros (0) to check sparsity
        return (CountNumberInMatrix(Matrix1, 0, Rows, Cols) >= (MatrixSize / 2));
    }

    bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols / 2; j++)
            {
                if (Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
}