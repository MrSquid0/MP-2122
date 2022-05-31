#include "Pintar.h"

void Pintar::pintarParticula(const Particula &p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}


void Pintar::pintarLadrillo(const Particula &p, Color c){
    Rectangle ladrillo = {p.GetX(), p.GetY(), 50, 15};
    DrawRectangleRec(ladrillo, c);
    //DrawRectangle(p.GetX(), p.GetY(), 50, 15, c);
}

void Pintar::pintarConjunto(const ConjuntoParticulas &cp, Color c) {
    int N = cp.GetUtiles();
    for (int i=0; i < N; i++){
        pintarParticula(cp.obtieneParticula(i), c);
    }
}

void Pintar::pintarPared(const ConjuntoParticulas &cp, Color c){
    int N = cp.GetUtiles();
    for (int i=0; i < N; i++){
        pintarLadrillo(cp.obtieneParticula(i), c);
    }
}

bool Pintar::colisionaBolaYLadrillo(Particula &_bola, Particula &_ladrillo){
    Vector2 bola = {_bola.GetX(), _bola.GetY()};
    Rectangle ladrillo = {_ladrillo.GetX(), _ladrillo.GetY(), 50, 15};

    if (CheckCollisionCircleRec(bola, _bola.GetRadio(), ladrillo)){
        return true;
    }
    return false;
}