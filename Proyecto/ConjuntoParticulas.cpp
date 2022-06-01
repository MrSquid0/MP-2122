#include "ConjuntoParticulas.h"

ConjuntoParticulas::ConjuntoParticulas() : set{0}, capacidad{0}, utiles{0}{};

ConjuntoParticulas::ConjuntoParticulas(int N) : set{new Particula[N]},
                                                capacidad{N}, utiles{N} {};

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &conjunto) {
    copiar(conjunto);
}

void ConjuntoParticulas::copiar(const ConjuntoParticulas &conjunto) {
    this->capacidad = conjunto.capacidad;
    this->utiles = conjunto.utiles;
    this->set = new Particula[capacidad];
    for (int i=0; i<utiles; i++){
        this->set[i] = conjunto.set[i];
    }
}

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
    if (utiles < capacidad) {
        set[utiles].SetXY(parti.GetX(), parti.GetY());
        set[utiles].SetDX(parti.GetDX());
        set[utiles].SetDY(parti.GetDY());
        utiles++;
    } else {
        if (capacidad == 0) {
            capacidad += TAM_BLOQUE;
            delete [] set;
            set = new Particula[capacidad];
            agregaParticula(parti);
        } else {
            capacidad += TAM_BLOQUE;
            Particula array[capacidad];
            for (int i = 0; i < utiles; i++) {
                array[i].SetXY(set[i].GetX(), set[i].GetY());
                array[i].SetDX(set[i].GetDX());
                array[i].SetDY(set[i].GetDY());
            }
            delete[] set;
            set = new Particula[capacidad];
            for (int i = 0; i < utiles; i++) {
                set[i].SetXY(array[i].GetX(), array[i].GetY());
                set[i].SetDX(array[i].GetDX());
                set[i].SetDY(array[i].GetDY());
            }
            agregaParticula(parti);
        }
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
            this->set[i].SetXY(conjunto.set[i].GetX(), conjunto.set[i].GetY());
            this->set[i].SetDX(conjunto.set[i].GetDX());
            this->set[i].SetDY(conjunto.set[i].GetDY());
        }
        delete [] conjunto.set;
        conjunto.set = 0;
        conjunto.capacidad = 0;
        conjunto.utiles = 0;

        if ((capacidad - utiles) > TAM_BLOQUE)
            capacidad -= TAM_BLOQUE;
    }
}

Particula& ConjuntoParticulas::obtieneParticula(int pos) const {
    return set[pos];
}

void ConjuntoParticulas::reemplazaParticula(int pos, Particula parti){
    if (pos >= 0 && pos < utiles) {
        set[pos].SetXY(parti.GetX(), parti.GetY());
        set[pos].SetDX(parti.GetDX());
        set[pos].SetDY(parti.GetDY());
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

void ConjuntoParticulas::operator=(const ConjuntoParticulas &conjunto) {
    delete [] this->set;
    copiar(conjunto);
}

std::ostream& operator<<(std::ostream &os, const ConjuntoParticulas &conjunto){
    conjunto.mostrarInfo();
}

Particula& ConjuntoParticulas::operator[](int i) const{
    return this->set[i];
}

ConjuntoParticulas& operator +(ConjuntoParticulas &conjunto, Particula parti){
    conjunto.agregaParticula(parti);
}

bool operator ==(ConjuntoParticulas const& conjunto1, ConjuntoParticulas const& conjunto2){
    bool sonIguales = false;
    if ((conjunto1.GetUtiles() == conjunto2.GetUtiles())){
        for (int i=0; i<conjunto1.GetUtiles(); i++){
            for (int j=0; j<conjunto2.GetUtiles(); j++){
                if (conjunto1.obtieneParticula(i) == conjunto2.obtieneParticula(j)) {
                    sonIguales = true;
                    break;
                }
                else {
                    if (j==conjunto2.GetUtiles()-1){
                        sonIguales = false;
                        return sonIguales;
                    }
                }
            }
        }
    }
    return sonIguales;
}

float ConjuntoParticulas::distanciaPromedio(Particula &parti) const {
    float distancia = 0;
    for(int i=0; i<utiles; i++){
        distancia += parti.distancia(this->obtieneParticula(i));
    }
    distancia /= utiles;
    return distancia;
}

bool operator<(const ConjuntoParticulas &cp1, const ConjuntoParticulas &cp2){
    Particula cero(0,0,0,0,0);
    if (cp1.distanciaPromedio(cero) < cp2.distanciaPromedio(cero))
        return true;

    return false;
}