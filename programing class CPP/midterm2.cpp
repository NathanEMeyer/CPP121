#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

void loadData(string filepath, string voterIDs[], string candidateNames[], int &voterCount);

void displayVotes(string voterIDs[], string candidateNames[], int voterCount);

void displayResults(string candidateNames[], int candidateCount);

int main()
{
    string path = "voter.txt";
    string candidate[50];
    string IDs[50];
    int voterCount =0;
    int candidateCount =0;

    loadData(path, IDs, candidate, voterCount);

    displayVotes(IDs, candidate, voterCount);

    displayResults(candidate, candidateCount);

    return 0;
}

void loadData(string filepath, string voterIDs[], string candidateNames[], int &voterCount)
{
    ifstream inFile;
    inFile.open(filepath);

    string IDChecker;
    string candidateChecker;
    bool isSame = false;
    int checkCounter =0;

    while(!inFile.eof())
    {
        inFile >> IDChecker;
        inFile >> candidateChecker;

        for(int i=0; i <= voterCount; ++i)
        {
            if(IDChecker == voterIDs[i])
            {
                isSame = true;
            }
        }

        if(!isSame)
        {
            voterIDs[voterCount] = IDChecker;
            candidateNames[voterCount] = candidateChecker;
            ++voterCount;
        }

    }
}

void displayVotes(string voterIDs[], string candidateNames[], int voterCount)
{
    for(int i =0; i < voterCount; ++i)
    {
        cout<<voterIDs[i] << " "<< candidateNames[i]<<endl;
    }
}

void displayResults(string candidateNames[], int candidateCount)
{
    for(int i =1; i<candidateNames.length(); ++i)
    {
        if(candidateNames[i] != "" && && candidateNames[0] != candidateNames[i])
        {
            ++candidateCount;
        }
    }

    for(int i =0; i<candidateNames.length(); ++i)
    {
        
    }
}