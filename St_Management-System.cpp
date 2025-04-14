#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void data();
void view(ifstream&output);
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
    {
        data();
        goto menu;
    }

    case 2:
    {
        ifstream out("students.txt");
        view(out);  
        goto menu;
    }

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

    ofstream data("students.txt", ios::app);
    if (data.is_open())
    {
        data << name << " " << rollno << " " << dep << " " << gpa << "\n";
    }
    data.close();
}

void view(ifstream & out)
{
    string name, dep, rollno;
    float gpa;
    ifstream out1("students.txt");  

    if (out1.is_open())  
    {
        bool fileEmpty = true;  
        while (out1 >> name >> rollno >> dep >> gpa)
        {
            cout << "Name : " << name << " Roll no : " << rollno << " Department : " << dep << " GPA : " << gpa << endl;
            fileEmpty = false;  
        }

        if (fileEmpty) {
            cout << "No records to display. The file is empty.\n";
        }
        out1.close(); 
    }
    else
    {
        cout << "Failed to open the file for reading." << endl;  
    }
}

void search(string srollno)
{
    ifstream searchrollno("students.txt");
    string name, dep, rollno;
    float gpa;
    bool found = false;
    if (searchrollno.is_open())
    {
        while (searchrollno >> name >> rollno >> dep >> gpa)
        {
            if (rollno == srollno)
            {
                cout << "Name : " << name << " Roll no : " << rollno << " Department : " << dep << " GPA : " << gpa << endl;
                found = true;
            }
        }
        if (!found)
        {
            cout << "Roll Number Not Found!" << endl;
        }
    }
    else
    {
        cout << "Failed to open the file for searching." << endl;
    }

}

void update()
{
    string srollno;
    cout << "Enter Roll number to Update Record : ";
    cin >> srollno;

    ifstream read("students.txt");
    ofstream temp("temp.txt");
    string name, dep, rollno;
    float gpa;
    bool updated = false;

    if (read.is_open() && temp.is_open())
    {
        while (read >> name >> rollno >> dep >> gpa)
        {
            if (rollno == srollno)
            {
                cout << "Enter Updated GPA: ";
                cin >> gpa;
                updated = true;
            }
            // Removed the extra space before \n
            temp << name << " " << rollno << " " << dep << " " << gpa << "\n";
        }
        read.close();
        temp.close();

        remove("students.txt");
        if (rename("temp.txt", "students.txt") != 0)
        {
            perror("Error renaming file");
        }

        if (updated)
            cout << "Record updated successfully.\n";
        else
            cout << "Roll Number not found!\n";
    }
    else
    {
        cout << "Failed to open." << endl;
    }
}

void deleteRecord()
{
    string srollno;
    cout << "Enter Roll number to Delete Record : ";
    cin >> srollno;

    ifstream read("students.txt");
    ofstream temp("temp.txt");
    string name, dep, rollno;
    float gpa;
    bool deleted = false;

    if (read.is_open() && temp.is_open())
    {
        while (read >> name >> rollno >> dep >> gpa)
        {
            if (rollno == srollno)
            {
                deleted = true;
                continue;
            }
            // Removed the extra space before \n
            temp << name << " " << rollno << " " << dep << " " << gpa << "\n";
        }
        read.close();
        temp.close();

        remove("students.txt");
        if (rename("temp.txt", "students.txt") != 0)
        {
            perror("Error renaming file");
        }

        if (deleted)
            cout << "Record deleted successfully.\n";
        else
            cout << "Roll Number not found!\n";
    }
    else
    {
        cout << "Failed to open." << endl;
    }
}
