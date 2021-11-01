#include <bits/stdc++.h>
#include "C:\Users\rckle\Desktop\Assignment\SEM 3\OOPL Lab\Minor Project\levels.cpp"
#include <windows.h>
using namespace std;

class Menu
{
private:
    int choice;

public:
    void start()
    {
        cout << "************************************************************************************************" << endl;
        cout << "  _______                   _                     __  __                 _                 " << endl;
        cout << " |__   __|                 (_)                   |  \\/  |               | |                " << endl;
        cout << "    | |     _   _   _ __    _   _ __     __ _    | \\  / |   __ _   ___  | |_    ___   _ __ " << endl;
        cout << "    | |    | | | | | '_ \\  | | | '_ \\   / _` |   | |\\/| |  / _` | / __| | __|  / _ \\ | '__|" << endl;
        cout << "    | |    | |_| | | |_) | | | | | | | | (_| |   | |  | | | (_| | \\__ \\ | |_  |  __/ | |   " << endl;
        cout << "    |_|     \\__, | | .__/  |_| |_| |_|  \\__, |   |_|  |_|  \\__,_| |___/  \\__|  \\___| |_|   " << endl;
        cout << "             __/ | | |                   __/ |                                             " << endl;
        cout << "            |___/  |_|                  |___/                                              " << endl;
        cout << "************************************************************************************************" << endl;
        cout << "\n                                  Welcome to Typing Master                                     " << endl;
        cout << "\nSelect the Mode:-\n"
             << endl;
        cout << "1. Classic Mode" << endl;
        cout << "2. Time Attack Mode" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            modes(choice);
            break;
        case 2:
            modes(choice);
            break;
        case 3:
            cout << endl << endl;
            cout << " _____  _                    _     __   __              " << endl;
            cout << "|_   _|| |                  | |    \\ \\ / /              " << endl;
            cout << "  | |  | |__    __ _  _ __  | | __  \\ V /   ___   _   _ " << endl;
            cout << "  | |  | '_ \\  / _` || '_ \\ | |/ /   \\ /   / _ \\ | | | |" << endl;
            cout << "  | |  | | | || (_| || | | ||   <    | |  | (_) || |_| |" << endl;
            cout << "  \\_/  |_| |_| \\__,_||_| |_||_|\\_\\   \\_/   \\___/  \\__,_|" << endl<<endl<<endl;
            exit(0);
        }
    }

    void modes(int i)
    {
        if(i==1) {
            ClassicMode obj;
            obj.menu();
        }
        else if(i==2) {
            TimeAttackMode obj;
            obj.menu();
        }
    }
};
