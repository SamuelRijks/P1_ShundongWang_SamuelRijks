#include <iostream>
#include <string>
#include "../Headers/include/Position.h"
#include "../Headers/include/Taulell.h"
#include "../Headers/include/MyEnum.h"
#include "../Headers/include/Snake.h"
#include "../Sources/src/MyEnum.cpp"


void nuevamatriz(Taulell taulell);

void jocdelaserp(Taulell taulell);

void movimento(MyEnum::eDirection direction, Taulell taulell);

void visualitza(Taulell taulell);

bool printFirstRow(int j);



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

    game.visualitzar();

    std::cout<<"nombre de bonificacions disponibles: "<<cantidaddepro<<"\n";

    //nuevamatriz(game)


    //El joc de la serp
    jocdelaserp(game);

    return 0;
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

void movimento(MyEnum::eDirection direction, Taulell taulell) {
 taulell.movimentSerp(direction);
}
