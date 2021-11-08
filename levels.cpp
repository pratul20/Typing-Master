#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include ".\input.cpp"
#include <chrono>
#include ".\paragraph.cpp"

using namespace std;
using namespace std::chrono;

class Time
{
private:
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;
    int target;

public:
    Time() {}

    Time(int target)
    {
        this->target = target;
    }

    void startClock()
    {
        start = high_resolution_clock::now();
    }

    void stopClock()
    {
        stop = high_resolution_clock::now();
    }

    double getTime()
    {
        duration<double> elapsedTime = duration_cast<duration<double>>(stop - start);
        return elapsedTime.count();
    }

    int getTarget()
    {
        return target;
    }

    void setTarget(int target)
    {
        this->target = target;
    }

    virtual void forAbstract() = 0;

    void startsIn()
    {
        cout << "\nTo stop, press ^\n";
        cout << "Starting in 3... ";
        Sleep(1000);
        cout << "2... ";
        Sleep(1000);
        cout << "1... ";
        Sleep(1000);
        cout << endl;
    }
};

class ClassicMode : public Time
{
private:
    int level;
    int words;
    int errors;
    int total;
    int fixed;
    double avgAccuracy;

public:
    ClassicMode() {
        errors = 0;
        words = 0;
        total = 0;
        fixed = 0;
        avgAccuracy = 0.00;
    }

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
        int n = 0; 
        Paragraph para("easy");
        vector<string> lines = para.getParagraph();
        startClock();
        for(auto line: lines) {
            UserInput obj(line);
            obj.type();
            if(obj.isTerminated()) {
                break;
            }
            n++;
            updateDetails(obj);
            cout<<endl;
        } 
        stopClock();
        printDetails(n);
        double time = getTime();
        cout << "Time Taken: " << time << " seconds"<<endl;
    }

    void medium()
    {
        int n = 0; 
        Paragraph para("medium");
        vector<string> lines = para.getParagraph();
        startClock();
        for(auto line: lines) {
            UserInput obj(line);
            obj.type();
            if(obj.isTerminated()) {
                break;
            }
            n++;
            updateDetails(obj);
            cout<<endl;
        } 
        stopClock();
        printDetails(n);
        double time = getTime();
        cout << "Time Taken: " << time << " seconds"<<endl;
    }

    void hard()
    {
        int n = 0; 
        Paragraph para("hard");
        vector<string> lines = para.getParagraph();
        startClock();
        for(auto line: lines) {
            UserInput obj(line);
            obj.type();
            if(obj.isTerminated()) {
                break;
            }
            n++;
            updateDetails(obj);
            cout<<endl;
        } 
        stopClock();
        printDetails(n);
        double time = getTime();
        cout << "Time Taken: " << time << " seconds"<<endl;
    }

    void updateDetails(UserInput &obj) {
        errors += obj.getErrors();
        fixed += obj.getFixedErrors();
        total += obj.getTotal();
        avgAccuracy += obj.getAccuracy();
        words += obj.getWordCount();
    }

    void printDetails(int n) {
        cout << "\n\nErrors: "<< errors;
        cout << "\nFixed: " << fixed;
        cout << "\nTotal Entries: " << total;
        cout << "\nSpeed: " << (int) words*60/(int)getTime() << " wpm"; 
        cout << "\nAccuracy: " << (double) avgAccuracy/n << " %"<<endl;
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
