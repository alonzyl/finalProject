#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "../structs.h"
#include "../helpersFuncs.h"
#include "./displayChessBoard.h"

//----------------------functions implementation-----------------//
chessPosArrayWithPos uniqueSortList(chessPosList lst) {
    /*
     * Description: The function create sorted and unique chessPosList.
     * Param chessPosList lst: A given list of chessPosCells.
     * Return: returns a linked list with the chessPosList sorted
     */

//    TODO make sure if position printed is the original pos or after removing dupls
    chessPosCell *currPosCell = lst.head;
    int originalIndex = 0;
    bool isInitial = true;

    chessPosArrayWithPos sortedChessPosList;
    makeEmptyChessPosArrayWithPos(&sortedChessPosList);


    while (currPosCell != NULL) {

        if (isInitial) {
            insertDataToEndChessPosArrayWithPosList(&sortedChessPosList, currPosCell, originalIndex++);
            isInitial = false;
            currPosCell = currPosCell->next;
            continue;
        }

        int resListTailPos = positionToNum(sortedChessPosList.tail->cell->position);
        int currPos = positionToNum(currPosCell->position);

        if (resListTailPos < currPos) {
            insertDataToEndChessPosArrayWithPosList(&sortedChessPosList, currPosCell, originalIndex++);
        }
        else if (resListTailPos > currPos)   // e.g A4 < H5
        {
            insertDataBeforeBiggerToChessPosArrayWithPosList(&sortedChessPosList, currPosCell, originalIndex++);
        }

        currPosCell = currPosCell->next;
    }
    return sortedChessPosList;
}

void printTable(chessPosArrayWithPos sortedChessPosList) {
    /*
     * Description: The function prints the chess table with the original positions
     * Param chessPosArrayWithPos lst: A given list of chessPosArrayWithPos.
    */

    chessPosCellWithPos *runner = sortedChessPosList.head;

    //align the print
    printf(" ");
    for (int i = 0; i < BOARD_SIZE ; ++i) {  // a loop to print the header
        printf("   %d", i+1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {  // print board border
            if (j == 0)
                printf("%2c", DIGIT_TO_UPPERCASE(i));

            if (UPPERCASE_TO_DIGIT(runner->cell->position[0]) == i && CHAR_TO_INT_NUM(runner->cell->position[1]) == j) {
                printf("|%2d|", runner->originalIndex+1);
                runner = runner->next;
            } else
                printf("| |");
        }
        printf("\n");
    }
}

void display(chessPosList *lst) {
    /*
     * Description: The function prints a chess board by a given chessPosList.
     * Param chessPosList *lst: A given list of chess positions.
     */

    chessPosArrayWithPos sortedList = uniqueSortList(*lst);
    printTable(sortedList);
}
