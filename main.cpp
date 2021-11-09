#include <bits/stdc++.h>
#include ".\menu.cpp"
#include <conio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    Menu obj;
    obj.start();
    while(1) {
        obj.menu();
    }
    return 0;
}