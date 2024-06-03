#include <stdio.h>
#include "question1/validKnightMoves.h"
#include "question2/displayChessBoard.h"
#include "structs.h"


int main(void) {
//    chessPosArray ***arr = validKnightMoves();
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE; j++) {
//            printf("my position: %d %d: ", i+1, j+1);
//            for (int k = 0; k < arr[i][j]->size; ++k) {
//                printf("%c%c ", arr[i][j]->positions[k][0], arr[i][j]->positions[k][1]);
//            }
//            printf("\n");
//        }
//    }

    chessPosList positions = getUserInput();
    int i=0;
    deleteDuplicates(&positions);
    int t=0;
    chessPosArrayWithPos test = sortList(positions);
    int j=0;

    return 0;
}
