#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>   // For remove, rename, perror
using namespace std;

void data();
void view();
void search(string srollno);
void update();
void deleteRecord();

int main()
{
menu:
    int choice;
    cout << "\n-----------------------\n";
    cout << " Student Record System\n";
    cout << "-----------------------\n";
    cout << "1. Add New Student Record\n";
    cout << "2. View All Student Records\n";
    cout << "3. Search Student by Roll Number\n";
    cout << "4. Update Student GPA\n";
    cout << "5. Delete Student Record\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        data();
        goto menu;

    case 2:
        view();
        goto menu;

    case 3:
    {
        string srollno;
        cout << "Enter Roll Number to Search: ";
        cin >> srollno;
        search(srollno);
    }
    goto menu;

    case 4:
        update();
        goto menu;

    case 5:
        deleteRecord();
        goto menu;

    case 6:
        cout << "Exiting Program !\n";
        break;

    default:
        cout << "Invalid choice ! Try Again.\n";
        goto menu;
    }

    return 0;
}

void data()
{
    // Write each record as four consecutive lines.
    string name, dep, rollno;
    float gpa;
    cout << "Enter Student Name : ";
    cin >> ws;
    getline(cin, name);
    cout << "Enter Student Roll Number  : ";
    cin >> rollno;
    cout << "Enter Student Department : ";
    cin >> ws;
    getline(cin, dep);
    cout << "Enter Student GPA : ";
    cin >> gpa;

    // Open in append mode.
    ofstream data("students.txt", ios::app);
    if (data.is_open())
    {
        data << name << "\n";
        data << rollno << "\n";
        data << dep << "\n";
        data << gpa << "\n";
    }
    data.close();
}

void view()
{
    ifstream inFile("students.txt");
    if (!inFile.is_open())
    {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    bool fileEmpty = true;
    string name, rollno, dep, gpaStr;
    while (getline(inFile, name))
    {
        // Read one record: 4 lines (assume file is correctly formatted).
        if (!getline(inFile, rollno)) break;
        if (!getline(inFile, dep)) break;
        if (!getline(inFile, gpaStr)) break;

        cout << "Name: " << name
            << " | Roll no: " << rollno
            << " | Department: " << dep
            << " | GPA: " << gpaStr << endl;
        fileEmpty = false;
    }
    if (fileEmpty)
        cout << "No records to display. The file is empty.\n";

    inFile.close();
}

void search(string srollno)
{
    ifstream inFile("students.txt");
    if (!inFile.is_open())
    {
        cout << "Failed to open file for reading." << endl;
        return;
    }

    bool found = false;
    string name, rollno, dep, gpaStr;
    while (getline(inFile, name))
    {
        if (!getline(inFile, rollno)) break;
        if (!getline(inFile, dep)) break;
        if (!getline(inFile, gpaStr)) break;

        if (rollno == srollno)
        {
            cout << "Name: " << name
                << " | Roll no: " << rollno
                << " | Department: " << dep
                << " | GPA: " << gpaStr << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Roll Number Not Found!" << endl;

    inFile.close();
}

void update()
{
    string srollno;
    cout << "Enter Roll number to Update Record : ";
    cin >> srollno;

    ifstream read("students.txt");
    ofstream temp("temp.txt");

    if (!read.is_open() || !temp.is_open())
    {
        cout << "File error!" << endl;
        return;
    }

    bool updated = false;
    string name, rollno, dep, gpaStr;
    float gpa;

    while (getline(read, name))
    {
        if (!getline(read, rollno)) break;
        if (!getline(read, dep)) break;
        if (!getline(read, gpaStr)) break;

        // Convert GPA string to float.
        gpa = stof(gpaStr);

        if (rollno == srollno)
        {
            cout << "Enter Updated GPA: ";
            cin >> gpa;
            updated = true;
        }

        temp << name << "\n";
        temp << rollno << "\n";
        temp << dep << "\n";
        temp << gpa << "\n";
    }

    read.close();
    temp.close();

    remove("students.txt");
    if (rename("temp.txt", "students.txt") != 0)
        perror("Error renaming file");

    if (updated)
        cout << "Record updated successfully.\n";
    else
        cout << "Roll Number not found!\n";
}

void deleteRecord()
{
    string srollno;
    cout << "Enter Roll number to Delete Record : ";
    cin >> srollno;

    ifstream read("students.txt");
    ofstream temp("temp.txt");

    if (!read.is_open() || !temp.is_open())
    {
        cout << "File error!" << endl;
        return;
    }

    bool deleted = false;
    string name, rollno, dep, gpaStr;
    while (getline(read, name))
    {
        if (!getline(read, rollno)) break;
        if (!getline(read, dep)) break;
        if (!getline(read, gpaStr)) break;

        if (rollno == srollno)
        {
            deleted = true;
            continue;  // Skip this record.
        }

        temp << name << "\n";
        temp << rollno << "\n";
        temp << dep << "\n";
        temp << gpaStr << "\n";
    }

    read.close();
    temp.close();

    remove("students.txt");
    if (rename("temp.txt", "students.txt") != 0)
        perror("Error renaming file");

    if (deleted)
        cout << "Record deleted successfully.\n";
    else
        cout << "Roll Number not found!\n";
}

