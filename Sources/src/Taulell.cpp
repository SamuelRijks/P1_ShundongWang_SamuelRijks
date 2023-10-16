//
// Created by samur on 05/10/2023.
//

#include "../../Headers/include/Taulell.h"

Taulell::Taulell() : nBonificacions(0), aSnake(new Snake(0)) {
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            contenidor[a][b] = 0;
        }
    }
}

int Taulell::getFiles() {
    return files;
}

int Taulell::getColumnes() {
    return columnes;
}

int Taulell::getNBonificacions() {
    return nBonificacions;
}

void Taulell::inici(int quantes) {
    this->nBonificacions = quantes;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rowDist(1, files - 1);
    std::uniform_int_distribution<int> colDist(0, columnes - 1);

    while (quantes > 0) {
        int randomRow = rowDist(gen);
        int randomCol = colDist(gen);

        if (contenidor[randomRow][randomCol] == 0) {
            contenidor[randomRow][randomCol] = 1;
            quantes--;
            std::cout << "Activem la posicio: " << randomRow << " , " << randomCol << '\n';

        }
    }

}

void Taulell::visualitzar() {
    std::cout << " ";
    for (int j = 0; j < columnes; j++) {
        std::cout << j << " ";
    }
    std::cout << std::endl;
    int a = 1;
    for (int i = 0; i < files; i++) {
        std::cout << i;
        std::cout << "|";
        for (int j = 0; j < columnes; j++) {
            if (contenidor[i][j] == 1) {
                std::cout << "& ";
            } else {
                if (!aSnake->visualitza(i, j)) {
                    std::cout << "  ";
                }
            }
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}


bool Taulell::movimentSerp(MyEnum::eDirection dir) {
    if (aSnake != nullptr) {
        int *newPos = aSnake->movimentSerp(dir, files, columnes);

        int fila = newPos[0];
        int columna = newPos[1];

        if (contenidor[fila][columna] == 1) {
            contenidor[fila][columna] = 0;
            nBonificacions--;
        } else if (contenidor[fila][columna] != 1) {
            aSnake->doesntEat();
        }

    }

    if (aSnake->isDead()) {
        return false;
    }

    return true;
}

void Taulell::finalitzar() {

    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columnes; j++) {
            contenidor[i][j] = 0;
        }
    }

    nBonificacions = 0;
    if (aSnake != nullptr) {
        aSnake->finalitzar();
        aSnake = nullptr;
    }

}

Taulell::~Taulell() {
    delete aSnake;
}



