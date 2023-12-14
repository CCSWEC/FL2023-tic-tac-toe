Test
/*
This function will display the tictactoe gameboard, each cell will be an index of a 2D array
*/

#include <iostream>
#include <iomanip>

using namespace std;

void displayBoard(char[][3], int, int);

const int ROWS = 3;
const int COLUMNS = 3;

int main()
{
	int player1Score = 2; 
	int player2Score = 11;
	/*
	The cells array will contain input from the user, right now they contain filler values
	to make sure the board is displayed correctly
	*/
	char cells[ROWS][COLUMNS] = { {'A', 'A', 'A'}, {'B', 'B', 'B'}, {'C', 'C', 'C'} };
	
	displayBoard(cells, player1Score, player2Score); //display the board
}

void displayBoard(char cells[][3], int p1Score, int p2Score)
{
    int dashes = 22; //these dashes will separate the rows of the board
	cout << "Player 1: " << p1Score;
	cout << setw(15);
	cout << "Player 2: " << p2Score << endl << endl;
	
	cout << " ";
	cout << setw(8);
	cout << "A";
	cout << setw(9);
	cout <<"B";
	cout << setw(9);
	cout <<"C";
	//cout << setw(8);
	cout << endl << endl;
	
	for (int i = 0; i < ROWS; i++)
	    {
            cout << i + 1;
            cout << setw(8);
            for (int j = 0; j < COLUMNS; j++)
            {
                cout << cells[j][i] << i + 1;
                cout << setw(4);
                if (j < 2)
                {
                cout << "|";
                cout << setw(4);
                }
            }
            cout << endl;
            cout << " ";
            cout << setw(4);
            if (i < 2)
            {
            for (int k = 0; k < dashes; k++)
            {
                cout << "-";
            }
            cout << endl;
            }
	    }
}