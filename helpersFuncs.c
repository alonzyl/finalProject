#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "helpersFuncs.h"
#include "structs.h"

// Checks if memory allocation was successful and exits if not
void checkMemoryAllocation(void *ptr) {
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}


//-----------------displayChessBoard helper functions---------------//
void makeEmptyChessPosArrayWithPos(chessPosArrayWithPos *arr) {
    arr->head = arr->tail = NULL;
}
// Returns true if the list is empty
bool isEmptyChessPosArrayWithPosList(chessPosArrayWithPos lst) {
    return (lst.head == NULL);
}

// Frees all nodes and their associated data in a list
void freeChessPosArrayWithPos(chessPosArrayWithPos *lst) {
    chessPosCellWithPos *curr = lst->head, *saver;
    while (curr != NULL) {
        saver = curr->next;
        free(curr->cell);
        free(curr);
        curr = saver;
    }
}

chessPosCellWithPos *createNewChessPosCellWithPos(chessPosCell *cell, chessPosCellWithPos *next, int originalIndex) {
    /*
     * Description: create new chessPosCellWithPos node
     */

    chessPosCellWithPos *newTail = malloc(sizeof(chessPosCellWithPos));
    checkMemoryAllocation(newTail);

    newTail->next = next;
    newTail->cell = cell;
    newTail->originalIndex = originalIndex;

    return newTail;
}

void insertDataBeforeBiggerToChessPosArrayWithPosList(chessPosArrayWithPos *sortedChessPosList, chessPosCell *cell,
                                                      int originalIndex) {
    chessPosCellWithPos *prev = NULL;
    chessPosCellWithPos *tmpRunner = sortedChessPosList->head;

    while (tmpRunner != NULL && positionToNum(tmpRunner->cell->position) < positionToNum(cell->position)) {
        prev = tmpRunner;
        tmpRunner = tmpRunner->next;
    }

    chessPosCellWithPos *newChessPosCellWithPos = createNewChessPosCellWithPos(cell, tmpRunner, originalIndex++);

    if (prev != NULL) {
        prev->next = newChessPosCellWithPos;
    }
    else
    {
        sortedChessPosList->head = newChessPosCellWithPos;
    }

}

// Inserts a new integer at the end of the list
void insertDataToEndChessPosArrayWithPosList(chessPosArrayWithPos *lst, chessPosCell *cell, int originalIndex) {
    chessPosCellWithPos *newTail = createNewChessPosCellWithPos(cell, NULL, originalIndex);

    if (isEmptyChessPosArrayWithPosList(*lst)) {
        lst->head = lst->tail = newTail;
    } else {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
}

int positionToNum(chessPos position) {
    int numPosition = UPPERCASE_TO_DIGIT(position[0]);

    numPosition *= 10;
    numPosition += CHAR_TO_INT_NUM(position[1]);

    return numPosition;
}