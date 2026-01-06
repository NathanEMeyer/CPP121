#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void loadTable(string filepath, double gasPrices[][4]);

void displaySortedAverages(double gasPrices[][4], bool isAscending = true);

int main()
{
    double gasPrices[12][4];
    string path = "Input.txt";
    string choice;
    bool order;
    bool acention;

    loadTable(path, gasPrices);

    do
    {
        cout<<"What order do you want? (ascending or decending)"<<endl;
        cin>>choice;
    } while (choice != "ascending"&& choice != "decending");

    if(choice == "ascending")
    {
        acention =true;
    }
    else if (choice == "decending")
    {
        acention =false;
    }
    

    displaySortedAverages(gasPrices, acention);

    return 0;
}

void loadTable(string filepath, double gasPrices[][4])
{
    string empty;
    int j =0;
    ifstream inFile;
    inFile.open(filepath);

    while(!inFile.eof())
    {
        inFile >> empty;

        for(int i=0; i<4; ++i)
        {
            inFile >> gasPrices[j][i];
        }

        for(int i=1; i<4; ++i)
        {
            gasPrices[j][0] += gasPrices[j][i];
        }

        gasPrices[j][0]=gasPrices[j][0]/4.0;

        ++j;
    }
}

void displaySortedAverages(double gasPrices[][4], bool isAscending)
{
    bool swap=true;

    string months[12] = 
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    double tempD;
    string tempS;


    if(isAscending)
    {
        while(swap)
        {
            swap = false;

            for(int i =0; i <11; ++i)
            {
                if(gasPrices[i][0]<gasPrices[i+1][0])
                {
                    tempD = gasPrices[i][0];
                    gasPrices[i][0] = gasPrices[i+1][0];
                    gasPrices[i+1][0] = tempD;

                    tempS = months[i];
                    months[i] = months[i+1];
                    months[i+1] =tempS;
                    swap =true;
                }
            }
        }
    }
    else
    {
        while(swap)
        {
            swap = false;

            for(int i =0; i <11; ++i)
            {
                if(gasPrices[i][0]>gasPrices[i+1][0])
                {
                    tempD = gasPrices[i][0];
                    gasPrices[i][0] = gasPrices[i+1][0];
                    gasPrices[i+1][0] = tempD;

                    tempS = months[i];
                    months[i] = months[i+1];
                    months[i+1] =tempS;
                    swap =true;
                }
            }
        }
    }

    for(int i =0; i <12; ++i)
    {
        cout<< months[i]<<": "<<setprecision(4)<<gasPrices[i][0]<<endl;
    }
}