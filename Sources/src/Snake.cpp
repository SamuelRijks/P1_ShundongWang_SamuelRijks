//
// Created by samur on 05/10/2023.
//

#include "../../Headers/include/Snake.h"


Snake::Snake(int nBonubicacion) {
    currentLength += nBonubicacion;
    currentDir = MyEnum::Rigth;
    vector = new Position[currentLength];

    for (int i = 0; i < currentLength; i++) {
        vector[i].putData(0, i);
    }

}

bool Snake::visualitza(int row, int col) {
    /*//检查蛇是否位于由参数指定的位置
    bool a = false;
    if (vector[currentLength - 1].getCol() == col && vector[currentLength - 1].getRow() == row) {
        vector->visualitza();
        return true;
    }
    return a;*/
    // Comprueba si la serpiente está en la posición especificada por los argumentos "row" y "col".
    for (int i = 0; i < currentLength; i++) {
        if (vector[i].getCol() == col && vector[i].getRow() == row) {
            // Si la serpiente está en esta posición, llama al método visualitza de la clase Position.
            if(i < currentLength){
                vector[i].visualitza(); // Suponiendo que visualitza sea un método de la clase Position.

            }
            else{
                vector[i].visualitza(currentDir);
            }
            return true;
        }
    }
    return false; // La serpiente no está en la posición especificada.
}

bool Snake::contains(int row, int col) {
    //判断蛇是否包含位置
    for (int a = 0; a < currentLength; a++) {
        if (vector[a].getRow() == row && vector[a].getCol() == col) {
            return true;
        }
    }
    return false;
}

bool Snake::isDead() {
    //判断🐍是否死亡
    if (currentLength <= 0) {
        return true;
    }
    return false;
}

int *Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol) {
    // 更新currentDir和currentLength属性，并分配蛇头的新位置。
    // 必须检查这个新位置是否已经属于蛇，使用前一个方法进行检查，这将导致蛇的死亡
    this->currentDir = newdir;


    Position *nuevovector = new Position[currentLength];
    for (int a = 0; a < currentLength; a++) {
        if (a == 0) {
            nuevovector[a].putData(nRow, nCol);
        } else {
            nuevovector[a].putData(vector[a - 1].getRow(), vector[a - 1].getCol());
        }
    }
    delete[] vector;
    vector = nuevovector;
    if (contains(nRow, nCol)) {
        currentLength = 0;
    }
    // 返回蛇头的新位置
    int *newPos = new int[2];
    newPos[0] = nRow;
    newPos[1] = nCol;
    return newPos;
}

void Snake::doesntEat() {
    // 当蛇没有吃到奖励时，删除蛇的最后一个位置
    if (currentLength > 0) {
        currentLength--;
    }
}
void Snake::doesEat() {
    currentLength++;
}

Position *Snake::getvector() {
    return vector;
}

int Snake::getcurrentLength() {
    return currentLength;
}

MyEnum::eDirection Snake::getCurrentDirection() {
    return currentDir;
}
