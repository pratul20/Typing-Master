#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class UserInput
{
private:
    int errors;
    int position;
    string s;
    char *typed;
    char current;
    double accuracy;

public:
    UserInput(string str)
    {
        this->s = str;
        typed = new char[str.length()];
        accuracy = 0.00;
        position = 0;
        errors = 0;
    }

    void type()
    {
        cout << s << endl
             << endl;

        while (position != s.length())
        {
            current = getche();

            if (current == '^')
            {
                cout << "\nTest Terminated";
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

        cout << "\n\nErrors: " << errors;

        accuracy = getAccuracy();
        cout << "\nAccuracy: " << accuracy << "%";
    }

    double getAccuracy()
    {
        int finalErrors = 0;
        double accu;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != typed[i])
            {
                finalErrors++;
            }
        }

        accu = (double)(s.length() - finalErrors) * 100 / s.length();
        return accu;
    }
};