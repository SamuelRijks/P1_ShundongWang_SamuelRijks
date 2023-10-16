#include <iostream>
#include <string>
#include "../Headers/include/Taulell.h"
#include "../Headers/include/Snake.h"


/*#include "../Sources/src/MyEnum.cpp"
#include "../Sources/src/Taulell.cpp"
#include "../Sources/src/Snake.cpp"
#include "../Sources/src/Position.cpp"*/



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
        return true; // 返回 true 表示继续游戏
    } else {
        return false; // 返回 false 表示退出游戏
    }
}

void jocdelaserp(Taulell *pTaulell) {
    int nTirada = 0;
    while (!pTaulell->getSnake()->isDead() && pTaulell->getNBonificacions() > 0) {
        int direccionelegida;
        do {
            nTirada++;
            std::cout << "Numero de bonificaciones disponibles: " << pTaulell->getNBonificacions() << "\n";
            std::cout << "Tirada: " << nTirada << "\n";
            std::cout << "********** " << "\n";
            for (int dir = MyEnum::Up; dir <= MyEnum::Rigth; dir++) {
                std::cout << dir + 1 << ". " << MyEnum::nameDir[dir] << "\n";
            }

            std::cout << "Especifica un valor dentro del intervalo [1,4]: ";
            std::cin >> direccionelegida;

        } while (direccionelegida < 1 || direccionelegida > 4);
        MyEnum::eDirection newdir = static_cast<MyEnum::eDirection>(direccionelegida - 1);
        pTaulell->movimentSerp(newdir);
        pTaulell->visualitzar();
    }
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

        // Realiza el juego de la serpiente
        jocdelaserp(game);

        // Libera la memoria del objeto Taulell
        delete game;

        jugarNuevaPartida = tornarJugar(game);

    }
    return 0;

}





