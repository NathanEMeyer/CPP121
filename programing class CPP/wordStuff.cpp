#include <iostream>
#include <cmath>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
    string newWord;
    bool lower =false;
    bool noRepeat = false;
    int counter =0;
    
    ifstream inFile;
    inFile.open("words.txt");
    ofstream outFile;
    outFile.open("newWords.txt");


    while(!inFile.eof())
    {
        inFile >> newWord;

        lower = !isupper(newWord[0]);

        if(newWord.length() == 5 && lower)
        {

            for(int i =0; i<5; ++i)
            {
                for(int j = 0; j<5; ++j)
                {
                    if(newWord[i] == newWord[j] && i != j)
                    {
                        ++counter;
                    }
                }
            }

            if(counter == 0)
            {
                outFile << newWord <<endl;
            }

        }
        counter =0;
    }

    return 0;

}