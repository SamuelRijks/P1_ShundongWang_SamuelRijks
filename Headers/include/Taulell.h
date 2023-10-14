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
        const static int files = 8;
        const static int columnes = 8;
        int contenidor[files][columnes];
        int nBonificacions;
        Snake* aSnake;

    public:
        Taulell();
        // Add other member function declarations here


    static int getFiles();

    static int getColumnes();

    int getNBonificacions();

    void inici(int quantes);

    void visualitzar();

    bool movimentSerp( MyEnum::eDirection dir);

    void finalitzar();

    Snake* getSnake();

    int getContenidorValue(int row, int col) const;

};


#endif //P1_SHUNDONGWANG_SAMUELRIJKS_TAULELL_H
