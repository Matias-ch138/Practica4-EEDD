#include "Arbol.h"

// --- CONSTRUCTORES ---
/**
 * @brief Constructor parametrizado de un Arbol
 * 
 * @param assetnum su assetnum
 * @param num_parque el número de parque asignado
 * @param num_distrito el número de distrito en el que esta
 * @param nbre_distrito el nombre del distrito en el que esta
 * @param num_barrio el número del barrio en el que esta
 * @param nbre_barrio el nombre del barrio en el que esta
 * @param X 
 * @param Y 
 * @param perimetro perimetro del arbol
 * @param altura altura del arbol
 */
Arbol::Arbol(string assetnum, int num_parque, int num_distrito, string nbre_distrito, 
             int num_barrio, string nbre_barrio, double X, double Y, 
             float perimetro, float altura) {
    assetnum_ = assetnum;
    num_parque_ = num_parque;
    num_distrito_ = num_distrito;
    nbre_distrito_ = nbre_distrito;
    num_barrio_ = num_barrio;
    nbre_barrio_ = nbre_barrio;
    X_ = X;
    Y_ = Y;
    perimetro_ = perimetro;
    altura_ = altura;
    especieAsociada_ = nullptr;
    isInto_=nullptr;
}
/**
 * @brief Constructor por defecto de un Arbol
 * 
 */
Arbol::Arbol() {
    assetnum_ = "";
    num_parque_ = 0;
    num_distrito_ = 0;
    nbre_distrito_ = "";
    num_barrio_ = 0;
    nbre_barrio_ = "";
    X_ = 0;
    Y_ = 0;
    perimetro_ = 0;
    altura_ = 0;
    especieAsociada_ = nullptr;
    isInto_=nullptr;
}

// --- GETTERS ---
/**
 * @brief obtener el assetnum
 * 
 * @return string el assetnum
 */
string Arbol::get_assetnum() const { return assetnum_; }
/**
 * @brief obtener el número del parque asignado
 * 
 * @return int número del parque asignado
 */
int Arbol::get_num_parque() const { return num_parque_; }
/**
 * @brief obtener el número del distrito en el que esta
 * 
 * @return int número del distrito en el que esta
 */
int Arbol::get_num_distrito() const { return num_distrito_; }
/**
 * @brief obtener el nombre del distrito en el que esta
 * 
 * @return string nombre del distrito en el que esta
 */
string Arbol::get_nbre_distrito() const { return nbre_distrito_; }
/**
 * @brief obtener el número del barrio en el que esta
 * 
 * @return int número del barrio en el que esta
 */
int Arbol::get_num_barrio() const { return num_barrio_; }
/**
 * @brief obtener el nombre del barrio en el que esta
 * 
 * @return string nombre del barrio en el que esta
 */
string Arbol::get_nbre_barrio() const { return nbre_barrio_; }
/**
 * @brief 
 * 
 * @return double 
 */
double Arbol::get_X() const { return X_; }
/**
 * @brief 
 * 
 * @return double 
 */
double Arbol::get_Y() const { return Y_; }
/**
 * @brief obtener el perimetro del arbol
 * 
 * @return float perimetro del arbol
 */
float Arbol::get_perimetro() const { return perimetro_; }
/**
 * @brief obtener la altura del arbol
 * 
 * @return float altura del arbol
 */
float Arbol::get_altura() const { return altura_; }

// --- SETTERS ---
/**
 * @brief Establecer el assetnum de un arbol
 * 
 * @param assetnum assetnum que vamos a establecer
 */
void Arbol::set_assetnum(const string& assetnum) { assetnum_ = assetnum; }
/**
 * @brief Establecer el número del paque de un arbol
 * 
 * @param num_parque número del parque
 */
void Arbol::set_num_parque(int num_parque) { num_parque_ = num_parque; }
/**
 * @brief Estabecer el número de un distrito a un arbol
 * 
 * @param num_distrito número de un distrito
 */
