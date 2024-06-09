#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../helpersFuncs.h"
#include "../structs.h"
#include "../question1/validKnightMoves.h"
#include "KnightTour.h"


void resetPrevPositionsArr(int prevPositions[BOARD_SIZE][BOARD_SIZE]);

int solveKTUtil(int x, int y, int movei, int sol[BOARD_SIZE][BOARD_SIZE], chessPosList *lst);

bool isValidKnightMove(int row, int column, int prevPositions[BOARD_SIZE][BOARD_SIZE]);

bool isEmptyChesPosListList(chessPosList lst);

void makeEmptyChesPosList(chessPosList *lst);

void removeLastPositionFromList(chessPosList *lst);

void convertAndInsertPosition(chessPosList *lst, int x, int y);


chessPosList *findKnightPathCoveringAllBoard(pathTree *path_tree) {
    int sol[BOARD_SIZE][BOARD_SIZE];
    int row = UPPERCASE_TO_DIGIT(path_tree->root->position[0]);
    int column = CHAR_TO_INT_NUM(path_tree->root->position[1]);

    chessPosList *lst = (chessPosList *) malloc(sizeof(chessPosList));
    checkMemoryAllocation(lst);
    makeEmptyChesPosList(lst);

    resetPrevPositionsArr(sol);

    // this is the first move the knight does
    sol[row][column] = 0;
    convertAndInsertPosition(lst, row, column);

    if (solveKTUtil(row, column, 1, sol,lst) == 0) {
        free(lst); // Free the list if no solution is found
        return NULL;
    }
    int i = 0;

    return lst;
}

/* A recursive utility function to solve Knight Tour
   problem */
int solveKTUtil(int x, int y, int movei, int sol[BOARD_SIZE][BOARD_SIZE], chessPosList *lst) {
    int k, next_x, next_y;
    if (movei == BOARD_SIZE * BOARD_SIZE)
        return 1;

    /* Try all next moves from the current coordinate x, y */
    for (k = 0; k < 8; k++) {
        next_x = x + XValidMoves[k];
        next_y = y + YValidMoves[k];
        if (isValidKnightMove(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            convertAndInsertPosition(lst, next_x, next_y);

            if (solveKTUtil(next_x, next_y, movei + 1, sol, lst) == 1)
                return 1;
            else {
                sol[next_x][next_y] = -1; // backtracking
                removeLastPositionFromList(lst);
            }
        }
    }
    return 0; // This should be outside the for loop
}
//----------------- local helper functions -----------------------//
    void resetPrevPositionsArr(int prevPositions[BOARD_SIZE][BOARD_SIZE]) {
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                prevPositions[i][j] = -1;
            }
        }
    }

    bool isValidKnightMove(int row, int column, int prevPositions[BOARD_SIZE][BOARD_SIZE]) {
        /*
         * Description: The function validate if a given coordinate exist in a chess board.
         *
         * Param int row: A whole number on the horizontal Axis.
         * Param int column: A whole number on the vertical Axis.
         *
         * Returns: (bool) indicates whether the coordinate exists on the board.
         */

        return row >= 0 && column >= 0 && row < BOARD_SIZE && column < BOARD_SIZE && prevPositions[row][column] == -1;
    }


//----------------- lists helper functions -----------------------//
    void makeEmptyChesPosList(chessPosList *lst) {
        lst->head = lst->tail = NULL;
    }

    bool isEmptyChesPosListList(chessPosList lst) {
        return (lst.head == NULL);
    }

    void convertAndInsertPosition(chessPosList *lst, int x, int y) {
        chessPos newPos = {DIGIT_TO_UPPERCASE(x), INT_TO_CHAR_NUM(y)};
        chessPosCell *listCell = (chessPosCell *) malloc(sizeof(chessPosCell));
        checkMemoryAllocation(listCell);

        listCell->position[0] = newPos[0];
        listCell->position[1] = newPos[1];
        listCell->next = NULL;

        if (lst->head == NULL) {
            lst->head = lst->tail = listCell;
        } else {
            lst->tail->next = listCell;
            lst->tail = listCell;
        }
    }

    void removeLastPositionFromList(chessPosList *lst) {
        if (lst->tail == NULL) return; // Empty list, nothing to remove

        chessPosCell *temp = lst->tail;
        if (lst->head == lst->tail) {
            lst->head = lst->tail = NULL;
        } else {
            chessPosCell *prev = lst->head;
            while (prev->next != lst->tail) {
                prev = prev->next;
            }
            prev->next = NULL;
            lst->tail = prev;
        }
        free(temp);
    }