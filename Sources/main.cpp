#include <iostream>
#include <string>
#include "../Headers/include/Position.h"
#include "../Headers/include/Taulell.h"
#include "../Headers/include/MyEnum.h"
#include "../Headers/include/Snake.h"
#include "../Sources/src/MyEnum.cpp"
#include "../Sources/src/Taulell.cpp"
#include "../Sources/src/Snake.cpp"
#include "../Sources/src/Position.cpp"


void jocdelaserp(Taulell *pTaulell);

int demanarValor(int min, int max) {
    int valor;
    std::cout << "Indica quantes bonificacions vols: \n";
    do {
        std::cout << "Especifica un valor dins de l'interval [" << min << "," << max << "]: ";
        std::cin >> valor;
    } while (valor < min || valor > max);
    return valor;
}
bool preguntarSiContinuarJuego() {
    char resposta;
    std::cout << "Vols tornar a jugar una altra partida? (S/N): ";
    std::cin >> resposta;
    return (resposta == 'S' || resposta == 's');
}
bool tornarJugar(Taulell *tau) {
    if (preguntarSiContinuarJuego()) {
        // 重新初始化游戏板 *tau
        tau->finalitzar();
        tau->inici(demanarValor(1, 8)); // 重新初始化游戏板并指定奖励数量
        return true; // 返回 true 表示继续游戏
    } else {
        return false; // 返回 false 表示退出游戏
    }
}

void movimento(MyEnum::eDirection direction, Taulell *pTaulell) {
    pTaulell->movimentSerp(direction);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    bool jugarNuevaPartida = true;

    while (jugarNuevaPartida) {
        // Pregunta al usuario la cantidad de bonificaciones a crear
        int cantidadBonificaciones = demanarValor(1, 8);

        // Crea un objeto de la clase Taulell
        Taulell *game = new Taulell;

        // Inicializa el juego con la cantidad de bonificaciones
        game->inici(cantidadBonificaciones);

        // Muestra el tablero
        game->visualitzar();

        std::cout << "Numero de bonificaciones disponibles: " << cantidadBonificaciones << "\n";

        // Realiza el juego de la serpiente
        jocdelaserp(game);

        // Libera la memoria del objeto Taulell
        delete game;

        // Pregunta al jugador si desea jugar otra partida

            // Pregunta al jugador si desea jugar otra partida
            jugarNuevaPartida = tornarJugar(game);


        return 0;
    }
}
    void jocdelaserp(Taulell *pTaulell) {
        while (!pTaulell->getSnake()->isDead()|| !pTaulell->getNBonificacions() == 0) {
            int direccionelegida;
            do {
                std::cout << "Tirada: " << "\n";
                for (int dir = MyEnum::Up; dir <= MyEnum::Rigth; dir++) {
                    std::cout << dir + 1 << ". " << MyEnum::nameDir[dir] << "\n";
                }

                std::cout << "Especifica un valor dentro del intervalo [1,4]: ";
                std::cin >> direccionelegida;
            } while (direccionelegida < 1 || direccionelegida > 4);
            Position *v1 = pTaulell->getSnake()->getvector();
            std::cout << v1->getCol() << "y" << v1->getRow()  << "\n";
            MyEnum::eDirection newdir = static_cast<MyEnum::eDirection>(direccionelegida - 1);
            movimento(newdir, pTaulell);
            Position *v = pTaulell->getSnake()->getvector();
            std::cout << v->getCol() << "y" << v->getRow()  << "\n";
            pTaulell->visualitzar();
        }
    }


