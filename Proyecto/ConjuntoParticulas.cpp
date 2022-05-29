#include <iomanip>
#include "ConjuntoParticulas.h"

ConjuntoParticulas::ConjuntoParticulas() : set{0}, capacidad{0}, utiles{0}{};

ConjuntoParticulas::ConjuntoParticulas(int N) : set{new Particula[N]},
capacidad{N}, utiles{N} {};

ConjuntoParticulas::~ConjuntoParticulas() {
    if (set != 0){
        delete [] set;
        set = 0;
    }
}

int ConjuntoParticulas::GetCapacidad() const{
    return capacidad;
}

int ConjuntoParticulas::GetUtiles() const{
    return utiles;
}


void ConjuntoParticulas::agregaParticula(Particula parti) {
    if (utiles < capacidad){
        set[utiles].SetXY(parti.GetX(), parti.GetY());
        set[utiles].SetDX(parti.GetDX());
        set[utiles].SetDY(parti.GetDY());
        set[utiles].SetRadio(parti.GetRadio());
        utiles++;
    } else{
        capacidad += TAM_BLOQUE;
        delete [] set;
        set = new Particula[capacidad];
        agregaParticula(parti);
    }
}

void ConjuntoParticulas::borraParticula(int pos){
    if (this->capacidad == 0){
        std::cout << "\nERROR: El conjunto está vacío. Por tanto, no es posible"
                     " borrar ninguna partícula.\n";
    } else if (pos >= utiles || pos < 0){
        std::cout << "\nERROR: La partícula dada no pertenece al conjunto.\n";
    } else {
        ConjuntoParticulas conjunto;

        for (int i = 0; i < pos; i++) {
            conjunto.agregaParticula(this->obtieneParticula(i));
        }
        for (int i = pos+1; i < utiles; i++) {
            conjunto.agregaParticula(this->obtieneParticula(i));
        }
        this->capacidad = conjunto.capacidad;
        this->utiles = conjunto.utiles;
        for(int i=0; i<utiles; i++){
            this->set[i].SetXY(conjunto.set[i].GetX(), conjunto.set->GetY());
            this->set[i].SetDX(conjunto.set[i].GetDX());
            this->set[i].SetDY(conjunto.set[i].GetDY());
            this->set[i].SetRadio(conjunto.set[i].GetRadio());
        }
        delete [] conjunto.set;
        conjunto.set = 0;
        conjunto.capacidad = 0;
        conjunto.utiles = 0;

        if ((capacidad - utiles) > TAM_BLOQUE)
            capacidad -= TAM_BLOQUE;
    }
}

Particula ConjuntoParticulas::obtieneParticula(int pos) const {
    return set[pos];
}

void ConjuntoParticulas::reemplazaParticula(int pos, Particula parti){
    if (pos >= 0 && pos < utiles) {
        set[pos].SetXY(parti.GetX(), parti.GetY());
        set[pos].SetDX(parti.GetDX());
        set[pos].SetDY(parti.GetDY());
        set[pos].SetRadio(parti.GetRadio());
    }
}

void ConjuntoParticulas::moverParticulas(int ancho, int alto) {
    for (int i=0; i<utiles; i++){
        set[i].mover(ancho,alto);
    }
}

void ConjuntoParticulas::rebotar(int ancho, int alto) {
    for (int i=0; i<utiles; i++){
        set[i].rebotaBordes(ancho,alto);
    }
}

void ConjuntoParticulas::mostrarInfo() const{
    if (utiles == 0){
        std::cout << "\nEl conjunto de partículas está vacío.\n";
    } else {
    std::cout << "Capacidad total del conjunto: " << capacidad << std::endl;
    std::cout << "Partículas en el conjunto: " << utiles << std::endl;
    std::cout << "Datos de cada partícula: " << std::endl;
        for (int i=0; i<utiles; i++){
            std::cout << "Partícula " << i+1 << ": " << set[i].toString()
            << std::endl;
        }
    }
}
