#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class UserInput
{
private:
    int errors;
    int position;
    string s;
    char current;

public:

    UserInput(string str) {
        this->s = str;
        position = 0;
        errors = 0;
    }

    void type()
    {
        cout << s << endl << endl;

        while (position != s.length())
        {
            current = getche();

            if (current == 8)
            {
                position--;
                continue;
            }

            else if (current != s[position])
            {
                errors++;
            }

            position++;
        }

        cout<<"\n\nErrors: "<<errors;
    }
};