// My GitHub account: github.com/ABDLLH2PG
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include "MyStringLib.h"

using namespace std;

string ClientsFileName = "";

namespace MyFileLib
{
    // ---------------------------------------------------------
    // 1. Data Structure Definitions
    // ---------------------------------------------------------

    struct stClient
    {
        string AccountNumber = "";
        string PinCode = "";
        string Name = "";
        string Phone = "";
        double AccountBalance = 0.0;
        bool MarkForDelete = false;
    };

    // ---------------------------------------------------------
    // 2. Data Conversion Functions (Record <-> Line)
    // ---------------------------------------------------------

    string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";

        stClientRecord += Client.AccountNumber + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += Client.Name + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
    {
        stClient Client;

        vector <string> vClientData;
        vClientData = MyStringLib::SplitString(Line, Seperator);

        Client.AccountNumber = vClientData[0];
        Client.PinCode = vClientData[1];
        Client.Name = vClientData[2];
        Client.Phone = vClientData[3];
        Client.AccountBalance = stod(vClientData[4]); // cast string to double

        return Client;
    }

    // ---------------------------------------------------------
    // 3. Generic File Utilities
    // ---------------------------------------------------------

    void PrintFileContent(string FileName)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::in); // Read Mode

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

    void AddDataLineToFile(string FileName, string stDataLine)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    // ---------------------------------------------------------
    // 4. Client-Specific Management (UI & Logic)
    // ---------------------------------------------------------

    stClient ReadNewClient()
    {
        stClient Client;

        cout << "Enter Account Number? ";
        getline(cin >> ws, Client.AccountNumber);

        cout << "Enter PinCode? ";
        getline(cin, Client.PinCode);

        cout << "Enter Name? ";
        getline(cin, Client.Name);

        cout << "Enter Phone? ";
        getline(cin, Client.Phone);

        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;

        return Client;
    }

    void PrintClientCard(stClient Client)
    {
        cout << "\nThe following are the Client details:\n";

        cout << "\nAccount Number: " << Client.AccountNumber;
        cout << "\nPin Code      : " << Client.PinCode;
        cout << "\nName          : " << Client.Name;
        cout << "\nPhone         : " << Client.Phone;
        cout << "\nAccount Balance: " << Client.AccountBalance;
    }

    void AddNewClient()
    {
        stClient Client;
        Client = ReadNewClient();
        AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
    }

    void AddClients()
    {
        char AddMore = 'Y';
        do
        {
            system("cls");
            cout << "Adding New Client:\n\n";

            AddNewClient();
            cout << "\nClient Added Successfully, do you want to add more Client? Y/N? ";
            cin >> AddMore;

        } while (toupper(AddMore) == 'Y');
    }

    vector <stClient> LoadClientsDataFromFile(string FileName)
    {
        vector <stClient> vClients;

        fstream MyFile;
        MyFile.open(FileName, ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            stClient Client;

            while (getline(MyFile, Line))
            {
                Client = ConvertLineToRecord(Line);
                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    void PrintfClientRecord(stClient& Client)
    {
        cout << "| " << left << setw(15) << Client.AccountNumber;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(40) << Client.Name;
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }

    void PrintAllClientsData(vector <stClient>& vClients)
    {
        cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";

        cout << "\n________________________________________________________________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n________________________________________________________________________________________________\n" << endl;

        for (stClient& Client : vClients)
        {
            PrintfClientRecord(Client);
            cout << endl;
        }

        cout << "\n________________________________________________________________________________________________\n" << endl;
    }

    // ---------------------------------------------------------
    // 5. Search, Update & Delete Operations
    // ---------------------------------------------------------

    bool FindClientByAccountNumber(string AccountNumber, vector <stClient> vClients, stClient& Client)
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                Client = C;
                return true;
            }
        }
        return false;
    }

    bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <stClient>& vClients)
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.MarkForDelete = true;
                return true;
            }
        }
        return false;
    }

    vector <stClient> SaveClientsDataToFile(string FileName, vector <stClient> vClients)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out); // overWrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (stClient C : vClients)
            {
                if (C.MarkForDelete == false)
                {
                    DataLine = ConvertRecordToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
        return vClients;
    }

    bool DeleteClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
    {
        stClient Client;
        char Answer = 'n';

        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);

            cout << "\n\nAre you sure you want delete this client? y/n ? ";
            cin >> Answer;

            if (tolower(Answer) == 'y')
            {
                MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
                SaveClientsDataToFile(ClientsFileName, vClients);

                // Refresh Clients
                vClients = LoadClientsDataFromFile(ClientsFileName);

                cout << "\n\nClient Deleted Successfully.";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
        }
        return false;
    }

    stClient ChangeClientRecord(string AccountNumber)
    {
        stClient Client;

        Client.AccountNumber = AccountNumber;

        cout << "\n\nEnter PinCode? ";
        getline(cin >> ws, Client.PinCode);

        cout << "Enter Name? ";
        getline(cin, Client.Name);

        cout << "Enter Phone? ";
        getline(cin, Client.Phone);

        cout << "Enter AccountBalance? ";
        cin >> Client.AccountBalance;

        return Client;
    }

    bool UpdateClientByAccountNumber(string AccountNumber, vector <stClient>& vClients)
    {
        stClient Client;
        char Answer = 'n';

        if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        {
            PrintClientCard(Client);

            cout << "\n\nAre you sure you want update this client? y/n ? ";
            cin >> Answer;

            if (tolower(Answer) == 'y')
            {
                for (stClient& C : vClients)
                {
                    if (C.AccountNumber == AccountNumber)
                    {
                        C = ChangeClientRecord(AccountNumber);
                        break;
                    }
                }

                SaveClientsDataToFile(ClientsFileName, vClients);

                cout << "\n\nClient Update Successfully.";
                return true;
            }
        }
        else
        {
            cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
            return false;
        }
        return false;
    }
}