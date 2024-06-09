#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../helpersFuncs.h"
#include "../structs.h"
#include "../question1/validKnightMoves.h"

//----------------------functions signatures -----------------//
void makeEmptyList(treeNodeList *lst);
bool isEmptyList(treeNodeList lst);
pathTree findAllPossibleKnightPaths(chessPos *startingPosition);
void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]);
void resetArr(bool prevPositions[BOARD_SIZE][BOARD_SIZE]);
void insertTNodeCellToEndList(treeNodeList *lst, chessPos position, treeNodeListCell *next);
treeNode *createTreeNode(chessPos position);
treeNodeListCell *createTreeNodeListCell(chessPos position, treeNodeListCell *next);



//----------------------functions-----------------//
pathTree findAllPossibleKnightPaths(chessPos *startingPosition) {
    /*
     * Description: The function creates a tree of all the possible knoght ig
     * Param chessPos *startingPosition:
     * Return: (pathTree)
     */

    chessPosArray ***possibleMoves = validKnightMoves();
    pathTree resTree;

    bool prevPositions[BOARD_SIZE][BOARD_SIZE];
    resetArr(prevPositions);

    treeNode *root = createTreeNode(*startingPosition);
    resTree.root = root;

    findAllPossibleKnightPathsRec(resTree.root, possibleMoves, prevPositions);

    return resTree;
}

void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    /*
     * Description: The function finds all the possible knight moves from a given position (tNode) and build the subtree of it.
     * Param treeNode *tNode: A given tree node.
     * Param chessPosArray ***possibleMoves: An 2D array of possible position.
     * Param bool prevPositions[BOARD_SIZE][BOARD_SIZE]:
     */
    int row = UPPERCASE_TO_DIGIT(tNode->position[0]);
    int col = CHAR_TO_INT_NUM(tNode->position[1]);

    chessPosArray validPositions = *possibleMoves[row][col];
    int amountOfMoves = validPositions.size;

    prevPositions[row][col] = true;

    for (int i = 0; i < amountOfMoves; ++i) {
        int nextPosRow = UPPERCASE_TO_DIGIT(validPositions.positions[i][0]);
        int nextPosCol = CHAR_TO_INT_NUM(validPositions.positions[i][1]);

        if (!prevPositions[nextPosRow][nextPosCol]) {
            insertTNodeCellToEndList(&tNode->next_possible_positions, validPositions.positions[i], NULL);
            findAllPossibleKnightPathsRec(tNode->next_possible_positions.tail->node, possibleMoves, prevPositions);
        }
    }

    prevPositions[row][col] = false;
}



//----------------- trees helper functions -----------------------//
treeNode *createTreeNode(chessPos position) {
    treeNode *node = (treeNode *) malloc(sizeof(treeNode));
    checkMemoryAllocation(node);

    node->position[0] = position[0];
    node->position[1] = position[1];

    treeNodeList nodeList;
    makeEmptyList(&nodeList);

    node->next_possible_positions = nodeList;

    return node;
}

treeNodeListCell *createTreeNodeListCell(chessPos position, treeNodeListCell *next) {
    treeNodeListCell *listCell = (treeNodeListCell *) malloc(sizeof(treeNodeListCell));

    listCell->node = createTreeNode(position);
    listCell->next = next;

    return listCell;
}



//----------------- lists helper functions -----------------------//
// Initializes an empty list
void makeEmptyList(treeNodeList *lst) {
    lst->head = lst->tail = NULL;
}

// Inserts a new integer at the end of the list
void insertTNodeCellToEndList(treeNodeList *lst, chessPos position, treeNodeListCell *next) {

    treeNodeListCell *listCell = createTreeNodeListCell(position, next);

    if (isEmptyList(*lst)) {
        lst->head = lst->tail = listCell;
    } else {
        lst->tail->next = listCell;
        lst->tail = listCell;
    }
}

// Returns true if the list is empty
bool isEmptyList(treeNodeList lst) {
    return (lst.head == NULL);
}



//----------------- local helper functions -----------------------//
void resetArr(bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            prevPositions[i][j] = false;
        }
    }
}