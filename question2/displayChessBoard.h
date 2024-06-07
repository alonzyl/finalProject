#include "../structs.h"

#ifndef UNTITLED_DISPLAYCHESSBOARD_H
#define UNTITLED_DISPLAYCHESSBOARD_H

chessPosList getUserInput();

chessPosArrayWithPos sortList(chessPosList lst);

void display(chessPosList *lst);
void test();

#endif //UNTITLED_DISPLAYCHESSBOARD_H
