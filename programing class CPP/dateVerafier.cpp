#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
// This program checks if a date is valid or invalid using a switch statment for the month 
//and using if statments for the day and year
int main()
{
    //declaring vearables
    int year;
    int month;
    int day;

    cout<<"enter month day year using numbers only (1/1/1) ";
    cin>>month;
    cin.ignore();  //ignoring an imput so in the termminal people can type 1/23/2024
    cin>>day;
    cin.ignore();  //ignoring an imput so in the termminal people can type 1/23/2024
    cin>>year;

    if(year>0)  //checking if the year is positive aka a real year
    {

        switch(month)  //a switch that reads what the month is
        {
            //all of these cases are for months that have 31 days in them
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            if(day>=1 && day<=31)  //checking if the day is between 1 and 31
            {
                cout<<"Valid date";
            }
            else
            {
                cout<<"Invalid date";
            }
            break;  //going straight to the end of the switch

            //all of these cases are for months that have 30 days in them
            case 4:
            case 6:
            case 9:
            case 11:
            if(day>=1 && day<=30)  //checking if the day is between 1 and 30
            {
                cout<<"Valid date";
            }
            else
            {
                cout<<"Invalid date";
            }
            break;   //going straight to the end of the switch

            case 2:  //this case is for febuary 
            if(((year%4)==0&&(year%100)!=0)||(year%400)==0)  //this is checking if the year is a leap year
            {
                if(day>=1 && day<=29)  //checking if the day is between 1 and 29
                {
                    cout<<"Valid date";
                }
                else
                {
                    cout<<"Invalid date";
                }
            }
            else  //if the year is not leap
            {
                if(day>=1 && day<=28)  //checking if the day is between 1 and 28
                {
                    cout<<"Valid date";
                }
                else
                {
                   cout<<"Invalid date"; 
                }
            }
            break;  //going straight to the end of the switch
            
            default:  //if the month is not between 1 and 12
            cout<<"Invalid date";
        }
    }
    else //if the year isn't positive
    {
        cout<<"Invalid date";
    }
    return 0; //ends program
}