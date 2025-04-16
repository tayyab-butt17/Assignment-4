#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void record();
void view();
void search(string n);
void update();
void deleteRecord();

int main()
{
menu:
    int choice;
    cout << "\n-----------------------\n";
    cout << " PSL Management System\n";
    cout << "-----------------------\n";
    cout << "1. Add Player Record\n";
    cout << "2. View All Players\n";
    cout << "3. Search Player by Name or Team\n";
    cout << "4. Update Player Stats (Runs or Wickets)\n";
    cout << "5. Delete Player Record\n";
    cout << "6. Exit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        record();
        goto menu;
    case 2:
        view();
        goto menu;
    case 3:
    {
        string n;
    reenter_ttname:
        cout << "Enter Player Name or Team (no spaces allowed): ";
        cin >> ws;
        getline(cin, n);
        for (int i = 0; n[i] != '\0'; i++)
        {
            if (n[i] == ' ')
            {
                cout << "Spaces are not allowed in name or team. Please re-enter.\n";
                goto reenter_ttname;
            }
        }
        search(n);
        goto menu;
    }
    case 4:
        update();
        goto menu;
    case 5:
        deleteRecord();
        goto menu;
    case 6:
        cout << "Exiting Program!\n";
        break;
    default:
        cout << "Invalid choice! Try Again.\n";
        goto menu;
    }

    return 0;
}

void record()
{
    string pname, teamname, role;
    int truns, wickets;

reenter_name:
    cout << "Enter Player Name (no spaces allowed): ";
    cin >> ws;
    getline(cin, pname);
    for (int i = 0; pname[i] != '\0'; i++)
    {
        if (pname[i] == ' ')
        {
            cout << "Spaces are not allowed in name. Please re-enter.\n";
            goto reenter_name;
        }
    }

reenter_tname:
    cout << "Enter Team Name (no spaces allowed): ";
    cin >> ws;
    getline(cin, teamname);
    for (int i = 0; teamname[i] != '\0'; i++)
    {
        if (teamname[i] == ' ')
        {
            cout << "Spaces are not allowed in name. Please re-enter.\n";
            goto reenter_tname;
        }
    }

reenter_role:
    cout << "Enter Role (Batsman/Bowler/All-rounder)(no spaces allowed): ";
    cin >> ws;
    getline(cin, role);
    for (int i = 0; role[i] != '\0'; i++)
    {
        if (role[i] == ' ')
        {
            cout << "Spaces are not allowed in role. Please re-enter.\n"; // fixed message
            goto reenter_role;
        }
    }

    cout << "Enter Total Runs: ";
    cin >> truns;

    cout << "Enter Wickets: ";
    cin >> wickets;

    ofstream record("players.txt", ios::app);
    if (record.is_open())
    {
        record << pname << " " << teamname << " " << role << " " << truns << " " << wickets << "\n";
    }
    record.close();
}

void view()
{
    string pname, teamname, role;
    int truns, wickets;
    ifstream out("players.txt");

    if (out.is_open())
    {
        bool fileEmpty = true;
        while (out >> pname >> teamname >> role >> truns >> wickets)
        {
            cout << "Player's Name: " << pname << " | Team: " << teamname
                << " | Role: " << role << " | Runs: " << truns << " | Wickets: " << wickets << "\n";
            fileEmpty = false;
        }

        if (fileEmpty)
        {
            cout << "No records to display. The file is empty.\n";
        }
        out.close();
    }
    else
    {
        cout << "Failed to open the file for reading." << endl;
    }
}

void search(string n)
{
    ifstream searchplayer("players.txt");
    string pname, teamname, role;
    int truns, wickets;
    bool found = false;
    if (searchplayer.is_open())
    {
        while (searchplayer >> pname >> teamname >> role >> truns >> wickets)
        {
            if (n == pname || n == teamname)
            {
                cout << "Player's Name: " << pname << " | Team: " << teamname
                    << " | Role: " << role << " | Runs: " << truns << " | Wickets: " << wickets << "\n";
                found = true;
            }
        }
        if (!found)
        {
            cout << "Player Not Found!" << endl;
        }
        searchplayer.close();
    }
    else
    {
        cout << "Failed to open the file for searching." << endl;
    }
}

void update()
{
    string name;
reenter_pname:
    cout << "Enter Player's Name (Without Spaces) to Update Stats: ";
    cin >> ws;
    getline(cin, name);
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            cout << "Spaces are not allowed in name. Please re-enter.\n";
            goto reenter_pname;
        }
    }

    ifstream pstats("players.txt");
    ofstream temp("temp.txt");
    string pname, teamname, role;
    int truns, wickets;
    bool updated = false;

    if (pstats.is_open() && temp.is_open())
    {
        while (pstats >> pname >> teamname >> role >> truns >> wickets)
        {
            if (name == pname)
            {
                int ch;
            reenter:
                cout << "Enter 1 to update Runs or 2 for Wickets: ";
                cin >> ch;
                if (ch == 1)
                {
                    cout << "Enter updated Runs: ";
                    cin >> truns;
                    updated = true;
                }
                else if (ch == 2)
                {
                    cout << "Enter updated Wickets: ";
                    cin >> wickets;
                    updated = true;
                }
                else
                {
                    cout << "Invalid Choice. Re-enter.\n";
                    goto reenter;
                }
            }
            temp << pname << " " << teamname << " " << role << " " << truns << " " << wickets << "\n"; // always write
        }
        pstats.close();
        temp.close();

        remove("players.txt");
        if (rename("temp.txt", "players.txt") != 0)
        {
            perror("Error in renaming file");
        }

        if (updated)
            cout << "Record updated successfully.\n";
        else
            cout << "Player not found!\n";
    }
    else
    {
        cout << "Failed to open the file for updating." << endl;
    }
}

void deleteRecord()
{
    string name;
reenter_pname:
    cout << "Enter Player's Name (Without Spaces) to Delete Record: ";
    cin >> ws;
    getline(cin, name);
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] == ' ')
        {
            cout << "Spaces are not allowed in name. Please re-enter.\n";
            goto reenter_pname;
        }
    }

    ifstream pdel("players.txt");
    ofstream temp("temp.txt");
    string pname, teamname, role;
    int truns, wickets;
    bool deleted = false;

    if (pdel.is_open() && temp.is_open())
    {
        while (pdel >> pname >> teamname >> role >> truns >> wickets)
        {
            if (name == pname)
            {
                deleted = true;
                continue;
            }
            temp << pname << " " << teamname << " " << role << " " << truns << " " << wickets << "\n";
        }
        pdel.close();
        temp.close();

        remove("players.txt");
        if (rename("temp.txt", "players.txt") != 0)
        {
            perror("Error in renaming file");
        }

        if (deleted)
            cout << "Record deleted successfully.\n";
        else
            cout << "Player not found!\n";
    }
    else
    {
        cout << "Failed to open the file for deleting." << endl;
    }
}
