#include <iostream>
using namespace std;
#include "Especie.h"

/**
 * @brief obtener el código de la especie
 * @return devuelve el código de la especie
 */
string Especie::getcodigo_especie() const{
    return codigoEspecie_;
}
/**
 * @brief establecer el código de la especie
 * @param codigoEspecie es el código que se le va a asignar al codigo de la especie
 */
void Especie::set_codigo_especie(string codigoEspecie){
    codigoEspecie_ = codigoEspecie;
}
/**
 * @brief obtener el nombre común de la especie
 * @return devuelve el nombre común de la especie
 */
string Especie::getnombre_comun() const{
    return nombreComun_;
}
/**
 * @brief establecer el nombre común de la especie
 * @param nombreComun es el nombre que se le va a asignar al nombre común de la especie 
 */
void Especie::setNombreComun(string nombreComun){
    nombreComun_ = nombreComun;
}
/**
 * @brief obtener el nombre cientifico de la especie
 * @return devuelve el nombre cientifico de la especie
 */
string Especie::getnombre_cientifico() const{
    return nombreCientifico_;
}
/**
 * @brief establecer el nombre cientifico de la especie
 * @param nombrecientifico es el nombre que se le va a asignar al nombre cientifico de la especie 
 */
void Especie::setNombreCientifico(string nombreCientifico){
    nombreCientifico_ = nombreCientifico;
}
/**
 * @brief obtener el tipo de planta de la especie
 * @return devuelve el tipo de planta de la especie
 */
string Especie::gettipo_planta() const{
    return tipoPlanta_;
}
/**
 * @brief establecer el tipo de planta
 * @param tipoPlanta es el tipo de planta que se le va a asignar a la especie
 */
void Especie::setTipoPlanta(string tipoPlanta){
    tipoPlanta_ = tipoPlanta;
}
/**
 * @brief muestra toda la información sobre la especie en formato CSV
 */
void Especie::mostrarInfo() const{
    cout<<"Codigo de especie: " + codigoEspecie_ + "\nNombre comun: " + nombreComun_ + "\nNombre cientifico: " + nombreCientifico_ + "\nTipo de planta: " + tipoPlanta_+"\n";
}

/**
 * @brief es el operador menor el cuál compara los códigos de la especie y si es cierta la operación devuelve true
 * @param origen es la especie con la que estamos comparando otra especie
 * @return devuelve true si la operación es cierta
 */
bool Especie::operator<(const Especie& origen) const{
    return codigoEspecie_ < origen.codigoEspecie_;
}
/**
 * @brief es el operador igua el cuál compara si los códigos de dos especies son iguales
 * @param origen es la especie con la que estamos comparando otra especie
 * @return devuelve true si la operación es cierta
 */
bool Especie::operator==(const Especie& origen) const{
    return codigoEspecie_ == origen.codigoEspecie_;
}
// Alias para que coincida con el uso de main.cpp 
string Especie::get_codigo_especie() const { return codigoEspecie_; }
string Especie::get_nombre_comun() const { return nombreComun_; }
string Especie::get_nombre_cientifico() const { return nombreCientifico_; }
string Especie::get_tipo_planta_str() const { return tipoPlanta_; }