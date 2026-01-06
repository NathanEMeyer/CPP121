#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

int main()
{
   const int MAX_NAMES = 10;
    
    string names[MAX_NAMES];
    string insertName ="";
    bool insertTrue = false;
    bool isSame = false;
    int i =0;
    int j =0;
    int index =0;
    int stringCount = 0;

    while (insertName != "quit" && stringCount < MAX_NAMES)
    {
        
        insertTrue = false;
        isSame = false;
        i =0;
        j =0;
        index = 0;


        cout<<"enter name or \"quit\":"<<endl;
        getline(cin, insertName);

        if(insertName != "quit")
        {
            if(stringCount == 0)
            {
                names[0] = insertName;
            }
            else
            {
                i = insertName.find(" ")+1;

                while(!insertTrue && index < stringCount)
                {
                    j = names[index].find(" ")+1;

                    if(insertName.substr(i)==names[index].substr(j))
                    {
                        if(insertName == names[index])
                        {
                            isSame = true;
                        }
                        else if(insertName > names[index])
                        {
                            ++index;
                        }
                        else if(insertName < names[index])
                        {
                            insertTrue = true;
                        }
                    }
                    else if(insertName.substr(i)>names[index].substr(j))
                    {
                        ++index;
                    }
                    else if(insertName.substr(i)<names[index].substr(j))
                    {
                        insertTrue = true;
                    }

                }

                for (int i = stringCount-1; i >= index; --i) 
                {
                    names[i+1] = names[i];
                }
                names[index] = insertName;

                if(isSame)
                {
                    cout<<"Same name"<<endl;
                }
            }

            ++stringCount;
        }
    }

    for(i = 0; i < stringCount; ++i )
    {
        cout<<names[i]<<endl;
    }

    return 0;
}