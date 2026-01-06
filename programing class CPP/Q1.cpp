#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{

    int length;
    int width;
    int height;
    double volumeShpere;
    do
    {
        cout<<"What is the Length?"<<endl;
        cin>>length;
    } while (length<0);

    do
    {
        cout<<"What is the Width?"<<endl;
        cin>>width;
    } while (width<0);

    do
    {
        cout<<"What is the height?"<<endl;
        cin>>height;
    } while (height<0);

    if(height <= width && height <= length)
    {
        volumeShpere = (4/3.0)*M_PI*(pow((height/2.0),3));
    }
    else if(width <= height && width <= length)
    {
        volumeShpere = (4/3.0)*M_PI*(pow((width/2.0),3));
    }
    else if(length <= width && length <= height)
    {
        volumeShpere = (4/3.0)*M_PI*(pow((height/2.0),3));
    }
    
    cout<<"The biggest shpere you can have is one with a volume of "<<volumeShpere<<endl;

    return 0;
}