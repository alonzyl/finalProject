#include "./structs.h"

#ifndef FINALPROJECT_HELPERSFUNCS_H
#define FINALPROJECT_HELPERSFUNCS_H

#define DIGIT_TO_UPPERCASE(d) (d + 'A')
#define UPPERCASE_TO_DIGIT(c) (c - 'A')
#define INT_TO_CHAR_NUM(d) (d + '1')
#define CHAR_TO_INT_NUM(c) (c - '1')

void checkMemoryAllocation(void *ptr);


//-----------------all valid moves a knight can do ---------------//
int XValidMoves[8];
int YValidMoves[8];

//-----------------displayChessBoard helper functions---------------//
void makeEmptyChessPosArrayWithPos(chessPosArrayWithPos *arr);
bool isEmptyChessPosArrayWithPosList(chessPosArrayWithPos lst);
void freeChessPosArrayWithPos(chessPosArrayWithPos *lst);
chessPosCellWithPos* createNewChessPosCellWithPos(chessPosCell *cell, chessPosCellWithPos *next, int originalIndex);
void insertDataBeforeBiggerToChessPosArrayWithPosList(chessPosArrayWithPos *sortedChessPosList, chessPosCell *cell, int originalIndex);
void insertDataToEndChessPosArrayWithPosList(chessPosArrayWithPos *lst, chessPosCell *cell, int OriginalIndex);
int positionToNum(chessPos position);


//-----------------validKnightMoves helper functions---------------//
bool alreadyVisitedPosition(treeNodeListCell *lst, chessPos currPos);

#endif //FINALPROJECT_HELPERSFUNCS_H
