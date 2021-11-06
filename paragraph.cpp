#include <bits/stdc++.h>
using namespace std;

class Paragraph {

    private :

        string difficulty;

    public :

        Paragraph(string difficulty) {

            this->difficulty = difficulty;
        }

        string get_paragraph() {

            string filename;
            if (this->difficulty == "easy") {
                filename = "./Database/WordLists/easy.txt";
            }else if (this->difficulty == "medium") {
                filename = "./Database/WordLists/medium.txt";
            }else {
                filename = "./Database/WordLists/hard.txt";
            }
            fstream file;
            file.open(filename.c_str());
            string output;
            vector<string> paragraphs;
            while(getline(file,output)) {
                paragraphs.push_back(output);
            }
            file.close();
            int start = 0;
            int end = paragraphs.size();
            random_device rd;     
            mt19937 rng(rd());
            uniform_int_distribution<int> uni(start,end - 1);
            int select = uni(rng);
            string to_type = paragraphs[select];
            return to_type;
        }
};