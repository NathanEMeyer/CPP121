#include <iostream>
using namespace std;

int main()
{
    double subT;
    int tipPercent;
    double total;

    cout<<"Enter Subtotal      :";
    cin>>subT;

    cout<<"Enter Tip Percentage:";
    cin>>tipPercent;

    cout<<endl<<"Subtotal            :"<<subT<<endl<<"Tip                 :"<<(subT*(tipPercent/100.0))<<endl<<endl;
    total = subT + (subT*(tipPercent/100.0));
    cout<<"Total               :"<<total;
    return 0;
}