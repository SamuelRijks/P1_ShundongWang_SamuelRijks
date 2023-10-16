//
// Created by samur on 05/10/2023.
//


#ifndef P1_SHUNDONGWANG_SAMUELRIJKS_POSITION_H
#define P1_SHUNDONGWANG_SAMUELRIJKS_POSITION_H

#include <iostream>
#include "MyEnum.h"

class Position {
private:
    int row;
    int col;

public:
    Position();

    Position(int i, int j);

    void putData(int newRow, int newCol);

    int getRow() const;

    int getCol() const;

    void visualitza() const;

    void visualitza(MyEnum::eDirection dir) const;

    bool operator==(const Position &other) const;

    bool operator!=(const Position &other) const;
};






#endif //P1_SHUNDONGWANG_SAMUELRIJKS_POSITION_H
