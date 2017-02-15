#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//game peice
char X = 'X';
char O = 'O';
char clear = ' ';
char tie = 'T';

int turn = 0;

bool checkMove(vector<char>& board, int placement)
{
    if(board[placement] == clear)
    {
        return true;
    }

    else
        return false;
}

void playerMove(vector<char>& board)
{

    cout << "Where would you like to go: ";
    int place;
    cin >> place;

    if(checkMove(board, place))
    {

        if(turn)
        {
            board[place] = O;

            turn = 0;
        }

        else if(!turn)
        {
            board[place] = X;

            turn = 1;
        }

    }

    else if(!checkMove(board, place))
        cout << "Invalid Move !" << endl;
}

void display(vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
     cout << "\n\t" << "-----"          << "-----";
     cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
     cout << "\n\t" << "-----"          << "-----";
     cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
     cout << "\n\n";
}

char checkWinner(vector<char>& board)
{
    if(board[0] == board[1] && board[2] == board[0])
    return board[0];

    if(board[3] == board[4] && board[5] == board[4])
    return board[3];

    if(board[6] == board[7] && board[8] == board[6])
    return board[6];

    if(board[0] == board[3] && board[6] == board[0])
    return board[0];

    if(board[1] == board[4] && board[7] == board[1])
    return board[1];

    if(board[2] == board[5] && board[8] == board[2])
    return board[2];

    if(board[0] == board[4] && board[8] == board[0])
    return board[0];

    if(board[2] == board[4] && board[6] == board[2])
    return board[2];

    if(count(board.begin(), board.end(), clear) == 0)
    return tie;

    else
    return clear;
}

int main()
{
    vector<char> board(9, clear);


    while(checkWinner(board) == clear)
    {
        display(board);

        playerMove(board);
    }

    display(board);

    if(checkWinner(board) == tie)
    {
        cout << "It was a tie !" << endl;
    }

    else
        cout << "Congradulations !" << checkWinner(board) << " has won !" << endl;

     return 0;
}
