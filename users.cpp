#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
using std::filesystem::directory_iterator;

void pressEnter();

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
                default:
                    cout << "Invalid Choice Entered\n";
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
            pressEnter();
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
                    cout<<"\t      Classic Mode"<<endl;
                    cout<<setw(16)<<"Easy"<<setw(4)<<"|"<<setw(8)<<scores[0]<<endl;
                    cout<<setw(16)<<"Medium"<<setw(4)<<"|"<<setw(8)<<scores[1]<<endl;
                    cout<<setw(16)<<"Hard"<<setw(4)<<"|"<<setw(8)<<scores[2]<<endl<<endl;
    
                    cout<<"\t   Time Attack Mode"<<endl;
                    cout<<setw(16)<<"30 seconds"<<setw(4)<<"|"<<setw(8)<<scores[3]<<endl;
                    cout<<setw(16)<<"60 seconds"<<setw(4)<<"|"<<setw(8)<<scores[4]<<endl;
                    cout<<setw(16)<<"90 seconds"<<setw(4)<<"|"<<setw(8)<<scores[5]<<endl<<endl;


                    cout<<"\t\t Stats"<<endl;

                    cout<<setw(16)<<"Accuracy"<<setw(4)<<"|"<<setw(8)<<scores[6]<<endl;
                    cout<<setw(16)<<"Words per Minute"<<setw(4)<<"|"<<setw(8)<<scores[7]<<endl;
                    cout<<setw(16)<<"Tests Taken"<<setw(4)<<"|"<<setw(8)<<scores[8]<<endl;

                    cout<<"***************************************"<<endl; 
            }
            pressEnter();
        
        }

        string addUserStarting(){
            string player;
            label:
            cout << "\nEnter your name: ";
            cin >> player;
            if(getUserData(player)) { return player; }
            else{
                char c;
                cout << "This user doesn't exist. Do you want to create a new one (y/n)";
                c = getche();
                if(c == 'y' || c == 'Y') {
                    ofstream out("Database/HighScores/" + player + ".txt");
                    int i=0;
                    while(i!=9){
                        out<<0<<endl;
                        i++;
                    }
                    cout<<player<<" has been registered succesfully";
                    out.close();
                    return player;
                }
                else 
                {
                    goto label;
                }
            }
            pressEnter();
            return "";
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

            pressEnter();
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
                if(fileData[code-1] < inGameScore) {
                    fileData[code - 1] = inGameScore;
                }
                currentLine = 0;
                while ( currentLine < 9 )
                {
                    file<<fileData[currentLine]<<"\n";
                    ++currentLine ;
                }
                file.close();
            }
        }

        friend void pressEnter();
}; 

void pressEnter() {
    cout<<"\nPress Enter to continue.";
    while(getch()!=13);
}