#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include ".\input.cpp"
#include ".\users.cpp"
#include <chrono>
#include ".\paragraph.cpp"

using namespace std;
using namespace std::chrono;


class Report {
    private:
        int words;
        int errors;
        int total;
        int fixed;
        double avgAccuracy;
        double time;
    
    public: 
        Report() {
            errors = 0;
            words = 0;
            total = 0;
            fixed = 0;
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

        int getFixed() {
            return fixed;
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

        void setFixed(int fixed) {
            this -> fixed = fixed;
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
            fixed += obj.getFixedErrors();
            total += obj.getTotal();
            avgAccuracy += obj.getAccuracy();
            words += obj.getWordCount();
        }

        void printDetails(int n, Users &userObj, string &playerName, int mode) 
        {
            double accuracy = (double) avgAccuracy/n;
            int wpm = (int) words*60/(int)getTime();
            cout << "\n\nErrors: "<< errors;
            cout << "\nFixed: " << fixed;
            cout << "\nTotal Entries: " << total;
            cout << "\nSpeed: " << wpm << " wpm"; 
            cout << "\nAccuracy: " << accuracy << " %"<<endl;
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
            Time::startsIn();
            easy();
            break;
        case 2:
            Time::startsIn();
            medium();
            break;
        case 3:
            Time::startsIn();
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

    void easy()
    {
        int n = 0; 
        Paragraph para("easy");
        vector<string> lines = para.getParagraph();
        Report myReport;
        Time::startClock();
        for(auto line: lines) {
            UserInput obj(0, line);
            n++;
            obj.type();
            if(obj.isTerminated()) {
                break;
            }
            myReport.updateDetails(obj);
            cout<<endl;
        } 
        Time::stopClock();
        double time = Time::getTime();
        myReport.setTime(time);
        myReport.printDetails(n, userObj, playerName, 1);
        cout << "Time Taken: " << time << " seconds"<<endl;
        pressEnter();
    }

    void medium()
    {
        int n = 0; 
        Paragraph para("medium");
        vector<string> lines = para.getParagraph();
        Report myReport;
        Time::startClock();
        for(auto line: lines) {
            UserInput obj(0, line);
            n++;
            obj.type();
            if(obj.isTerminated()) {
                break;
            }
            myReport.updateDetails(obj);
            cout<<endl;
        } 
        Time::stopClock();
        double time = Time::getTime();
        myReport.setTime(time);
        myReport.printDetails(n, userObj, playerName, 2);
        cout << "Time Taken: " << time << " seconds"<<endl;
        pressEnter();
    }

    void hard()
    {
        int n = 0; 
        Paragraph para("hard");
        vector<string> lines = para.getParagraph();
        Report myReport;
        Time::startClock();
        for(auto line: lines) {
            UserInput obj(0, line);
            n++;
            obj.type();
            if(obj.isTerminated()) {
                break;
            }
            myReport.updateDetails(obj);
            cout<<endl;
        } 
        Time::stopClock();
        double time = Time::getTime();
        myReport.setTime(time);
        myReport.printDetails(n, userObj, playerName, 3);
        cout << "Time Taken: " << time << " seconds"<<endl;
        pressEnter();
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
            Time::startsIn();
            sec_30();
            break;
        case 2:
            Time::startsIn();
            sec_60();
            break;
        case 3:
            Time::startsIn();
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

    void sec_30()
    {
        int n = 0; 
        Paragraph para("easy");
        vector<string> lines = para.getParagraph();
        Report myReport;
        setTarget(30);
        Time::startClock();
        for(auto line: lines) {
            UserInput obj(1, line);
            n++;
            obj.type();
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
            myReport.updateDetails(obj);
            cout<<" ("<<Time::getTarget()-Time::getTime()<<" seconds remaining)";
            cout<<endl;
        } 
        double time = Time::getTime();
        myReport.setTime(time);
        myReport.printDetails(n, userObj, playerName, 4);
        cout << "Time Taken: " << time << " seconds"<<endl;
        pressEnter();
    }

    void sec_60()
    {
    }

    void sec_90()
    {
    }

    friend void pressEnter();
};



