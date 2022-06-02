#ifndef PROYECTO_PINTAR_H
#define PROYECTO_PINTAR_H

#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "raylib.h"

class Pintar {
public:
    //Método para pintar una bola
    static void pintarParticula (const Particula &p, Color c);

    //Método para pintar un ladrillo
    static void pintarLadrillo(const Particula &p, Color c);

    //Método para pintar un conjunto de bolas
    static void pintarConjunto (const ConjuntoParticulas &cp, Color c);

    //Método para pintar una pared de ladrillos
    static void pintarPared(const ConjuntoParticulas &cp);

    static bool colisionaBolaYLadrillo(Particula &_bola, Particula &_ladrillo);

    static char Direccion();
};


#endif //PROYECTO_PINTAR_H