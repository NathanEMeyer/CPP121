#include <iostream>
using namespace std;

int main() 
{
    
    //declaring verables
    double inputOfodds =0;
    double outputOfProbability =0;
    
    //inputing odds then turning them into a total probability
    cout<<"odds with 5 white balls and with the powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 5 white balls and with no powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 4 white balls and with the powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 4 white balls and with no powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 3 white balls and with the powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 3 white balls and with no powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 2 white balls and with the powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with 1 white balls and with the powerball: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    cout<<"odds with the powerball only: 1 in ";
    cin>>inputOfodds;
    outputOfProbability = outputOfProbability + (1/(inputOfodds+1));

    //printing out the final probablitlity
    cout<<"The probabilty of you winning anything is :"<<(outputOfProbability)<<"%";
    
    return 0;
}