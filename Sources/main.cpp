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
        tau->finalitzar();
        return true;
    } else {
        return false;
    }
}

void jocdelaserp(Taulell *pTaulell) {
    int nTirada = 1;
    bool dead = true;
    while (dead && pTaulell->getNBonificacions() > 0) {
        int direccionElegida;
        do {

            std::cout << "Numero de bonificaciones disponibles: " << pTaulell->getNBonificacions() << "\n";
            std::cout << "Tirada: " << nTirada << "\n";
            std::cout << "********** " << "\n";
            for (int dir = MyEnum::Up; dir <= MyEnum::Rigth; dir++) {
                std::cout << dir + 1 << ". " << MyEnum::nameDir[dir] << "\n";
            }

            std::cout << "Especifica un valor dentro del intervalo [1,4]: ";
            std::cin >> direccionElegida;

        } while (direccionElegida < 1 || direccionElegida > 4);
        nTirada++;
        MyEnum::eDirection newdir = static_cast<MyEnum::eDirection>(direccionElegida - 1);
        dead = pTaulell->movimentSerp(newdir);
        pTaulell->visualitzar();
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    bool jugarNuevaPartida = true;

    while (jugarNuevaPartida) {
        int cantidadBonificaciones = demanarValor(1, 8);

        Taulell *game = new Taulell;

        game->inici(cantidadBonificaciones);

        game->visualitzar();

        jocdelaserp(game);

        game->finalitzar();

        jugarNuevaPartida = tornarJugar(game);

    }
    std::cout << "Adeu!" << std::endl;
    return 0;

}





