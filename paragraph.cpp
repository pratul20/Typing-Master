#include <bits/stdc++.h>
#include <time.h>
using namespace std;

vector<string> split(string s, char c);
class Paragraph
{

private:
    string difficulty;
    string toType;

public:
    Paragraph(string difficulty)
    {
        this->difficulty = difficulty;

        string filename;
        if (this->difficulty == "easy")
        {
            filename = "./Database/WordLists/easy.txt";
        }
        else if (this->difficulty == "medium")
        {
            filename = "./Database/WordLists/medium.txt";
        }
        else
        {
            filename = "./Database/WordLists/hard.txt";
        }

        fstream file;
        file.open(filename.c_str());
        string output;
        vector<string> paragraphs;
        while (getline(file, output))
        {
            paragraphs.push_back(output);
        }
        file.close();
        // int start = 0;
        // int end = paragraphs.size();
        srand((int)time(NULL));
        // random_device rd;
        // mt19937 rng(rd());
        // uniform_int_distribution<int> uni(start, end - 1);
        // int select = uni(rng);
        int select = rand()%paragraphs.size();
        this->toType = paragraphs[select];
    }

    vector<string> getParagraph()
    {
        vector<string> lines = split(toType, '.');
        return lines;
    }

};

vector<string> split(string s, char c) {
    vector <string> tokens;

    stringstream check1(s);    
    string intermediate;

    while(getline(check1, intermediate, c))
    {
        tokens.push_back(intermediate);
    }

    return tokens;
}