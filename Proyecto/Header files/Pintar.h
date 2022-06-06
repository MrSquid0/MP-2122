#ifndef PROYECTO_PINTAR_H
#define PROYECTO_PINTAR_H

#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "raylib.h"
#include "parametros.h"

class Pintar {
public:
    //Método para pintar una bola
    void pintarParticula (const Particula &p, Color c);

    //Método para pintar un ladrillo
    void pintarLadrillo(const Particula &p, Color c);

    //Método para pintar una fila de partículas (ladrillos)
    void pintarFila(const ConjuntoParticulas &fila, Color c);

    //Método para pintar todas las filas de partículas (pared de ladrillos)
    void pintarPared(const ConjuntoParticulas pared[]);
};


#endif //PROYECTO_PINTAR_H