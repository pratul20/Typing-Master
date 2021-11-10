#include <bits/stdc++.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include ".\input.cpp"
#include ".\users.cpp"
#include <chrono>
#include ".\paragraph.cpp"

using namespace std;
using namespace std::chrono;

void typingMaster();
class Report {
    private:
        int words;
        int errors;
        int total;
        int fixedErr;
        double avgAccuracy;
        double time;
    
    public: 
        Report() {
            errors = 0;
            words = 0;
            total = 0;
            fixedErr = 0;
            avgAccuracy = 0.00;
            time = 0.00;
        }

        int getWords() {
            return words;
        }

        int getErrors() {
            return errors;
        }

        int getTotal() {
            return total;
        }

        int getFixedErr() {
            return fixedErr;
        }

        double getAvgAccuracy() {
            return avgAccuracy;
        }

        double getTime() {
            return time;
        }

        void setWords(int words) {
            this -> words = words;
        }

        void setErrors(int errors) {
            this -> errors = errors;
        }

        void setTotal(int total) {
            this -> total = total;
        }

        void setFixedErr(int fixedErr) {
            this -> fixedErr = fixedErr;
        }

        void setAvgAccuracy(double avgAccuracy) {
            this -> avgAccuracy = avgAccuracy;
        }

        void setTime(double time) {
            this -> time = time;
        }
        
        void updateDetails(UserInput &obj) 
        {
            errors += obj.getErrors();
            fixedErr += obj.getFixedErrors();
            total += obj.getTotal();
            avgAccuracy += obj.getAccuracy();
            words += obj.getWordCount();
        }

        void printDetails(int n, Users &userObj, string &playerName, int mode) 
        {
            double accuracy = (double) avgAccuracy/n;
            int wpm = (int) words*60/(int)getTime();
            cout << endl << endl;
            cout << "\t   Results" << endl;
            cout << "******************************" << endl;
            cout << setw(10) << "Errors"<< setw(4) << "|" << setw(6) << errors << endl;
            cout << setw(10) << "Fixed"<< setw(4) << "|" << setw(6) << fixedErr << endl;
            cout << setw(10) << "Speed"<< setw(4) << "|" << setw(6) << wpm << endl;
            cout << setw(10) << "Accuracy"<< setw(4) << "|" << setw(6) << fixed << setprecision(2) << accuracy << " %" << endl;
            userObj.updateUserInfo(playerName, accuracy, wpm);
            userObj.updateScores(playerName, wpm, mode);
        }
};

class ClassicMode: public Time
{
private:
    int level;
    string playerName;
    Users userObj;

public:
    ClassicMode(string playerName) {
        this->playerName = playerName;
    }

    void menu()
    {
        cout << "\nSelect the level:-" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;
        cout << "4. Back To Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> level;

        switch (level)
        {
        case 1:
            easy();
            break;
        case 2:
            medium();
            break;
        case 3:
            hard();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice Entered\n\n";
            menu();
            break;
        }
    }

    void takeTest(string difficulty, int mode) 
    {
        system("cls");
        typingMaster();
        cout << "\n                                  Classic Mode (" << difficulty << ")" <<endl;
        Time::startsIn();
        int n = 0; 
        Paragraph para(difficulty);
        vector<string> lines = para.getParagraph();
        Report myReport;
        Time::startClock();
        for(auto line: lines) {
            UserInput obj(0, line);
            n++;
            obj.type();
            myReport.updateDetails(obj);
            if(obj.isTerminated()) {
                cout<<"\n\n***************";
                cout<<"Test Terminated";
                cout<<"***************";
                break;
            }
            cout << " (" << lines.size()-n << " lines Remaining)";
            cout << endl;
        } 
        Time::stopClock();
        double time = Time::getTime();
        myReport.setTime(time);
        myReport.printDetails(n, userObj, playerName, mode);
        cout << setw(10) << "Time Taken"<< setw(4) << "|" << setw(6) << fixed << setprecision(2) << time << " seconds" << endl;
        pressEnter();
    }

    void easy()
    {
        takeTest("easy", 1);
    }

    void medium()
    {
        takeTest("medium", 2);
    }

    void hard()
    {
        takeTest("hard", 3);
    }

    friend void pressEnter();

};

class TimeAttackMode: public Time
{
private:
    int level;
    string playerName;
    Users userObj;

public:
    TimeAttackMode(string playerName) {
        this->playerName = playerName;
    }
    
    void menu()
    {
        cout << "\nSelect the Time:-" << endl;
        cout << "1. 30 seconds" << endl;
        cout << "2. 60 seconds" << endl;
        cout << "3. 90 seconds" << endl;
        cout << "4. Back To Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> level;

        switch (level)
        {
        case 1:
            sec_30();
            break;
        case 2:
            sec_60();
            break;
        case 3:
            sec_90();
            break;
        case 4:
            break;
        default:
            cout << "Invalid Choice Entered\n\n";
            menu();
            break;
        }
    }

    void takeTest(int target, int mode) 
    {
        system("cls");
        typingMaster();
        cout << "\n                                  Time Attack Mode (" << target << " seconds)" <<endl;
        Time::startsIn();
        int n = 0; 
        Paragraph para("timeAttack");
        vector<string> lines = para.getParagraph();
        Report myReport;
        setTarget(target);
        Time::startClock();
        for(auto line: lines) {
            UserInput obj(1, line);
            n++;
            obj.type();
            myReport.updateDetails(obj);
            if(obj.isTerminated()) {
                cout<<"\n\n***************";
                cout<<"Test Terminated";
                cout<<"***************";
                break;
            }
            
            if(obj.isTimeFinished()) {
                cout<<"\n\n***************";
                cout<<"Time Finished";
                cout<<"***************";
                break;
            }
            cout<<" ("<<Time::getTarget()-Time::getTime()<<" seconds remaining)";
            cout<<endl;
        } 
        double time = Time::getTime();
        myReport.setTime(time);
        myReport.printDetails(n, userObj, playerName, mode);
        cout << setw(10) << "Time Taken"<< setw(4) << "|" << setw(6) << fixed << setprecision(2) << time << " seconds" << endl;
        pressEnter();
    }

    void sec_30()
    {
        takeTest(30, 4);
    }

    void sec_60()
    {
        takeTest(60, 5);
    }

    void sec_90()
    {
        takeTest(90, 6);
    }

    friend void pressEnter();
};

void typingMaster() {
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
}
