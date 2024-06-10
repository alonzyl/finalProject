#include "./structs.h"

#ifndef FINALPROJECT_HELPERSFUNCS_H
#define FINALPROJECT_HELPERSFUNCS_H

#define DIGIT_TO_UPPERCASE(d) (d + 'A')
#define UPPERCASE_TO_DIGIT(c) (c - 'A')
#define INT_TO_CHAR_NUM(d) (d + '1')
#define CHAR_TO_INT_NUM(c) (c - '1')
#define MAX_KNIGHT_MOVES_VARIATIONS 8
#define MIN_PHY_SIZE 2
#define MIN_LOG_SIZE 0


//-----------------overall helper functions ---------------//
void checkMemoryAllocation(void *ptr);


//-----------------all valid moves a knight can do ---------------//
int XValidMoves[MAX_KNIGHT_MOVES_VARIATIONS];
int YValidMoves[MAX_KNIGHT_MOVES_VARIATIONS];


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


//-----------------main helper functions---------------//
void getUserInput(chessPos *startingPosition);


#endif //FINALPROJECT_HELPERSFUNCS_H
