#include "../Header files/Particula.h"
#include "../Header files/ConjuntoParticulas.h"
#include <iostream>
#include <cassert>

using namespace std;


void start(){
    cout << "***************** INICIO *****************" << endl;
}

void end(){
    cout << "*****************  FIN   *****************" << endl;
}

void rellenar(ConjuntoParticulas & cp, int n){
    // agrega n particulas con posiciones (1,1), (2,2),,,(n,n)
   float x = 1.0;
   float y = 1.0;
   for(int i = 0; i < n; i++){
        Particula p(x,y, 0, 0, 1);
        cp + p;
        x++; y++;
    }  
    
}

void testP1(string s) {
    start();
    cout << s << endl;
    cout << "Prueba Particulas" << endl;
    cout << "Paso 1 " << endl;
    Particula a(8,8,-1,-1,3), b(3,3,1,1,5);
    cout << "Particula 1: " << a << endl;
    cout << "Particula 2: " << b << endl;
    
    bool rta = (a == b);
    assert(!rta);
    cout <<  "Las particulas son distintas " << endl;
    
    cout << "Paso 2 " << endl;
    a = b;
    cout << "Particula 1: " << a << endl;
    cout << "Particula 2: " << b << endl;
    
    rta = (a == b);
    assert(rta);
    cout << "Las particulas son iguales" << endl;
    
    end();
}

void test1(string s) {
    cout << s << endl;
    start();
    cout << "Prueba constructores y destructor" << endl;
    ConjuntoParticulas cp1; // por defecto
    ConjuntoParticulas cp2(3); // con parametros 
    ConjuntoParticulas otro(cp2); // ctor copia
    end();
}


void test2(string s) {
    cout << s << endl;
    start();
    cout << "Sobrecarga de operador + y <<  " << endl;

    cout << "Crear y mostrar conjunto de 5 particulas " << endl;
    ConjuntoParticulas cp1;
    rellenar(cp1, 5);
    /*
    float x = 1.0;
    float y = 1.0;
    for(int i = 0; i < 5; i++){
        Particula p(x,y, -x, -y,1);
        cp1 + p;
        x++; y++;
    }
     */
    cout << cp1 << endl;
    Particula p2(10,10,10,10,10), p3(11,11,11,11,11);
    cp1 + p2 + p3;
    cout << cp1 << endl;
    end();
}

void test3(string s) {
    cout << s << endl;
    start();
    cout << "Sobrecarga de operador =  " << endl;

    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2;
    
    cp1 + Particula(10,10,0,0,3);
    cp1 + Particula(11,11,0,0,3);

    rellenar(cp2, 4);

    
    cout << "Dos conjuntos iniciales: " << endl;
    cout << "C1: " << cp1 << endl;
    cout << "C2: " << cp2 << endl;

    // asignaciones
    ConjuntoParticulas aux;
    aux = cp1;
    cp1 = cp2;
    cp2 = aux;

    cout << "Conjuntos finales intercambiados: " << endl;
    cout << "C1: " << cp1 << endl;
    cout << "C2: " << cp2 << endl;
    end();
}

void test4(string s) {
  cout << s << endl;
    start();
    cout << "Sobrecarga del operador == " << endl;
    
    ConjuntoParticulas cp1;
    rellenar(cp1, 5);
    //ConjuntoParticulas cp2(cp1);
    ConjuntoParticulas cp2;
    
    for(int i = 0; i < 5; i++){
        cp2 + cp1.obtieneParticula(4-i);
    }
    
    cout << "Dos conjuntos iniciales: " << endl;
    cout << "C1: " << cp1 << endl;
    cout << "C2: " << cp2 << endl;
    cout.flush();
    assert (cp1 == cp2);
    cout << "Conjuntos iguales " << endl;
    
    cp1.reemplazaParticula(2, Particula(-10,-10,0,0,0));
    cout << "Conjunto 1 cambiado " << endl;
    cout << "C1: " << cp1 << endl;

    assert (!(cp1 == cp2));
    cout << "Conjuntos diferentes " << endl;
    end();
    
}

void test5(string s){
    cout << s << endl;
    start();
    cout << "Prueba de distanciaPromedio " << endl;
    Particula p_ref(0,0,0,0,0);
    ConjuntoParticulas c1;
    
    // agrego puntos en el eje x
    c1 + Particula(10,0,0,0,0);
    cout << c1.distanciaPromedio(p_ref) << endl;//10
    
    c1 + Particula(20,0,0,0,0);
    cout << c1.distanciaPromedio(p_ref) << endl;//15
    
    c1 + Particula(30,0,0,0,0);
    cout << c1.distanciaPromedio(p_ref) << endl;//20
    
    c1 + Particula(40,0,0,0,0);
    cout << c1.distanciaPromedio(p_ref) << endl;//25
    end();
}

