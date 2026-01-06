#include <iostream>
#include <cmath>

//Nathan Meyer
//8/29/2024

using namespace std;

int main()
{
    //each one of these I neamed after number and the just in order of 123
    int num1;
    int num2;
    int num3;

    //this I named avarege because it is the averge 
    double avarege;

    //this takes in the imput for the 3 numbers
    cin >>num1;
    cin >>num2;
    cin >>num3;

    //this calculates the avarege
    avarege = (num1+num2+num3)/3.0;

    //this prints out the avarege
    cout<<avarege;
}
//some diffrences is I didn't have to worry in python about what type of math i was doing (for example my code has /3.0 insead of just /3 so it
//doesn't round) another thing was white space because python doesn't use ; but instead uses white space.