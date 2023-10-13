//
// Created by samur on 05/10/2023.
//

#include <iostream>
#include <string>
using namespace std;



#ifndef P1_SHUNDONGWANG_SAMUELRIJKS_MYENUM_H
#define P1_SHUNDONGWANG_SAMUELRIJKS_MYENUM_H


namespace MyEnum {
    enum eDirection { Up, Down, Left, Rigth};
    const string nameDir[] = { "Up", "Down", "Left", "Rigth" };
    const string symbolDir[] = { "^", "v", "<", ">" };
    const int length = 4;
    const int moveDir[2][length] = {-1, 1, 0, 0, //row
                                    0, 0, -1, 1}; //col

    string toName( eDirection dir);

    string toSymbol( eDirection dir);

    eDirection giveDirection();

    int* movement(eDirection dir);
};


#endif //P1_SHUNDONGWANG_SAMUELRIJKS_MYENUM_H
