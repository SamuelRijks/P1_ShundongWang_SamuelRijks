//
// Created by samur on 05/10/2023.
//

#ifndef P1_SHUNDONGWANG_SAMUELRIJKS_TAULELL_H
#define P1_SHUNDONGWANG_SAMUELRIJKS_TAULELL_H
#include "Snake.h"
#include <ctime>
#include <random>
#include "MyEnum.h"
#include "Position.h"


class Taulell {
    private:
        int file;
        int columnes;
        int contrnidor[8][8];
        int nBonificacions;
        Snake* aSnake;

    public:
        Taulell();
        // Add other member function declarations here


    int getFiles();

    int getColumnes();

    int getNBonificacions();

    void inici(int quantes);

    void visualitzar();

     bool movimentSerp( MyEnum::eDirection dir);

    void finalitzar();

    Snake* getSnake();

    int getContrnidorValue(int row, int col) const;

};


#endif //P1_SHUNDONGWANG_SAMUELRIJKS_TAULELL_H
