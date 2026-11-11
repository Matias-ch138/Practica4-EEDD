#ifndef CONTROLPARQUES_H
#define CONTROLPARQUES_H

#include <iostream>
#include <string>
using namespace std;

#include "Especie.h"
#include "Parque.h"
#include <list>

class ControlParques {
private:
    vector<Especie> varieties;
    list<Parque> parks;
    map<string, Arbol> trees; //clave assetnum
    multimap<string, Arbol*> treeName; //clave nombrecomun

public:
    /**
     * @brief Constructor por defecto de la clase ControlParques
     * 
     */
    ControlParques();
    /**
     * @brief Constructor parametrizado de la clase ControlParques
     * 
     * @param rutaEspecies ruta del archivo que contiene las especies
     * @param rutaParques ruta del archivo que contienen los parques
     * @param rutaArboles ruta del archivo que contiene los arboles
     */
    ControlParques(const string& rutaEspecies, const string& rutaParques, const string& rutaArboles);
    /**
     * @brief Cuenta el número de especies que hay en todos los parques dado un nombre comun
     * 
     * @param ncomun el nombre comun de las especies que queremos contar
     * @return int el número de especies con @param ncomun que hay en todos los parques
     */
    int contarEspecieParque(string ncomun);
    /**
     * @brief Genera un vector de todas las especies con un subnombre especifico
     * 
     * @param cadena subnombre que buscamos
     * @return vector<Especie> Vector de especies con ese subnombre
     */
    vector<Especie> listadoEspecieSubNbre(string cadena);
    /**
     * @brief Busqueda de un parque dado su nombre
     * 
     * @param nbre_parque nombre del parque que buscamos
     * @return Parque* puntero al parque con nombre @param nbre_parque
     */
    Parque* buscarParque(const string& nbre_parque);

    /**
     * @brief Busqueda de un arbol dado su @param asNum
     * 
     * @param asNum asNum del arbol que buscamos
     * @return Arbol* puntero al arbol con @param asNum
     */
    Arbol* buscarArbol(string asNum);
    /**
     * @brief Dado un nombre de un parque genera un vector con todos los arboles que tiene
     * 
     * @param nbre_parque nombre del parque
     * @return vector<Arbol*> todos los arboles que se encuentran en el parque cuyo nombre es @param nbre_parque
     */
    vector<Arbol*> listaArbParque(string nbre_parque);
    /**
     * @brief Nos da el arbol mas alto de todos los parques
     * 
     * @return Arbol* puntero al arbol mas alto
     */
    Arbol* arbolMasAlto();
    /**
     * @brief Segun el nombre del parque cuenta las especies distintas que tiene
     * 
     * @param nbre_parque nombre del parque
     * @return int número de especies distintas que tiene el parque
     */
    int contarEspecies(string nbre_parque);
    /**
     * @brief Cuenta todos los tipos de especies diferentes alojados en todos los parques
     * 
     * @return int número de tipos de especies diferentes alojados en todos los parques
     */
    int contarTipos();
    /**
     * @brief Devuelve el número de árboles almacenados en el AVL.
     * @return unsigned int cantidad total de árboles cargados.
     */
    unsigned int numArboles() const;
    /**
     * @brief obtener las especies de todos los parques
     * 
     * @return vector<Especie>& vector dinamico con todas las especies de todos los parques
     */
    vector<Especie>& get_varieties();
    /**
     * @brief obtener las especies de todos los parques
     * 
     * @return const vector<Especie>& vector dinamico con todas las especies de todos los parques
     */
    const vector<Especie>& get_varieties() const;
    /**
     * @brief obtener todos los parques
     * 
     * @return list<Parque>& Lista Doblemente Enlazada con todos los parques
     */
    list<Parque>& get_parks();
    /**
     * @brief obtener todos los parques
     * 
     * @return const list<Parque>& Lista Doblemente Enlazada con todos los parques
     */
    const list<Parque>& get_parks() const;
    /**
     * @brief obtner todos los parques
     * 
     * @return list<Parque>& Lista Doblemente Enlazada con todos los parques
     */
    list<Parque>& get_nbre_parque();
    /**
     * @brief obtner todos los parques
     * 
     * @return const list<Parque>& Lista Doblemente Enlazada con todos los parques
     */
    const list<Parque>& get_nbre_parque() const;
};

#endif