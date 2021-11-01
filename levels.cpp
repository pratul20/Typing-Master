#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Time
{
private:
    int sec;
    int target;

public:
    Time()
    {
        sec = 0;
    }

    Time(int target)
    {
        sec = 0;
        this->target = target;
    }

    void tick()
    {
        if (sec < target)
        {
            sec++;
        }
    }

    int getSeconds()
    {
        return sec;
    }

    int getTarget()
    {
        return target;
    }

    void setSeconds(int sec)
    {
        this->sec = sec;
    }

    void setTarget(int target)
    {
        this->target = target;
    }

    virtual void forAbstract() = 0;

    void startsIn()
    {
        cout << "Starting in 3... ";
        Sleep(1000);
        cout<<"2... ";
        Sleep(1000);
        cout<<"1... \n";
        Sleep(1000);
    }
};

class ClassicMode : public Time
{
private:
    int level;

public:
    ClassicMode() {}

    void forAbstract() {}

    void menu()
    {
        cout << "\nSelect the level:-" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "Enter your choice: ";
        cin >> level;

        switch (level)
        {
        case 1:
            startsIn();
            easy();
            break;
        case 2:
            startsIn();
            medium();
            break;
        case 3:
            startsIn();
            hard();
            break;
        default:
            cout << "Invalid Choice Entered\n\n";
            menu();
            break;
        }
    }

    void easy()
    {
    }

    void medium()
    {
    }

    void hard()
    {
    }
};

class TimeAttackMode : public Time
{
private:
    int level;

public:
    TimeAttackMode() {}


    void forAbstract() {}

    void menu()
    {
        cout << "\nSelect the Time:-" << endl;
        cout << "1. 30 seconds" << endl;
        cout << "2. 60 seconds" << endl;
        cout << "3. 90 seconds" << endl;
        cout << "Enter your choice: ";
        cin >> level;

        switch (level)
        {
        case 1:
            startsIn();
            sec_30();
            break;
        case 2:
            startsIn();
            sec_60();
            break;
        case 3:
            startsIn();
            sec_90();
            break;
        default:
            cout << "Invalid Choice Entered\n\n";
            menu();
            break;
        }
    }

    void sec_30()
    {
    }

    void sec_60()
    {
    }

    void sec_90()
    {
    }
};
