#include <bits/stdc++.h>
#include <conio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

class UserInput
{
private:
    int errors;
    int position;
    char current;

public:
    void type(string s)
    {
        cout << s << endl
             << endl;

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
    }
};

int main()
{
    return 0;
}