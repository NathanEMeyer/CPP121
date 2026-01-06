#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;

int* loadArray(string filepath, int &count)
{
    ifstream inFile;

    const int STEP =10;

    int *list = new int[STEP];

    count =0;

    inFile.open(filepath);

    while(inFile >> list[count++])
    {
        //inFile >> list[count++];

        if(count%STEP ==0)
        {
            int *temp = new int[count +STEP];

            for(int i=0; i< count; ++i)
            {
                temp[i] = list[i];

            }

            delete [] list;

            list = temp;
        }
    }

    return list;
}

int main()
{

    int *p = new int[100];

    int **t;

    t = new int*[10];

    for(int r =0; r<10; ++r)
    {
        t[r] = new int[6];
    }

    for(int r =0; r<10; ++r)
    {
        delete [] t[r];
    }


    

    return 0;
}