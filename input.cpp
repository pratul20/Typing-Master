#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

class Time
{
private:
    inline static high_resolution_clock::time_point start = high_resolution_clock::now();
    inline static high_resolution_clock::time_point stop = high_resolution_clock::now();
    inline static int target = 0;

public:
    Time() {}

    static void startClock()
    {
        start = high_resolution_clock::now();
    }


    static void stopClock()
    {
        stop = high_resolution_clock::now();
    }

    static void lap() {
        stop = high_resolution_clock::now();
    }

    static double getTime()
    {
        duration<double> elapsedTime = duration_cast<duration<double>>(stop - start);
        return elapsedTime.count();
    }

    static int getTarget()
    {
        return target;
    }

    static void setTarget(int tar1)
    {
        target = tar1;
    }

    static void startsIn()
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

class UserInput: public Time
{
private:
    int errors;
    int mode;   // 0 for Classic; 1 for TimeAttack
    int timeFinished; 
    int wpm;
    int total;
    int fixed;
    int position;
    string s;
    char *typed;
    char current;
    double accuracy;
    int terminate;

public:
    UserInput(int mode, string str)
    {
        this->s = str;
        this->mode = mode;
        typed = new char[str.length()];
        accuracy = 0.00;
        position = 0;
        errors = 0;
        terminate = 0;
        timeFinished = 0;
        wpm = 0;
    }

    void type()
    {
        cout << endl << s << endl << endl;

        while (position != s.length())
        {

            if(mode == 1) {
                Time::lap();
                if(Time::getTime() > Time::getTarget()) {
                    timeFinished = 1;
                    break;
                }
            }

            current = getche();
            

            if (current == '^')
            {
                terminate = 1;
                break;
            }

            if (current == 8)
            {
                position--;
                continue;
            }

            else if (current != s[position])
            {
                errors++;
            }

            typed[position] = current;

            position++;
        }

    }

    int isTimeFinished() {
        return timeFinished;
    }

    int isTerminated() {
        return terminate;
    }

    int getErrors() {
        return errors;
    }

    int getTotal() {
        return (position == s.length() ? s.length() : position);
    }

    double getAccuracy()
    {
        double accu;
        if(position == s.length()) 
        {
            accu = (double) (s.length()-errors)*100/s.length();
        }

        else 
        {
            if(position!=0) {
                accu = (double) (position-errors)*100/position;
            }
            else
            {
                accu = 0;
            }
        }
        return accu;
    }

    int getFixedErrors() {
        int final_errors = 0 ;

        if(position == s.length())
        {
            for(int i=0;i<s.length();i++) {
                if(typed[i] != s[i]) {
                    final_errors++;
                }
            }
        }

        else 
        {
            for(int i=0;i<position;i++) {
                if(typed[i] != s[i]) {
                    final_errors++;
                }
            }
        }
        return errors-final_errors;
    }

    int getWordCount() {
        int count = 0;
        for(int i=0; i<position;i++) {
            if(typed[i] == ' ') {
                count++;
            }
        }
        return count;
    }

    ~UserInput() {
        delete(typed);
    }

};