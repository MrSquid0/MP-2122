#ifndef PROYECTO_CONJUNTOPARTICULAS_H
#define PROYECTO_CONJUNTOPARTICULAS_H


#include "Particula.h"

const int TAM_BLOQUE = 3;

class ConjuntoParticulas {
private:
    Particula *set;
    int capacidad;
    int utiles;

public:
    //Constructor sin parámetros
    ConjuntoParticulas();

    //Constructor con parámetros
    ConjuntoParticulas(int capacidad);

    //Destructor
    ~ConjuntoParticulas();

    //Getters
    int GetCapacidad() const;
    int GetUtiles() const;

    //Método para agregar partícula
    void agregaParticula(Particula parti);

    //Método para borrar partícula
    void borraParticula(int pos);

    //Método para obtener partícula
    Particula obtieneParticula(int pos) const;

    //Método para reemplazar una partícula por otra
    void reemplazaParticula(int pos, Particula parti);

    //Método para mover partícula
    void moverParticulas(int ancho, int alto);

    //Método para rebotar
    void rebotar(int ancho, int alto);

    //Método para mostrar por pantalla un conjunto de partículas
    void mostrarInfo() const;
};


#endif //PROYECTO_CONJUNTOPARTICULAS_H