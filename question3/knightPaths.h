#ifndef FINALPROJECT_KNIGHTPATHS_H
#define FINALPROJECT_KNIGHTPATHS_H

#include "../structs.h"
#include <stdbool.h>

void makeEmptyList(treeNodeList *lst);
bool isEmptyList(treeNodeList lst);
pathTree findAllPossibleKnightPaths(chessPos *startingPosition);
void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]);
void resetPrevPosArr(bool prevPositions[BOARD_SIZE][BOARD_SIZE]);
void insertTNodeCellToEndList(treeNodeList *lst, chessPos position, treeNodeListCell *next);
treeNode *createTreeNode(chessPos position);
treeNodeListCell *createTreeNodeListCell(chessPos position, treeNodeListCell *next);
void freePathTree(pathTree *tree);
void freeTreeNodeList(treeNodeList *list);
void freeTreeNode(treeNode *node);

#endif //FINALPROJECT_KNIGHTPATHS_H
