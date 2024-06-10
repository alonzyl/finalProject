#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../helpersFuncs.h"
#include "KnightTour.h"
#include "../question3/knightPaths.h"

chessPosList *findKnightPathCoveringAllBoard(pathTree *path_tree) {
    bool prevPositions[BOARD_SIZE][BOARD_SIZE];
    int row = UPPERCASE_TO_DIGIT(path_tree->root->position[0]);
    int column = CHAR_TO_INT_NUM(path_tree->root->position[1]);

    chessPosList *lst = (chessPosList *) malloc(sizeof(chessPosList));
    checkMemoryAllocation(lst);
    makeEmptyChesPosList(lst);

    resetPrevPosArr(prevPositions);

    // this is the first move the knight does
    prevPositions[row][column] = true;
    convertAndInsertPosition(lst, row, column);

    if (!findKnightPathCoveringRec(row, column, 1, prevPositions, lst)) {
        free(lst); // Free the list if no solution is found
        return NULL;
    }

    return lst;
}

/* A recursive utility function to solve Knight Tour
   problem */
bool findKnightPathCoveringRec(int x, int y, int amountOfMoves, bool prevPositions[BOARD_SIZE][BOARD_SIZE], chessPosList *lst) {
    if (amountOfMoves == BOARD_SIZE * BOARD_SIZE)
        return 1;

    for (int i = 0; i < 8; i++) {
        int nextX = x + XValidMoves[i];
        int nextY = y + YValidMoves[i];
        if (isValidKnightMove(nextX, nextY, prevPositions)) {
            prevPositions[nextX][nextY] = true;
            convertAndInsertPosition(lst, nextX, nextY);

            if (findKnightPathCoveringRec(nextX, nextY, amountOfMoves + 1, prevPositions, lst) == true)
                return true;
            else {
                prevPositions[nextX][nextY] = false;
                removeLastPositionFromList(lst);
            }
        }
    }
    return false; // This should be outside the for loop
}

//----------------- local helper functions -----------------------//

bool isValidKnightMove(int row, int column, bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    /*
     * Description: The function validate if a given coordinate exist in a chess board.
     *
     * Param int row: A whole number on the horizontal Axis.
     * Param int column: A whole number on the vertical Axis.
     *
     * Returns: (bool) indicates whether the coordinate exists on the board.
     */

    return row >= 0 && column >= 0 && row < BOARD_SIZE && column < BOARD_SIZE && prevPositions[row][column] == false;
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

    if (isEmptyChesPosListList(*lst)) {
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