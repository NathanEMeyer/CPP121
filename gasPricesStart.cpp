// The goal of this exercise is to display the average gas prices per month in descending order.
//
// So, 
//     (1) Compute the average per month and store it in a 1D array
//
//     (2) Sort into decscending order (Here's the rub: You must also sort the months!)
//
//     (3) Display the results
//
// Here's the correct answer:
//
// May:       2.796
// April:     2.737
// July:      2.710
// June:      2.668
// August:    2.587
// October:   2.561
// November:  2.550
// September: 2.548
// December:  2.534
// March:     2.503
// February:  2.286
// January:   2.214
//
#include <iostream>

using namespace std;


int main() {
    
  // The number of months and the number of weeks per month.
  //
  const int MONTH_COUNT = 12;
  const int WEEK_COUNT = 4;

  // The cost of gas per gallon per week per month.
  //
  double gasPricesPerWeek[MONTH_COUNT][WEEK_COUNT] = 
      { {2.199, 2.212, 2.216, 2.229}, // January 
        {2.228, 2.251, 2.293, 2.372}, // February
        {2.412, 2.458, 2.537, 2.604}, // March
        {2.670, 2.710, 2.785, 2.785}, // April    
        {2.834, 2.800, 2.789, 2.762}, // May 
        {2.757, 2.687, 2.621, 2.608}, // June 
        {2.674, 2.708, 2.745, 2.716}, // July   
        {2.653, 2.590, 2.567, 2.538}, // August
        {2.527, 2.517, 2.521, 2.627}, // September
        {2.581, 2.565, 2.581, 2.539}, // October
        {2.555, 2.563, 2.544, 2.539}, // November
        {2.554, 2.548, 2.518, 2.516}  // December
      };


  // The months of the year.
  //
  string months[MONTH_COUNT] = { "January", "February", "March", "April", "May", "June",
                                  "July", "August", "September", "October", "November", "December"};


  // The average gas price per month.
  //
  double averageGasPricePerMonth[MONTH_COUNT];

  double averagePerMonth;
  double tempD;
  string tempS;
  bool swap = true;

  for(int r =0; r<MONTH_COUNT; ++r)
  {
    for(int c =0; c<WEEK_COUNT; ++c)
    {
      averagePerMonth += gasPricesPerWeek[r][c];
    }
    averageGasPricePerMonth[r] = averagePerMonth/WEEK_COUNT;
    averagePerMonth=0;
  }
 
  while(swap)
  {
    swap = false;
    for(int i =0; i <MONTH_COUNT; ++i)
    {
      if(averageGasPricePerMonth[i]<averageGasPricePerMonth[i+1])
      {
        tempD = averageGasPricePerMonth[i];
        averageGasPricePerMonth[i] = averageGasPricePerMonth[i+1];
        averageGasPricePerMonth[i+1] = tempD;

        tempS = months[i];
        months[i] = months[i+1];
        months[i+1] =tempS;
        swap =true;
      }
    }
  }


  for(int i =0; i < MONTH_COUNT; ++i)
  {
    cout<<months[i]<<" "<<averageGasPricePerMonth[i]<<endl;
  }
  
 return 0;
}