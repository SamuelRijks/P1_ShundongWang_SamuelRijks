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
            if(i < currentLength-1){
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
    // Obtenir la nova posició de moviment utilitzant MyEnum::movement
    int* newPos = MyEnum::movement(newdir);

    // Calcular la nova posició del cap de la serp
    int newHeadRow = vector[0].getRow() + newPos[0];
    int newHeadCol = vector[0].getCol() + newPos[1];

    // Actualitzar la direcció actual i la longitud actual de la serp
    currentDir = newdir;
    currentLength++;

    // Comprovar si la nova posició ja pertany a la serp (provocant la mort)
    if (contains(newHeadRow, newHeadCol)) {
        currentLength = 0; // Estableix la longitud actual a 0
        return nullptr;    // Retorna nullptr per indicar que la serp ha mort
    }

    // Actualitzar el vector de posicions de la serp per a la nova posició
    for (int i = currentLength - 1; i > 0; i--) {
        vector[i] = vector[i - 1];
    }

    vector[0].putData(newHeadRow, newHeadCol);

    // Retorna la nova posició del cap de la serp per comprovar si s'ha menjat una bonificació
    int* newHeadPos = new int[2];
    newHeadPos[0] = newHeadRow;
    newHeadPos[1] = newHeadCol;
    return newHeadPos;
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
