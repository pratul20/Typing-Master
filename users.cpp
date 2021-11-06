#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
using std::filesystem::directory_iterator;

class Users {

    private :
        vector<string> users;

    public :

        Users() {}

        Users(vector<string> currentUserList) { users = currentUserList; }

        void menu()
        {
            cout << "\nSelect from the follwing choice:-" << endl;
            cout << "1. User Data" << endl;
            cout << "2. Users List" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            

            switch (choice)
            {
                case 1:{
                    string player;
                    cout<<"Enter the player\'s name you want to search:- ";
                    cin>>player;
                    getUserData(player);
                    break;
                }
                case 2:
                    printUsers();
                    break;
                default:
                    cout << "Invalid Choice Entered\n\n";
                    menu();
                    break;
            }
        }

        void getUsers() {
            string path = "Database/HighScores";
            vector<string> users;
        
            for (const auto & file : directory_iterator(path)){
                string us = file.path().filename().string();
                us.resize(us.size() - 4);
                this->users.push_back(us);
            }
        }

        void printUsers() {
            getUsers();
            if(users.size() == 0)
                cout<<"\nNo users registered yet\n";
            else{
                cout<<endl;
                int i=1;
                for (auto user : users) {
                    cout << i <<". "<<user <<endl;
                    i++;
                }
            }
        }

        void getUserData(string player) {
            getUsers();
            vector<string>::iterator it;
            it = find (users.begin(), users.end(), player);

            if (it != users.end())
            {
                string scores[6];
                int i=0;

                ifstream fin;
                fin.open("Database/HighScores/"+ player + ".txt");
                while (fin) {
                    getline(fin, scores[i]);
                    i++;
                }
    
                fin.close();
                cout<<"***************************************"<<endl;
                cout<<'\t'<<player<<"'s Scoreboard :"<<endl;
                cout<<"***************************************"<<endl;
                cout<<"Classic Mode :"<<endl;
                cout<<"Easy   :"<<scores[0]<<endl;
                cout<<"Medium : "<<scores[1]<<endl;
                cout<<"Hard   : "<<scores[2]<<endl<<endl;
                cout<<"Time Attack Mode : "<<endl;
                cout<<"30 seconds : "<<scores[3]<<endl;
                cout<<"60 seconds : "<<scores[4]<<endl;
                cout<<"90 seconds : "<<scores[5]<<endl;
                cout<<"***************************************"<<endl;
            }
            else
                cout << "\nUser is not registered yet\n";
        }
}; 