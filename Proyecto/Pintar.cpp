#include "Pintar.h"

void Pintar::pintarParticula(const Particula &p, int c) {
    DrawCircle (p.GetX(), p.GetY(), p.GetRadio(), c);
}

void Pintar::pintarConjunto(const ConjuntoParticulas &cp, int c) {
    int N = cp.GetUtiles();
    for (int i = 0; i < N; i++){
        pintarParticula(cp.obtieneParticula(i));
    }
}