#ifndef UNTITLED_KNIGHTTOUR_H
#define UNTITLED_KNIGHTTOUR_H

#include <stdbool.h>

chessPosList *findKnightPathCoveringAllBoard(pathTree *path_tree);

bool findKnightPathCoveringRec(int x, int y, int movei, bool prevPositions[BOARD_SIZE][BOARD_SIZE], chessPosList *lst);

bool isValidKnightMove(int row, int column, bool prevPositions[BOARD_SIZE][BOARD_SIZE]);

bool isEmptyChesPosListList(chessPosList lst);

void makeEmptyChesPosList(chessPosList *lst);

void removeLastPositionFromList(chessPosList *lst);

void convertAndInsertPosition(chessPosList *lst, int x, int y);

#endif //UNTITLED_KNIGHTTOUR_H
