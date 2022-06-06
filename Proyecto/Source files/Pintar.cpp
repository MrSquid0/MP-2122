#include "../Header files/Pintar.h"

void Pintar::pintarParticula(const Particula &p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}


void Pintar::pintarLadrillo(const Particula &p, Color c){
    Rectangle ladrillo = {p.GetX(), p.GetY(), AnchoLadrillo, AltoLadrillo};
    DrawRectangleRec(ladrillo, c);
}

void Pintar::pintarFila(const ConjuntoParticulas &fila, Color c){
    for (int i=0; i < fila.GetUtiles(); i++){
        pintarLadrillo(fila.obtieneParticula(i), c);
    }
}

void Pintar::pintarPared(const ConjuntoParticulas pared[]) {
    Color colores[5] = {PURPLE, RED, ORANGE, GREEN, BLUE};
    for (int i=0; i<numFilas; i++){
            pintarFila(pared[i],colores[i]);
    }
}