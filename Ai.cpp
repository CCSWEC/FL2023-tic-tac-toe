#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
class TicTacToe {
private:
    std::vector<char> board;
    char current_player;

    void displayBoard() {
        for (int i = 0; i < 3; ++i) {
            std::cout << board[i*3] << "|" << board[i*3 + 1] << "|" << board[i*3 + 2] << std::endl;
            if (i < 2) std::cout << "-+-+-" << std::endl;
        }
    }

    bool makeMove(int position) {
        if (position >= 0 && position < board.size() && board[position] == ' ') {
            board[position] = current_player;
            return true;
        }
        return false;
    }

    char checkWin() {
        const int win_conditions[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };
        for (auto &condition : win_conditions) {
            if (board[condition[0]] == board[condition[1]] &&
                board[condition[1]] == board[condition[2]] &&
                board[condition[0]] != ' ') {
                return board[condition[0]];
            }
        }
        return 0;
    }

    void switchPlayer() {
        current_player = (current_player == 'X') ? 'O' : 'X';
    }

    void makeAIMove() {
        std::vector<int> available_positions;
        for (int i = 0; i < board.size(); ++i) {
            if (board[i] == ' ') available_positions.push_back(i);
        }
        int position = available_positions[rand() % available_positions.size()];
        makeMove(position);
        switchPlayer();
    }

    void displayResult(char winner) {
        if (winner) {
            std::cout << "Player " << winner << " wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
    }

public:
    TicTacToe() : board(9, ' '), current_player('X') {}

    void initializeBoard() {
        board.assign(9, ' ');
        current_player = 'X';
    }

    void playAgainstAI() {
        char winner = 0;
        while (!winner && std::count(board.begin(), board.end(), ' ') > 0) {
            displayBoard();
            if (current_player == 'X') {
                bool validMove = false;
                while (!validMove) {
                    int position;
                    std::cout << "Choose your move (0-8): ";
                    std::cin >> position;
                    validMove = makeMove(position);
                    if (!validMove) {
                        std::cout << "Invalid move, try again." << std::endl;
                    }
                }
            } else {
                makeAIMove();
            }
            winner = checkWin();
            if (!winner) switchPlayer(); 
        }
        displayBoard();
        displayResult(winner);
    }

    void playAgainstPlayer() {
        char winner = 0;
        while (!winner && std::count(board.begin(), board.end(), ' ') > 0) {
            displayBoard();
            bool validMove = false;
            while (!validMove) {
                int position;
                std::cout << "Player " << current_player << "'s turn (0-8): ";
                std::cin >> position;
                validMove = makeMove(position);
                if (!validMove) {
                    std::cout << "Invalid move, try again." << std::endl;
                }
            }
            winner = checkWin();
            if (!winner) switchPlayer(); 
        }
        displayBoard();
        displayResult(winner);
    }

    static void displayMenu() {
        std::cout << "Welcome to Tic Tac Toe!" << std::endl;
        std::cout << "1. Play Against AI" << std::endl;
        std::cout << "2. Play Against Another Player" << std::endl;
        std::cout << "3. Exit" << std::endl;
    }

    static int getUserInput() {
        int choice;
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;
        return choice;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    TicTacToe game;
    while (true) {
        TicTacToe::displayMenu();
        int choice = TicTacToe::getUserInput();

        switch (choice) {
            case 1:
                game.initializeBoard();
                game.playAgainstAI();
                break;
            case 2:
                game.initializeBoard();
                game.playAgainstPlayer();
                break;
            case 3:
                std::cout << "Exiting game. Thanks for playing!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    }
}
