#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//this function displays the board entered to the spesifided dimension
//
void displayBoard(char board[][5], int dimension);

//this funtion will put a X or O in where the player wants it
//
void makeMove(char player, char board[][5], int dimension);

//this function determans a winner and returns true if a winner 
//or tie happens and will return what player won
//
bool hasWon(char &player, char board[][5], int dimension);

int main()
{
    //constant verable for board size max
    const int MAX_BOARD =5;

    //declaing verables 
    char board[MAX_BOARD][MAX_BOARD];
    int boardSize = 3;
    char player;
    bool isWin = false;

    //fills in the board with -
    for(int r = 0; r<MAX_BOARD; ++r)
    {
        for(int c =0; c<MAX_BOARD; ++c)
        {
            board[r][c] = '-';
        }
    }

    //will propt the user for a correct board size
    do
    {
        cout<<"Enter a board size"<<endl;
        cin>>boardSize;
    } while (boardSize<3 || boardSize>5);
    
    cout<<endl<<endl;
    displayBoard(board,boardSize);

    //will go until a winner is found
    do
    {
        player = 'X';
        makeMove(player, board, boardSize);
        isWin = hasWon(player, board, boardSize);

        if(!isWin)
        {
            player = 'O';
            makeMove(player, board, boardSize);
            isWin = hasWon(player, board, boardSize);
        }

    } while (!isWin);

    //this prints out who won or if it was a tie 
    if(player == '-')
    {
        cout<<"IT'S A TIE"<<endl;

    }
    else
    {
        cout<<"PLAYER "<<player<<" HAS WON!!!"<<endl;
    }
    
    return 0;
}
void displayBoard(char board[][5], int dimension)
{
    for(int r = -1; r<dimension; ++r)
    {
        if(r>=0)
        {
            cout<<r<<" ";
        }
        for(int c =0; c<dimension; ++c)
        {
            if(r == -1)
            {
                cout<<"  "<<c;
            }
            else
            {
                cout<<board[r][c]<<"  ";
            }
        }
        cout<<endl;
    }
}
void makeMove(char player, char board[][5], int dimension)
{
    int row;
    int column;

    //this will run until the user enters a row or column that isn't filled or isn't outside of the dimension
    do
    {
        cout<<"player "<<player<<" enter a row and column with a space seperating them (ex. 0 0)"<<endl;
        cin>>row;
        cin.ignore();
        cin>>column;
    } while (board[row][column] != '-' || (row > dimension-1 || column > dimension-1));

    board[row][column] = player;

    displayBoard(board, dimension);
    
}
bool hasWon(char &player, char board[][5], int dimension)
{
    //counts the number of x's or o's in rows and columns
    int counter =0;

    // this loop checks if one of the columns is filled with x's or o's
    for(int r = 0; r<dimension; ++r)
    {
        for(int c =0; c<dimension; ++c)
        {
            if(board[r][c] == player)
            {
                ++counter;
            }
        }
        if(counter == dimension)
        {
            return true;
        }
        counter =0;
    }

    // this loop checks if one of the rows is filled with x's or o's
    for(int c = 0; c<dimension; ++c)
    {
        for(int r =0; r<dimension; ++r)
        {
            if(board[r][c] == player)
            {
                ++counter;
            }
        }

        if(counter == dimension)
        {
            return true;
        }
        counter =0;
    }

    // this loop checks if the diganal is filled with x's or o's
    for(int i = 0; i<dimension; ++i)
    {
        if(board[i][i] == player)
        {
            ++counter;
        }
    }

    if(counter == dimension)
    {
        return true;
    }

    counter =0;

    // this loop checks if the diganal in the other direction is filled with x's or o's
    for(int i = 0; i<dimension; ++i)
    {
        if(board[i][dimension-1-i] == player)
        {
            ++counter;
        }
    }

    if(counter == dimension)
    {
        return true;
    }

    counter =0;

    //this checks if all the spaces are filled and if so it will send back a - as player meaning it is a tie
    for(int c = 0; c<dimension; ++c)
    {
        for(int r =0; r<dimension; ++r)
        {
            if(board[r][c] != '-')
            {
                ++counter;
            }
        }
    }

    if(counter == pow(dimension,2))
    {
        player = '-';

        return true;
    }

    //if all checks fail it returns false
    return false;
}