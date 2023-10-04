/* -------------------------------------------------------------- */
/* This part serves as a pseudo random number generator for auto grade purpose only */
/* You are suggested not to refer to these codes in this assignment. */
/* You are not allowed to use global variables in this course. */
unsigned int next_num = 1; // Here we initiate an unsigned integer to be used in the following functions.

unsigned int custom_rand() // This function is used to return a pseudo random number from 0 to 32767.
{
    next_num = next_num * 1103515245 + 2011;
    return static_cast<unsigned int>(next_num / 65536) % 32768;
}

void custom_srand(unsigned int seed) // This function is used to set a seed of the pseudo random number generator.
{
    next_num = seed;
}
/* Everytime you call rand(), you will get a new pseudo random number. For the same seed, the sequence of pseudo
   random number is fixed. For example, when seed = 3, the sequence of pseudo random number is fixed to be [17746,
   30897, 9622, 18921, 4034, 17510, 24152, 14388, 23665, 31532, ...]. When seed = 5, the sequence of pseudo random
   number is fixed to be [18655, 32247, 9873, 9718, 26373, 27678, 5314, 22512, 31845, 22885, ...] */
/* -------------------------------------------------------------- */

/* -------------------------------------------------------------- */
/* Your tasks begin below this line */
/* -------------------------------------------------------------- */

/**
 * TODO
 *
 * Initialize displayBoard's all entries to -1.
 */
void initializeDisplayBoard(int displayBoard[][NUM_BOARD_COLS])
{
    for (int i = 0; i < NUM_BOARD_ROWS; i++)
    {
        for (int j = 0; j < NUM_BOARD_COLS; j++)
        {
            displayBoard[i][j] = -1;
        }
    }
}

/**
 * TODO
 *
 * Return a char corresponding to the display tile's value.
 * - Unexcavated tile: ' '
 * - Flagged tile: '#'
 * - Excavated tile: the tile's value
 */
char getDisplayChar(int displayBoardTile)
{
    if (displayBoardTile == -1)
    {
        return ' ';
    }
    else if (displayBoardTile == 10)
    {
        return '#';
    }
    return (char)(displayBoardTile + '0');
}

/**
 * TODO
 *
 * Check if the player has won the game.
 * The game is won when all non-mine tiles have been excavated.
 */
bool checkWin(int displayBoard[][NUM_BOARD_COLS], bool minesweeperBoard[][NUM_BOARD_COLS])
{
    for (int i = 0; i < NUM_BOARD_ROWS; i++)
    {
        for (int j = 0; j < NUM_BOARD_COLS; j++)
        {
            if (minesweeperBoard[i][j] == false && (displayBoard[i][j] == -1 || displayBoard[i][j] == 10))
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * TODO
 *
 * Toggle the flag status on the specified tile.
 * If the tile is unexcavated, set it to flagged. If it is flagged, set it to unexcavated. Ignore excavated tiles.
 * You can assume (row, col) refers to a valid tile.
 */
void setFlag(int displayBoard[][NUM_BOARD_COLS], int row, int col)
{
    if (displayBoard[row][col] == -1)
    {
        displayBoard[row][col] = 10;
    }
    else if (displayBoard[row][col] == 10)
    {
        displayBoard[row][col] = -1;
    }
}

/**
 * TODO
 *
 * Excavate the specified tile by:
 * - Counting the number of adjacent mines
 * - Set the tile value to that number
 * - If the value is 0, excavate all unexcavated adjacent tiles without flags.
 * You can assume (row, col) refers to a valid unexcavated tile. However, make sure your recursive calls also provide valid parameters.
 */
void excavateTile(int displayBoard[][NUM_BOARD_COLS], int row, int col, bool minesweeperBoard[][NUM_BOARD_COLS])
{
    // check surroundings
    int mines = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        if (i < 0 || i >= NUM_BOARD_ROWS)
            continue;
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (j < 0 || j >= NUM_BOARD_COLS || (i == row && j == col))
                continue;
            if (minesweeperBoard[i][j])
                mines++;
        }
    }
    displayBoard[row][col] = mines;

    if (mines == 0)
    {
        for (int i = row - 1; i <= row + 1; i++)
        {
            if (i < 0 || i >= NUM_BOARD_ROWS)
                continue;
            for (int j = col - 1; j <= col + 1; j++)
            {
                if (j < 0 || j >= NUM_BOARD_COLS || (i == row && j == col))
                    continue;
                if (displayBoard[i][j] == -1)
                    excavateTile(displayBoard, i, j, minesweeperBoard);
            }
        }
    }
}