#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class UserInput
{
private:
    int errors;
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
    UserInput(string str)
    {
        this->s = str;
        typed = new char[str.length()];
        accuracy = 0.00;
        position = 0;
        errors = 0;
        terminate = 0;
    }

    void type()
    {
        cout << endl << s << endl << endl;

        while (position != s.length())
        {
            current = getche();

            if (current == '^')
            {
                cout << "\nTest Terminated";
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