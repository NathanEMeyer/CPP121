#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int* removeLowestAndHighest(const int * const values, const int count);

int main()
{
    const int MAXVALUES = 20;

    int * values = new int[MAXVALUES];
    int count;
    int newNumber;
    bool matches=false;

    srand(time(0));

    while(count<MAXVALUES)
    {
        newNumber = (rand()%40)-20;
        for(int i=0; i<count; ++i)
        {
            if(newNumber==values[i])
            {
                matches =true;
            }
        }
        if(!matches)
        {
            values[count]=newNumber;
            ++count;
        }

        matches =false;
    }


    cout<<"Intial List: ";
    for(int i =0; i<count; ++i)
    {

        cout<<values[i]<<", ";
    }

    values= removeLowestAndHighest(values, count);

    cout<<endl<<"Updated List: ";
    for(int i=0; i<count-2; ++i)
    {
        cout<<values[i]<<", ";
    }
    
    return 0;
}

int* removeLowestAndHighest(const int * const values, const int count)
{
    int largest=0;
    int smallest=100;
    int locationL;
    int locationS;
    int j =0;
    int * result = new int[count-2];

    for(int i=0; i<count; ++i)
    {
        if(values[i] > largest)
        {
            largest = values[i];
            locationL =i;

        }
        if(values[i]<smallest)
        {
            smallest = values[i];
            locationS = i;
        }
    }

    for(int i=0; i<count-2; ++i)
    {
        if(j == locationS || j== locationL)
        {
            ++j;
        }

        result[i] = values[j];
        ++j;
    }

    return result;
}