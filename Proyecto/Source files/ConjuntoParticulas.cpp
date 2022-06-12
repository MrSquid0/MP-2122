#include "../Header files/ConjuntoParticulas.h"

ConjuntoParticulas::ConjuntoParticulas() : set{0}, capacidad{0}, utiles{0}{};

ConjuntoParticulas::ConjuntoParticulas(int N){
    if (N < 0)
        N = 0;
    set = new Particula[N];
    capacidad = N;
    utiles = N;
}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas &conjunto) {
    copiar(conjunto);
}

ConjuntoParticulas::ConjuntoParticulas(const char *nombre) {
    capacidad = 0;
    utiles = 0;
    set = 0;
    std::fstream fichero(nombre);
    if (!nombre){
        std::cout << "\nEl archivo está vacío o no existe.";
    } else {
        int numParticulas;
        fichero >> numParticulas;

        Particula fila;
        for (int i=0; i<numParticulas; i++) {
            fichero >> fila;
            this->agregaParticula(fila);
        }
    }
}

void ConjuntoParticulas::copiar(const ConjuntoParticulas &conjunto) {
    this->capacidad = conjunto.capacidad;
    this->utiles = conjunto.utiles;
    this->set = new Particula[capacidad];
    for (int i=0; i<utiles; i++){
        this->set[i] = conjunto.set[i];
    }
}

void ConjuntoParticulas::reservarMemoria() {
    liberarMemoria();
    set = new Particula[capacidad];
}

void ConjuntoParticulas::liberarMemoria() {
    if (set != 0){
        delete [] set;
        set = 0;
    }
}

ConjuntoParticulas::~ConjuntoParticulas() {
    liberarMemoria();
}

int ConjuntoParticulas::GetCapacidad() const{
    return capacidad;
}

int ConjuntoParticulas::GetUtiles() const{
    return utiles;
}


void ConjuntoParticulas::agregaParticula(Particula &parti) {
    if (utiles < capacidad) {
        set[utiles].SetXY(parti.GetX(), parti.GetY());
        set[utiles].SetDX(parti.GetDX());
        set[utiles].SetDY(parti.GetDY());
        set[utiles].SetRadio(parti.GetRadio());
        utiles++;
    } else {
        if (capacidad == 0) {
            capacidad += TAM_BLOQUE;
            reservarMemoria();
            agregaParticula(parti);
        } else {
            capacidad += TAM_BLOQUE;
            Particula array[capacidad];
            for (int i = 0; i < utiles; i++) {
                array[i].SetXY(set[i].GetX(), set[i].GetY());
                array[i].SetDX(set[i].GetDX());
                array[i].SetDY(set[i].GetDY());
                array[i].SetRadio(set[i].GetRadio());
            }
            reservarMemoria();
            for (int i = 0; i < utiles; i++) {
                set[i].SetXY(array[i].GetX(), array[i].GetY());
                set[i].SetDX(array[i].GetDX());
                set[i].SetDY(array[i].GetDY());
                set[i].SetRadio(array[i].GetRadio());
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
        conjunto.liberarMemoria();
        conjunto.capacidad = 0;
        conjunto.utiles = 0;

        if ((capacidad - utiles) > TAM_BLOQUE)
            capacidad -= TAM_BLOQUE;
    }
}

Particula& ConjuntoParticulas::obtieneParticula(int pos) const {
    return set[pos];
}

void ConjuntoParticulas::reemplazaParticula(int pos, Particula &parti){
    if (pos >= 0 && pos < utiles) {
        set[pos].SetXY(parti.GetX(), parti.GetY());
        set[pos].SetDX(parti.GetDX());
        set[pos].SetDY(parti.GetDY());
    } else{
        std::cout << "La posición no es válida";
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

std::string ConjuntoParticulas::mostrarInfo() const {
    std::string s = "\n";
    if (utiles == 0) {
        s += "\nEl conjunto de partículas está vacío.\n";
    } else {
        s += "Capacidad total del conjunto: " + std::to_string(capacidad) + "\n";
        s += "Partículas en el conjunto: " + std::to_string(utiles) + "\n";
        s += "Datos de cada partícula: \n";
        for (int i = 0; i < utiles; i++) {
            s += "Partícula " + std::to_string(i + 1) + ": " +
                    set[i].toString() + "\n";
        }
    }
    return s;
}

void ConjuntoParticulas::operator=(const ConjuntoParticulas &conjunto) {
    liberarMemoria();
    copiar(conjunto);
}

Particula& ConjuntoParticulas::operator[](int i) const{
    return this->set[i];
}

ConjuntoParticulas &ConjuntoParticulas::operator+(Particula &parti) {
    this->agregaParticula(parti);
    return *this;
}

bool ConjuntoParticulas::operator ==(ConjuntoParticulas const &cp2) const{
    bool sonIguales = false;
    if ((this->GetUtiles() == cp2.GetUtiles())){
        if (this->GetUtiles() != 0 && cp2.GetUtiles() != 0){
            for (int i=0; i<this->GetUtiles(); i++){
                for (int j=0; j<cp2.GetUtiles(); j++){
                    if (this->obtieneParticula(i) == cp2.obtieneParticula(j)) {
                        sonIguales = true;
                        break;
                    }
                    else {
                        if (j==cp2.GetUtiles()-1)
                            return false;
                    }
                }
            }
        } else
            sonIguales = true;
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

bool ConjuntoParticulas::operator<(const ConjuntoParticulas &cp2) const{
    Particula cero(0,0,0,0,0);
    if (this->distanciaPromedio(cero) < cp2.distanciaPromedio(cero))
        return true;

    return false;
}

std::ostream& operator<<(std::ostream &flujo, ConjuntoParticulas &cp){
    flujo << cp.mostrarInfo();
    return flujo;
}