void Arbol::set_num_distrito(int num_distrito) { num_distrito_ = num_distrito; }
/**
 * @brief Establecer nombre de un distrito a un arbol
 * 
 * @param nbre_distrito nombre de un distrito
 */
void Arbol::set_nbre_distrito(const string& nbre_distrito) { nbre_distrito_ = nbre_distrito; }
/**
 * @brief establecer número de un barrio al arbol
 * 
 * @param num_barrio número de un barrio
 */
void Arbol::set_num_barrio(int num_barrio) { num_barrio_ = num_barrio; }
/**
 * @brief establecer nombre de un barrio al arbol
 * 
 * @param nbre_barrio nombre de un barrio
 */
void Arbol::set_nbre_barrio(const string& nbre_barrio) { nbre_barrio_ = nbre_barrio; }
/**
 * @brief inicializa el atributo X
 * 
 * @param X 
 */
void Arbol::set_X(double X) { X_ = X; }
/**
 * @brief inicializa el atributo Y
 * 
 * @param Y 
 */
void Arbol::set_Y(double Y) { Y_ = Y; }
/**
 * @brief establecer el perimetro de un arbol
 * 
 * @param perimetro perimetro que vamos a establecer
 */
void Arbol::set_perimetro(float perimetro) { perimetro_ = perimetro; }
/**
 * @brief establecer la altura de un arbol
 * 
 * @param altura altura que vamos a estabecer
 */
void Arbol::set_altura(float altura) { altura_ = altura; }

// --- MÉTODOS DE ESPECIE ---
/**
 * @brief Establecer una especie a un arbol
 * 
 * @param e especie que vamos a establecer
 */
void Arbol::setEspecie(Especie *e) { 
    especieAsociada_ = e; 
}
/**
 * @brief obtener el codigo de la especie asociada
 * 
 * @return string el codigo de la especie asociada
 */
string Arbol::getCodEspecie() const {
    if (especieAsociada_ == nullptr) return "";
    return especieAsociada_->get_codigo_especie();
}
/**
 * @brief obtener el tipo de la especie asociada al arbol
 * 
 * @return string tipo de la especie asociada al arbol
 */
string Arbol::getTipoEspecie() const {
    if (especieAsociada_ == nullptr) return "";
    return especieAsociada_->gettipo_planta();
}
/**
 * @brief obtener el nombre común de la especie asociada al arbol
 * 
 * @return string nombre común de la especie asociada al arbol
 */
string Arbol::getNbreComun() const {
    if (especieAsociada_ == nullptr) return "";
    return especieAsociada_->getnombre_comun();
}
/**
 * @brief obtener el nombre cientifico de la especie asociada al arbol
 * 
 * @return string nombre cientifico de la especie asociada al arbol
 */
string Arbol::getNbreCientifico() const {
    if (especieAsociada_ == nullptr) return "";
    return especieAsociada_->getnombre_cientifico();
}
// --- OPERADORES ---
/**
 * @brief operador de menor
 * 
 * @param otro arbol que vamos a comparar
 * @return true si @param otro es mayor
 * @return false si @param otro es menor
 */
bool Arbol::operator<(const Arbol &otro) const {
    return assetnum_ < otro.assetnum_;
}
/**
 * @brief operador de igual
 * 
 * @param otro arbol que vamos a comparar
 * @return true si @param otro es igual
 * @return false si @param otro es diferente
 */
bool Arbol::operator==(const Arbol &otro) const {
    return assetnum_ == otro.assetnum_;
}

/**
 * @brief Obtener la especie asociada al arbol
 * 
 * @return Especie* especie asociada al arbol
 */
Especie* Arbol::getEspecie(){
    return this->especieAsociada_;
}

/**
 * @brief Establecer el parque al que pertenece
 * 
 * @param p parque al que pertenece
 */
void Arbol::setParque(Parque* p){
    this->isInto_=p;
}
/**
 * @brief Obtener el parque al que pertenece
 * 
 * @return Parque* parque al que pertenece
 */
Parque* Arbol::getParque(){
    return this->isInto_;
}