void test6(string s) {
    cout << s << endl;
    start();
    cout << "Prueba del operador < " << endl;

    ConjuntoParticulas cp1; // constructor por defecto
    ConjuntoParticulas cp2;

    Particula ref(0,0,0,0,0);
    Particula p1(10, 0, 1, 1, 3);
    Particula p2(0, 10, 1, 1, 3);
    Particula p3(10, 10, 1, 1, 3);

    cp1 + p1 + p2;
    
    cp2 = cp1; // sobrecarga de asignacion
    cp2 + p3;
    cout << "Conjuntos " << endl;
    cout << cp1 << endl;
    cout << cp2 << endl;

    cout << "distancia promedio al (0,0): c1: " << cp1.distanciaPromedio(ref) << " c2:" << cp2.distanciaPromedio(ref) << endl;
    if (cp1 < cp2)
        cout << "Conj 1 es menor que Conj 2 " << endl;
    else
        cout << "Conj 2 es mayor o igual que Conj 1 " << endl;
    end();
}

void test7(string s) {
    cout << s << endl;
    start();
    cout << "Ordenar array de ConjuntoParticulas < " << endl;

    srand(12345678);
    int N = 6;
    Particula p_ref(0,0,0,0,0);
    ConjuntoParticulas *cp = new ConjuntoParticulas[N];

    // cada conjunto está vacío. Agrego 10 particulas a cada uno
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            Particula p_rnd;
            cp[i] + p_rnd;
        }
    }

    cout << "\ndistancias sin ordenar" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Conj: " << i << " -> distProm: " << cp[i].distanciaPromedio(p_ref) << endl;
    }

    //ordenar conjuntos
    float min;
    int posMin;

    for (int i = 0; i < N - 1; i++) {
        posMin = i;
        for (int j = i + 1; j < N; j++) {
            if (cp[j] < cp[posMin])
                posMin = j;
        }

        if (posMin != i) {
            ConjuntoParticulas aux(cp[i]);
            cp[i] = cp[posMin];
            cp[posMin] = aux;
        }

    }


    cout << "\nConjuntos ordenados" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Conj: " << i << " -> distPrim: " << cp[i].distanciaPromedio(p_ref) << endl;
    }

    delete [] cp;
    end();
}

void test8(string s) {
    cout << s << endl;
    start();
    cout << "Sobrecarga [] - 1" << endl;
    Particula inicial(1,1,1,1,0);
    ConjuntoParticulas cp(5);
    
    cp[0] = inicial;
    for(int i = 1; i < 5; i++){
        cp[i] = cp[i-1];
        cp[i].mover(100,100);
    }
    
    cout << "Conjunto " << cp << endl;
    end();
}

void funcionAuxiliar(const ConjuntoParticulas & cp){
    cout << "\nImprimir desde auxiliar" << endl;
    for(int i = 0; i < cp.GetUtiles();i++)
        cout << cp[i] << endl;
        
}

void test9(string s) {
    cout << s << endl;
    start();
    cout << "Sobrecarga [] - 2" << endl;
    
    ConjuntoParticulas cp;
    rellenar(cp, 4);
    
    funcionAuxiliar(cp);
    //cout << "Conjunto " << cp << endl;
    end();
}


// al ejecutar el programa, debes indicar el nro de test que quieres ejecutar
// un número entre el 1 y el 10
int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Uso: pruebaFinal <nroTest> donde nroTest es un valor entre 0 y 9" << endl;
        exit(-1);
    }
    
    
    int test = atoi(argv[1]);
    

    int opc = 0;
    if (argc > 1)
         opc = atoi(argv[1]);
    else
        cout << "USO: test <nro>   donde nro indica el test a ejecutar" << endl;

    switch (opc){
        // pruebas particula
        case 0:{testP1("\n***************** TEST 0 ****************** "); break; }

        // ctor/dtor
        case 1:{test1("\n****************** TEST 1 ****************** "); break; } 
        
        //Sobrecarga de operador <<
        case 2:{test2("\n****************** TEST 2 ****************** "); break; } 
        
        //Sobrecarga de operador =
        case 3:{test3("\n****************** TEST 3 ****************** "); break; } 
        
        //Sobrecarga del operador == 
        case 4:{test4("\n****************** TEST 4 ****************** "); break; } 
        
        //distanciaPromedio
        case 5:{test5("\n****************** TEST 5 ****************** "); break; }
        
        //Prueba del operador < entre conjuntos
        case 6:{test6("\n****************** TEST 6 ****************** "); break; }
        
        // ordenacion de conjuntos
        case 7:{test7("\n****************** TEST 7 ****************** "); break; }
     
        // prueba 1 []
        case 8:{test8("\n****************** TEST 8 ****************** "); break; }
     
        // prueba 2 []
        case 9:{test9("\n****************** TEST 9 ****************** "); break; }
             
       
        default: {cout << "Nro. de test incorrecto " << endl; break;}
        }
        
    return 0;
}
