#include "Pintar.h"

void Pintar::pintarParticula(const Particula &p, Color c) {
    DrawCircle (p.GetX(), p.GetY(), p.GetRadio(), c);
}

void Pintar::pintarConjunto(const ConjuntoParticulas &cp, Color c) {
    int N = cp.GetUtiles();
    for (int i = 0; i < N; i++){
        pintarParticula(cp.obtieneParticula(i), c);
    }
}
