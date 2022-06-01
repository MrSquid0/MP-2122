#ifndef PROYECTO_CONJUNTOPARTICULAS_H
#define PROYECTO_CONJUNTOPARTICULAS_H


#include "Particula.h"

const int TAM_BLOQUE = 3;

class ConjuntoParticulas {
private:
    Particula *set;
    int capacidad;
    int utiles;
    //Método auxiliar para copiar conjuntos
    void copiar(const ConjuntoParticulas &conjunto);

public:
    //Constructor sin parámetros
    ConjuntoParticulas();

    //Constructor con parámetros
    ConjuntoParticulas(int capacidad);

    //Constructor de copia
    ConjuntoParticulas(const ConjuntoParticulas &conjunto);

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
    Particula& obtieneParticula(int pos) const;

    //Método para reemplazar una partícula por otra
    void reemplazaParticula(int pos, Particula parti);

    //Método para mover partícula
    void moverParticulas(int ancho, int alto);

    //Método para rebotar
    void rebotar(int ancho, int alto);

    //Método para mostrar por pantalla un conjunto de partículas
    void mostrarInfo() const;

    //Operador de asignación sobrecargado para asignar un conjunto a otro
    void operator=(const ConjuntoParticulas &conjunto);

    //Operador sobrecargado << para mostrar por pantalla un conjunto
    friend std::ostream& operator<<(std::ostream &os, const ConjuntoParticulas &conjunto);

    //Operador sobrecargado [] para acceso y modificación
    Particula& operator[](int i) const;

    //Operador sobrecargado + para agregar una partícula a un conjunto
    friend ConjuntoParticulas& operator +(ConjuntoParticulas &conjunto, Particula parti);

    //Operador sobrecargado == para saber si 2 conjuntos son iguales
    friend bool operator ==(ConjuntoParticulas const& conjunto1, ConjuntoParticulas const& conjunto2);

    //Método que devuelve la distancia promedio del conjunto a una partícula
    float distanciaPromedio(Particula &parti) const;

    //Operador sobrecargado < para saber si la distancia promedio de las partículas
    //de cp1 al punto (0,0) es menor que la distancia promedio de las partículas de
    // cp2 a dicho punto.
    friend bool operator<(const ConjuntoParticulas &cp1, const ConjuntoParticulas &cp2);
};


#endif //PROYECTO_CONJUNTOPARTICULAS_H