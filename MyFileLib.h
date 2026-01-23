// My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

namespace MyFileLib
{
    // Print all file content to console
    void PrintFileContent(string FileName)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::in); //Read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                cout << Line << endl;
            }

            MyFile.close();
        }
    }

    // Load file lines into a vector
    void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                vFileContent.push_back(Line);
            }

            MyFile.close();
        }
    }

    // Save vector content to file (overwrites file)
    void SaveVectorToFile(string FileName, const vector <string>& vFileContent)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::out); // Write Mode

        if (MyFile.is_open())
        {
            for (const string& Line : vFileContent)
            {
                if (Line != "")
                {
                    MyFile << Line << endl;
                }
            }

            MyFile.close();
        }
    }

    // Delete a specific record/line from file
    void DeleteRecordFromFile(string FileName, string Record)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string& Line : vFileContent)
        {
            if (Line == Record)
            {
                Line = "";
            }
        }

        SaveVectorToFile(FileName, vFileContent);
    }

    // Update a specific record/line in file
    void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string& Line : vFileContent)
        {
            if (Line == Record)
            {
                Line = UpdateTo;
            }
        }

        SaveVectorToFile(FileName, vFileContent);
    }

}