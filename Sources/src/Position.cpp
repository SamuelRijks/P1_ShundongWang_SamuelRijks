//
// Created by samur on 05/10/2023.
//

#include "../../Headers/include/Position.h"

Position::Position() : row(-1), col(-1){}

Position::Position(int i, int j) : row(i), col(j) {}

void Position::putData(int newRow, int newCol) {
    row = newRow;
    col = newCol;
}


int Position::getRow() const {
    return row;
}

int Position::getCol() const {
    return col;
}

void Position::visualitza() const {
    std::cout <<"* ";
}

void Position::visualitza(MyEnum::eDirection dir) const {
    std::cout << MyEnum::toSymbol(dir);
}

bool Position::operator==(const Position &other) const {
    return (row == other.row) && (col == other.col);
}

bool Position::operator!=(const Position &other) const {
    return !(*this == other);
}









