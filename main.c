#include <stdio.h>
#include "question1/validKnightMoves.h"
#include "question2/displayChessBoard.h"
#include "question3/knightPaths.h"
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

    chessPos temp;
    temp[0] = 'A';
    temp[1] = '2';

    pathTree temp2;

    temp2 = findAllPossibleKnightPaths(&temp);
    int i=0;
}