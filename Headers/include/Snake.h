//
// Created by samur on 05/10/2023.
//

#ifndef P1_SHUNDONGWANG_SAMUELRIJKS_SNAKE_H
#define P1_SHUNDONGWANG_SAMUELRIJKS_SNAKE_H

#include "Position.h"
#include "MyEnum.h"


class Snake {
private:
    Position *vector;
    int currentLength = 3;
    MyEnum::eDirection currentDir;

public:
    Snake(int nBonubicacion);



    bool visualitza(int row, int col);

    bool contains(int row, int col);

    bool isDead();

    int *movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol);

    void doesntEat();

    Position *getvector();

    int getcurrentLength();

    MyEnum::eDirection getCurrentDirection();

    ~Snake();

};
#endif //P1_SHUNDONGWANG_SAMUELRIJKS_SNAKE_H


