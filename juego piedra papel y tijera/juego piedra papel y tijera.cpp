#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Jugador {
public:
    virtual int seleccionar() = 0;
};

class Humano : public Jugador {
public:
    int seleccionar() {
        cout << "Elige tu jugada por favor (1 - Piedra, 2 - Papel, 3 - Tijera): ";
        int opcion;
        cin >> opcion;
        return opcion;
    }
};

class Computadora : public Jugador {
public:
    int seleccionar() {
        srand(time(0));
        return rand() % 3 + 1;
    }
};

class Juego {
private:
    Jugador* jugador1;
    Jugador* jugador2;
    int puntaje_jugador1;
    int puntaje_jugador2;

public:
    Juego() : jugador1(new Humano()), jugador2(new Computadora()), puntaje_jugador1(0), puntaje_jugador2(0) {}

    ~Juego() {
        delete jugador1;
        delete jugador2;
    }

    void jugar() {
        int rondas;
        cout << "¿Cuántas rondas quieres jugar? ";
        cin >> rondas;

        for (int i = 0; i < rondas; ++i) {
            int jugada1 = jugador1->seleccionar();
            int jugada2 = jugador2->seleccionar();
            evaluar(jugada1, jugada2);
        }

        mostrarPuntajes();
        mostrarResultadoFinal();
    }

private:
    void evaluar(int jugada1, int jugada2) {
        cout << "Jugador 1 eligió: " << jugada1 << endl;
        cout << "Jugador 2 eligió: " << jugada2 << endl;

        if (jugada1 == jugada2) {
            cout << "Empate!" << endl;
        }
        else if ((jugada1 == 1 && jugada2 == 3) ||
            (jugada1 == 2 && jugada2 == 1) ||
            (jugada1 == 3 && jugada2 == 2)) {
            cout << "¡Jugador 1 gana esta ronda!" << endl;
            puntaje_jugador1++;
        }
        else {
            cout << "¡Jugador 2 gana esta ronda!" << endl;
            puntaje_jugador2++;
        }
    }

    void mostrarPuntajes() {
        cout << "Puntaje final:" << endl;
        cout << "Jugador 1: " << puntaje_jugador1 << " puntos" << endl;
        cout << "Jugador 2: " << puntaje_jugador2 << " puntos" << endl;
    }

    void mostrarResultadoFinal() {
        if (puntaje_jugador1 > puntaje_jugador2) {
            cout << "¡Jugador 1 gana el juego!" << endl;
        }
        else if (puntaje_jugador1 < puntaje_jugador2) {
            cout << "¡Jugador 2 gana el juego!" << endl;
        }
        else {
            cout << "El juego termina en empate." << endl;
        }
    }

public:

    int getPuntajeJugador1() const {
        return puntaje_jugador1;
    }

    int getPuntajeJugador2() const {
        return puntaje_jugador2;
    }

    void setPuntajeJugador1(int puntaje) {
        puntaje_jugador1 = puntaje;
    }

    void setPuntajeJugador2(int puntaje) {
        puntaje_jugador2 = puntaje;
    }
};

int main() {
    Juego juego;
    juego.jugar();
    return 0;
}