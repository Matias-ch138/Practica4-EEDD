#ifndef PARQUE_H
#define PARQUE_H

#include <iostream>
#include <string>
#include "Especie.h"
#include <vector>
#include <set>
#include <map>
#include "Arbol.h"
using namespace std;

//TODO: Revisar metodos realmente necesarios
class Parque { 
private:
    int cod_parque;
    string nbre_parque;
    vector<Arbol*> contains_;
public:
    Parque();
    Parque(int cod, string nombre);
    ~Parque();

    int get_cod_parque() const;
    void set_cod_parque(int cod);

    string get_nbre_parque() const;
    void set_nbre_parque(string nombre);
    const vector<Arbol*>& get_contains() const;

    bool existeNbreCom(string ncomun);


    void insertarArbol(Arbol* arbol);   
    Arbol* arbolMasAlto();
    int contarEspecies();
    int contarTipos();

    Especie* especieMasComun();
};

#endif