#ifndef FINALPROJECT_STRUCTS_H
#define FINALPROJECT_STRUCTS_H
#define BOARD_SIZE 5

typedef char chessPos[2];

typedef struct _chessPosArray {
    unsigned int size;
    chessPos *positions;
} chessPosArray;

typedef struct _chessPosCell {
    chessPos position;
    struct _chessPosCell *next;
} chessPosCell;

typedef struct _chessPosCellWithPos {
    chessPosCell *cell;
    int originalIndex;
    struct _chessPosCellWithPos *next;
} chessPosCellWithPos;

typedef struct _chessPosArrayWithPos {
    chessPosCellWithPos *head;
    chessPosCellWithPos *tail;
} chessPosArrayWithPos;

typedef struct _chessPosList {
    chessPosCell *head;
    chessPosCell *tail;
} chessPosList;

struct _treeNodeListCell;

typedef struct _treeNodeList {
    struct _treeNodeListCell *head;
    struct _treeNodeListCell *tail;
} treeNodeList;

typedef struct _treeNode {
    chessPos position;
    treeNodeList next_possible_positions;
} treeNode;

typedef struct _treeNodeListCell {
    treeNode *node;
    struct _treeNodeListCell *next;
} treeNodeListCell;

typedef struct _pathTree {
    treeNode *root;
} pathTree;


#endif //FINALPROJECT_STRUCTS_H
