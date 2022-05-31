#include "Pintar.h"

const int ancho = 745;
const int alto = 600;

void desafio1(int const &N){
    std::cout << "Desafío 1" << std::endl;
    // Inicializar ventana y objetos
    //---------------------------------------------------------


    InitWindow(ancho, alto, "Desafío 1");

    ConjuntoParticulas gas(N);

    SetTargetFPS(60);
    //----------------------------------------------------------
    // bucle principal
    while (!WindowShouldClose())
    {
        // actualizar objetos
        //-----------------------------------------------------

        gas.moverParticulas(ancho, alto);
        gas.rebotar(ancho, alto);

        for (int i=0; i<gas.GetUtiles(); i++){
            if (gas.obtieneParticula(i).GetDY() > 1)
                gas.obtieneParticula(i).SetDY(gas.obtieneParticula(i).GetDY() - 1);
        }



        //-----------------------------------------------------
        // Dibujar
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Pintar::pintarConjunto(gas, BLUE);

        DrawText("ESC para salir", 10, 10 , 20, BLACK);


        EndDrawing();
        //-----------------------------------------------------
    }


    //---------------------------------------------------------
    CloseWindow();
    //----------------------------------------------------------

}

void desafio2(int const &N){
    std::cout << "Desafío 2" << std::endl;
    // Inicializar ventana y objetos
    //---------------------------------------------------------


    InitWindow(ancho, alto, "Desafío 2");

    ConjuntoParticulas pared(N);
    Particula bola;

    bola.SetDY(20);


    SetTargetFPS(60);
    //----------------------------------------------------------
    // bucle principal
    while (!WindowShouldClose())
    {
        // actualizar objetos
        //-----------------------------------------------------

        bola.mover(ancho, alto);
        bola.rebotaBordes(ancho, alto);

        for (int i=pared.GetUtiles()-1; i>=0; i--){
            if (Pintar::colisionaBolaYLadrillo(bola, pared.obtieneParticula(i))){
                pared.borraParticula(i);
                bola.SetDY(bola.GetDY() * -1.0);
            }
        }



        //-----------------------------------------------------
        // Dibujar
        //-----------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Pintar::pintarPared(pared, ORANGE);
        Pintar::pintarParticula(bola, RED);

        DrawText("ESC para salir", 10, 10 , 20, BLACK);


        EndDrawing();

        if (pared.GetUtiles() == 0){
            DrawText("FINAL DE LA PARTIDA", 200, 300 , 30, BLACK);
            bola.SetRadio(0);
        }
        //-----------------------------------------------------
    }


    //---------------------------------------------------------
    CloseWindow();
    //----------------------------------------------------------

}

int main(){
    int opc;

    std::cout << "Elige entre 1 o 2 (desafío 1 o desafío 2): ";

    std::cin >> opc;

    switch (opc){
        int N;
        case 1:{
            do{
                std::cout << "\nIntroduce el número de partículas del conjunto "
                             "(igual o mayor a 0): ";
                std::cin >> N;
            } while (N < 0);
            desafio1(N);
            break;
        }
        case 2:{
            do{
                std::cout << "\nIntroduce el número de partículas del conjunto "
                             "(igual o mayor a 0): ";
                std::cin >> N;
            } while (N < 0);
            desafio2(N);
            break; }
        default: {std::cout << "Número de desafío incorrecto." << std::endl; break;}
    }
}