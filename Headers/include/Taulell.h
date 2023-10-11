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
    int file = 8;
    int columnes = 8 ;
    //一个整数矩阵，大小与这些常量的维度相同，
    // 用于指定奖励的位置。如果有奖励，将其值设置为1，否则设置为0
    int contrnidor[8][8];
    int nBonificacions;
    Snake *aSnake;

public:
    Taulell(){
        this->nBonificacions = 0;
        this->aSnake = new Snake(0);

        for(int a = 0; a < 8; a++){
            for(int b = 0; b < 8 ; b++){
                contrnidor[a][b] = 0 ;
            }
        }
    }
    int getFiles() {
        return file;
    }

    int getColumnes() {
        return columnes;
    }

    int getNBonificacions() {
        return nBonificacions;
    }
    void inici(int quantes) {
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
    void visualitzar(){
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
    };
    //显示contenidor表格，为奖励设置特殊字符，例如&

     bool movimentSerp( MyEnum::eDirection dir){

    };
    void finalitzar(){
        //清理内存
        if(aSnake!= nullptr){
            delete aSnake;
        }
    };
};


#endif //P1_SHUNDONGWANG_SAMUELRIJKS_TAULELL_H
