//
// Created by 顺东 on 2023/10/12.
//

#ifndef P1_SHUNDONGWANG_SAMUELRIJKS_COGIDO_H
#define P1_SHUNDONGWANG_SAMUELRIJKS_COGIDO_H


#include "Snake.h"
#include <iostream>

class cogido {



    void visualitzar(){
        //画出奖励
        int file = 8;
        int columnes = 8 ;
        //一个整数矩阵，大小与这些常量的维度相同，
        // 用于指定奖励的位置。如果有奖励，将其值设置为1，否则设置为0
        int contrnidor[8][8];
        int nBonificacions;
        Snake *aSnake;

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
};

if(i>=1&&j>=3&&j<=8&&i) {

    在这里是main中重新健在的期盼
    void visualitza(Taulell taulell) {
        int rows = 9;
        int cols = 10;
        char nuevatau[9][10];

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                nuevatau[i][j] = ' '; // 初始化为空格或其他字符
            }
        }

// 初始化第一行
        for (int j = 0; j <=cols; j++) {

            if(j!=0&&j!=1) {
                nuevatau[0][j] = '0' + j-2; // 存储数字字符 '0' 到 '9'
            }else{
                nuevatau[0][j] = ' ';
            }
        }

// 初始化第一列
        for (int i = 1; i < rows; i++) {
            nuevatau[i][0] = '0' + (i - 1); // 将数字字符放入矩阵
            nuevatau[i][1] = '|';
            nuevatau[i][9] = '|';

        }


// 初始化其余位置,讲久复制到新的上去;
        int a = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if(i>=1&&j>=2&&j<=8){
                    if(taulell.)
                }else{
                    cout << nuevatau[i][j] << " "; // 打印矩阵内容，使用空格分隔
                }
            }
            cout << endl; // 打印换行符，将内容移到下一行
        }

    }

}

void jocdelaserp(Taulell taulell) {
    int direccionelegida;
    do{do {

            int a = 1;
            std::cout << "Tirada: " << a << "\n";
            for (int dir = MyEnum::Up; dir <= MyEnum::Rigth; dir++) {
                std::cout << "  " << dir + 1 << ". " << MyEnum::nameDir[dir] << "\n";
            }

            std::cout << std::endl;

            std::cout << "Especifica un valor dins de l'interval: [1,4]"<< "\n";
            std::cin >> direccionelegida;
        }while(direccionelegida<1||direccionelegida>4);
        MyEnum::eDirection newdir;
        newdir = static_cast<MyEnum::eDirection>(direccionelegida - 1);

        movimento(newdir, taulell);
        taulell.visualitzar();
    }while(taulell.getSnake()->isDead());

}

#endif //P1_SHUNDONGWANG_SAMUELRIJKS_COGIDO_H
