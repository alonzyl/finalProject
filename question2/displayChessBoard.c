#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "../structs.h"
#include "../helpersFuncs.h"

void resetArray(bool visited[], int size);

void deleteDuplicates(chessPosList *lst);

chessPosArrayWithPos sortList(chessPosList lst) {
    chessPosCell *currPosCell = lst.head;
    int originalIndex = 0;

    chessPosArrayWithPos sortedChessPosList;
    makeEmptyChessPosArrayWithPos(&sortedChessPosList);

    while (currPosCell != NULL) {
        if (isEmptyChessPosArrayWithPosList(sortedChessPosList) ||
            positionToNum(sortedChessPosList.tail->cell->position) < positionToNum(currPosCell->position)) {
            insertDataToEndChessPosArrayWithPosList(&sortedChessPosList, currPosCell, originalIndex++);
        } else  // e.g A4 < H5
        {
            insertDataBeforeBiggerToChessPosArrayWithPosList(&sortedChessPosList, currPosCell, originalIndex++);
        }
        currPosCell = currPosCell->next;
    }
    return sortedChessPosList;
}

void display(chessPosList *lst) {

}

chessPosList getUserInput();

chessPosList getUserInput() {
    chessPosList list = {NULL, NULL};
    char input[3];
    bool validInput;

    while (1) {
        printf("Enter a chess position (e.g., A1, H8) or '-1' to exit: ");
        fgets(input, sizeof(input), stdin);

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
                      (input[1] >= '1' && input[1] <= '8'));

        if (validInput) {
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

void deleteDuplicates(chessPosList *lst) {
    chessPosCell *current = lst->head;
    chessPosCell *prev = NULL;

//    TODO CHANGE THE 55
    bool visited[55]; // 'h5' ascii
    resetArray(visited, 55);

    while (current != NULL) {
        int numPosition = UPPERCASE_TO_DIGIT(current->position[0]) * 5 + CHAR_TO_INT_NUM(current->position[1]);

        if (visited[numPosition]) {
            chessPosCell *toDelete = current;
            current = current->next;

            if (prev != NULL) {
                prev->next = current;
            } else {
                lst->head = current;
            }

            if (lst->tail == toDelete) {
                lst->tail = prev;
            }

            free(toDelete);
        } else {
            visited[numPosition] = true;
            prev = current;
            current = current->next;
        }
    }

    if (lst->tail != NULL && prev != NULL && prev->next != NULL) {
        lst->tail = prev;
    }
}

void resetArray(bool visited[], int size) {
    for (int i = 0; i < size; ++i)
        visited[i] = false;
}