#include <fstream>
#include "Pintar.h"
#include "Game.h"

int main(){
    // Inicializar objetos y ventana
    //---------------------------------------------------------

    ConjuntoParticulas pared[numFilas];
    Particula base(ancho/2.0f, alto-100.0f, 0, 0, 15);
    Particula bola(base.GetX()+25.0f,base.GetY()-20.0f,0,0,15);
    char dir;
    int soloPrimeraVez = 0;

    Game breakout;

    breakout.Init(pared);
    //----------------------------------------------------------
    // Bucle principal
    while (!WindowShouldClose())
    {
        // Actualizar objetos
        //-----------------------------------------------------

        breakout.Update(dir, bola, base, pared, soloPrimeraVez);

        //-----------------------------------------------------
        // Dibujar
        //-----------------------------------------------------
        breakout.pintar(pared, bola, base, soloPrimeraVez);


        //-----------------------------------------------------
        // Acabar la partida
        //-----------------------------------------------------

        breakout.End(pared, bola, base);
        //-----------------------------------------------------
    }

    //---------------------------------------------------------
    CloseWindow();
    //----------------------------------------------------------
    return 0;
}