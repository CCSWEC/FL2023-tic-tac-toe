#include <iostream>
#include <iomanip>


using namespace std;

const int ROWS = 3;
const int COLUMNS = 3;
const int MAX_ATTEMPTS = 3; // Maximum attempts for making a move

void displayBoard(char[][COLUMNS]);
bool makeMove(char[][COLUMNS], int, int, char);
bool isBoardFull(char[][COLUMNS]);
bool checkForWin(char[][COLUMNS], char);
void restartGame();

int main()
{
    int player1Score = 0;
    int player2Score = 0;

    char cells[ROWS][COLUMNS] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

    cout << "Enter 0 to play against another player,\nEnter 1 to play against the A.I." << endl;
    int playChoice;
    cin >> playChoice;

    //loop to determine validity of playChoice
    while (playChoice < 0 && playChoice > 1) {
        cout << "Invalid. Please enter either 0 or 1";
        cin >> playChoice;
    }

    //call to the AI function
    if (playChoice == 1) {
        //call to AI function
    }

    displayBoard(cells);

    char currentPlayer = 'X';

    while (true)
    {
        int row, col;
        int attempts = 0;

        while (true)
        {
            // Get player move
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            char colChar;
            cin >> row >> colChar;

            // Convert the column character to uppercase
            colChar = toupper(colChar);

            // Check if the move is valid
            col = colChar - 'A' + 1; // Convert column character to a numerical value
            if (row >= 1 && row <= ROWS && col >= 1 && col <= COLUMNS && cells[row - 1][col - 1] == ' ')
            {
                break; // Valid move, exit the loop
            }

            cout << "Invalid move. Try again." << endl;

            attempts++;
            if (attempts >= MAX_ATTEMPTS)
            {
                cout << "Too many invalid attempts. Exiting the game." << endl;
                return 1; // Exit with an error code
            }
        }

        // Make the move
        if (makeMove(cells, row - 1, col - 1, currentPlayer))
        {
            displayBoard(cells);

            // Check for a win
            if (checkForWin(cells, currentPlayer))
            {
                cout << "Player " << currentPlayer << " wins!" << endl;

            //call restartGame function
            restartGame();
            break;
            }

            // Check for a tie
            if (isBoardFull(cells))
            {
                cout << "The game is a tie!" << endl;
            
            //call restartGame function
            restartGame();    
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}


void displayBoard(char cells[][COLUMNS])
{
    const int DASHES = 22;

    cout << " ";
    cout << setw(8) << "A" << setw(9) << "B" << setw(9) << "C" << endl
        << endl;

    for (int i = 0; i < ROWS; i++)
    {
        cout << i + 1 << setw(8);

        for (int j = 0; j < COLUMNS; j++)
        {
            cout << cells[i][j] << setw(4);

            if (j < COLUMNS - 1)
            {
                cout << "|";
                cout << setw(4);
            }
        }

        cout << endl;

        if (i < ROWS - 1)
        {
            cout << " ";
            cout << setw(4);

            for (int k = 0; k < DASHES; k++)
            {
                cout << "-";
            }

            cout << endl;
        }
    }
    cout << endl;
}

bool makeMove(char cells[][COLUMNS], int row, int col, char player)
{
    if (cells[row][col] == ' ')
    {
        cells[row][col] = player;
        return true;
    }
    return false;
}

bool isBoardFull(char cells[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (cells[i][j] == ' ')
            {
                return false; // Found an empty cell, the board is not full
            }
        }
    }
    return true; // All cells are filled, the board is full
}

bool checkForWin(char cells[][COLUMNS], char player)
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < ROWS; i++)
    {
        if (cells[i][0] == player && cells[i][1] == player && cells[i][2] == player)
            return true; // Row win

        if (cells[0][i] == player && cells[1][i] == player && cells[2][i] == player)
            return true; // Column win
    }

    if (cells[0][0] == player && cells[1][1] == player && cells[2][2] == player)
        return true; // Diagonal win

    if (cells[0][2] == player && cells[1][1] == player && cells[2][0] == player)
        return true; // Diagonal win

    return false;
}

//Define restartGame function
    void restartGame()
    {
        cout << "Do you want to play again?" << endl;
        cout << "Enter 1 to play again. Enter 0 to end." << endl;
        
        int restart = 0;
        cin >> restart;
                
         //check for restart input validity
            while (restart !=0)
            {
                while (restart < 0 || restart > 1)
                    {
                        cout << "Invalid please enter either 0 or 1" << endl;
                        cin >> restart;
                    }
        //restart game
                if (restart = 1)
                    {
                        main();
                    }
                else 
                {
        //end game
                    return;
                }
            }
    }