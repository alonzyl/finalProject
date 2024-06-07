#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../helpersFuncs.h"
#include "../structs.h"
#include "../question1/validKnightMoves.h"

void makeEmptyList(treeNodeList *lst);

bool isEmptyList(treeNodeList lst);

pathTree findAllPossibleKnightPaths(chessPos *startingPosition);

void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]);

void resetArr(bool prevPositions[BOARD_SIZE][BOARD_SIZE]);

void insertTNodeCellToEndList(treeNodeList *lst, chessPos position, treeNodeListCell *next);

treeNode *createTreeNode(chessPos position);




pathTree findAllPossibleKnightPaths(chessPos *startingPosition) {
    chessPosArray ***possibleMoves = validKnightMoves();
    pathTree resTree;

    bool prevPositions[BOARD_SIZE][BOARD_SIZE];
    resetArr(prevPositions);

    treeNode *root = createTreeNode(*startingPosition);
    resTree.root = root;

    findAllPossibleKnightPathsRec(resTree.root,possibleMoves,prevPositions);

    // create pathTree for the given startingPosition
    // run the recursion func with the root of pathTree
    //get the full tree from the recursion func and return
    return resTree;
}

//void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
//    if (tNode == NULL) {
//
//    } else {
//        chessPosArray validPositions = *possibleMoves[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])];
//
//        printf("\nall valid positions from (%c%c):\n", tNode->position[0], tNode->position[1]);
//        prevPositions[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])] = true;
//        for (int i = 0; i <validPositions.size ; ++i) {
//         printf("\t(%c%c) \n",validPositions.positions[i][0],validPositions.positions[i][1]);
//        }
//        printf("\n");
//
//        for (int i = 0; i <validPositions.size; ++i) {
//            if(prevPositions[UPPERCASE_TO_DIGIT(validPositions.positions[i][0])][CHAR_TO_INT_NUM(validPositions.positions[i][1])] == false){
//                printf("moving from: (%c %c) to: (%c %c) \n",tNode->position[0],tNode->position[1],validPositions.positions[i][0],validPositions.positions[i][1]);
//                prevPositions[UPPERCASE_TO_DIGIT(validPositions.positions[i][0])][CHAR_TO_INT_NUM(validPositions.positions[i][1])] = true;
//                insertTNodeCellToEndList(&tNode->next_possible_positions,validPositions.positions[i],NULL);
//
//
//                findAllPossibleKnightPathsRec(tNode->next_possible_positions.head->node, possibleMoves, prevPositions);
//                prevPositions[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])] = false;
//            }
//
//        }
//        treeNodeListCell *cellRunner = tNode->next_possible_positions.head;
//        while (cellRunner != NULL) {
//            findAllPossibleKnightPathsRec(cellRunner->node, possibleMoves, prevPositions);
//            cellRunner = cellRunner->next;
//        }
//        printf("\n");
//        prevPositions[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])] = false;
//
//    }
//}

void findAllPossibleKnightPathsRec(treeNode *tNode, chessPosArray ***possibleMoves,bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    if (tNode == NULL) {

    } else {
        chessPosArray validPositions = *possibleMoves[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])];

//        printf("\nall valid positions from (%c%c):\n", tNode->position[0], tNode->position[1]);
        prevPositions[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])] = true;
//
//        for (int i = 0; i <validPositions.size ; ++i) {
//         printf("\t(%c%c) \n",validPositions.positions[i][0],validPositions.positions[i][1]);
//        }
        printf("\n");

        for (int i = 0; i <validPositions.size; ++i) {
            if(prevPositions[UPPERCASE_TO_DIGIT(validPositions.positions[i][0])][CHAR_TO_INT_NUM(validPositions.positions[i][1])] == false){
                printf("moving from: (%c %c) to: (%c %c) \n",tNode->position[0],tNode->position[1],validPositions.positions[i][0],validPositions.positions[i][1]);
//                prevPositions[UPPERCASE_TO_DIGIT(validPositions.positions[i][0])][CHAR_TO_INT_NUM(validPositions.positions[i][1])] = true;
                insertTNodeCellToEndList(&tNode->next_possible_positions,validPositions.positions[i],NULL);

            }

        }
        treeNodeListCell *cellRunner = tNode->next_possible_positions.head;
        while (cellRunner != NULL) {
            prevPositions[UPPERCASE_TO_DIGIT(cellRunner->node->position[0])][CHAR_TO_INT_NUM(cellRunner->node->position[1])] = true;
            findAllPossibleKnightPathsRec(cellRunner->node, possibleMoves, prevPositions);
            prevPositions[UPPERCASE_TO_DIGIT(cellRunner->node->position[0])][CHAR_TO_INT_NUM(cellRunner->node->position[1])] = false;
            cellRunner = cellRunner->next;
        }
        prevPositions[UPPERCASE_TO_DIGIT(tNode->position[0])][CHAR_TO_INT_NUM(tNode->position[1])] = false;



    }
}




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

// Initializes an empty list
void makeEmptyList(treeNodeList *lst) {
    lst->head = lst->tail = NULL;
}

// Inserts a new integer at the end of the list
void insertTNodeCellToEndList(treeNodeList *lst, chessPos position, treeNodeListCell *next) {

    treeNodeListCell *listCell = createTreeNodeListCell(position,next);

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

void resetArr(bool prevPositions[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            prevPositions[i][j] = false;
        }
    }
}