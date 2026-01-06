#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    const int MAXVALUES = 20;

    int * values = new int[MAXVALUES];
    int count;
    int newNumber;
    bool matches=false;

    srand(time(0));

    for(int i =0; i<MAXVALUES; ++i)
    {
        newNumber = (rand()%40)-20;
        for(int j=0; j<count; ++j)
        {
            if(newNumber==values[j])
            {
                matches =true;
            }
        }

        if(!matches)
        {
            values[i]=newNumber;
        }

        matches =false;
    }

    matches =true;
    while(matches)
    {
        for(int i=0; i<count; ++i)
        {
            for(int j=0; j<count; ++j)
            {
                if(values[i]<values[j])
                {
                    newNumber = values[i];
                    values[i] = values[j];
                    values[j] = newNumber;
                }
            }
        }
    }

    for(int i =0; i<count; ++i);
    {
        cout<<values[i]<<endl;
    }
    
    return 0;
}