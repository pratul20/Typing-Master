#include <bits/stdc++.h>
#include <cstdlib>
#include ".\menu.cpp"
#include <conio.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    Menu obj;
    system("cls");
    obj.logo();
    obj.start();
    while(1) {
        system("cls");
        obj.logo();
        obj.menu();
    }
    return 0;
}