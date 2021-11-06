#include <bits/stdc++.h>
#include <filesystem>

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
                users.push_back(file.path().filename().string());
            }
        }

        void printUsers() {
            getUsers();
            if(users.size() == 0)
                cout<<"\nNo users registered yet\n";
            else{
                cout<<endl;
                int i=0;
                for (auto user : users) {
                    cout << i <<". "<<user <<endl;
                    i++;
                }
            }
        }

        void getUserData(string player) {
            vector<string>::iterator it;
            it = find (users.begin(), users.end(), player);

            if (it != users.end())
            {
                cout << "User: " << player <<" exists in DB " ;
            }
            else
                cout << "\nUser is not registered yet\n";
        }
}; 