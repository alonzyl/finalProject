#include <stdlib.h>
#include <stdbool.h>
#include "../structs.h"
#include "../helpersFuncs.h"


// TODO WHEN VALID MOVE TO SAVE chessPosArray ARRAY PROPERLY

void findPossibleKnightMoves(int row, int column, chessPosArray *arr);

bool isValidMove(int x, int y);

void freeChessPosArray(chessPosArray ***arr);

chessPosArray ***populateChessPosArray();

chessPosArray ***validKnightMoves();


void findPossibleKnightMoves(int row, int column, chessPosArray *arr) {

    // All possible moves of a knight
    int X[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int logSize = 0, phySize = 2;

    // there are only 8 possible ways for the knight to move
    for (int i = 0; i < 8; i++) {

        // Position of knight after move
        int x = row + X[i];
        int y = column + Y[i];

        // count valid moves
        if (isValidMove(x, y)) {
            if (logSize >= phySize) {
                phySize *= 2;
                arr->positions = (chessPos *) realloc(arr->positions, sizeof(chessPos));
                checkMemoryAllocation(arr->positions);
            }

            arr->size++;
            arr->positions[logSize][0] = INT_TO_CHAR_NUM(x);
            arr->positions[logSize][1] = DIGIT_TO_UPPERCASE(y);
            logSize++;
        }
    }
    if (logSize < phySize) {
        arr->positions = (chessPos *)realloc(arr->positions, logSize);
    }

}

//----------------- helper functions -----------------------//

bool isValidMove(int row, int column)
{
    /*
     * Description: The function validate if a given coordinate exist in a chess board.
     *
     * Param int row: A whole number on the horizontal Axis.
     * Param int column: A whole number on the vertical Axis.
     *
     * Returns: (bool) indicates whether the coordinate exists on the board.
     */

    return row >= 0 && column >= 0 && row < BOARD_SIZE && column < BOARD_SIZE;
}


chessPosArray ***populateChessPosArray()
{
    /*
     * Description: The function creates a chess board of size BOARD_SIZE.
     *
     * Return: (chessPosArray) A 2D array of chessPosArray pointers as each coordinate on the board.
     */

    chessPosArray ***arr = (chessPosArray ***) malloc(BOARD_SIZE * sizeof(chessPosArray **));
    checkMemoryAllocation(arr);


    for (int i = 0; i < BOARD_SIZE; i++) {
        arr[i] = (chessPosArray **) malloc(
                BOARD_SIZE * sizeof(chessPosArray *));

        for (int j = 0; j < BOARD_SIZE; j++) {
            arr[i][j] = (chessPosArray *) malloc(sizeof(chessPosArray));
            checkMemoryAllocation(arr[i][j]);

            arr[i][j]->size = 0;
            arr[i][j]->positions = (chessPos *) malloc(2 * sizeof(chessPos));
            checkMemoryAllocation(arr[i][j]->positions);
        }
    }
    return arr;
}


chessPosArray ***validKnightMoves()
{
    /*
     * Description: The function creates a 2D chess board of size BOARD_SIZE and for each coordinate
     *              on the board, it lists all the validate moves that a knight can make from there.
     *
     * Return: (chessPosArray) 2D array of chessPos pointer contains valid Knight move list.
     */

    chessPosArray ***arr = populateChessPosArray();

    int row, column;
    for (row = 0; row < BOARD_SIZE; row++) {
        for (column = 0; column < BOARD_SIZE; column++) {
            findPossibleKnightMoves(row, column, arr[row][column]);
        }
    }
    return arr;
}


void freeChessPosArray(chessPosArray ***arr)
{
    /*
     * Description: The function frees a given chessPossArray.
     *
     * Param chessPosArray ***arr: A given chessPosArray.
     */

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int column = 0; column < BOARD_SIZE; column++) {
            free(arr[row][column]->positions);
            free(arr[row][column]);
        }
        free(arr[row]);
    }
    free(arr);
}