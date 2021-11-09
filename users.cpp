#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
using std::filesystem::directory_iterator;

class Users {

    private :
        vector<string> users;
        vector<double> scores;

    public :

        Users() {}

        Users(vector<string> currentUserList) { users = currentUserList; }

        void menu()
        {
            cout << "\nSelect from the follwing choice:-" << endl;
            cout << "1. User Data" << endl;
            cout << "2. Users List" << endl;
            cout << "3. Register User" << endl;
            cout << "4. Update User Accuracy" << endl;
            cout << "5. Update User Score" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            

            switch (choice)
            {
                case 1:{
                    string player;
                    cout<<"Enter the player\'s name you want to search:- ";
                    cin>>player;
                    printUserData(player);
                    break;
                }
                case 2:
                    printUsers();
                    break;
                case 3:{
                    string player;
                    cout<<"Enter your user name:- ";
                    cin>>player;
                    addUser(player);
                    break;
                }
                // case 4:{
                //     string player;
                //     cout<<"Enter the user name, you want to update:- ";
                //     cin>>player;
                //     updateUserInfo(player, 100, 100);
                //     break;
                // }
                // case 5:{
                //     string player;
                //     cout<<"Enter the user name, you want to update:- ";
                //     cin>>player;
                //     updateScores(player, 100, 2);
                //     break;
                // }
                default:
                    cout << "Invalid Choice Entered\n\n";
                    menu();
                    break;
            }
        }

        void getUsers() {
            this->users.clear();
            string path = "Database/HighScores";
        
            for (const auto & file : directory_iterator(path)){
                string us = file.path().filename().string();
                us.resize(us.size() - 4);
                transform(us.begin(), us.end(), us.begin(), ::tolower);
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

        bool getUserData(string player) {
            this->scores.clear();
            getUsers();
            vector<string>::iterator it;
            it = find (users.begin(), users.end(), player);

            if (it != users.end())
            {
                ifstream fin;
                fin.open("Database/HighScores/"+ player + ".txt");
                double score;
                int i=0;

                while (i!=9) {
                    fin>>score;
                    this->scores.push_back(score);
                    i++;
                }
                fin.close();
                return true;
            }
            return false;
        }

        void printUserData(string player){
            getUserData(player);
            if(scores.size() == 0){
                cout << "\nUser is not registered yet\n";
            }
            else{
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
                    cout<<"Accuracy : "<<scores[6]<<endl;
                    cout<<"Words per minute (wpm) : "<<scores[7]<<endl;
                    cout<<"Tests taken : "<<scores[8]<<endl;
                    cout<<"***************************************"<<endl; 
            }
        }

        void addUser(string player){
            if(getUserData(player)){
                cout<<"\nUsername already exists, try a different username\n";
            }
            else{
                ofstream out("Database/HighScores/" + player + ".txt");
                int i=0;
                while(i!=9){
                    out<<0<<endl;
                    i++;
                }
                cout<<player<<" has been registered succesfully";
                out.close();
            }
        }

        void updateUserInfo(string player, double inGameAcc, int wpm){
            if(!getUserData(player)){
                cout<<"Username doesn't exist"; //This print statement is only for development purposes and is meant to to be removed afterwards
            }
            else{
                fstream file;
                file.open("Database/HighScores/" + player + ".txt") ;
                vector <double> fileData;
                int currentLine = 0;
                while ( currentLine < 9 )
                {
                    double fileD;
                    file>>fileD;
                    fileData.push_back(fileD);
                    ++currentLine ;
                }

                double newAcc = (double)((scores[6]*(scores[8]) + inGameAcc) / (scores[8]+1));
                int newWpm = ((scores[7]*(scores[8]) + wpm) / (scores[8]+1));
                scores[8]++;

                cout<<newAcc<<endl;
                cout<<newWpm<<endl;
                cout<<scores[8]<<endl;

                fileData[6] = newAcc;
                fileData[7] = newWpm;
                fileData[8] = scores[8];

                file.close();
                file.open("Database/HighScores/" + player + ".txt");
                currentLine = 0;   
                while ( currentLine < 9 )
                {
                    file<<fileData[currentLine]<<"\n";
                    ++currentLine ;
                }
                file.close();

            }
        }

        void updateScores(string player, double inGameScore, int code){
            if(!getUserData(player)){
                cout<<"Username doesn't exist"; //This print statement is only for development purposes and is meant to to be removed afterwards
            }
            else{
                fstream file("Database/HighScores/" + player + ".txt") ;
                vector <double> fileData;
                int currentLine = 0;
                while ( currentLine < 9 )
                {
                    double fileD;
                    file>>fileD;
                    fileData.push_back(fileD);
                    ++currentLine ;
                }
                file.close();

                file.open("Database/HighScores/" + player + ".txt") ;
                fileData[code - 1] = inGameScore;
                currentLine = 0;
                while ( currentLine < 9 )
                {
                    file<<fileData[currentLine]<<"\n";
                    ++currentLine ;
                }
                file.close();
            }
        }
}; 