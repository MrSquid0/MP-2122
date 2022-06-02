#include "Pintar.h"
#include "parametros.h"

int main(){
    std::cout << "Desafío 2" << std::endl;
    // Inicializar ventana y objetos
    //---------------------------------------------------------


    InitWindow(ancho, alto, "Desafío 2");

    ConjuntoParticulas pared(NumLadrillosEnPared);

    Particula bola;
    Particula base(GetScreenWidth()/2.0f, GetScreenHeight()-100, DESP, DESP, 15);

    bola.SetDY(5);


    SetTargetFPS(60);
    //----------------------------------------------------------
    // bucle principal
    char dir;
    while (!WindowShouldClose())
    {
        // actualizar objetos
        //-----------------------------------------------------

        dir = Pintar::Direccion();

        base.moverGrid(dir, ancho-40, alto);

        bola.mover(ancho, alto);
        bola.rebotaBordes(ancho, alto);

        for (int i=pared.GetUtiles()-1; i>=0; i--){
            if (Pintar::colisionaBolaYLadrillo(bola, pared.obtieneParticula(i))){
                pared.borraParticula(i);
                bola.SetDY(bola.GetDY() * -1.0);
            }
        }

        if (Pintar::colisionaBolaYLadrillo(bola, base))
            bola.SetDY(bola.GetDY() * -1.0);



        //-----------------------------------------------------
        // Dibujar
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Pintar::pintarParticula(bola, RED);
        Pintar::pintarLadrillo(base, BLACK);
        Pintar::pintarPared(pared);

        DrawText("ESC para salir", 10, 10 , 20, BLACK);


        EndDrawing();

        if (pared.GetUtiles() == 0){
            DrawText("FINAL DE LA PARTIDA", 200, 300 , 30, BLACK);
            bola.SetRadio(0);
            base.SetRadio(0);
            for (int i=pared.GetUtiles()-1; i>=0; i--){
                    pared.borraParticula(i);
            }
        }
        //-----------------------------------------------------
    }


    //---------------------------------------------------------
    CloseWindow();
    //----------------------------------------------------------
    return 0;
}