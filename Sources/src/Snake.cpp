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

    return currentLength <= 0;
}

int *Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol) {
    // Obtenir la nova posició de moviment utilitzant MyEnum::movement
    int* newPos = MyEnum::movement(newdir);

    // Calcular la nova posició del cap de la serp
    int newHeadRow = vector[currentLength - 1].getRow() + newPos[0];
    int newHeadCol = vector[currentLength - 1].getCol() + newPos[1];

    // Verificar si la nueva posición estaría fuera de los bordes
    if (newHeadRow < 0) {
        newHeadRow = nRow - 1; // Aparece en la parte inferior
    } else if (newHeadRow >= nRow) {
        newHeadRow = 0; // Aparece en la parte superior
    }

    if (newHeadCol < 0) {
        newHeadCol = nCol - 1; // Aparece en el borde derecho
    } else if (newHeadCol >= nCol) {
        newHeadCol = 0; // Aparece en el borde izquierdo
    }

    currentDir = newdir;

    if (contains(newHeadRow, newHeadCol)) {
        currentLength = 0; // Estableix la longitud actual a 0
        //return nullptr;    // Retorna nullptr per indicar que la serp ha mort
    }

    vector[currentLength].putData(newHeadRow, newHeadCol);
    currentLength++;
    // Resto del código para actualizar la serpiente y comprobar otras condiciones
    // ...

    // Retorna la nueva posición del cap de la serpiente para comprobar si se ha comido una bonificación
    int* newHeadPos = new int[2];
    newHeadPos[0] = newHeadRow;
    newHeadPos[1] = newHeadCol;
    return newHeadPos;
}

void Snake::rebotarEnBordes() {

    for(int i=0; i < currentLength; i++){
        if(vector[i].getCol() > 7 || vector[i].getCol() < 0){
            if (vector[i].getCol() > 7) {
                vector[i].putData(vector[i].getRow(), 0);
            }
            else{
                vector[i].putData(vector[i].getRow(), 7);
            }
        }
        else if(vector[i].getRow() > 7 || vector[i].getRow() < 0){
            if (vector[i].getRow() > 7) {
                vector[i].putData(0, vector[i].getCol());
            }
            else{
                vector[i].putData(7, vector[i].getCol())  ;
            }
        }

    }
}

void Snake::doesntEat() {
    if (currentLength > 0) {
        for (int i = 0; i < currentLength; i++) {
            vector[i] = vector[i+1];
        }
        currentLength--;
    }

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

Snake::~Snake() {
    delete[] vector;
}
