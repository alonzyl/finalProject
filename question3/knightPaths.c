#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../helpersFuncs.h"
#include "../structs.h"
#include "../question1/validKnightMoves.h"
#include "./knightPaths.h"

//----------------------functions-----------------//
pathTree findAllPossibleKnightPaths(chessPos *startingPosition) {
    /*
     * Description: The function creates a tree that represents all the possible knight paths from a given position.
     * Param chessPos *startingPosition: A given chess starting position.
     * Return: (pathTree) A tree of valid night paths.
     */

    chessPosArray ***possibleMoves = validKnightMoves();
    pathTree resTree;

    bool prevPositions[BOARD_SIZE][BOARD_SIZE];  // bool map of the positions that the knight had visited.
    resetPrevPosArr(prevPositions);

    treeNode *root = createTreeNode(*startingPosition);
    resTree.root = root;

    findAllPossibleKnightPathsRec(resTree.root, possibleMoves, prevPositions);

    return resTree;
}

void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    /*
     * Description: The function finds all the possible knight moves from a given position (tNode) and build the subtree of it.
     *
     * Param treeNode *tNode: A given tree node.
     * Param chessPosArray ***possibleMoves: An 2D array of possible knight position from each position on chess board.
     * Param bool prevPositions[BOARD_SIZE][BOARD_SIZE]: A bool map in the size of the defined chess board which
     *                                                   represents positions which the knight have visited already.
     */

    int currRow = UPPERCASE_TO_DIGIT(tNode->position[0]);
    int currCol = CHAR_TO_INT_NUM(tNode->position[1]);

    chessPosArray validPositions = *possibleMoves[currRow][currCol];
    int amountOfMoves = validPositions.size;

    prevPositions[currRow][currCol] = true;  // to prevent subtrees of that tNode include that tNode in their subtrees

    for (int i = 0; i < amountOfMoves; ++i) {
        int nextPosRow = UPPERCASE_TO_DIGIT(validPositions.positions[i][0]);
        int nextPosCol = CHAR_TO_INT_NUM(validPositions.positions[i][1]);

        if (!prevPositions[nextPosRow][nextPosCol]) {
            insertTNodeCellToEndList(&tNode->next_possible_positions, validPositions.positions[i], NULL);
            findAllPossibleKnightPathsRec(tNode->next_possible_positions.tail->node, possibleMoves, prevPositions);
        }
    }
    prevPositions[currRow][currCol] = false;  // to let tNodes from the same tree level include that node in their subtrees.
}


//----------------- trees helper functions -----------------------//
treeNode *createTreeNode(chessPos position) {
    /*
     * Description: The function creates a new treeNode.
     * Param chessPos position: A given position on a chess board
     * Return: (treeNode) New tree node.
     */

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
    /*
     * Description: The function creates a new tree mode list cell.

     * Param chessPos position: A given position of chess board.
     * Param treeNodeListCell *next: The next list cell for the new list cell it's creating.

     * Return: (treeNodeListCell) A new tree node list cell.
     */

    treeNodeListCell *listCell = (treeNodeListCell *) malloc(sizeof(treeNodeListCell));

    listCell->node = createTreeNode(position);
    listCell->next = next;

    return listCell;
}


//----------------- lists helper functions -----------------------//
void makeEmptyList(treeNodeList *lst) {
    /*
     * Description: The function initializes a given list.
     * Param treeNodeList *lst: A given list.
     */

    lst->head = lst->tail = NULL;
}

void insertTNodeCellToEndList(treeNodeList *lst, chessPos position, treeNodeListCell *next) {
    /*
     * Description: The function create and insert a new treeNodeListCell to a given treeNodeList.

     * Param treeNodeList *lst: A given list.
     * Param chessPos position: A given position on a chess board.
     * Param treeNodeListCell *next: The next cell for the new list cell.
     */

    treeNodeListCell *listCell = createTreeNodeListCell(position, next);

    if (isEmptyList(*lst)) {
        lst->head = lst->tail = listCell;
    } else {
        lst->tail->next = listCell;
        lst->tail = listCell;
    }
}

bool isEmptyList(treeNodeList lst) {
    /*
     * Description: The function checks if a given list is empty.
     * Param treeNodeList lst: A given list.
     */

    return (lst.head == NULL);
}


//----------------- local helper functions -----------------------//
void resetPrevPosArr(bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    /*
     * Description: The function initialize a given 2D bool array with false values.
     * Param bool prevPositions[BOARD_SIZE][BOARD_SIZE]:
     */

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            prevPositions[i][j] = false;
        }
    }
}