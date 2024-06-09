#ifndef FINALPROJECT_VALIDKNIGHTMOVES_H
#define FINALPROJECT_VALIDKNIGHTMOVES_H

#include <stdbool.h>
#include "../structs.h"

void findPossibleKnightMoves(int row, int column, chessPosArray *arr);
bool isValidMove(int x, int y);
void freeChessPosArray(chessPosArray ***arr);
chessPosArray ***populateChessPosArray();
chessPosArray ***validKnightMoves();


#endif //FINALPROJECT_VALIDKNIGHTMOVES_H