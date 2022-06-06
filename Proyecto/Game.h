#include "Pintar.h"

#ifndef PROYECTO_GAME_H
#define PROYECTO_GAME_H


class Game {

private:
    int vidas = 3;
    double tiempo = 0;
    bool juegoActivo = false;
    bool mensajeEspacio = true;

    //Método para revisar si la partícula con estructura bola choca
    //otra partícula con estructura ladrillo
    bool colisionaBolaYLadrillo(Particula &_bola, Particula &_ladrillo);

    //Método para dirigir la base de izquierda a derecha
    char Direccion();

    //Método para inicializar el conjunto pared según el número de filas
    void inicializarPared(ConjuntoParticulas pared[]);

    //Método para colocar todas las filas de partículas (pared de ladrillos)
    void colocarPared (ConjuntoParticulas pared[]);

    //Método para borrar todas las filas de partículas (pared de ladrillos)
    void borrarPared (ConjuntoParticulas pared[], Particula &bola);
    void vaciarPared (ConjuntoParticulas pared[]);

    //Método para quitar la base del juego
    void quitarBase(Particula &base);

    //Método para empezar cada ronda según el número de vidas del jugador
    void empezarRonda (Particula &bola, Particula &base, int &soloPrimeraVez);

public:

    //Getters
    bool getJuegoActivo() const;
    int getVidas() const;
    double getTiempo() const;
    bool getMensajeEspacio() const;

    //Método para inicializar objetos y ventana
    void Init(ConjuntoParticulas pared[]);

    //Método para actualizar objetos
    void Update(char &dir, Particula &bola, Particula &base,
                       ConjuntoParticulas pared[], int &soloPrimeraVez);

    //Método para pintar la pared, bola y base
    void pintar(ConjuntoParticulas pared[], Particula &bola,
                Particula &base, int &soloPrimeraVez);

    //Método para quitar todo de la pantalla y acabar la
    // partida actual con un mensaje y el tiempo total
    void End(ConjuntoParticulas pared[], Particula &bola,
                    Particula &base);

};


#endif //PROYECTO_GAME_H
