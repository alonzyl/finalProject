#ifndef FINALPROJECT_STRUCTS_H
#define FINALPROJECT_STRUCTS_H

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


#define BOARD_SIZE 5

#endif //FINALPROJECT_STRUCTS_H
