#include "Pintar.h"
#include "parametros.h"

void Pintar::pintarParticula(const Particula &p, Color c) {
    DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}


void Pintar::pintarLadrillo(const Particula &p, Color c){
    Rectangle ladrillo = {p.GetX(), p.GetY(), AnchoLadrillo, AltoLadrillo};
    DrawRectangleRec(ladrillo, c);
}

void Pintar::pintarConjunto(const ConjuntoParticulas &cp, Color c) {
    int N = cp.GetUtiles();
    for (int i=0; i < N; i++){
        pintarParticula(cp.obtieneParticula(i), c);
    }
}

/*void Pintar::pintarPared(const ConjuntoParticulas &cp, Color c){
    int N = cp.GetUtiles();
    for (int i=0; i < N; i++){
        pintarLadrillo(cp.obtieneParticula(i), c);
    }
}*/

void Pintar::pintarPared(const ConjuntoParticulas &p){
    float x = 30, y = 90;
    int sumaX = 70, sumaY = 30;
    int pos = 0;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 10; j++){
            p.obtieneParticula(pos).SetXY(x, y);
            p.obtieneParticula(pos).SetDX(0);
            p.obtieneParticula(pos).SetDY(0);
            p.obtieneParticula(pos).SetRadio(3);
            pos++;
            x+=sumaX;
        }
        x = 30;
        y += sumaY;
    }

    for (int i=0; i < 10; i++){
            pintarLadrillo(p.obtieneParticula(i), PURPLE);
    }
    for (int i=10; i < 20; i++){
        pintarLadrillo(p.obtieneParticula(i), RED);
    }
    for (int i=20; i < 30; i++){
        pintarLadrillo(p.obtieneParticula(i), BLUE);
    }
    for (int i=30; i < 40; i++){
        pintarLadrillo(p.obtieneParticula(i), YELLOW);
    }
    for (int i=40; i < 50; i++){
        pintarLadrillo(p.obtieneParticula(i), GREEN);
    }
}

bool Pintar::colisionaBolaYLadrillo(Particula &_bola, Particula &_ladrillo){
    Vector2 bola = {_bola.GetX(), _bola.GetY()};
    Rectangle ladrillo = {_ladrillo.GetX(), _ladrillo.GetY(), AnchoLadrillo, AltoLadrillo};

    if (CheckCollisionCircleRec(bola, _bola.GetRadio(), ladrillo)){
        return true;
    }
    return false;
}

char Pintar::Direccion(){
    char dir = ' ';

    if (IsKeyDown(KEY_LEFT))
        dir = 'L';

    if (IsKeyDown(KEY_RIGHT))
        dir = 'R';

    return dir;
}