
#ifndef PROYECTO_PINTAR_H
#define PROYECTO_PINTAR_H

#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "raylib.h"

class Pintar {
public:
    void pintarParticula (const Particula &p, Color c);
    void pintarConjunto (const ConjuntoParticulas &cp, Color c);
};


#endif //PROYECTO_PINTAR_H