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
    Position() : row(-1), col(-1) {}

    Position(int i, int j) : row(i), col(j) {}

    void putData(int newRow, int newCol) {
        row = newRow;
        col = newCol;
    }

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }
//这里用来生成🐍的身体
    void visualitza() const {
        std::cout << "*";
    }
//屏幕上显示是的方向，，由蛇的头部使用
    void visualitza(MyEnum::eDirection dir) const {
        std::cout << MyEnum::toSymbol(dir);
    }

    bool operator==(const Position &other) const {
        return (row == other.row) && (col == other.col);
    }

    bool operator!=(const Position &other) const {
        return !(*this == other);
    }
};






#endif //P1_SHUNDONGWANG_SAMUELRIJKS_POSITION_H
