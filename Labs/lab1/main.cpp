#include <iostream>
using namespace std;

// Constants
const int NUM_BOARD_ROWS = 8;
const int NUM_BOARD_COLS = 8;

#include "functions.h"

int main()
{
    // Set the random number generator seed
    custom_srand(2023);

    // Initialize the minesweeper board and the display board
    bool minesweeperBoard[NUM_BOARD_ROWS][NUM_BOARD_COLS];
    for (int row = 0; row < NUM_BOARD_ROWS; ++row)
    {
        for (int col = 0; col < NUM_BOARD_COLS; ++col)
        {
            // custom_rand() gives a number between 0 and 32767, this means there are roughly 7.5% bombs
            minesweeperBoard[row][col] = custom_rand() < 2500;
        }
    }

    int displayBoard[NUM_BOARD_ROWS][NUM_BOARD_COLS];
    // Task 1: We initialize the displayBoard here
    initializeDisplayBoard(displayBoard);

    int choice;
    do
    {
        // This big section prints the board
        cout << ' ';
        for (int col = 0; col < NUM_BOARD_COLS; ++col)
            cout << col << ' ';
        cout << endl;
        for (int col = 0; col < 2 * NUM_BOARD_COLS + 1; ++col)
            cout << '=';
        cout << endl;
        for (int row = 0; row < NUM_BOARD_ROWS; ++row)
        {
            for (int col = 0; col < NUM_BOARD_COLS; ++col)
            {
                // Task 2: We print the displayBoard here
                cout << '|' << getDisplayChar(displayBoard[row][col]);
            }
            cout << '|' << ' ' << row << endl;
        }
        for (int col = 0; col < 2 * NUM_BOARD_COLS + 1; ++col)
            cout << '=';
        cout << endl;

        // Task 3: We check for win condition here
        if (checkWin(displayBoard, minesweeperBoard))
        {
            cout << "Congratulations! You won!" << endl;
            break;
        }

        cout << endl
             << "Select an option: " << endl;
        cout << "0: Exit" << endl;
        cout << "1: Excavate a tile" << endl;
        cout << "2: Place a flag" << endl;
        cin >> choice;

        if (choice < 0 || choice > 2)
        {
            cout << "Invalid choice." << endl;
            continue;
        }

        if (choice == 0)
        {
            break;
        }

        int rowChoice, colChoice;

        do
        {
            cout << "Choose a row from 0 to " << NUM_BOARD_ROWS - 1 << ": " << endl;
            cin >> rowChoice;
            if (rowChoice < 0 || rowChoice >= NUM_BOARD_ROWS)
            {
                cout << "Row index out of range, try again." << endl;
                continue;
            }
            else
                break;
        } while (true);

        do
        {
            cout << "Choose a column from 0 to " << NUM_BOARD_COLS - 1 << ": " << endl;
            cin >> colChoice;
            if (colChoice < 0 || colChoice >= NUM_BOARD_COLS)
            {
                cout << "Column index out of range, try again." << endl;
                continue;
            }
            else
                break;
        } while (true);

        if (choice == 2)
        {
            // Task 4: The player toggles the flag status on the provided coordinate
            setFlag(displayBoard, rowChoice, colChoice);
        }
        else
        {
            if (displayBoard[rowChoice][colChoice] != -1)
                continue;
            else if (minesweeperBoard[rowChoice][colChoice])
            {
                // Modified version of the board print to show the bombs
                cout << ' ';
                for (int col = 0; col < NUM_BOARD_COLS; ++col)
                    cout << col << ' ';
                cout << endl;
                for (int col = 0; col < 2 * NUM_BOARD_COLS + 1; ++col)
                    cout << '=';
                cout << endl;
                for (int row = 0; row < NUM_BOARD_ROWS; ++row)
                {
                    for (int col = 0; col < NUM_BOARD_COLS; ++col)
                    {
                        cout << '|' << (minesweeperBoard[row][col] ? '*' : getDisplayChar(displayBoard[row][col]));
                    }
                    cout << '|' << ' ' << row << endl;
                }
                for (int col = 0; col < 2 * NUM_BOARD_COLS + 1; ++col)
                    cout << '=';
                cout << endl;
                cout << "Game over! You excavated a mine!" << endl;
                break;
            }
            else
            {
                // Task 5: The player excavates the chosen tile
                excavateTile(displayBoard, rowChoice, colChoice, minesweeperBoard);
            }
        }
    } while (true);
}