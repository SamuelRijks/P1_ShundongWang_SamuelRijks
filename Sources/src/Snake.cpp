//
// Created by samur on 05/10/2023.
//

#include "../../Headers/include/Snake.h"


Snake::Snake(int nBonificacions) {
    currentLength += nBonificacions;
    currentDir = MyEnum::Rigth;
    vector = new Position[currentLength];

    for (int i = 0; i < currentLength; i++) {
        vector[i].putData(0, i);
    }

}

bool Snake::visualitza(int row, int col) {

    for (int i = 0; i < currentLength; i++) {
        if (vector[i].getCol() == col && vector[i].getRow() == row) {

            if(i < currentLength-1){
                vector[i].visualitza();

            }
            else{
                vector[i].visualitza(currentDir);
            }
            return true;
        }
    }
    return false;
}

bool Snake::contains(int row, int col) {

    for (int a = 0; a < currentLength; a++) {
        if (vector[a].getRow() == row && vector[a].getCol() == col) {
            return true;
        }
    }
    return false;
}

bool Snake::isDead() {


    return currentLength <= 0;
}

int *Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol) {

    int* newPos = MyEnum::movement(newdir);


    int newHeadRow = vector[currentLength - 1].getRow() + newPos[0];
    int newHeadCol = vector[currentLength - 1].getCol() + newPos[1];


    if (newHeadRow < 0) {
        newHeadRow = nRow - 1;
    } else if (newHeadRow >= nRow) {
        newHeadRow = 0;
    }

    if (newHeadCol < 0) {
        newHeadCol = nCol - 1;
    } else if (newHeadCol >= nCol) {
        newHeadCol = 0;
    }

    currentDir = newdir;

    if (contains(newHeadRow, newHeadCol)) {
        currentLength = 0;
    }

    vector[currentLength].putData(newHeadRow, newHeadCol);
    currentLength++;

    int* newHeadPos = new int[2];
    newHeadPos[0] = newHeadRow;
    newHeadPos[1] = newHeadCol;
    return newHeadPos;
}

void Snake::doesntEat() {
    if (currentLength > 0) {
        for (int i = 0; i < currentLength; i++) {
            vector[i] = vector[i+1];
        }
        currentLength--;
    }

}

void Snake::finalitzar()  {
    delete vector;
}

Snake::~Snake() {
    delete vector;
}
