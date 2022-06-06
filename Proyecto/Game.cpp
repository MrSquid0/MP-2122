#include "Game.h"

bool Game::getJuegoActivo() const{
    return juegoActivo;
}

int Game::getVidas() const {
    return vidas;
}

double Game::getTiempo() const {
    return tiempo;
}

bool Game::getMensajeEspacio() const {
    return mensajeEspacio;
}

void Game::Init(ConjuntoParticulas pared[]) {
    InitWindow(ancho, alto, "Minijuego");
    SetTargetFPS(60);

    inicializarPared(pared);
    colocarPared(pared);
}

void Game::Update(char &dir, Particula &bola, Particula &base,
                  ConjuntoParticulas pared[], int &soloPrimeraVez) {
    dir = Direccion();

    base.moverGrid(dir, ancho-40, alto);

    bola.mover(ancho, alto);
    bola.rebotaBordes(ancho, alto);

    borrarPared(pared,bola);

    if (colisionaBolaYLadrillo(bola,base))
        bola.SetDY(bola.GetDY() * -1.0);

    empezarRonda(bola, base, soloPrimeraVez);
}

void Game::pintar(ConjuntoParticulas pared[], Particula &bola,
                  Particula &base, int &soloPrimeraVez) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    Pintar ventana;

    ventana.pintarParticula(bola, RED);
    ventana.pintarLadrillo(base, BLACK);
    ventana.pintarPared(pared);

    DrawText("ESC para salir", 10, 10 , 20, BLACK);

    if (juegoActivo){
        std::string vidasString = "Vidas: " + std::to_string(vidas);
        DrawText(vidasString.c_str(), 600, 10, 20, BLACK);

        if (soloPrimeraVez != 0){
            tiempo = GetTime();
            std::string tiempoString = "Tiempo: " + std::to_string(tiempo);
            DrawText(tiempoString.c_str(), 10, 40, 20, BLACK);
        } else
            DrawText("Tiempo: 0", 10, 40, 20, BLACK);
    }

    if (mensajeEspacio){
        DrawText("ESPACIO para empezar", 280, 400 , 20, BLACK);
    }


    EndDrawing();
}

void Game::End(ConjuntoParticulas pared[], Particula &bola,
               Particula &base) {
    if ((pared[0].GetUtiles() == 0 && pared[1].GetUtiles() == 0 &&
         pared[2].GetUtiles() == 0 && pared[3].GetUtiles() == 0 &&
         pared[4].GetUtiles() == 0) || ((bola.GetY() + bola.GetRadio()) >= alto)) {
        bola.SetDX(0);
        bola.SetDY(0);
        if (vidas == 0){
            std::string tiempoString = "TIEMPO TOTAL: " + std::to_string(tiempo);
            DrawText("FINAL DE LA PARTIDA", 200, 300, 30, BLACK);
            DrawText(tiempoString.c_str(), 200-15, 400, 30, BLACK);
            bola.SetRadio(0);
            quitarBase(base);
            vaciarPared(pared);
            juegoActivo = false;
        } else {
            vidas--;
            base.SetXY(ancho/2.0f, alto-100.0f);
            bola.SetXY(base.GetX()+25.0f,base.GetY()-20.0f);
            base.SetDX(0);
            base.SetDY(0);
            int iter = 2;
            empezarRonda(bola, base, iter);
        }
    }
}

bool Game::colisionaBolaYLadrillo(Particula &_bola, Particula &_ladrillo){
    Vector2 bola = {_bola.GetX(), _bola.GetY()};
    Rectangle ladrillo = {_ladrillo.GetX(), _ladrillo.GetY(),
                          AnchoLadrillo, AltoLadrillo};

    //He utilizado este método en vez del de colision() para que tuviese en
    //cuenta toda la estructura de la bola y del ladrillo y no solo las
    //coordenadas exactas de la partícula
    if (CheckCollisionCircleRec(bola, _bola.GetRadio(), ladrillo)){
        return true;
    }
    return false;
}

char Game::Direccion(){
    char dir = ' ';

    if (IsKeyDown(KEY_LEFT))
        dir = 'L';

    if (IsKeyDown(KEY_RIGHT))
        dir = 'R';

    return dir;
}

void Game::inicializarPared(ConjuntoParticulas pared[]) {
    ConjuntoParticulas fila(numLadrillosPorFila);

    for (int i=0; i<numFilas; i++){
        pared[i] = fila;
    }
}

void Game::colocarPared(ConjuntoParticulas pared[]) {
    float x = 30, y = 90;
    float sumaX = 70, sumaY = 30;

    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < pared[i].GetUtiles(); j++){
            pared[i].obtieneParticula(j).SetXY(x, y);
            pared[i].obtieneParticula(j).SetDX(0);
            pared[i].obtieneParticula(j).SetDY(0);
            pared[i].obtieneParticula(j).SetRadio(3);
            x += sumaX;
        }
        x = 30;
        y += sumaY;
    }
}

void Game::borrarPared(ConjuntoParticulas pared[], Particula &bola) {

    for (int i = numFilas - 1; i >= 0; i--) {
        for (int j = pared[i].GetUtiles() - 1; j >= 0; j--) {
            if (Game::colisionaBolaYLadrillo(bola, pared[i].obtieneParticula(j))) {
                pared[i].borraParticula(j);
                bola.SetDY(bola.GetDY() * -1.0);
            }
        }
    }
}

void Game::vaciarPared(ConjuntoParticulas pared[]) {
    ConjuntoParticulas vacio;
    for (int i=0; i<numFilas; i++){
        pared[i] = vacio;
    }
}

void Game::quitarBase(Particula &base) {
    base.SetXY(base.GetX(),alto);
    base.SetDX(0);
    base.SetDY(0);
    base.SetRadio(0);
}

void Game::empezarRonda(Particula &bola, Particula &base, int &soloPrimeraVez) {
    //Empezar primera ronda
    if (soloPrimeraVez ==0  && IsKeyPressed(KEY_SPACE)){
        mensajeEspacio = false;
        bola.SetDX(2);
        bola.SetDY(5);
        base.SetDX(velocidadBase);
        base.SetDY(velocidadBase);
        soloPrimeraVez++;
        juegoActivo = true;
    }

    //Empezar resto de rondas (cuando se pierde una vida)
    if (soloPrimeraVez == 2){
        bola.SetDX(2);
        bola.SetDY(5);
        base.SetDX(velocidadBase);
        base.SetDY(velocidadBase);
    }
}