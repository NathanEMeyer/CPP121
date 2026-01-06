#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>
using namespace std;

int main()
{
    const int STEP =200;

    string *movies = new string[STEP];
    int *movieIDs = new int[STEP];
    int ratingIDs = 0;
    double *ratings = new double[STEP];

    int movieCounter =0;
    int ratingCounter =0;

    bool ifSwap =true;

    ifstream inFile;
    inFile.open("movie.txt");

    while(inFile >> movieIDs[movieCounter])
    {
        getline(inFile, movies[movieCounter]);

        ++movieCounter;

        if(movieCounter%STEP ==0)
        {
            int *temp = new int[movieCounter +STEP];
            string *temps =new string[movieCounter +STEP];

            for(int i=0; i< movieCounter; ++i)
            {
                temp[i] = movieIDs[i];
                temps[i] = movies[i];

            }

            delete [] movieIDs;
            delete [] movies;

            movieIDs = temp;
            movies = temps;
        }
    }
    inFile.close();

    int *numberOfRatings = new int[movieCounter];
    double *tempRatings = new double[movieCounter];
    for(int i = 0; i <movieCounter; ++i)
    {
        numberOfRatings[i] =0;
        tempRatings[i] =0;
    }

    inFile.open("rankings.txt");

    while(inFile >> ratingIDs)
    {
        inFile >> ratings[ratingCounter];

        for(int i =0; i< movieCounter; ++i)
        {
            if(movieIDs[i] == ratingIDs)
            {
                ++numberOfRatings[i];
                tempRatings[i] += ratings[ratingCounter];
            }
        }
        
        ++ratingCounter;

        if(ratingCounter%STEP ==0)
        {
            double *tempR = new double[ratingCounter +STEP];

            for(int i=0; i< ratingCounter; ++i)
            {
                tempR[i] = ratings[i];

            }

            delete [] ratings;

            ratings = tempR;
        }
    }

    delete [] ratings;

    ratings = tempRatings;



    while(ifSwap)
    {
        ifSwap = false;
        for(int i =0; i< movieCounter-1; ++i)
        {
            for(int j =i+1; j< movieCounter; ++j)
            {
                if(numberOfRatings[i] > numberOfRatings[j])
                {
                    int temp = numberOfRatings[i];
                    numberOfRatings[i] = numberOfRatings[j];
                    numberOfRatings[j] = temp;

                    temp = movieIDs[i];
                    movieIDs[i] = movieIDs[j];
                    movieIDs[j] = temp;

                    double tempD = ratings[i];
                    ratings[i] = ratings[j];
                    ratings[j] = tempD;

                    string temps = movies[i];
                    movies[i] = movies[j];
                    movies[j] = temps;
                    ifSwap = true;
                }
            }
        }
    }

    int C = numberOfRatings[static_cast<int>(movieCounter*.25)];
    double M =0;
    double total =0;
    for(int i =0; i< movieCounter; ++i)
    {
        M += ratings[i];
    }

    for(int i =0; i< movieCounter; ++i)
    {
        total += numberOfRatings[i];
    }

    M= M/total;

    for(int i=0; i<movieCounter; ++i)
    {
        ratings[i] =((ratings[i]/numberOfRatings[i])*numberOfRatings[i] + (C*M))/ 
                    (numberOfRatings[i]+C);
    }

    ifSwap = true;

    while(ifSwap)
    {
        ifSwap = false;
        for(int i =0; i< movieCounter-1; ++i)
        {
            for(int j =i+1; j< movieCounter; ++j)
            {
                if(ratings[i] < ratings[j])
                {
                    int temp = numberOfRatings[i];
                    numberOfRatings[i] = numberOfRatings[j];
                    numberOfRatings[j] = temp;

                    double tempD = ratings[i];
                    ratings[i] = ratings[j];
                    ratings[j] = tempD;

                    string temps = movies[i];
                    movies[i] = movies[j];
                    movies[j] = temps;
                    ifSwap = true;
                }
            }
        }
    }

    for(int i =0; i<30; ++i)
    {
        cout<<ratings[i]<<" "<<numberOfRatings[i]<<" "<<movies[i]<<endl;
    }

    return 0;
}