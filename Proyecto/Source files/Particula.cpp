#include "../Header files/Particula.h"
#include <cmath>
#include <iostream>



using namespace std;

// constructor sin parametros.
// Suponemos un tamaño minimo del mundo
// y una velocidad máxima permitida

Particula::Particula() {
    x = rand() % MIN_DIM + 1;
    y = rand() % MIN_DIM + 1;

    dx = rand() % MAX_VEL + 1;
    dy = rand() % MAX_VEL + 1;
    radio = RADIO;
}

float Particula::distancia(const Particula & otra) const {
    float xx = otra.x - this->x;
    float yy = otra.y - this->y;

    return (sqrt(xx * xx + yy * yy));
}

bool Particula::colision(const Particula & otra) const {
    float d = this->distancia(otra);

    return (d < (this->radio + otra.radio));
}

float Particula::GetX() const {
    return (x);
}

float Particula::GetY() const {
    return (y);
}

float Particula::GetDX() const {
    return (dx);
}

float Particula::GetDY() const {
    return (dy);
}

float Particula::GetRadio() const {
    return (radio);
}

void Particula::SetXY(float _x, float _y) {
    x = _x;
    y = _y;
}

void Particula::SetDX(float _dx) {
    dx = _dx;
}

void Particula::SetDY(float _dy) {
    dy = _dy;
}

void Particula::SetRadio(float _r) {
    radio = _r;
}

void Particula::ajustarPosicion(int ancho, int alto) {

    if (x >= ancho - radio)
        x = ancho - radio;
    else if (x <= radio)
        x = radio;


    if (y >= alto - radio)
        y = alto - radio;
    else if (y <= radio)
        y = radio;

}

void Particula::moverGrid(char dir, int ancho, int alto) {
    if (dir == 'U')
        y -= dy;

    if (dir == 'D')
        y += dy;

    if (dir == 'L')
        x -= dx;

    if (dir == 'R')
        x += dx;


    this->ajustarPosicion(ancho, alto);

}

void Particula::mover(int ancho, int alto) {
    x += dx;
    y += dy;
    this->ajustarPosicion(ancho, alto);
}

void Particula::rebotaBordes(int ancho, int alto) {

    if ((x >= (ancho - radio)) || (x <= radio))
        dx *= -1.0f;

    if ((y >= (alto - radio)) || (y <= radio))
        dy *= -1.0f;

}

void Particula::rotar(float posX, float posY, double rads) {
    float deltaX = x - posX;
    float deltaY = y - posY;

    x = posX + deltaX * cos(rads) - deltaY * sin(rads);
    y = posY + deltaX * sin(rads) + deltaY * cos(rads);

}

std::string Particula::toString() const {
    string s = "";
    s = "(x: " + to_string(x) + ", y: " + to_string(y) + ", ";
    s += " dx: " + to_string(dx) + ", dy: " + to_string(dy) + " R: " + to_string(radio) + ")";
    return s;
}

void Particula::intercambiaVelocidad(Particula & otra) {
    float aux_DX = otra.dx;
    float aux_DY = otra.dy;

    otra.dx = dx;
    otra.dy = dy;

    dx = aux_DX;
    dy = aux_DY;

}
std::ostream& operator<<(std::ostream &os, Particula &parti) {
    os << parti.toString();
    return os;
}

void operator>>(std::istream& in, Particula &parti){
    float x, y, dx, dy, radio;
    std::cout << "\nIntroduce la posición X: " ;
    in >> x;
    //if (x < 0) //No tiene sentido que la X sea negativa
    //    x = 0;

    std::cout << "Introduce la posición Y: ";
    in >> y;
    //if (y < 0) //No tiene sentido que la Y sea negativa
    //    y = 0;

    std::cout << "Introduce la velocidad de X: ";
    in >> dx;

    std::cout << "Introduce la velocidad de Y: ";
    in >> dy;

    std::cout << "Introduce el radio: ";
    in >> radio;
    if (radio < 0) //No tiene sentido que el radio sea negativo
        radio = 0;

    parti.SetXY(x,y);
    parti.SetDX(dx);
    parti.SetDY(dy);
    parti.SetRadio(radio);
}

bool Particula::operator ==(Particula const& parti2) const{
    if (this->distancia(parti2) < VALOR_PEQ) {
        return true;
    }
    return false;
}