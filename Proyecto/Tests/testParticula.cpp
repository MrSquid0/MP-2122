#include <iostream>
#include "../Header files/Particula.h"
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
    int ANCHO = 10;
    int ALTO = 10;

    Particula p(5, 5, 1, 1, 3);
    cout << "Estado 0: " << p.toString() << endl;

    p.mover(ANCHO, ALTO);
    cout << "Estado 1: " << p.toString() << endl;

    p.mover(ANCHO, ALTO);
    cout << "Estado 2: " << p.toString() << endl;

    p.mover(ANCHO, ALTO);
    cout << "Estado 3: " << p.toString() << endl;


    float grados = 180;
    float rads = grados * (M_PI / 180.0);
    p.rotar(5, 5, rads);
    cout << "Estado 4: " << p.toString() << endl;


    p.SetXY(6, 5);
    p.SetDY(0);
    p.SetDX(1);
    for (int i = 0; i < 10; i++) {
        p.mover(ANCHO, ALTO);
        p.rebotaBordes(ANCHO, ALTO);
        cout << "Paso: " << i << " " << p.toString() << endl;
    }

    Particula otra(1, 1, 1, 1, 2);

    cout << "Distancia entre:\n" << otra.toString() << "\n" << p.toString();
    cout << "\nEs: " << p.distancia(otra) << " Colision " << otra.colision(p) << endl;
    otra.mover(ANCHO, ALTO);
    otra.mover(ANCHO, ALTO);

    cout << "Distancia entre:\n" << otra.toString() << "\n" << p.toString();
    cout << "\nEs: " << p.distancia(otra) << " Colision " << otra.colision(p) << endl;
}