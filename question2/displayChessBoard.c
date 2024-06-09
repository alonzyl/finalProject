#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "../structs.h"
#include "../helpersFuncs.h"

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
    for (int i = 0; i < BOARD_SIZE ; ++i) {  // a loop to print the header
        printf("  %d", i+1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {  // print board border
            if (j == 0)
                printf("%c", DIGIT_TO_UPPERCASE(i));

            if (UPPERCASE_TO_DIGIT(runner->cell->position[0]) == i && CHAR_TO_INT_NUM(runner->cell->position[1]) == j) {
                printf("|%d|", runner->originalIndex+1);
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


//----------------- local helper functions -----------------------//
chessPosList getUserInput() {
    chessPosList list = {NULL, NULL};
    char input[3];
    bool validInput;

    while (1) { // todo: change condition to variable
        printf("Enter a chess position (e.g., A1, H8) or '-1' to exit: ");
        fgets(input, sizeof(input), stdin); // todo: remove stdin

        // Remove the newline character from the input string
        int i = 0;
        while (input[i] != '\n' && input[i] != '\0') {
            i++;
        }
        input[i] = '\0';

        // Check if the user wants to exit
        if (strcmp(input, "-1") == 0) {
            printf("Exiting...\n");
            break;
        }

        validInput = (strlen(input) == 2 && (input[0] >= 'A' && input[0] <= 'H') &&
                      (input[1] >= '1' && input[1] <= '8')); // todo:  create macro to check this

        if (validInput) { // todo: stack it to another function
            chessPosCell *newNode = (chessPosCell *) malloc(sizeof(chessPosCell));
            newNode->position[0] = input[0];
            newNode->position[1] = input[1];
            newNode->next = NULL;

            if (list.head == NULL) {
                list.head = newNode;
                list.tail = newNode;
            } else {
                list.tail->next = newNode;
                list.tail = newNode;
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return list;
}
