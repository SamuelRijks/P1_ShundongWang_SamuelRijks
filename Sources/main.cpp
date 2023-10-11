#include <iostream>
#include <string>
#include "../Headers/include/Position.h"
#include "../Headers/include/Taulell.h"
#include "../Headers/include/MyEnum.h"
#include "../Headers/include/Snake.h"
#include "../Sources/src/MyEnum.cpp"





int main() {
    std::cout << "Hello, World!" << std::endl;

    //提问用户
    int cantidaddepro;
    std::cout << "Indica quantes bonificacions vols: \n";
    do{
        std::cout << "Espacifica un valor dins de l'interval[1,8] \n";
        std::cin >> cantidaddepro;
    }while(cantidaddepro<1||cantidaddepro>8);


    //画表格和小蛇


    Taulell game;
    game.inici(cantidaddepro); // 初始化游戏板并分配5个奖励

    // 渲染游戏板和蛇的位置
    game.visualitzar(); // 显示游戏板上的奖励


    return 0;
}
