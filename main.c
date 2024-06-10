#include <stdio.h>
#include "question2/displayChessBoard.h"
#include "question3/knightPaths.h"
#include "question4/KnightTour.h"
#include "helpersFuncs.h"
#include "structs.h"


int main(void) {

    chessPos startingPos;

    getUserInput(&startingPos);

    pathTree allPossibleKnightPaths = findAllPossibleKnightPaths(&startingPos);
    chessPosList *coversAllBoardPath = findKnightPathCoveringAllBoard(&allPossibleKnightPaths);

    if(coversAllBoardPath != NULL)
        display(coversAllBoardPath);
    else {
        printf("No knight's tour");
    }

    freePathTree(&allPossibleKnightPaths);
}