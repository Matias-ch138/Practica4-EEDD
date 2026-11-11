#ifndef Arbol_H
#define Arbol_H

#include <iostream>
#include <string>
#include "Especie.h"
#include "Parque.h"

using namespace std;

class Arbol {
private:
    string assetnum_;
    int num_parque_;
    int num_distrito_;
    string nbre_distrito_;
    int num_barrio_;
    string nbre_barrio_;
    double X_;
    double Y_;
    float perimetro_;
    float altura_;
    Especie* especieAsociada_;
    Parque* isInto_;

public:
    Arbol(string assetnum, int num_parque, int num_distrito, string nbre_distrito, 
          int num_barrio, string nbre_barrio, double X, double Y, 
          float perimetro, float altura);
    Arbol();

    string get_assetnum() const;
    int get_num_parque() const;
    int get_num_distrito() const;
    string get_nbre_distrito() const;
    int get_num_barrio() const;
    string get_nbre_barrio() const;
    double get_X() const;
    double get_Y() const;
    float get_perimetro() const;
    float get_altura() const;

    // --- SETTERS ---
    void set_assetnum(const string& assetnum); // Corregido: faltaba el parámetro
    void set_num_parque(int num_parque);
    void set_num_distrito(int num_distrito);
    void set_nbre_distrito(const string& nbre_distrito);
    void set_num_barrio(int num_barrio);
    void set_nbre_barrio(const string& nbre_barrio);
    void set_X(double X);
    void set_Y(double Y);
    void set_perimetro(float perimetro);
    void set_altura(float altura);

    // --- MÉTODOS DE ESPECIE ---
    void setEspecie(Especie* e);
    Especie* getEspecie();
    string getCodEspecie() const;
    string getTipoEspecie() const;
    string getNbreComun() const;
    string getNbreCientifico() const;

    // --- OPERADORES ---
    bool operator<(const Arbol& otro) const;
    bool operator==(const Arbol& otro) const;

    void setParque(Parque* p);
    Parque* getParque();
};

#endif