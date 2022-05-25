
#include "Particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>


using namespace std;

const float ANCHO = 800.0;
const float ALTO = 800.0;

void test1(string s) {
    cout << s << endl;
    cout << "Prueba Constructores " << endl;
    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2(10);
}

void test2(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1(5);

    cout << "Conjunto Inicial " << endl;
    cp1.mostrarInfo();
    
    
    Particula nueva(5.0, 5.0, 0.0, 0.0, 5);
    int n = cp1.GetUtiles();
    for (int i = -1; i <= n + 1; i++)
        cp1.reemplazaParticula(i, nueva);
    
    cout << "----- Después de reemplazar particulas ---- " << endl;
    cp1.mostrarInfo();
}

void test3(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1;

    cout << " ---- Conjunto Inicial ----" << endl;
    cp1.mostrarInfo();
    int n = 12;
    for (int i = 0; i < n; i++) {
        Particula nueva;
        cp1.agregaParticula(nueva);
    }

    cout << " ---- Conjunto Final -----" << endl;
    cp1.mostrarInfo();
}

void test4(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1(11);


    cout << " ---- Conjunto Inicial ----" << endl;
    cp1.mostrarInfo();

    int n = cp1.GetUtiles();
    for (int i = 0; i < n; i++) {
        int nro = cp1.GetUtiles();
        if (nro > 0)
            cp1.borraParticula(random() % nro);
    }
    cout << " ---- Conjunto Final -----" << endl;
    cp1.mostrarInfo();
}

void test5(string s) {
    cout << s << endl;
    int N = 10;
    // creación de objetos
    //---------------------------------------------------------
    ConjuntoParticulas nube(N);
    for (int i = 0; i < 100; i++) {
        if ((random() % 10) > 5)
            for (int j = 0; j < 7; j++) {
                Particula nueva;
                nube.agregaParticula(nueva);
            } else {
            for (int j = 0; j < 7; j++) {
                int nro = nube.GetUtiles();
                if (nro > 0)
                    nube.borraParticula((random() % nro));
            }
        }
        nube.mover(ANCHO, ALTO);
        nube.rebotar(ANCHO, ALTO);

    }

}

int main(int argc, char* argv[]) {
    int opc = 0;
    if (argc > 1)
         opc = atoi(argv[1]);
    else
        cout << "USO: test <nro>   donde nro indica el test a ejecutar" << endl;

    switch (opc){
        case 1:{test1("\n************* Test 1 ************* "); break; } 
        case 2:{test2("\n************* Test 2 ************* "); break; } 
        case 3:{test3("\n************* Test 3 ************* "); break; } 
        case 4:{test4("\n************* Test 4 ************* "); break; } 
        case 5:{test5("\n************* Test 5 ************* "); break; } 
        default: {cout << "Nro. de test incorrecto " << endl; break;}
    }

    return 0;
}
