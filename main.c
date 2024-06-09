#include <stdio.h>
#include "question1/validKnightMoves.h"
#include "question2/displayChessBoard.h"
#include "question3/knightPaths.h"
#include "question4/KnightTour.h"

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

//    temp2 = findAllPossibleKnightPaths(&temp);
//    int i=0;

//    chessPosList *findKnightPathCoveringAllBoard(pathTree *path_tree)
    chessPos pos;
    pos[0] = 'A';
    pos[1] = '1';

    treeNode treeTmp;
    treeNodeList listTmp;

    treeTmp.position[0] = pos[0];
    treeTmp.position[1] = pos[1];
    treeTmp.next_possible_positions = listTmp;
    pathTree rootTemp;
    rootTemp.root = &treeTmp;

    findKnightPathCoveringAllBoard(&rootTemp);
    printf("%d", test);
}