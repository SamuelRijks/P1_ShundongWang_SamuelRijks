//
// Created by samur on 05/10/2023.
//

#include "../../Headers/include/Taulell.h"

Taulell::Taulell() : file(8), columnes(8), nBonificacions(0), aSnake(new Snake(0)) {
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            contrnidor[a][b] = 0;
        }
    }
}

int Taulell::getFiles() {
    return file;
}

int Taulell::getColumnes() {
    return columnes;
}

int Taulell::getNBonificacions() {
    return nBonificacions;
}

void Taulell::inici(int quantes) {
    // 分配奖励到随机位置，并记录奖励数量
    nBonificacions = quantes;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rowDist(1, file - 1);
    std::uniform_int_distribution<int> colDist(0, columnes - 1);

    while (nBonificacions > 0) {
        int randomRow = rowDist(gen);
        int randomCol = colDist(gen);

        if (contrnidor[randomRow][randomCol] == 0) {
            contrnidor[randomRow][randomCol] = 1;
            nBonificacions--;
            std::cout << "Activem la posicio: " << randomRow << " , " << randomCol << '\n';


        }
    }

}

void Taulell::visualitzar() {
    //画出奖励
    int a = 1;
    for (int i = 0; i < file; i++) {
        for (int j = 0; j < columnes; j++) {
            if (contrnidor[i][j] == 1) {
                std::cout << "& ";
            } else {

                if(aSnake->contains(i,j)){
                    if(aSnake->getcurrentLength()>a){
                        aSnake->getvector()->visualitza();
                        a++;}
                    else{
                        aSnake->getvector()->visualitza(aSnake->getCurrentDirection());
                    }

                }
                else {
                    std::cout << "  ";
                }
            }
        }
        std::cout << std::endl;
    }

}

bool Taulell::movimentSerp(MyEnum::eDirection dir) {
    if (aSnake != nullptr) {
        int* newPos = aSnake->movimentSerp(dir, file, columnes);
        int fila = newPos[0];
        int columna = newPos[1];

        if (contrnidor[fila][columna] == 1) {
            // 蛇吃到了奖励
            contrnidor[fila][columna] = 0;
            nBonificacions--;
            aSnake->doesntEat();
        }

        return aSnake->isDead();
    }

    return true; // 蛇不存在时返回true
}

void Taulell::finalitzar() {
    //清理内存
    if(aSnake!= nullptr){
        delete aSnake;
    }

}

Snake *Taulell::getSnake() {
    return aSnake;
}

int Taulell::getContrnidorValue(int row, int col) const {
    // 在这里可以添加一些范围检查来确保 row 和 col 的值有效
    return contrnidor[row][col];
}

